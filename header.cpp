#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//for the loading bar
// #include <ctime>   
// #include <chrono>
// #include <thread>

using namespace std ;

#include "header.h"

bool register_user()
{   
    char register_query = ' ';
    while(true){
        //want to register
        cout<<"Do you want to register [y]/[n] :";
        cin>>register_query;
        if (register_query == 'y' || register_query == 'Y')
        {
            string username = "" , password = "" , confirm_password = "" ;
            cout<<string(30,'-')<<endl;
            cout<<string(10,'=')<<" Register "<<string(10,'=')<<endl;

            cout<<"Please insert your username :";
            cin>>username ; 

            //password input 
            do{
                cout<<string(30,'-')<<endl;
                cout<<string(10,'=')<<" Password "<<string(10,'=')<<endl;
                cout<<"Please insert your password :";
                cin>>password;

                cout<<string(30,'-')<<endl;
                cout<<"Please confirm your password :" ; 
                cin>>confirm_password;
                cout<<string(30,'-')<<endl;
                cout<<string(30,'=')<<endl;

                if (password != confirm_password){
                    cout<<"Password not match ! Please try again !"<<endl;
                }

            }while(password != confirm_password);
            // store the user register data into member txt file
            ofstream outfile("member_detail.txt" , ios::app);
            outfile<<username<<","<<password;
            outfile.close();

            cout<<"register complete !"<< "welcome "<<username <<endl; 
            return true ; 
        }
        else if (register_query == 'n' || register_query == 'N'){
            cout<<"No register" <<endl;
            return false ; 
            }
        else{
            cout<<"only [y] and [n] available ! try again !"<<endl;
        }
        }  
}  


bool login(){
    int attemps = 3 , i = 0 ; 
    
    while (i<attemps){
        bool found_user = false ; 
        //input username and password
        string username, password;
        cout<<"welcome please login :) "<<endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        //call out the file for further checking
        ifstream infile("member_detail.txt");
        string line = "";
        
        //check login creditial one by one 
        while (getline(infile , line)){ // if there is not end of file (still got item inside the ==> true)
            stringstream ss(line); //convert the line into string stream
            string check_u ="" , check_p = "";
            getline(ss,check_u,',');
            getline(ss,check_p,',');
            if (username == check_u)
            {
                //user found !
                found_user = true ; 
                //password correct
                if (password == check_p)
                {
                    cout<<"welcome to Aeon "<<username<<endl;
                    return true ; 
                }
                //not correct
                else{
                    i+=1 ;
                    cout<<"Wrong password !"<<attemps-i<<"chances left" <<endl;
                     
                }
                break;
            }
            
        }
        if (found_user != true){
            cout<<"Username not exist ! "<<username<<endl;
        }

    }
cout<<"No more chance left ! Login fail !" ; 
return false ; 
    

}

bool auth(){
    char ismember = ' ';
    
    bool member = false , logged_in = false , found_user = false ; 

    while (logged_in!=true)
    {
        cout<<"Are you member Aeon (y/n) :";
        cin>>ismember;

        //is member need to login
        if (ismember == 'y' or ismember == 'Y')
        {   
            logged_in = login();
            member = true ;
        }
        //not member need to register 
        else if (ismember == 'n' or ismember == 'N')
        {
            //register function
            bool registered = register_user();
            if (registered == true)
            {
                logged_in = login();
                member = true ; 
            }else{
                cout << "Continue as guest.\n";
                break; 
            }

            
    }
    else{
        cout<<"Only [y] and [n] is allow "<<endl;
        cout<<string(20,'-')<<endl;
    }
    }
    int member_discount = member?10:0 ; 
    cout<<"ding ding ding !"<<"Its shopping time ~"<<endl;
    cout << "Your discount is " << member_discount << "%"<<endl;

    return member;
}



//stock function

void start_fruit_stock(){
    // input fruits item into store
    ifstream infile("fruitstock.txt") ;

    string name = "" , line ="" , stock = "", sold = "" , price = "";
    int i = 0 ; // i use this to as counter in the while loop -> 
    while(getline(infile,line)){
        
        stringstream ss(line);
        getline(ss,name,',');
        getline(ss,price,',');
        getline(ss,stock,',');
        getline(ss,sold,',');

        //store item into the list 

        fruitlist[i].name = name ;
        fruitlist[i].price = stod(price) ;
        fruitlist[i].stock = stoi(stock) ;
        fruitlist[i].sold = stoi(sold);
        i += 1 ; 
    }
    
    // check item 
    for(int x = 0; x < i; x++){
        cout << fruitlist[x].name << " " 
             << fruitlist[x].price << " "
             << fruitlist[x].stock << " "
             << fruitlist[x].sold <<"added"<< endl;
    }
};

