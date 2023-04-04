#include <cmath>
#include <iostream>
#include <bitset>
#include <sstream>

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
