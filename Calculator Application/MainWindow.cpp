#include "MainWindow.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_BUTTON(10001, ButtonSelected)
wxEND_EVENT_TABLE()

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(600, 850))
{
	long style = wxTE_RIGHT | wxTE_READONLY;

	outputWindow = new wxTextCtrl(this, wxID_ANY, "", wxPoint(20, 20), wxSize(540, 140), style);
	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	button = new wxButton * [fieldWidth * fieldLength];
	wxGridSizer* buttonSelection = new wxGridSizer(fieldWidth, fieldLength, 5, 5);


	int buttonLable = 0;
	for(int x = 0; x < fieldLength; x++)
	{
		for (int y = 0; y < fieldWidth; y++)
		{
			button[y * fieldWidth + x] = new wxButton(this, 100000 + (y * fieldWidth + x) , operationLabels[buttonLable], wxPoint(buttonStartingPosX,buttonStartingPosY));
			button[y * fieldWidth + x]->SetFont(font);
			buttonStartingPosX += buttonSizeX;
			buttonLable++;
		}

		buttonStartingPosX = orignalButtonPosX;
		buttonStartingPosY += buttonSizeY;
	}
}

void MainWindow::ButtonSelected(wxCommandEvent &event){

}

MainWindow::~MainWindow(){}