void start_can_stock(){
    //create a struct for fruits

    // input fruits item into store
    ifstream infile("canfoodstock.txt") ;

    string name = "" , line ="" , stock = "", sold = "" , price = "";
    int i = 0 ; // i use this to as counter in the while loop -> 
    while(getline(infile,line)){
        
        stringstream ss(line);
        getline(ss,name,',');
        getline(ss,price,',');
        getline(ss,stock,',');
        getline(ss,sold,',');

        //store item into the list 

        canlist[i].name = name ;
        canlist[i].price = stod(price) ;
        canlist[i].stock = stoi(stock) ;
        canlist[i].sold = stoi(sold);
        i += 1 ; 
    }
    
    //check item 
    for(int x = 0; x < i; x++){
        cout << canlist[x].name << " " 
             << canlist[x].price << " "
             << canlist[x].stock << " "
             << canlist[x].sold <<"added"<< endl;
    }
};

void start_drinks_stock(){

    // input fruits item into store
    ifstream infile("drinksstock.txt") ;

    string name = "" , line ="" , stock = "", sold = "" , price = "";
    int i = 0 ; // i use this to as counter in the while loop -> 
    while(getline(infile,line)){
        
        stringstream ss(line);
        getline(ss,name,',');
        getline(ss,price,',');
        getline(ss,stock,',');
        getline(ss,sold,',');

        //store item into thdrinklist

        drinklist[i].name = name ;
        drinklist[i].price = stod(price) ;
        drinklist[i].stock = stoi(stock) ;
        drinklist[i].sold = stoi(sold);
        i += 1 ; 
    }
    
    //check item 
    for(int x = 0; x < i; x++){
        cout << drinklist[x].name << " " 
             << drinklist[x].price << " "
             << drinklist[x].stock << " "
             << drinklist[x].sold <<"added"<< endl;
    }
};

void start_snack_stock(){

    // input fruits item into store
    ifstream infile("snackstock.txt") ;

    string name = "" , line ="" , stock = "", sold = "" , price = "";
    int i = 0 ; // i use this to as counter in the while loop -> 
    while(getline(infile,line)){
        
        stringstream ss(line);
        getline(ss,name,',');
        getline(ss,price,',');
        getline(ss,stock,',');
        getline(ss,sold,',');

        //store item into thdrinklist

        snackslist[i].name = name ;
        snackslist[i].price = stod(price) ;
        snackslist[i].stock = stoi(stock) ;
        snackslist[i].sold = stoi(sold);
        i += 1 ; 
    }
    
    //check item 
    for(int x = 0; x < i; x++){
        cout << snackslist[x].name << " " 
             << snackslist[x].price << " "
             << snackslist[x].stock << " "
             << snackslist[x].sold <<" added"<< endl;
    }
};

void start_stock(){
    
    start_can_stock();
    start_drinks_stock();
    start_snack_stock();
    start_fruit_stock();
    cout<<string(30,'=')<<endl;
    cout<<"all stocks added complete!"<<endl;    
    cout<<string(30,'=')<<endl;

    //loading bar useless 
    // int progress = 0 ;

    // while (progress <= 100){
    //     // \r in order to let the output stay at one line 
    //     cout<<"\r[" ;
    //     for (int i = 0 ; i<20 ; i++){
    //         if (i < progress/5){
    //             cout<<"=";
    //         }else{
    //             cout<<"+";
    //         }
    //     }
    //     // flush let the output come out immediately
    //     cout<<"]"<<progress<<"%"<<flush;
    //     this_thread::sleep_for(chrono::milliseconds(100));
    //     progress += 5;
    
    // }
    // cout<<endl;
}

char interface(){
    char choices = ' ' ; 
    cout << "========================" << endl;
    cout << "      AEON SYSTEM" << endl;
    cout << "========================" << endl;
    cout << "A. Put into cart" << endl;
    cout << "B. Check member credit" << endl;
    cout << "C. Check out" << endl;
    cout << "D. Check Stock (only admin)" << endl;
    cout << "Q. Exit" << endl;
    cout << "========================" << endl;
    cout << "Enter choice: ";
    cin>>choices;
    return choices ; 
}   

