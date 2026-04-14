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
    
    //postest loop for interface !
    do{
       choices = interface();
       switch (choices)
    {
    case 'a':case'A':
        //put in cart
        //Press enter to continue to avoid spamming interface
        cout<<"press enter to continue"<<endl;
        cin.ignore();
        cin.get(); 
        break;

    case 'b':case'B':
        //check credit (member)
        //Press enter to continue to avoid spamming interface
        cout<<"press enter to continue"<<endl;
        cin.ignore();
        cin.get(); 
        break;

    case 'c':case'C':
        //check out
        //Press enter to continue to avoid spamming interface
        cout<<"press enter to continue"<<endl;
        cin.ignore();
        cin.get(); 
        break;

    case 'd':case'D':
        //check stock (if admin)
        if (admin == true)
        {   
           stock_check();
        }else{
            cout<<"You are not admin !"<<endl;
        }
        //Press enter to continue to avoid spamming interface
        cout<<"press enter to continue"<<endl;
        cin.ignore();
        cin.get(); 
        break;
    
    case 'e':case'E':
        //generate sales report (if admin)
        if (admin == true)
        {   
           stock_check();
        }else{
            cout<<"You are not admin !"<<endl;
        }
        //Press enter to continue to avoid spamming interface
        cout<<"press enter to continue"<<endl;
        cin.ignore();
        cin.get(); 
        break;
    
    default:
        break;
    }
    } while (choices != 'q' and choices != 'Q');
    
    cout<<"Thanks for chosing Aeon ! See u soon ! ❤️"<<endl;
    
    return 0 ;
}