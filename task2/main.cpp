#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

int main() {
    cout << "Введите количество окон:\n>>> ";

    int n;
    cin >> n;

    initWindows(n);
    string command;
    while (cin >> command) {
        if (command == "ENQUEUE") {
            int time;
            cin >> time;

            cout << enqueueVisitor(time) << endl;
        }
        else if (command == "DISTRIBUTE") {
            distributeQueue();
            break;
        }
    }
    return 0;
}