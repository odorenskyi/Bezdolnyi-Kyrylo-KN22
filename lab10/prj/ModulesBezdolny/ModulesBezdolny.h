#ifndef MODULESBEZDOLNY_H_INCLUDED
#define MODULESBEZDOLNY_H_INCLUDED

using namespace std;

float s_calculation(float x, float y, float z);
string bofort(float wind);
double celsius_to_fahrenheit(double temp_C);
double average_temperature_C(const double temp_C[], int days);
string binary_count(unsigned int iNumber);

void abilityToEdit(string outputFileName, string inputFileName);
bool fillInputTxtFile(string inputFileName, string ukrWord);
bool authorInfo(string outputFileName);
int vowelsCountInFile(string outputFileName, string ukrWord);
bool findWordInPoem(string outputFileName, string ukrWord);
int consonantsCountInFile(string inputFileName, string ukrWord);
bool timestampInFile(string inputFileName);
double sCalculationResInFile(string outputFileName, float x, float y, float z);
bool decimalToBinary(string outputFileName, unsigned int number);

#endif // MODULESBEZDOLNY_H_INCLUDED
