//N16114306 �B�Ӻ@
//����ɦV�{���]�pHW3
//���e�eTicTocToe
//main()�禡

#include "Map.h"

using namespace System;
using namespace FinalProject;

[STAThreadAttribute]
int main(array<System::String^ >^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//Show windows
	Application::Run(gcnew Map());
	return 0;
}