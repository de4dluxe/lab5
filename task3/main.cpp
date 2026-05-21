#include "schedule.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    string line;
    cout << ">>> ";
    while (getline(cin, line))
    {
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while(ss >> token){
            tokens.push_back(token);
        }

        if (tokens.empty()) continue;

        Type cmd = parseType(tokens[0]);

        if (cmd == Type::CREATE_TRAIN){
            string name = tokens[1];

            vector<string> towns;
            for(auto i = 3; i < tokens.size(); i++){
                towns.push_back(tokens[i]);
            }

            createTrain(name,towns);
        }

        else if (cmd == Type::TRAINS_FOR_TOWN){
            trainsForTown(tokens[1]);
        }

        else if (cmd == Type::TOWNS_FOR_TRAIN)
        {
            townsForTrain(tokens[1]);
        }

        else if (cmd == Type::TRAINS)
        {
            printAllTrains();
        }
        
        else if (cmd == Type::UNKNOWN)
        {
            cout << "Неизвестная команда" << endl;
        }

        cout << ">>> ";
    }
    return 0;
}