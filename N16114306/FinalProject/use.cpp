//N16114306 劉倬愿
//物件導向程式設計HW3
//圈圈叉叉TicTocToe
//main()函式

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