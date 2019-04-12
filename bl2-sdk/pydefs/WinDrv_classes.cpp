#include "stdafx.h"
// Using =======================================================================
namespace py = pybind11;

// Module ======================================================================
void Export_pystes_WinDrv_classes(py::module &m)
{
	py::class_< UWindowsClient, UClient >(m, "UWindowsClient")
		.def_readwrite("AudioDeviceClass", &UWindowsClient::AudioDeviceClass, py::return_value_policy::reference)
		.def_readwrite("AllowJoystickInput", &UWindowsClient::AllowJoystickInput)
		;
	py::class_< UXnaForceFeedbackManager, UForceFeedbackManager >(m, "UXnaForceFeedbackManager")
		;
	py::class_< UFacebookWindows, UFacebookIntegration >(m, "UFacebookWindows")
		;

}