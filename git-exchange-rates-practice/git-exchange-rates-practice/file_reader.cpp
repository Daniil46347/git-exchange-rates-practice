#include "file_reader.h"
#include "constant.h"

#include <fstream>
#include <cstring>

pric convert(char* str)
{
    pric result;
    char* context = NULL;
    char* str_number = strtok_s(str, " ", &context);
    result.buy_price = atoi(str_number);
    str_number = strtok_s(NULL, " ", &context);
    result.sell_price = atoi(str_number);
    return result;
}

void read(const char* file_name, rates* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            rates* item = new rates;
            file >> item->bank; 
            file >> tmp_buffer;
            //item->prices = convert(tmp_buffer);
            //file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            file.getline(item->adress, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}