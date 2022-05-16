#include "MainWindow.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_BUTTON(10001, ButtonSelected)
wxEND_EVENT_TABLE()

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(600, 850))
{
	int buttonLable = 0;//Integrator for lables added to buttons
	ButtonFactory buttonMaker;//Button Factory to make new buttons

	//textbox used as the output display
	long style = wxTE_RIGHT | wxTE_READONLY;
	outputWindow = new wxTextCtrl(this, wxID_ANY, "", wxPoint(20, 20), wxSize(540, 270), style);

	//Main Sizer to put gridSizer into
	wxBoxSizer* mainWindowSizer = new wxBoxSizer(wxVERTICAL);
	mainWindowSizer->Add(outputWindow, 0, wxEXPAND | wxTOP | wxBOTTOM);
	
	//Created a grid for the calc UI
	wxGridSizer* buttonSelection = new wxGridSizer(fieldWidth, fieldLength, 3, 3);
	button = new wxButton * [fieldWidth * fieldLength];

	for(int x = 0; x < fieldLength * fieldWidth; x++)
	{
		button[x] = buttonMaker.CreateButton(this, x, operationLabels[x]);
		buttonSelection->Add(button[x], 1, wxEXPAND | wxALL);
		button[x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainWindow::ButtonSelected, this);
		buttonLable++;
	}
	
	
	mainWindowSizer->Add(buttonSelection, 1, wxEXPAND);

	this->SetSizer(mainWindowSizer);
	
	
}

void MainWindow::ButtonSelected(wxCommandEvent &event){
	
	//Cordinates of button selection.
	wxFont textBoxFont(32, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	int selectedButtonID = event.GetId() - 10000;
	outputWindow->SetFont(textBoxFont);

	switch (selectedButtonID)
	{
	case 0:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 1:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 2:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 3:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 4:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 5:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 6:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 7:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 8:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 9:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 10:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 11:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 12:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 13:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 14:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 15:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 16:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 17:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 18:
		writeTextForButtonSelected(selectedButtonID);
		break;
	case 19:
		writeTextForButtonSelected(selectedButtonID);
		break;
	default:
		break;
	}

	


}
void MainWindow::writeTextForButtonSelected(int buttonID) {

	outputWindow->AppendText(operationLabels[buttonID]);

}

MainWindow::~MainWindow(){}

