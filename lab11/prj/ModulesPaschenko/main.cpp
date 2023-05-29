#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

#include "struct_type_project_6.h"

using namespace std;

vector<string> split(string str)
{
    vector<string> arr;
    string delim(";");
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

vector<BusSchedule> getDataFromFile()
{
    ifstream f_read("C:\\Users\\User\\Documents\\Pashchenko-Danylo-KN22\\lab11\\prj\\BusSchedule.txt", ios::in);
    if(!f_read.is_open())
    {
        cout << endl << "Помилка відкриття файлу" << endl;
        exit(EXIT_FAILURE);
    }

    vector<BusSchedule> schedule;

    string line;
    while(getline(f_read, line))
    {
        vector<string> splitLine = split(line);

        BusSchedule bus;

        bus.busRouteNumber = stoi(splitLine[0]);
        bus.busRoute = splitLine[1];
        bus.busPeriodicity = splitLine[2];
        bus.busDepartureTime = splitLine[3];
        bus.busArrivalTime = splitLine[4];
        bus.busDepartureTimeStartingStation = splitLine[5];
        bus.busArrivalTimeFinalStation = splitLine[6];

        schedule.push_back(bus);
    }

    f_read.close();

    return schedule;
}

void saveDataInFile(vector<BusSchedule>& schedule)
{
    ofstream f_write("..\\BusSchedule.txt", ios::out);
    if(!f_write.is_open())
    {
        cout << endl << "Помилка відкриття файлу" << endl;
        return;
    }

    for(const auto& bus : schedule)
    {
        f_write << bus.busRouteNumber << ";" << bus.busRoute << ";" << bus.busPeriodicity << ";" << bus.busDepartureTime << ";" << bus.busArrivalTime << ";" << bus.busDepartureTimeStartingStation << ";" << bus.busArrivalTimeFinalStation << endl;
    }

    f_write.close();
}

