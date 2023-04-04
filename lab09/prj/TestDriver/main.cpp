#include <iostream>
#include "ModulesBezdolny.h"

using namespace std;

void test_bofort() {
    string expected_res[5] = {
        "Бал Бофорта: 7. Хитаються невеликi стовбури де рев. На морi здiймаються хвилi, пiняться.",
        "Бал Бофорта: 1. Дим «пливе». Флюгер не обертаеться.",
        "Бал Бофорта: 0. Вiдсутнiсть вiтру. Дим пiднiмаеться прямовисно. Листя дерев нерухомi.",
        "Бал Бофорта: 0. Вiдсутнiсть вiтру. Дим пiднiмаеться прямовисно. Листя дерев нерухомi.",
        "Бал Бофорта: 12. Призводить до спустошень"
    };
    float wind_power[5] = {14.1, 0.6, 0.0, -1.0, 100.0};

    cout << "Bafort ball test:" << endl;

    for (short int i = 0; i < 5; i++) {
        if (bofort(wind_power[i]) == expected_res[i]) cout << "Test #" << i <<": PASSED\n";
        else cout << "Test #" << i << ": FAILED" << endl;
    }
}

void test_temperature() {
    int days = 31;
    double possibleresult[5][2] = {
            {2.5, 36.5},
            {1, 33.8},
            {-2.5, 27.5},
            {0, 32},
            {-2, 28.4}
        };
    double temp_C[5][days] = {
        { -5.0, -4.5, -4.0, -3.5, -3.0, -2.5, -2.0, -1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5, 6.0, 6.5, 7.0, 7.5, 8.0, 8.5, 9.0, 9.5, 10.0},
        { -6.5, -6.0, -5.5, -5.0, -4.5, -4.0, -3.5, -3.0, -2.5, -2.0, -1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5, 6.0, 6.5, 7.0, 7.5, 8.0, 8.5},
        { -10.0, -9.5, -9.0, -8.5, -8.0, -7.5, -7.0, -6.5, -6.0, -5.5, -5.0, -4.5, -4.0, -3.5, -3.0, -2.5, -2.0, -1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0},
        { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        { 5.5, 5.0, 4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.5, 0.0, -0.5, -1.0, -1.5, -2.0, -2.5, -3.0, -3.5, -4.0, -4.5, -5.0, -5.5, -6.0, -6.5, -7.0, -7.5, -8.0, -8.5, -9.0, -9.5}
    };

    cout << endl << "Temperature function test:" << endl;
    for (short int i = 0; i < 5; i++) {
        double average_temp_C = average_temperature_C(temp_C[i], days);
        double average_temp_F = celsius_to_fahrenheit(average_temp_C);
        if (average_temp_C == possibleresult[i][0] && average_temp_F == possibleresult[i][1]) cout << "Test #" << i <<": PASSED\n";
        else cout << "Test #" << i << ": FAILED" << endl;
    }
}

void test_binary_count() {
    string possibleresult[5] = {
        "Zeros count: 19",
        "Zeros count: 21",
        "Ones count: 10",
        "Ones count: 5",
        "Ones count: 4"
        };

    unsigned int nums[5] = {655304,500403,40378,1688,3264};
    cout << endl << "Binary function test:" << endl;

    for (short int i = 0; i < 5; i++) {
        if (binary_count(nums[i]) == possibleresult[i]) cout << "Test #" << i + 1 << ": PASSED" << endl;
        else cout << "Test #" << i + 1 << ": FAILED" << endl;
    }
}

int main() {
    test_bofort();
    test_temperature();
    test_binary_count();
}
