#include <iostream>
#include <vector>
#include <string>
#include "struct_type_project_6.h"

using namespace std;

void addNewBusRoute(vector<BusSchedule>& schedule)
{
    cout << endl << ">>> УВАГА: писати без пробілів (через нижнє підкреслення)" << endl;
    cout << ">>> Введіть номер рейсу: ";
    string busRouteNumber;
    cin >> busRouteNumber;
    cout << ">>> Введіть маршрут: ";
    string busRoute;
    cin >> busRoute;
    cout << ">>> Введіть періодичність (наприклад: щоденно, день або декілька днів): ";
    string busPeriodicity;
    cin >> busPeriodicity;
    cout << ">>> Введіть час відправлення (введіть 0, якщо не задано): ";
    string busDepartureTime;
    cin >> busDepartureTime;
    cout << ">>> Введіть час прибуття (введіть 0, якщо не задано): ";
    string busArrivalTime;
    cin >> busArrivalTime;
    cout << ">>> Введіть час відправлення з початкової станції (введіть 0, якщо не задано): ";
    string busDepartureTimeStartingStation;
    cin >> busDepartureTimeStartingStation;
    cout << ">>> Введіть час прибуття до кінцевої станції (введіть 0, якщо не задано): ";
    string busArrivalTimeFinalStation;
    cin >> busArrivalTimeFinalStation;
    cout << endl;

    BusSchedule bus;

    bus.busRouteNumber = stoi(busRouteNumber);
    bus.busRoute = busRoute;
    bus.busPeriodicity = busPeriodicity;
    bus.busDepartureTime = busDepartureTime;
    bus.busArrivalTime = busArrivalTime;
    bus.busDepartureTimeStartingStation = busDepartureTimeStartingStation;
    bus.busArrivalTimeFinalStation = busArrivalTimeFinalStation;

    schedule.push_back(bus);
}

void deleteBusRoute(vector<BusSchedule>& schedule)
{
    cout << endl << ">>> Введіть номер рейсу: ";

    short int routeNumber;

    cin >> routeNumber;
    if(!routeNumber)
    {
        cout << endl << "--- Помилка: Невірний номер рейсу ---" << endl;
        return;
    }

    for(int i = 0; i < schedule.size(); i++)
    {
        if(routeNumber == schedule[i].busRouteNumber)
        {
            schedule.erase(schedule.begin() + i);
            cout << endl << "--- Готово ---" << endl << endl;
            return;
        }
    }

    cout << endl << "--- Помилка: Рейсу з таким номером не існує ---" << endl << endl;
}
