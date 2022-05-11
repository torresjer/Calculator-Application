#include "MainWindow.h"

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30,30), wxSize(600,850))
{
	long style =  wxTE_RIGHT | wxTE_READONLY;
	
	outputWindow = new wxTextCtrl(this, wxID_ANY, "", wxPoint(20, 20), wxSize(540, 140), style);
	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	
	int buttonLable = 0;
	for(int x = 0; x < fieldLength; x++)
	{
		for(int y = 0; y < fieldWidth; y++)
		{
			button = new wxButton(this, wxID_ANY, operationLabels[buttonLable], wxPoint(buttonStartingPosX, buttonStartingPosY), wxSize(buttonSizeX, buttonSizeY));
			button->SetFont(font);
			buttonStartingPosX += buttonSizeX;
			buttonLable++;
		}

		buttonStartingPosX = orignalButtonPosX;
		buttonStartingPosY += buttonSizeY;
	}
}

MainWindow::~MainWindow(){}