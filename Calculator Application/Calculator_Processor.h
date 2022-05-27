#pragma once
#include"wx/wx.h"
#include <string>
using namespace std;

class Calculator_Processor
{
private:

	Calculator_Processor() {};
	static Calculator_Processor* calcProcessor;

public:

	Calculator_Processor(const Calculator_Processor& other) = delete;
	Calculator_Processor& operator=(Calculator_Processor& other) = delete;

	static Calculator_Processor& GetInstance();

	float ConverStringToFloat(wxTextCtrl* outputWindow);
	
	float AddtionOperator(float inputOne, float inputTwo);
	float SubtractionOperator(float inputOne, float inputtTwo);
	float DivisionOperator(float inputOne, float inputTwo);
	float MultiplicationOperator(float inputOne, float inputTwo);
	float ModulusOperator(int inputOne, int inputTwo);
};

