#include "friends.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string line;
    int N;
    cout << "Введите количество запросов: " << endl;
    cout << ">>> ";
    cin >> N;
    cout << ">>> ";
    while(getline(cin,line)){
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while(ss >> token){
            tokens.push_back(token);
        }

        if(tokens.empty()) continue;

        Type cmd = parseType(tokens[0]);
        if(cmd == Type::FRIENDS){
            addFriends(tokens[1],tokens[2]);
        }

        else if(cmd == Type::COUNT){
            countFriends(tokens[1]);
        }

        else if(cmd == Type::QUESTION){
            checkFriends(tokens[1], tokens[2]);
        }
        else if(cmd == Type::UNKNOWN){
            cout << "Неизвестная команда" << endl;
        }

        cout << ">>> ";
    }
    return 0;
}