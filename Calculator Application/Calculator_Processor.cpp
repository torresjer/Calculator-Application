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
void Calculator_Processor::HexConverstion(wxTextCtrl* outputWindow)