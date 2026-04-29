#include <iostream>
#include <fstream>
#include <string>
#include "header.h"
#include <sstream>

using namespace std ;

int main () {
    char choices =' ' ;
    start_stock();
    string username = auth() ;
    bool admin = false ; 
    clear_screen();
    //check whether user is admin or not
    if (username == "admin")
    {
        admin = true ;
    }
    
    //admin interface
    if (admin == true)
    {
    do{
       choices = interface_admin();
       switch (choices)
    {
    case 'a':case'A':
        //check stock
        stock_check();
        pause();
        break;

    case 'b':case'B':
        //Update stock
        update_stock();
        pause();
        break;

    case 'c':case'C':
        //update price
        update_price() ;
        pause();
        break;

    case 'd':case'D':
        //add new item
        add_item();
        pause();
        break;

    case 'e':case'E':
        //remove item
        remove_item();
        pause();
        break;

    case 'f':case'F':
        //generate sales report
        sales_report();
        pause();
        break;

    case 'g':case'G':
        check_member_credential();
        pause();
        break;
        
    default:
        break;
    }   } while (choices != 'q' && choices != 'Q');
    }
    
    else{
    
    //normal interface
    do{
       choices = interface();
       switch (choices){
    case 'a':case'A':
        //put into cart
        clear_screen();
        pick_item();
        pause();
        break;

    case 'b':case'B':
        //check cart item
        clear_screen();
        view_cart();
        pause();
        break;

    case 'c':case'C':
        //check out
        clear_screen();
        checkout();
        pause();
        break;

    case 'd':case'D':
        //view member credit
        check_member_credit(username);
        pause();
        break;
    
    default:
        break;
    }
    } while (choices != 'q' && choices != 'Q');}
    
    cout<<"Thanks for chosing Aeon ! See u soon ! <3 "<<endl;
    
    return 0 ;
}
