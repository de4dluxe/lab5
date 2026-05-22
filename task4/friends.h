#ifndef FRIENDS_H
#define FRIENDS_H

#include <iostream>
#include <string>

using namespace std;

enum class Type{
    FRIENDS,
    COUNT,
    QUESTION,
    UNKNOWN
};

Type parseType(const string& cmd);

void addFriends(const string& name, const string& friends);

void countFriends(const string& name);

void checkFriends(const string& name, const string& friends);
#endif