#include "pch.h"
#include "Form1.h"
using namespace System;

//int main(array<System::String ^> ^args)
//{
//    return 0;
//}

using namespace System::Windows::Forms;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CppCLRWinFormsProjekt::Form1());
	return 0;
}