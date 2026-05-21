#include "warehouse.h"
#include <sstream>

using namespace std;

int main(){
    string line;

    while (true){
        cout << ">>> ";
        getline(cin, line);
        if (line == "EXIT"){
            break;
        }
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "ADD"){
            string product;
            int quantity;
            string address;
            ss >> product >> quantity >> address;
            addProduct(
                product,
                quantity,
                address);
        }

        else if (command == "REMOVE"){
            string product;
            int quantity;
            string address;
            ss >> product >> quantity >> address;
            removeProduct(
                product,
                quantity,
                address);
        }

        else if (command == "INFO"){
            showInfo();
        }

        else{
            cout << "Неизвестная команда\n";
        }
    }
    return 0;
}