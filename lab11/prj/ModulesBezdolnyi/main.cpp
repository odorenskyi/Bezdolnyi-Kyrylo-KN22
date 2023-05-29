#include <iostream>
#include <vector>
#include <cctype>
#include <fstream>
#include <cmath>
#include <bitset>
#include <sstream>
#include <cstring>
#include <ctime>

#include <struct_type_project_6.h>


using namespace std;

const double e = exp(1.0);
float s_calculation(float x, float y, float z){
    return 0.5*((pow(y,2)+2*z)/sqrt(7*M_PI+x))-sqrt(pow(e,abs(x))+(sqrt(abs(y-z)))/sin(z*y));
}

string bofort(float wind) {
    if (wind<0.3) return "��� �������: 0. �i�����i��� �i���. ��� �i��i������� ����������. ����� ����� �������i.";
    else if (wind<1.5) return "��� �������: 1. ��� ������. ������ �� �����������.";
    else if (wind<3.4) return "��� �������: 2. ��� ���i��� �i���������� ��������. ��������� �����. ������� ���������� �������.";
    else if (wind<5.4) return "��� �������: 3. ��i���� �����, ��������� ��i��i �i���. �������� �������.";
    else if (wind<7.9) return "��� �������: 4. ��������� ����i �i��� �� ���. �i��� �i��i��� ��� �� ������ ������.";
    else if (wind<10.7) return "��� �������: 5. ��������� �����i �i���. �� ���i �'��������� ����i.";
    else if (wind<13.8) return "��� �������: 6. ��������� �����i �i���";
    else if (wind<17.1) return "��� �������: 7. ��������� �������i �������� �� ���. �� ���i ��i�������� ����i, �i������.";
    else if (wind<20.7) return "��� �������: 8. ��������� �i��� ���� �. i ����� ��� ����� �i���.";
    else if (wind<24.4) return "��� �������: 9. �������i ����������. ������ ����i��i, ������ �����i.";
    else if (wind<28.4) return "��� �������: 10. �����i ����������. ������ ����������� � ���i����";
    else if (wind<32.6) return "��� �������: 11. �����i ����������";
    else return "��� �������: 12. ���������� �� ����������";
}

double celsius_to_fahrenheit(double temp_C) {
    return (temp_C * 9 / 5) + 32;
}

double average_temperature_C(const double temp_C[], int days) {
    double sum = 0;
    for (int i = 0; i < days; i++) {
        sum += temp_C[i];
    }
    return sum / days;
}

string binary_count(unsigned int iNumber) {
    const unsigned int maxNumber = 10008000;
    stringstream resultStr;
    if(iNumber > maxNumber) {
        resultStr << "Your number is more than " << maxNumber << " or less than zero!";
        return resultStr.str();
    }
    bitset<32> bNumber(iNumber);
    size_t ones = bNumber.count();
    size_t zeros = bNumber.size() - ones;

    if(bNumber.test(13)) resultStr << "Zeros count: " << zeros;
    else resultStr << "Ones count: " << ones;
    return resultStr.str();
}


void abilityToEdit(string outputFileName, string inputFileName)
{
    ofstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile || !outputFile) {
		cout << "��������� ������� ���� ��� �����������\a" << endl;
        inputFile.close();
        outputFile.close();
		exit(1);
	}
	inputFile.close();
	outputFile.close();
}

bool fillInputTxtFile(string inputFileName, string ukrWord)
{
    ofstream inputFile(inputFileName, ios::out);
	inputFile << ukrWord << endl << endl;
	inputFile.close();
	return true;
}

bool authorInfo(string outputFileName)
{
    ofstream outputFile(outputFileName, ios::out);
	outputFile << "====================================================================" << endl
               << " ����������:         ���������� ������ �������������" << endl
               << " г� ��������:       2023" << endl
               << " ̳���/�����:       �������������/������" << endl
               << " ���:                ����������� ������������ �������� ����������" << endl
               << "====================================================================" << endl << endl;
    outputFile.close();
    return true;
}

int vowelsCountInFile(string outputFileName, string ukrWord)
{
    ofstream outputFile(outputFileName, ios::app);
    string vowels[10] = { "�", "�", "�", "�", "�", "�", "�", "�", "�", "�" };
    int vowelsCount = 0;
    size_t foundVowel;

    for (int i = 0; i < 10; i++) {
        foundVowel = ukrWord.find(vowels[i]);
        if (foundVowel != string::npos) {
            vowelsCount++;
        }
    }
    outputFile << "ʳ������ �������� ���� � �������� �����: " << vowelsCount << endl << endl;
    outputFile.close();
    return vowelsCount;
}

bool findWordInPoem(string outputFileName, string ukrWord)
{
    ofstream outputFile(outputFileName, ios::app);
    string poemVI = { "�� ����� �� ����� ������ �����.\n"
                      "� ��� ���� - ���� �� ��� �� �����.\n"
                      "��������� ������ ������ ����� ������\n"
                      "�������� ������� ��������� �����\n" };
    size_t foundWord;

    foundWord = poemVI.find(ukrWord);
    if (foundWord != string::npos) {
        outputFile << "�������� ����� \"" << ukrWord << "\"" << endl << endl;
        outputFile.close();
        return true;
    }
    outputFile << "C���� \"" << ukrWord << "\" - �� ��������" << endl << endl;
    outputFile.close();
    return false;
}

