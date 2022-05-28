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
	vector<float>* numericInputs = GetNumericInputVector();
	bool numaricInputRange = ((selectedButtonID >= 0 && selectedButtonID <= 3) ||
								(selectedButtonID >= 5 && selectedButtonID <= 8) ||
									(selectedButtonID >= 10 && selectedButtonID <= 11));
	//Sets font for outputWindow
	outputWindow->SetFont(textBoxFont);
	//checks if operation has been answered
	if((syntaxErrorOccurred)){
		processor.ClearOperator(outputWindow, numericInputs);
		operationAnswered = false;
		syntaxErrorOccurred = false;
		return;
	}
	
	//enables all operations that have been disabled from using them.
	for (int i = 0; i < fieldWidth * fieldLength; i++) {
		button[i]->Enable();
	}
	
	//checks if sytax errors have occured and resets for input
	
	if (!outputWindow->IsEmpty() && currentOperator != Null && numaricInputRange) {


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
		if (currentOperator == Equals) {
			button[selectedButtonID]->Disable();
			currentOperator = Addition;
		}
		else {
			numericInputs->push_back(processor.ConverStringToFloat(outputWindow));
			button[selectedButtonID]->Disable();
			currentOperator = Addition;
		}
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
		if (currentOperator == Equals) {
			button[selectedButtonID]->Disable();
			currentOperator = Subtraction;
		}
		else {
			numericInputs->push_back(processor.ConverStringToFloat(outputWindow));
			button[selectedButtonID]->Disable();
			currentOperator = Subtraction;
		}
		break;
	//Operation = button
	case 12:
		if (numericInputs->empty() || currentOperator == Equals) {
			outputWindow->Clear();
			outputWindow->AppendText("SYNTAX ERROR");
			syntaxErrorOccurred = true;
			return;
		};
		processor.EqualsOperator(outputWindow, numericInputs, processor, operationAnswered);
		currentOperator = Equals;
		break;
	//Operation Clear button
	case 13:
		processor.ClearOperator(outputWindow, numericInputs);
		currentOperator = Clear;
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
		if (currentOperator == Equals) {
			button[selectedButtonID]->Disable();
			currentOperator = Division;
		}
		else {
			numericInputs->push_back(processor.ConverStringToFloat(outputWindow));
			button[selectedButtonID]->Disable();
			currentOperator = Division;
		}
		break;
	//Convert to Dec button
	case 15:
		converstionValue = processor.DecimalCoversion(outputWindow);
		break;
	//Convert to Bin button
	case 16:	
		converstionValue = processor.DecimalCoversion(outputWindow);
		processor.BinaryConversion(outputWindow, converstionValue);
		break;
	//Convert to Hex button
	case 17:
		converstionValue = processor.DecimalCoversion(outputWindow);
		processor.HexConverstion(outputWindow, converstionValue);
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
		if (currentOperator == Equals) {
			button[selectedButtonID]->Disable();
			currentOperator = Modulus;
		}
		else {
			numericInputs->push_back(processor.ConverStringToFloat(outputWindow));
			button[selectedButtonID]->Disable();
			currentOperator = Modulus;
		}
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
		if (currentOperator == Equals) {
			button[selectedButtonID]->Disable();
			currentOperator = Multiplication;
		}
		else {
			numericInputs->push_back(processor.ConverStringToFloat(outputWindow));
			button[selectedButtonID]->Disable();
			currentOperator = Multiplication;
		}
	default:
		break;
	}

	

	if (numericInputs->size() == 2 && previousOperator != Null) {
		
		float input1 = numericInputs->at(0);
		float input2 = numericInputs->at(1);


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
		while (numericInputs->size() != 0) {
			numericInputs->pop_back();
		}

		outputWindow->Clear();
		outputWindow->AppendText(to_string(currentValue));
		numericInputs->push_back(currentValue);
		previousOperator = Null;
		
	}

	if (previousOperator == Equals && numaricInputRange) {
		while (numericInputs->size() != 0) {
			numericInputs->pop_back();
		}
		currentValue = processor.ConverStringToFloat(outputWindow);
		numericInputs->push_back(currentValue);
		currentOperator = Equals;
		
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




MainWindow::~MainWindow() {delete numericInputs; }

