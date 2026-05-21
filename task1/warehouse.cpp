#include "warehouse.h"

#include <iomanip>

using namespace std;

map<string, Cell> warehouse;

bool isValidAddress(const string& address)
{
    if (address.length() != 5)
    {
        return false;
    }

    char zone = address[0];

    bool zoneFound = false;

    for (const auto& z : zones)
    {
        if (z == zone)
        {
            zoneFound = true;
        }
    }

    if (!zoneFound)
    {
        return false;
    }

    int rack;
    int section;
    int shelf;

    try
    {
        rack = stoi(address.substr(1, 2));
        section = stoi(address.substr(3, 1));
        shelf = stoi(address.substr(4, 1));
    }
    catch (...)
    {
        return false;
    }

    return rack >= 1 && rack <= racks &&
           section >= 1 && section <= sections &&
           shelf >= 1 && shelf <= shelves;
}

int getTotalCells()
{
    return zones.size() * racks * sections * shelves;
}

vector<string> getAllAddresses()
{
    vector<string> addresses;

    for (const auto& zone : zones)
    {
        for (int rack = 1; rack <= racks; ++rack)
        {
            for (int section = 1; section <= sections; ++section)
            {
                for (int shelf = 1; shelf <= shelves; ++shelf)
                {
                    string address;

                    address += zone;

                    if (rack < 10)
                    {
                        address += "0";
                    }

                    address += to_string(rack);
                    address += to_string(section);
                    address += to_string(shelf);

                    addresses.push_back(address);
                }
            }
        }
    }

    return addresses;
}

void addProduct(
    const string& product,
    int quantity,
    const string& address
)
{
    if (!isValidAddress(address))
    {
        cout << "Ошибка: Некорректный адрес\n";
        return;
    }

    if (quantity > maxCellCapacity)
    {
        cout << "Ошибка: Превышена вместимость ячейки (максимум 10)\n";
        return;
    }

    auto& cell = warehouse[address];

    if (cell.quantity > 0 && cell.product != product)
    {
        cout
            << "Ошибка: Ячейка "
            << address
            << " занята товаром "
            << cell.product
            << "\n";

        return;
    }

    if (cell.quantity + quantity > maxCellCapacity)
    {
        cout << "Ошибка: Превышена вместимость ячейки (максимум 10)\n";
        return;
    }

    cell.product = product;
    cell.quantity += quantity;

    cout
        << "Добавлено "
        << quantity
        << " "
        << product
        << " в "
        << address
        << "\n";
}

void removeProduct(
    const string& product,
    int quantity,
    const string& address
)
{
    if (!isValidAddress(address))
    {
        cout << "Ошибка: Некорректный адрес\n";
        return;
    }

    if (!warehouse.count(address) ||
        warehouse.at(address).quantity == 0)
    {
        cout << "Ошибка: Ячейка пуста\n";
        return;
    }

    auto& cell = warehouse[address];

    if (cell.product != product)
    {
        cout
            << "Ошибка: Товар "
            << product
            << " не найден в ячейке "
            << address
            << "\n";

        return;
    }

    if (cell.quantity < quantity)
    {
        cout << "Ошибка: Недостаточно товаров для удаления\n";
        return;
    }

    cell.quantity -= quantity;

    cout
        << "Удалено "
        << quantity
        << " "
        << product
        << " (остаток: "
        << cell.quantity
        << ")\n";

    if (cell.quantity == 0)
    {
        cell.product.clear();
    }
}

void showInfo()
{
    int occupied = 0;

    for (const auto& [address, cell] : warehouse)
    {
        occupied += cell.quantity;
    }

    double totalPercent =
        static_cast<double>(occupied) /
        (getTotalCells() * maxCellCapacity) * 100.0;

    cout << fixed << setprecision(2);

    cout
        << "Загруженность склада: "
        << totalPercent
        << " %\n\n";

    for (const auto& zone : zones){
        int zoneOccupied = 0;

        for (const auto& [address, cell] : warehouse)
        {
            if (address[0] == zone)
            {
                zoneOccupied += cell.quantity;
            }
        }

        double zonePercent = static_cast<double>(zoneOccupied) / (racks * sections * shelves * maxCellCapacity) * 100.0;

        cout << "Загруженность зоны " << zone << ": " << zonePercent << " %\n";
    }

    cout << "\nЗаполненные ячейки:\n";

    for (const auto& [address, cell] : warehouse){
        if (cell.quantity > 0){
            cout << address << ": " << cell.product << " (" << cell.quantity << ")\n";
        }
    }

    cout << "\nПустые ячейки:\n";

    auto allAddresses = getAllAddresses();

    for (const auto& address : allAddresses){
        if (!warehouse.count(address) || warehouse.at(address).quantity == 0){
            cout << address << " ";
        }
    }

    cout << "\n";
}