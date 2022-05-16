#include "MainWindow.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_BUTTON(10001, ButtonSelected)
wxEND_EVENT_TABLE()

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(600, 850))
{
	long style = wxTE_RIGHT | wxTE_READONLY;
	int buttonLable = 0;
	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	wxBoxSizer* mainWindowSizer = new wxBoxSizer(wxVERTICAL);

	//textbox used as the output display
	outputWindow = new wxTextCtrl(this, wxID_ANY, "", wxPoint(20, 20), wxSize(540, 270), style);
	mainWindowSizer->Add(outputWindow, 0, wxEXPAND | wxTOP | wxBOTTOM);
	
	//Created a grid for the calc UI

	wxGridSizer* buttonSelection = new wxGridSizer(fieldWidth, fieldLength, 3, 3);
	button = new wxButton * [fieldWidth * fieldLength];

	
	


	
	for(int x = 0; x < fieldLength; x++)
	{
		for (int y = 0; y < fieldWidth; y++)
		{
			button[y * fieldWidth + x] = new wxButton(this, 10000 + (y * fieldWidth + x) , operationLabels[buttonLable], wxPoint(buttonStartingPosX,buttonStartingPosY));
			button[y * fieldWidth + x]->SetFont(font);
			buttonSelection->Add(button[y * fieldWidth + x], 1, wxEXPAND | wxALL);
			buttonLable++;
		}

		
	}

	mainWindowSizer->Add(buttonSelection, 1, wxEXPAND);

	this->SetSizer(mainWindowSizer);
	
}

void MainWindow::ButtonSelected(wxCommandEvent &event){

}

MainWindow::~MainWindow(){}