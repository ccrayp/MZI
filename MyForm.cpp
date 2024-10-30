#pragma optimize("agi", off)

#include "MyForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	FreaquencyAnalisys::MyForm form;
	Application::Run(% form);
}