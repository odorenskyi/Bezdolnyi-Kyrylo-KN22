#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

#include "ModulesPaschenko.h"
#include "ModulesBezdolnyi.h"
#include "ModulesShchychenko.h"

int main()
{
    system("chcp 1251");
    system("cls");

    std::vector<BusSchedule> schedule = getDataFromFile();

    while(true)
    {

        cout << "=====================================================================================================" << endl
            << "| Знайти запис у розкладі рухів автобусів за введеною назвою початкової або кінцевої автостанції [1]" << endl
            << "| Вивести всі розклади рухів автобусів [2]" << endl
            << "| Додавання нового рейса до розкладу [3]" << endl
            << "| Вилучення рейса з розкладу за його номером [4]" << endl
            << "| Збереження розкладу рухів автобусів в файл і завершення роботи програми [5]" << endl
            << "=====================================================================================================" << endl << endl;

        char userChoice;
        cout << "Введіть номер потрібної функції: ";
        cin >> userChoice;

        switch(userChoice)
        {
            case '1':
                getRecordUseBusStation(schedule);
                continue;
            case '2':
                getAllInfo(schedule);
                continue;
            case '3':
                addNewBusRoute(schedule);
                continue;
            case '4':
                deleteBusRoute(schedule);
                continue;
            case '5':
                saveDataInFile(schedule);
                system("pause");
                return 0;
            default:
                cout << endl << "--- Помилка: Функції з таким номером не існує ---" << endl << endl;
        }
    }
}
