#include <iostream>
#include <windows.h>
#include "ModulesBezdolny.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char input;
    bool exit = false;

    while (!exit) {
        cout << endl << "Введіть символ ('t', 'T' або 'С' для виходу з програми): ";
        cin >> input;
        input = tolower(input);

        switch (input) {
            case '7':
            {
                int x, y, z;
                cout << "Введiть x, y, z: ";
                cin >> x >> y >> z;
                cout << "Result: " << s_calculation(x, y, z) << endl;
                break;
            }
            case '5':
            {
                float wind_power;
                cout << "Enter wind power: ";
                cin >> wind_power;
                cout << bofort(wind_power) << endl;
                break;
            }
            case '4':
            {
                int days;
                cout << "Enter days count: ";
                cin >> days;
                double temp_C[days];
                cout << "Enter temperature for every day(" << days << "): ";
                for(int i = 0; i < days; i++) {
                    cin >> temp_C[i];
                }
                double average_temp_C = average_temperature_C(temp_C, days);
                cout << "Середньомісячна температура у градусах Цельсія: " << average_temp_C << endl;
                cout << "Середньомісячна температура у градусах Фаренгейта: " << celsius_to_fahrenheit(average_temp_C) << endl;
                break;
            }
            case '3':
            {
                unsigned int num;
                cout << "Enter num: ";
                cin >> num;
                cout << binary_count(num) << endl;
                break;
            }
            case 't':
                exit = true;
                break;
            case 'c':
                exit = true;
                break;
            default:
                cout << '\a';
        }
    }
    return 0;
}
