#include "Calculator_Processor.h"

Calculator_Processor& Calculator_Processor::GetInstance() {

	if (calcProcessor == nullptr)
		calcProcessor = new Calculator_Processor;

	return *calcProcessor;

}

Calculator_Processor* Calculator_Processor::calcProcessor = nullptr;
float Calculator_Processor::ConverStringToFloat(wxTextCtrl* outputWindow) {

	string input = outputWindow->GetValue().ToStdString();
	float value = stof(input);

	return value;
}

float Calculator_Processor::AddtionOperator(float inputOne, float inputTwo) {

	return (inputOne + inputTwo);
}
float Calculator_Processor::SubtractionOperator(float inputOne, float inputTwo) {

	return (inputOne - inputTwo);
}
float Calculator_Processor::DivisionOperator(float inputOne, float inputTwo) {

	return inputOne / inputTwo;
}
float Calculator_Processor::MultiplicationOperator(float inputOne, float inputTwo) {

	return inputOne * inputTwo;
}
float Calculator_Processor::ModulusOperator(int inputOne, int inputTwo) {

	return inputOne % inputTwo;

}
void Calculator_Processor::ClearOperator(wxTextCtrl* outputWindow, vector<float>* numaricInputs) {
	outputWindow->Clear();
	while (numaricInputs->size() != 0)
	{
		numaricInputs->pop_back();
	}

}
bool Calculator_Processor::EqualsOperator(wxTextCtrl* outputWindow, vector<float>* numaricInputs, Calculator_Processor& processor) {
	numaricInputs->push_back(processor.ConverStringToFloat(outputWindow));
	outputWindow->Clear();
	return true;
}
bool Calculator_Processor::HexConverstion(wxTextCtrl* outputWindow) {
	vector<int> hexValues;
	string input = outputWindow->GetValue().ToStdString();
	int value = stoi(input);
	while (value != 0) {
		hexValues.push_back(value % 16);
		value = value / 16;
	}

	outputWindow->Clear();
	outputWindow->AppendText("0x");
		for (size_t i = 0; i < hexValues.size(); i++)
		{
			switch (hexValues[i]) {
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				outputWindow->AppendText(to_string(hexValues[i]));
				break;
			case 10:
				outputWindow->AppendText("A");
				break;
			case 11:
				outputWindow->AppendText("B");
				break;
			case 12:
				outputWindow->AppendText("C");
				break;
			case 13:
				outputWindow->AppendText("D");
				break;
			case 14:
				outputWindow->AppendText("E");
				break;
			case 15:
				outputWindow->AppendText("F");
				break;
			}

		}

		return true;
}