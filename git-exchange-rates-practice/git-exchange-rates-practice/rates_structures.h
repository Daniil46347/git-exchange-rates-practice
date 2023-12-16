#ifndef BOOK_SUBSCRIPTION_H
#define BOOK_SUBSCRIPTION_H

#include "constant.h"

struct pric
{
    float buy_price;
    float sell_price;
};
struct rates
{
    char bank[MAX_STRING_SIZE];
    pric prices;
    char adress[MAX_STRING_SIZE];
};

#endif
