#include "stdafx.h"
#include "CPythonInterface.h"
#include "Logging.h"
#include "Settings.h"
#include "Util.h"
#include "BL2-SDK.h"
#include "GameHooks.h"
#include <algorithm>
#include <sstream>
#include <functional>
#include <iostream>
#include <string>
#include <cstdlib>

void RegisterEngineHook(const std::string& funcName, const std::string& hookName, py::object funcHook) {
	GameHooks::EngineHookManager->Register(funcName, hookName, [funcHook](UObject* caller, UFunction* function, void* parms, void* result) {
		try {
			py::object py_caller = py::cast(caller, py::return_value_policy::reference);
			py::object py_function = py::cast(function, py::return_value_policy::reference);
			py::object py_parms = py::cast(FStruct(parms), py::return_value_policy::reference);
			py::object py_result = py::cast(FStruct(result), py::return_value_policy::reference);
			py::object ret = funcHook(py_caller, py_function, py_parms, py_result);
			return ret.cast<bool>();
		} catch (std::exception e) {
			Logging::LogF(e.what());
		}
		return true;
		}
	);
}


void RegisterScriptHook(const std::string& funcName, const std::string& hookName, py::object funcHook) {
	GameHooks::UnrealScriptHookManager->Register(funcName, hookName, [funcHook](UObject* caller, FFrame& stack, void* const result, UFunction* function) {
		try {
			py::object py_caller = py::cast(caller, py::return_value_policy::reference);
			py::object py_stack = py::cast(stack, py::return_value_policy::reference);
			py::object py_result = py::cast(FStruct(result), py::return_value_policy::reference);
			py::object py_function = py::cast(function, py::return_value_policy::reference);
			py::object ret = funcHook(py_caller, py_stack, py_result, py_function);
			return ret.cast<bool>();
		} catch (std::exception e) {
			Logging::LogF(e.what());
		}
		return true;
		}
	);
}


namespace py = pybind11;

PYBIND11_EMBEDDED_MODULE(bl2sdk, m)
{
	Export_pystes_gamedefines(m);
	Export_pystes_Core_structs(m);
	Export_pystes_Core_classes(m);
	Export_pystes_Engine_structs(m);
	Export_pystes_Engine_classes(m);
	Export_pystes_GameFramework_structs(m);
	Export_pystes_GameFramework_classes(m);
	Export_pystes_GFxUI_structs(m);
	Export_pystes_GFxUI_classes(m);
	Export_pystes_GearboxFramework_structs(m);
	Export_pystes_GearboxFramework_classes(m);
	Export_pystes_WillowGame_structs(m);
	Export_pystes_WillowGame_classes(m);
	Export_pystes_AkAudio_structs(m);
	Export_pystes_AkAudio_classes(m);
	Export_pystes_IpDrv_structs(m);
	Export_pystes_IpDrv_classes(m);
	Export_pystes_WinDrv_structs(m);
	Export_pystes_WinDrv_classes(m);
	Export_pystes_XAudio2_structs(m);
	Export_pystes_XAudio2_classes(m);
	Export_pystes_OnlineSubsystemSteamworks_structs(m);
	Export_pystes_OnlineSubsystemSteamworks_classes(m);
	Export_pystes_TArray(m);
	m.def("Log", [](std::string in) { Logging::Log(in.c_str(), in.length()); });
	m.def("LoadPackage", &BL2SDK::LoadPackage);
	m.def("RegisterEngineHook", &RegisterEngineHook);
	m.def("GetEngine", &BL2SDK::GetEngine, py::return_value_policy::reference);
	m.def("RegisterScriptHook", &RegisterScriptHook);
	m.def("RemoveEngineHook", [](const std::string& funcName, const std::string& hookName) {GameHooks::EngineHookManager->Remove(funcName, hookName); });
	m.def("RemoveScriptHook", [](const std::string& funcName, const std::string& hookName) {GameHooks::UnrealScriptHookManager->Remove(funcName, hookName); });
	m.def("DoInjectedCallNext", &BL2SDK::doInjectedCallNext);
}

bool PythonGCTick(UObject* caller, UFunction* function, void* parms, void* result)
{
	return true;
}

bool CheckPythonCommand(UObject* caller, FFrame& stack, void* const result, UFunction* function)
{
	FString *command = &FString();
	unsigned char *code = stack.Code;
	BL2SDK::pFrameStep(&stack, stack.Object, command);
	char *input = command->AsString();
	if (strncmp("py ", input, 3) == 0) {
		BL2SDK::Python->DoString(input + 3);
		stack.SkipFunction();
		return true;
	}
	else if (strncmp("pyexec ", input, 7) == 0) {
		BL2SDK::Python->DoFile(input + 7);
		stack.SkipFunction();
		return true;
	}
	stack.Code = code;
	return true;
}

CPythonInterface::CPythonInterface()
{
	m_modulesInitialized = false;
	InitializeState();

	GameHooks::EngineHookManager->Register("Function WillowGame.WillowGameViewportClient:Tick", "PythonGCTick", &PythonGCTick);
	GameHooks::UnrealScriptHookManager->Register("Function Engine.Console.ShippingConsoleCommand", "CheckPythonCommand", &CheckPythonCommand);
}

CPythonInterface::~CPythonInterface()
{
	if (m_modulesInitialized)
	{
		CallShutdownFuncs();
	}

	CleanupState();

	GameHooks::EngineHookManager->Remove("Function WillowGame.WillowGameViewportClient:Tick", "PythonGCTick");
}

void CPythonInterface::InitializeState()
{
	try
	{
		py::initialize_interpreter();
		py::module::import("bl2sdk");
		m_mainNamespace = py::module::import("__main__");
		SetPaths();
	}
	catch (std::exception e) {
		Logging::LogF("%s", e.what());
	}

}
void CPythonInterface::CleanupState()
{
	py::finalize_interpreter();
}

PythonStatus CPythonInterface::InitializeModules()
{
	m_modulesInitialized = false;

	if (DoFile("init.py") != 0)
	{
		Logging::Log("[Python] Failed to initialize Python modules\n");
		return PYTHON_MODULE_ERROR;
	}
	Logging::Log("[Python] Python initialized (" PYTHON_ABI_STRING ")\n");
	m_modulesInitialized = true;
	return PYTHON_OK;
}

void CPythonInterface::SetPaths()
{
	m_PythonPath = Util::Narrow(Settings::GetPythonFile(L""));
	const char *pythonString = Util::Format("import sys;sys.path.append(r'%s\\')", m_PythonPath.c_str()).c_str();
	DoString(pythonString);
}

int CPythonInterface::DoFile(const char *filename)
{
	return DoFileAbsolute(Util::Format("%s\\%s", m_PythonPath.c_str(), filename).c_str());
}

int CPythonInterface::DoString(const char *command)
{
	try {
		py::exec(command);
	}
	catch (std::exception e) {
		Logging::LogF("%s", e.what());
	}
	return 0;
}

int CPythonInterface::DoFileAbsolute(const char *path)
{
	try {
		py::eval_file(path);
	}
	catch (std::exception e) {
		Logging::LogF("%s", e.what());
	}
	return 0;
}

void CPythonInterface::CallShutdownFuncs()
{
}

py::object CPythonInterface::GetPythonNamespace()
{
	return m_mainNamespace;
}
