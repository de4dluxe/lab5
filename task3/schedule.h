#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include <string>
#include <map>

using namespace std;

enum class Type {
    CREATE_TRAIN,
    TRAINS_FOR_TOWN,
    TOWNS_FOR_TRAIN,
    TRAINS,
    UNKNOWN
};

Type parseType(const string& cmd);

void createTrain(const string& name, const vector<string>& towns);
void trainsForTown(const string& town);
void townsForTrain(const string& train);
void printAllTrains();
#endif