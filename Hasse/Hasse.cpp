#include "stdafx.h"
#include "input1.h"

using namespace System;
using namespace System::Windows::Forms;

int main(cli::array<String^>^ arg) {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Hasse::input());

	return 0;


	/*
	for (c = 0; c < matrix.d; c++) {
	for (int f = 0; f < matrix.d; f++) {

	}
	}
	matrix.*/
	//delete matrix;
}