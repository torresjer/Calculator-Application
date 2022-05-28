#include "Calculator_Processor.h"
#include <bitset>

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
void Calculator_Processor::EqualsOperator(wxTextCtrl* outputWindow, vector<float>* numaricInputs, Calculator_Processor& processor, bool operationAnswered) {
	float answer = processor.ConverStringToFloat(outputWindow);
	numaricInputs->push_back(answer);
	outputWindow->Clear();
	operationAnswered = true;
	return;
}
void Calculator_Processor::HexConverstion(wxTextCtrl* outputWindow, int converstionValue) {
	vector<int> hexValues;
	int value = converstionValue;
	while (value != 0) {
		hexValues.push_back(value % 16);
		value = value / 16;
	}

	outputWindow->Clear();
	outputWindow->AppendText("0x");
	for (int i = hexValues.size() - 1; i >= 0; i--)
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

}
void Calculator_Processor::BinaryConversion(wxTextCtrl* outputWindow, int converstionValue) {
	
	int value = converstionValue;
	outputWindow->Clear();

	//Binary Conversion
	outputWindow->AppendText(bitset<16>(value).to_string());
}
int Calculator_Processor::DecimalCoversion(wxTextCtrl* outputWindow) {
	string input = outputWindow->GetValue().ToStdString();
	int conversionValue = 0;

	if (input[0] == '0' && input[1] == 'x') {
		int base = 1;
		for (int i = input.length(); i > 1; i--) {
			if (input[i] >= '0' && input[i] <= '9') {
				conversionValue += (int(input[i]) - 48) * base;

				base = base * 16;
			}
			else if (input[i] >= 'A' && input[i] <= 'F') {
				conversionValue += (int(input[i]) - 55) * base;
				base = base * 16;
			}
		}
		outputWindow->Clear();
		outputWindow->AppendText(to_string(conversionValue));
		return conversionValue;

	}

	if (input.length() == 16) {
		int base = 1;
		for (int i = input.length() - 1; i >= 0; i--) {
			if (input[i] == '1')
				conversionValue += base;
			base = base * 2;
		}

		outputWindow->Clear();
		outputWindow->AppendText(to_string(conversionValue));
		return conversionValue;
	}

	return stoi(input);
}