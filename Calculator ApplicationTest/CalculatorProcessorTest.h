#pragma once
#include "../Calculator Application/Calculator_Processor.h"
#include "wx/wx.h"
#include <string>

using namespace std;
class CalculatorProcessorTestMethods
{
public:
	CalculatorProcessorTestMethods();

	Calculator_Processor& test = Calculator_Processor::GetInstance();

	void CalculatorProcessorTestAddition(float input1, float input2, float expectedResult);
	void CalculatorProcessorTestSubtraction(float input1, float input2, float expectedResult);
	void CalculatorProcessorTestDivision(float input1, float input2, float expectedResult);
	void CalculatorProcessorTestMultiplication(float input1, float input2, float expectedResult);
	void CalculatorProcessorTestModulus(float input1, float input2, float expectedResult);
	void CalculatorProcessorTestHexConversion(wxTextCtrl* input, int numberToConvert, string expectedResult);
	void CalculatorProcessorTestBinConversion(wxTextCtrl* input, int numberToConvert, string expectedResult);
	void CalculatorProcessorTestDecConversion(wxTextCtrl* input, int expectedResult);
};

