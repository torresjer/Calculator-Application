//This is the Main window of the application
#pragma once
#include "wx/wx.h"

class MainWindow : public wxFrame //ensure that you are inheriting from wxFrame 
{
public:
	MainWindow();
	~MainWindow();

public:
	//This is the button field available to the user
	int fieldWidth = 4;
	int fieldLength = 5;
	//The individual button size 
	//int buttonSizeX = 135;
	//int buttonSizeY = 107;
	//int orignalButtonPosX = 20;
	//int orignalButtonPosY = 220;
	int buttonStartingPosX = 20;
	int buttonStartingPosY = 220;
private:


	wxSizer* buttonSelection = nullptr;
	std::string operationLabels[20] = 
		{ "1","2","3","4","+","5","6","7","-","8","9","0","/","=","C","*","%","Bin","Hex","Dec"};
	wxTextCtrl* outputWindow = nullptr;
	wxButton** button = nullptr;

	void ButtonSelected(wxCommandEvent &event);

	wxDECLARE_EVENT_TABLE();


};

