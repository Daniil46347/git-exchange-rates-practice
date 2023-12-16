#include <iostream>

using namespace std;

#include "rates_structures.h"
#include "file_reader.h"
#include "constant.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №4. GIT\n";
    cout << "Вариант №4. Курсы валют\n";
    cout << "Автор: Ильющенко Яна\n\n";
    rates* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {
            cout << subscriptions[i]->bank << ' ';
            cout << subscriptions[i]->buy_price << ' ';
            cout << subscriptions[i]->sell_price << ' ';
            cout << subscriptions[i]->adress << ' ';
            cout << '\n';
        }

    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    for (int i = 0; i < size; i++)
    {
        delete subscriptions[i];
    }
    return 0;
}