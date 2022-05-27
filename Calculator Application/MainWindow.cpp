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
	
	//Created a gridSizer for the calc UI
    buttonSelection = new wxGridSizer(fieldWidth, fieldLength, 3, 3);
	button = new wxButton * [fieldWidth * fieldLength];

	

	//Adding button array to the gridsizer
	for(int x = 0; x < fieldLength * fieldWidth; x++)
	{
		//Uses ButtonFactory to generate buttons
		button[x] = buttonMaker.CreateButton(this, x, operationLabels[x]);
		buttonSelection->Add(button[x], 1, wxEXPAND | wxALL);

		//Binds button event to the ButtonSelected function
		button[x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainWindow::ButtonSelected, this);
		buttonLable++;
	}
	
	//Adds the gridsizer(buttonSelection) to the boxsizer(mainWindowSizer)
	mainWindowSizer->Add(buttonSelection, 1, wxEXPAND);

	//Sets boxsizer as the sizer for the mainWindow
	this->SetSizer(mainWindowSizer);
	
}

void MainWindow::ButtonSelected(wxCommandEvent &event){
	//Local Variables for ButtonSelected
	
	int selectedButtonID = event.GetId() - 10000;//Cordinates of button selection.
	wxFont textBoxFont(32, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	Calculator_Processor& processor = Calculator_Processor::GetInstance(); //Calculator_Processor Instance for this App
	vector<float>* numaricInputs = GetNumaricInputVector();
	bool numericInputRange = ((selectedButtonID >= 0 && selectedButtonID <= 3) &&
								(selectedButtonID >= 5 && selectedButtonID <= 8) &&
									(selectedButtonID >= 10 && selectedButtonID <= 11));
	//Sets font for outputWindow
	outputWindow->SetFont(textBoxFont);
	//checks if operation has been answered
	if (operationAnswered) {
		processor.ClearOperator(outputWindow, numaricInputs);
		operationAnswered = false;
		return;
	}
	
	//enables all operations that have been disabled from using them.
	for (int i = 0; i < fieldWidth * fieldLength; i++) {
		button[i]->Enable();
	}
	
	//checks if sytax errors have occured and resets for input
	if (syntaxErrorOccurred) {
		processor.ClearOperator(outputWindow, numaricInputs);
		syntaxErrorOccurred = false;
		return;
	}
		
	

	if (!outputWindow->IsEmpty() && currentOperator != Null) {
		
			previousOperator = currentOperator;
			currentOperator = Null;
			outputWindow->Clear();
		
	}
	
	switch (selectedButtonID)
	{
		//Writing to outputwindow button 1-4.
	case 0:
	case 1:
	case 2:
	case 3:
		//Writing to outputwindow button 5-8.
	case 5:
	case 6:
	case 7:
	case 8:
	case 10:
	case 11:
		//Writing to outputwindow button 9, 0.
		writeTextForButtonSelected(selectedButtonID); //Number 8 button
		break;
		}
	
	
	//Handels Operation event cases.
	switch (selectedButtonID)
	{
	//Operation + button
	case 4:
		try
		{
			processor.ConverStringToFloat(outputWindow);
		}
		catch (const std::exception&)
		{
			outputWindow->Clear();
			outputWindow->AppendText("SYNTAX ERROR");
			syntaxErrorOccurred = true;
			break;
		}
		numaricInputs->push_back(processor.ConverStringToFloat(outputWindow));  
		button[selectedButtonID]->Disable();
		currentOperator = Addition;

		break;
	//Operation - button
	case 9:
		try 
		{
			processor.ConverStringToFloat(outputWindow);
		}
		catch (const std::exception&)
		{
			outputWindow->Clear();
			outputWindow->AppendText("SYNTAX ERROR");
			syntaxErrorOccurred = true;
			break;
		}
		numaricInputs->push_back(processor.ConverStringToFloat(outputWindow));  
		button[selectedButtonID]->Disable();
		currentOperator = Subtraction;
		break;
	//Operation = button
	case 12:
		operationAnswered = processor.EqualsOperator(outputWindow, numaricInputs, processor);
		break;
	//Operation Clear button
	case 13:
		processor.ClearOperator(outputWindow, numaricInputs);
		break;
	//Operation / button
	case 14:
		try
		{
			processor.ConverStringToFloat(outputWindow);
		}
		catch (const std::exception&)
		{
			outputWindow->Clear();
			outputWindow->AppendText("SYNTAX ERROR");
			syntaxErrorOccurred = true;
			break;
		}
		numaricInputs->push_back(processor.ConverStringToFloat(outputWindow)); 
		button[selectedButtonID]->Disable();
		currentOperator = Division;
		break;
	//Convert to Dec button
	case 15:
		writeTextForButtonSelected(selectedButtonID); 
		break;
	//Convert to Bin button
	case 16:
		writeTextForButtonSelected(selectedButtonID); 
		break;
	//Convert to Hex button
	case 17:
		writeTextForButtonSelected(selectedButtonID); 
		break;
	//Operation % button
	case 18:
		try
		{
			processor.ConverStringToFloat(outputWindow);
		}
		catch (const std::exception&)
		{
			outputWindow->Clear();
			outputWindow->AppendText("SYNTAX ERROR");
			syntaxErrorOccurred = true;
			break;
		}
		numaricInputs->push_back(processor.ConverStringToFloat(outputWindow)); 
		button[selectedButtonID]->Disable();
		currentOperator = Modulus;
		break;
	//Operation * button
	case 19:
		try
		{
			processor.ConverStringToFloat(outputWindow);
		}
		catch (const std::exception&)
		{
			outputWindow->Clear();
			outputWindow->AppendText("SYNTAX ERROR");
			syntaxErrorOccurred = true;
			break;
		}
		numaricInputs->push_back(processor.ConverStringToFloat(outputWindow)); 
		button[selectedButtonID]->Disable();
		currentOperator = Multiplication;
		break;
	default:
		break;
	}

	if (numaricInputs->size() == 2 && previousOperator != Null) {
		
		float input1 = numaricInputs->at(0);
		float input2 = numaricInputs->at(1);


		switch (previousOperator)
		{
		case Addition:
			currentValue = processor.AddtionOperator(input1, input2);
			break;
		case Subtraction:
			currentValue = processor.SubtractionOperator(input1, input2);
			break;
		case Multiplication:
			currentValue = processor.MultiplicationOperator(input1, input2);
			break;
		case Division:
			currentValue = processor.DivisionOperator(input1, input2);
			break;
		case Modulus:
			currentValue = processor.ModulusOperator((int)input1, (int)input2);
			break;
		default:
			break;
		}
		while (numaricInputs->size() != 0) {
			numaricInputs->pop_back();
		}

		outputWindow->Clear();
		outputWindow->AppendText(to_string(currentValue));
		numaricInputs->push_back(currentValue);
		previousOperator = Null;
	}

	
	
}

//Writes text to output windown depending on selected button.
void MainWindow::writeTextForButtonSelected(int buttonID) {

	outputWindow->AppendText(operationLabels[buttonID]);

}
void MainWindow::SetOutputWindowToZero(wxTextCtrl* outputWindow) {

	outputWindow->Clear();
	outputWindow->AppendText("0");
}




MainWindow::~MainWindow() {delete numaricInputs; }

