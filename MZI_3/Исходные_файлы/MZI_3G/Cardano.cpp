#pragma optimize("agi", off)

#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>
#include "Cardano.h"
#include "ClassicMethods.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MZI3G::ClassicMethods form;
	Application::Run(% form);
}