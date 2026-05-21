#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Cell{
    string product;
    int quantity = 0;
};

extern map<string, Cell> warehouse;

const vector<char> zones = {'A', 'B', 'C'};

const int racks = 20;
const int sections = 5;
const int shelves = 2;

const int maxCellCapacity = 10;

bool isValidAddress(const string& address);

int getTotalCells();

vector<string> getAllAddresses();

void addProduct(
    const string& product,
    int quantity,
    const string& address
);

void removeProduct(
    const string& product,
    int quantity,
    const string& address);

void showInfo();
#endif