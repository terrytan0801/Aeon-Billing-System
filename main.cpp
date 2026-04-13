#include <iostream>
#include <fstream>
#include <string>
#include "header.h"
#include <sstream>

using namespace std ;



int main () {
    char choices =' ';
    start_stock();
    bool member = auth();
    do{
    
    char choices = interface();
       switch (choices)
    {
    case 'a':case'A':
        //put in cart
        break;

    case 'b':case'B':
        //check credit (member)
        break;

    case 'c':case'C':
        //check out
        break;

    case 'd':case'D':
        //check stock (if admin)
        break;
    
    case 'e':case'E':
        //generate sales report (if admin)
        break;
    
    default:
        break;
    }
    } while (choices != 'q' || choices != 'Q');
    
    
    
    return 0 ;
}