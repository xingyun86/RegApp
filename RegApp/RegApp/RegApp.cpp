// RegApp.cpp : Defines the entry point for the application.
//

#include "RegApp.h"

int main(int argc, char ** argv)
{
	std::cout << "Hello CMake." << std::endl;
	RegApp::Inst()->RegAuto(1);
	//RegApp::Inst()->EnabledUAC(1);
	system("PAUSE");
	return 0;
}
