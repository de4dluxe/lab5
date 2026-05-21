#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <string>

using namespace std;

struct Visitor {
    string ticket;
    int time;
};

struct Window {
    int totalTime;
    vector<string> tickets;
};

void initWindows(int windowCount);

string enqueueVisitor(int time);

void distributeQueue();

#endif