#include "friends.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

unordered_map<string, unordered_set<string>> friendsOf;

Type parseType(const string& cmd){
    if(cmd == "FRIENDS") return Type::FRIENDS;
    if(cmd == "COUNT") return Type::COUNT;
    if(cmd == "QUESTION") return Type::QUESTION;
    return Type::UNKNOWN;
}

void addFriends(const string& name, const string& friends){
    if (name == friends){
        return;
    }

    if(friendsOf[name].count(friends)){
        cout << name << " и " << friends << " уже друзья" << endl;
        return;
    }

    friendsOf[name].insert(friends);
    friendsOf[friends].insert(name);

    cout << name << " и " << friends << " теперь друзья" << endl;
    return;
}

void countFriends(const string& name){
    if(!friendsOf.count(name)){
        cout << "Не найден в базе" << endl;
        return;
    }
    cout << friendsOf[name].size() << endl;
}

void checkFriends(const string& name, const string& friends){
    if(!friendsOf.count(name)){
        cout << "Не найден в базе" << endl;
        return;
    }

    if (name == friends){
        return;
    }

    if(friendsOf[name].count(friends)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

