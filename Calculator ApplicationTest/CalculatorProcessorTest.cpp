#include "CalculatorProcessorTest.h"
CalculatorProcessorTestMethods::CalculatorProcessorTestMethods() {}
void CalculatorProcessorTestMethods::CalculatorProcessorTestAddition(float input1, float input2, float expectedResult) {

	if (testProcessor.AddtionOperator(input1, input2) == expectedResult) {
		cout << "Passed";
	}
	else {
		cout << "Failed";
	}

}
void CalculatorProcessorTestMethods::CalculatorProcessorTestSubtraction(float input1, float input2, float expectedResult) {
	if (testProcessor.SubtractionOperator(input1, input2) == expectedResult) {
		cout << "Passed";
	}
	else {
		cout << "Failed";
	}
};
void CalculatorProcessorTestMethods::CalculatorProcessorTestDivision(float input1, float input2, float expectedResult) {
	if (testProcessor.DivisionOperator(input1, input2) == expectedResult) {
		cout << "Passed";
	}
	else {
		cout << "Failed";
	}
};
void CalculatorProcessorTestMethods::CalculatorProcessorTestMultiplication(float input1, float input2, float expectedResult) {
	if (testProcessor.MultiplicationOperator(input1, input2) == expectedResult) {
		cout << "Passed";
	}
	else {
		cout << "Failed";
	}
};
void CalculatorProcessorTestMethods::CalculatorProcessorTestModulus(float input1, float input2, float expectedResult) {
	if (testProcessor.ModulusOperator(input1, input2) == expectedResult) {
		cout << "Passed";
	}
	else {
		cout << "Failed";
	}
};
void CalculatorProcessorTestMethods::CalculatorProcessorTestHexConversion(wxTextCtrl* input, int numberToConvert, string expectedResult) {

	testProcessor.HexConverstion(input, numberToConvert);

	if (input->GetValue().ToStdString() == expectedResult) {
		cout << "Passed";
	}
	else {
		cout << "Failed";
	}
	

};
void CalculatorProcessorTestMethods::CalculatorProcessorTestBinConversion(wxTextCtrl* input, int numberToConvert, string expectedResult) {
	testProcessor.BinaryConversion(input, numberToConvert);

	if (input->GetValue().ToStdString() == expectedResult) {
		cout << "Passed";
	}
	else {
		cout << "Failed";
	}
};
void CalculatorProcessorTestMethods::CalculatorProcessorTestDecConversion(wxTextCtrl* input, int expectedResult) {
	

	if (testProcessor.DecimalCoversion(input) == expectedResult) {
		cout << "Passed";
	}
	else {
		cout << "Failed";
	}
};
