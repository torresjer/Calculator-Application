#pragma once
#include "../Calculator Application/Calculator_Processor.h"
#include "wx/wx.h"
class CalculatorProcessorTest
{
public:
	

	void CalculatorProcessorTestAddition(float input1, float input2, float expectedResult);
	void CalculatorProcessorTestSubtraction(float input1, float input2, float expectedResult);
	void CalculatorProcessorTestDivision(float input1, float input2, float expectedResult);
	void CalculatorProcessorTestMultiplication(float input1, float input2, float expectedResult);
	void CalculatorProcessorTestModulus(float input1, float input2, float expectedResult);
	void CalculatorProcessorTestHexConversion(wxTextCtrl* input, int numberToConvert, string expectedResult);
	void CalculatorProcessorTestBinConversion(wxTextCtrl* input, int numberToConvert, string expectedResult);
	void CalculatorProcessorTestDecConversion(wxTextCtrl* input, int numberToConvert, int expextedResult);
};

