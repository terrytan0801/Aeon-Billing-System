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

        //Pause
        cout<<"press enter to continue"<<endl;
        cin.ignore();
        cin.get(); 
        clear_screen();
        break;

    case 'b':case'B':
        //check member credential
        //Press enter to continue to avoid spamming interface
        cout<<"press enter to continue"<<endl;
        cin.ignore();
        cin.get();
        clear_screen(); 
        break;

    case 'c':case'C':
        //generate sales report
        //Press enter to continue to avoid spamming interface
        cout<<"press enter to continue"<<endl;
        cin.ignore();
        cin.get();
        clear_screen(); 
        break;
    default:
        break;
    }
    } while (choices != 'q' and choices != 'Q');
    }
    
    else{
    
    //normal interface
    do{
       choices = interface();
       switch (choices)
    {
        
    case 'a':case'A':
        //put into cart
        //Press enter to continue to avoid spamming interface
        cout<<"press enter to continue"<<endl;
        cin.ignore();
        cin.get(); 
        clear_screen();
        break;

    case 'b':case'B':
        //check member credit
        //Press enter to continue to avoid spamming interface
        cout<<"press enter to continue"<<endl;
        cin.ignore();
        cin.get(); 
        clear_screen();
        break;

    case 'c':case'C':
        //check out
        //Press enter to continue to avoid spamming interface
        cout<<"press enter to continue"<<endl;
        cin.ignore();
        cin.get(); 
        clear_screen();
        break;

    case 'd':case'D':
        //check item price
        //Press enter to continue to avoid spamming interface
        cout<<"press enter to continue"<<endl;
        cin.ignore();
        cin.get(); 
        clear_screen();
        break;
    
    default:
        break;
    }
    } while (choices != 'q' and choices != 'Q');}
    
    cout<<"Thanks for chosing Aeon ! See u soon ! ❤️"<<endl;
    
    return 0 ;
}