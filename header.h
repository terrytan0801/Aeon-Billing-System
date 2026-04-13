#pragma once
#include <string>

using namespace std ;

struct item {
    string name;
    double price;
    int stock;
    int sold;
};

extern item fruitlist[100];
extern item canlist[100];
extern item drinklist[100];
extern item snackslist[100];

bool register_user() ;
bool login() ; 
void start_fruit_stock();
void start_can_stock();
void start_drinks_stock();
void start_snack_stock();
void start_stock();
bool auth();

char interface();