int consonantsCountInFile(string inputFileName, string ukrWord)
{
    ofstream inputTxtFile(inputFileName, ios::app);
    string vowels[10] = { "�", "�", "�", "�", "�", "�", "�", "�", "�", "�" };
    size_t foundConsonants;

    for (int i = 0; i < 10; i++) {
        foundConsonants = ukrWord.find(vowels[i]);
        if (foundConsonants != string::npos) {
            ukrWord.erase(foundConsonants, vowels[i].length());
        }
    }
    inputTxtFile << "ʳ������ ����������� ���� � �������� �����: " << ukrWord.length() / 2 << endl << endl;
    inputTxtFile.close();
    return ukrWord.length() / 2;
}

bool timestampInFile(string inputFileName)
{
    ofstream inputFile(inputFileName, ios::app);
    time_t rawtime;
    time(&rawtime);
    inputFile << "���� �� ��� �������� �����������: " << ctime(&rawtime) << endl << endl;
    inputFile.close();
    return true;
}

double sCalculationResInFile(string outputFileName, float x, float y, float z)
{
    ofstream outputFile("prjOutputFile.txt", ios::app);
    outputFile << "��������� ��������� s_calculation: " << s_calculation(x, y, z) << endl << endl;
    outputFile.close();
    return s_calculation(x, y, z);
}

bool decimalToBinary(string outputFileName, unsigned int number)
{
    if (number <= 0) {
        return false;
    }
    ofstream outputFile(outputFileName, ios::app);
    int binaryCels[32];
    int i;
    unsigned int convertedNum = number;

    for(i = 0; convertedNum > 0; i++) {
        binaryCels[i] = convertedNum % 2;
        convertedNum = convertedNum / 2;
    }
    outputFile << "������� ������������� ����� " << number << " : ";
    for(i = i - 1; i >= 0; i--) {
        outputFile << binaryCels[i];
    }
    outputFile << endl << endl;
    outputFile.close();
    return true;
}

vector<string> splitRoute(string str)
{
    vector<string> arr;
    string delim("-");
    size_t prev = 0;
    size_t next;
    size_t delta = delim.length();

    while( ( next = str.find( delim, prev ) ) != string::npos ){
        string tmp = str.substr( prev, next-prev );
        arr.push_back( str.substr( prev, next-prev ) );
        prev = next + delta;
    }
    string tmp = str.substr( prev );
    arr.push_back( str.substr( prev ) );

    return arr;
}

void outputRecord(int busRouteNumber, string busRoute, string busPeriodicity, string busDepartureTime, string busArrivalTime, string busDepartureTimeStartingStation, string busArrivalTimeFinalStation)
{
    cout << "| ����� �����: " << busRouteNumber << endl
        << "| �������: " << busRoute << endl
        << "| �����������: " << busPeriodicity << endl
        << "| ��� �����������: " << busDepartureTime << endl
        << "| ��� ��������: " << busArrivalTime << endl
        << "| ��� ����������� � ��������� �������: " << busDepartureTimeStartingStation << endl
        << "| ��� �������� �� ������ �������: " << busArrivalTimeFinalStation << endl << endl;
}

void getRecordUseBusStation(vector<BusSchedule>& schedule)
{
    cout << endl << ">>> ������ ����� ��������� ��� ������ �������: ";

    string sfStation;
    cin >> sfStation;
    string sfStationLower;

    for (char& c : sfStation)
    {
        sfStationLower += tolower(c);
    }

    bool stationFound = false;

    for(const auto& bus : schedule)
    {
        vector<string> splitText = splitRoute(bus.busRoute);

        string splitTextLower0;
        for (char& c : splitText[0])
        {
            splitTextLower0 += tolower(c);
        }
        string splitTextLower1;
        for (char& c : splitText[1])
        {
            splitTextLower1 += tolower(c);
        }

        if(sfStation == splitText[0] || sfStationLower == splitTextLower0 || sfStation == splitText[1] || sfStationLower == splitTextLower1)
        {
            outputRecord(bus.busRouteNumber, bus.busRoute, bus.busPeriodicity, bus.busDepartureTime, bus.busArrivalTime, bus.busDepartureTimeStartingStation, bus.busArrivalTimeFinalStation);
            stationFound = true;
        }
    }

    if(stationFound == false)
    {
        cout << endl << "--- �������: ������ ����� ������� ��� ������ ������� ---" << endl << endl;
        return;
    }
}

void getAllInfo(vector<BusSchedule>& schedule)
{
    for(const auto& bus : schedule)
    {
        cout << "| ����� �����: " << bus.busRouteNumber << endl
        << "| �������: " << bus.busRoute << endl
        << "| �����������: " << bus.busPeriodicity << endl
        << "| ��� �����������: " << bus.busDepartureTime << endl
        << "| ��� ��������: " << bus.busArrivalTime << endl
        << "| ��� ����������� � ��������� �������: " << bus.busDepartureTimeStartingStation << endl
        << "| ��� �������� �� ������ �������: " << bus.busArrivalTimeFinalStation << endl << endl;
    }
}
