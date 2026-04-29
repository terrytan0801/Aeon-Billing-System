#pragma once
#include <string>

using namespace std ;

//struct
struct item {
    string name;
    double price;
    int stock;
    int sold;
};

struct cart_item{
	string name;
	double price;
	int quantity;
    item* category;
};

//stock array 
extern item fruitlist[100];
extern item canlist[100];
extern item drinklist[100];
extern item snackslist[100];

//cart
extern cart_item cart[100];
extern int cartSize;

//admin functions
extern int fruitCount;
extern int canCount;
extern int drinkCount;
extern int snackCount;

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
void update_file();

//stock check function
void stock_check();
void stock_check_fruits();
void stock_check_can();
void stock_check_drinks();
void stock_check_snack();

// Process Card & Billing
void add_to_cart(item list[], int index , int qty);
void view_cart();
void pick_item();

//checkout
void checkout();


//ui interface
char interface();
char interface_admin();

//command prompt clean
void clear_screen();

//check member credential
void check_member_credential();
void check_member_credit(string username);

char admin_interface();
void write_stock_file(string filename, item list[], int size);
void update_stock();
void sales_report();
void add_item();
void remove_item();
void update_price();

//extra func
void pause();
