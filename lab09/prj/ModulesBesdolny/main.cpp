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
