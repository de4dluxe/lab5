#include "queue.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

vector<Visitor> queueData;
vector<Window> windows;
int ticketCounter = 1;

string generateTicket() {
    stringstream ss;
    ss << "T" << setw(3) << setfill('0') << ticketCounter++;
    return ss.str();
}

void initWindows(int windowCount) {
    windows.clear();
    windows.resize(windowCount);
}

string enqueueVisitor(int time) {
    Visitor v;
    v.time = time;
    v.ticket = generateTicket();

    queueData.push_back(v);
    return v.ticket;
}

void distributeQueue() {
    for (auto &w : windows) {
        w.totalTime = 0;
        w.tickets.clear();
    }
    for (auto &visitor : queueData) {
        int bestIndex = 0;
        for (int i = 1; i < windows.size(); i++) {
            if (windows[i].totalTime < windows[bestIndex].totalTime) {
                bestIndex = i;
            }
        }
        windows[bestIndex].totalTime += visitor.time;
        windows[bestIndex].tickets.push_back(visitor.ticket);
    }

    for (int i = 0; i < windows.size(); i++) {
        cout << "Окно " << i + 1
             << " (" << windows[i].totalTime << " минут): ";
        for (int j = 0; j < windows[i].tickets.size(); j++) {
            if (j) cout << ", ";
            cout << windows[i].tickets[j];
        }
        cout << endl;
    }
}