#include "stdafx.h"
// Using =======================================================================
namespace py = pybind11;

// Module ======================================================================
void Export_pystes_gamedefines(py::module &m)
{
	py::class_< FName >(m, "FName")
		.def(py::init<>())
		.def(py::init<const std::string&>())
		.def_static("Names", &FName::Names, py::return_value_policy::reference)
		.def_readwrite("Index", &FName::Index)
		.def_readwrite("Number", &FName::Number)
		.def("GetName", &FName::GetName, py::return_value_policy::reference)
		;
	py::class_< FNameEntry >(m, "FNameEntry")
		.def(py::init<>())
		.def_readonly("Name", &FNameEntry::Name)
		.def("AppendNameToString", &FNameEntry::AppendNameToString)
		;
	py::class_< FStruct >(m, "FStruct")
		.def("popObject", &FStruct::popObject, py::return_value_policy::reference)
		.def("popFName", &FStruct::popFName, py::return_value_policy::reference)
		.def("popFVector", &FStruct::popFVector, py::return_value_policy::reference)
		.def("popFloat", &FStruct::popFloat, py::return_value_policy::reference)
		.def("popBool", &FStruct::popBool, py::return_value_policy::reference)
		.def("popByte", &FStruct::popByte, py::return_value_policy::reference)
		.def("popInt", &FStruct::popInt, py::return_value_policy::reference)
		.def("popFString", &FStruct::popFString, py::return_value_policy::reference)
		.def("popULong", &FStruct::popULong, py::return_value_policy::reference)
		;
	py::class_< FOutputDevice >(m, "FOutputDevice")
		.def(py::init<>())
		.def_readwrite("VfTable", &FOutputDevice::VfTable, py::return_value_policy::reference)
		.def_readwrite("bAllowSuppression", &FOutputDevice::bAllowSuppression, py::return_value_policy::reference)
		.def_readwrite("bSuppressEventTag", &FOutputDevice::bSuppressEventTag, py::return_value_policy::reference)
		.def_readwrite("bAutoEmitLineTerminator", &FOutputDevice::bAutoEmitLineTerminator, py::return_value_policy::reference)
		;
	py::class_< FFrame, FOutputDevice >(m, "FFrame")
		.def_readwrite("Node", &FFrame::Node, py::return_value_policy::reference)
		.def_readwrite("Object", &FFrame::Object, py::return_value_policy::reference)
		.def_readwrite("PreviousFrame", &FFrame::PreviousFrame, py::return_value_policy::reference)
		.def_property("Code", [](FFrame &self) { return (int)self.Code; }, [](FFrame &self, int value) {self.Code = (unsigned char *)value; })
		.def_property("Locals", [](FFrame &self) { return (int)self.Locals; }, [](FFrame &self, int value) {self.Locals = (unsigned char *)value; })
		.def("SkipFunction", &FFrame::SkipFunction, py::return_value_policy::reference)
		.def("popObject", &FFrame::popObject, py::return_value_policy::reference)
		.def("popFName", &FFrame::popFName, py::return_value_policy::reference)
		.def("popFloat", &FFrame::popFloat, py::return_value_policy::reference)
		.def("popByte", &FFrame::popByte, py::return_value_policy::reference)
		.def("popInt", &FFrame::popInt, py::return_value_policy::reference)
		.def("popFString", &FFrame::popFString, py::return_value_policy::reference)
		.def("popULong", &FFrame::popULong, py::return_value_policy::reference)
		.def("popBool", &FFrame::popBool, py::return_value_policy::reference)
		.def("popTArrayObjects", &FFrame::popTArrayObjects, py::return_value_policy::reference)
		.def("popRawTArray", &FFrame::popRawTArray, py::return_value_policy::reference)
		;

	py::class_< FString >(m, "FString")
		.def(py::init<wchar_t*>())
		.def_readwrite("Count", &FString::Count)
		.def_readwrite("Max", &FString::Max)
		.def_readwrite("Data", &FString::Data)
		.def("AsString", &FString::AsString)
		;
}