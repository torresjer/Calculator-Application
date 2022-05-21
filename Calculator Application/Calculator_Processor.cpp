#include "Calculator_Processor.h"

Calculator_Processor::GetInstance() {

}

Calculator_Processor* Calculator_Processor::calcProcessor = nullptr;
float ConverStringToFloat(const string& userInput) {


}

float AddtionOperator(float inputOne, float inputTwo) {

	return inputOne + inputTwo;
}
float SubtractionOperator(float inputOne, float inputTwo) {

	return inputOne - inputTwo;
}
float DivisionOperator(float inputOne, float inputTwo) {

	return inputOne / inputTwo;
}
float MultiplicationOperator(float inputOne, float inputTwo) {

	return inputOne * inputTwo;
}
float ModulusOperator(int inputOne, int inputTwo) {

	return inputOne % inputTwo;

}