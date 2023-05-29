#ifndef DATABASESTRUCT_H_INCLUDED
#define DATABASESTRUCT_H_INCLUDED

#include "struct_type_project_6.h"
#include <vector>

using namespace std;

vector<BusSchedule> getDataFromFile();

void saveDataInFile(vector<BusSchedule>& schedule);

#endif // DATABASESTRUCT_H_INCLUDED
