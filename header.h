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

// members login function
bool register_user() ;
string login() ; 
string auth();

//stock function
void start_fruit_stock();
void start_can_stock();
void start_drinks_stock();
void start_snack_stock();
void start_stock();
void stock_check();
void stock_check_fruits();
void stock_check_can();
void stock_check_drinks();
void stock_check_snack();


//ui interface
char interface();
char interface_admin();



//command prompt clean
void clear_screen();