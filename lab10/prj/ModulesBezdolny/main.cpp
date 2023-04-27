#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>
#include <sstream>
#include <cstring>
#include <ctime>

using namespace std;

const double e = exp(1.0);
float s_calculation(float x, float y, float z){
    return 0.5*((pow(y,2)+2*z)/sqrt(7*M_PI+x))-sqrt(pow(e,abs(x))+(sqrt(abs(y-z)))/sin(z*y));
}

string bofort(float wind) {
    if (wind<0.3) return "Бал Бофорта: 0. Вiдсутнiсть вiтру. Дим пiднiмаеться прямовисно. Листя дерев нерухомi.";
    else if (wind<1.5) return "Бал Бофорта: 1. Дим «пливе». Флюгер не обертаеться.";
    else if (wind<3.4) return "Бал Бофорта: 2. Рух повiтря вiдчуваеться обличчям. Шелестить листя. Флюгеро обертається спокійно.";
    else if (wind<5.4) return "Бал Бофорта: 3. Трiпоче листя, хитаються дрiбнi гiлки. Майорять прапори.";
    else if (wind<7.9) return "Бал Бофорта: 4. Хитаються тонкi гiлки де рев. Вiтер пiднiмае пил та шматки паперу.";
    else if (wind<10.7) return "Бал Бофорта: 5. Хитаються великi гiлки. На водi з'являються хвилi.";
    else if (wind<13.8) return "Бал Бофорта: 6. Хитаються великi гiлки";
    else if (wind<17.1) return "Бал Бофорта: 7. Хитаються невеликi стовбури де рев. На морi здiймаються хвилi, пiняться.";
    else if (wind<20.7) return "Бал Бофорта: 8. Ламаються гiлки дере в. i важко йти проти вiтру.";
    else if (wind<24.4) return "Бал Бофорта: 9. Невеликi руйнування. Зривае покрiвлi, руйнуе димарi.";
    else if (wind<28.4) return "Бал Бофорта: 10. Значнi руйнування. Дерева вириваються з корiнням";
    else if (wind<32.6) return "Бал Бофорта: 11. Великi руйнування";
    else return "Бал Бофорта: 12. Призводить до спустошень";
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
		cout << "Неможливо відкрити файл для редагування\a" << endl;
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
               << " Виконавець:         Бездольний Кирило Олександрович" << endl
               << " Рік розробки:       2023" << endl
               << " Місто/Країна:       Кропивницький/Україна" << endl
               << " ВНЗ:                Центральний Національний Технічний Університет" << endl
               << "====================================================================" << endl << endl;
    outputFile.close();
    return true;
}

int vowelsCountInFile(string outputFileName, string ukrWord)
{
    ofstream outputFile(outputFileName, ios::app);
    string vowels[10] = { "а", "е", "є", "и", "і", "ї", "о", "у", "ю", "я" };
    int vowelsCount = 0;
    size_t foundVowel;

    for (int i = 0; i < 10; i++) {
        foundVowel = ukrWord.find(vowels[i]);
        if (foundVowel != string::npos) {
            vowelsCount++;
        }
    }
    outputFile << "Кількість голосних літер з вхідного файлу: " << vowelsCount << endl << endl;
    outputFile.close();
    return vowelsCount;
}

bool findWordInPoem(string outputFileName, string ukrWord)
{
    ofstream outputFile(outputFileName, ios::app);
    string poemVI = { "до щастя не пускає лінощів орава.\n"
                      "у чім воно - ніхто не знає до пуття.\n"
                      "навчитись радісно робити кожну справу\n"
                      "найперше правило щасливого життя\n" };
    size_t foundWord;

    foundWord = poemVI.find(ukrWord);
    if (foundWord != string::npos) {
        outputFile << "Знайдено слово \"" << ukrWord << "\"" << endl << endl;
        outputFile.close();
        return true;
    }
    outputFile << "Cлово \"" << ukrWord << "\" - не знайдено" << endl << endl;
    outputFile.close();
    return false;
}

int consonantsCountInFile(string inputFileName, string ukrWord)
{
    ofstream inputTxtFile(inputFileName, ios::app);
    string vowels[10] = { "а", "е", "є", "и", "і", "ї", "о", "у", "ю", "я" };
    size_t foundConsonants;

    for (int i = 0; i < 10; i++) {
        foundConsonants = ukrWord.find(vowels[i]);
        if (foundConsonants != string::npos) {
            ukrWord.erase(foundConsonants, vowels[i].length());
        }
    }
    inputTxtFile << "Кількість приголосних літер з вхідного файлу: " << ukrWord.length() / 2 << endl << endl;
    inputTxtFile.close();
    return ukrWord.length() / 2;
}

bool timestampInFile(string inputFileName)
{
    ofstream inputFile(inputFileName, ios::app);
    time_t rawtime;
    time(&rawtime);
    inputFile << "Дата та час дозапису інформаціїї: " << ctime(&rawtime) << endl << endl;
    inputFile.close();
    return true;
}

double sCalculationResInFile(string outputFileName, float x, float y, float z)
{
    ofstream outputFile("prjOutputFile.txt", ios::app);
    outputFile << "Результат виконання s_calculation: " << s_calculation(x, y, z) << endl << endl;
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
    outputFile << "Двійкове представлення числа " << number << " : ";
    for(i = i - 1; i >= 0; i--) {
        outputFile << binaryCels[i];
    }
    outputFile << endl << endl;
    outputFile.close();
    return true;
}
