#include "schedule.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

unordered_map<string, vector<string>> trainToTowns;
unordered_map<string, unordered_set<string>> townToTrains;

Type parseType(const string& cmd) {
    if (cmd == "CREATE_TRAIN") return Type::CREATE_TRAIN;
    if (cmd == "TRAINS_FOR_TOWN") return Type::TRAINS_FOR_TOWN;
    if (cmd == "TOWNS_FOR_TRAIN") return Type::TOWNS_FOR_TRAIN;
    if (cmd == "TRAINS") return Type::TRAINS;
    return Type::UNKNOWN;
}

void createTrain(const string& name, const vector<string>& towns){
    if (trainToTowns.count(name)){
        cout << "Поезд уже существует" << endl;
        return;
    }

    if(towns.size() == 1){
        cout << "Поезд должен иметь минимум 2 остановки" << endl;
        return;
    }

    for(int i = 1; i < towns.size(); i++){
        if (towns[i-1] == towns[i]){
            cout << "У поезда не может быть 2 одинаковые остановки" << endl;
            return;
        }
    }


    trainToTowns[name] = towns;

    for(const auto& town : towns){
        townToTrains[town].insert(name);
    }
    
    cout << "Поезд " << name << " создан" << endl;
}

void trainsForTown(const string& town) {
    if(!townToTrains.count(town)){
        cout << "Нет таких поездов" << endl;
        return;
    }

    for(const auto& train : townToTrains[town]){
        cout << train << " ";
    }
    
    cout << "\n";
}

void townsForTrain(const string& train){
    if(!trainToTowns.count(train)){
        cout << "Нет такого поезда" << endl;
        return;
    }

    for(const auto& town : trainToTowns[train]){
        cout << town << ": ";

        if(townToTrains.count(town)){
            for(const auto& qurentTrain : townToTrains[town]){
                if (qurentTrain != train){
                    cout << qurentTrain << " ";
                }
            }
        }
        cout << "\n";
    }
}

void printAllTrains(){
    for (const auto& [train, towns] : trainToTowns){
        cout << train << ": ";
        for(const auto& town : towns){
            cout << town << " ";

        }
        cout << "\n";
    }
}