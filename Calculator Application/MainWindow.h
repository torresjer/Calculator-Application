//This is the Main window of the application
#pragma once
#include "wx/wx.h"
#include "ButtonFactory.h"
#include "Calculator_Processor.h"
enum CalculatorOperations
{
	Null = 0,
	Addition,
	Subtraction,
	Multiplication,
	Division,
	Modulus,
	Equals,
	Clear
};
using namespace std;


class MainWindow : public wxFrame //ensure that you are inheriting from wxFrame 
{
public:
	MainWindow();
	~MainWindow();

public:
	//This is the button field available to the user
	int fieldWidth = 4;
	int fieldLength = 5;
	int converstionValue = 0;
	float currentValue = 0.0F;
	bool syntaxErrorOccurred = false;
	bool operationAnswered = false;
	bool conversionTookPlace = false;
	
	CalculatorOperations currentOperator = Null;
	CalculatorOperations previousOperator = Null;
	
	void SetNumericInputs(vector<float>* numaricInputs) { this->numericInputs = numaricInputs; }; 
	

	vector<float>* GetNumericInputVector() { return numericInputs; }

private:

	vector<float>* numericInputs = new vector<float>;
	wxGridSizer* buttonSelection = nullptr;
	std::string operationLabels[20] = 
		{ "1","2","3","4","+","5","6","7","8","-","9","0","=","C","/","Dec","Bin","Hex","%","*"};
	wxTextCtrl* outputWindow = nullptr;
	wxButton** button = nullptr;

	void ButtonSelected(wxCommandEvent &event);
	

	//Helper Functions
	void SetOutputWindowToZero(wxTextCtrl* outputWindow);
	void writeTextForButtonSelected(int buttonID);
	
	


	

	wxDECLARE_EVENT_TABLE();


};

