#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

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
            outfile<<username<<","<<password<<","<<0;
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


string login(){
    int attemps = 3 , i = 0 ; 
    
    while (i<attemps){
        bool found_user = false ; 
        //input username and password
        string username, password;
        cout<<string(30,'-')<< endl;
        cout<<"welcome please login :) "<<endl;
        cout<<string(30,'-')<< endl;
        cout << "Enter username: ";
        cin >> username;
        cout<<string(30,'-')<< endl;
        cout << "Enter password: ";
        cin >> password;
        cout<<string(30,'-')<< endl;

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
                    return username ; 
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
return "Login Fail !" ; //login fail
    

}

string auth(){
    char ismember = ' ';
    
    while (true)
    {   
        cout<<string(30,'=')<<endl;
        cout<<string(9,' ')<<"LOGIN SYSTEM"<<endl;    
        cout<<string(30,'=')<<endl;

        cout<<"Are you member Aeon (y/n) :";
        cin>>ismember;

        //is member need to login
        if (ismember == 'y' || ismember == 'Y')
        {   
            return login();
        }
        //not member need to register 
        else if (ismember == 'n' || ismember == 'N')
        {
            //register function
            bool registered = register_user();
            if (registered == true)
            {
                return login();
            }
            else{
                cout << "Continue as guest.\n";
                return "guest" ;
                }
        }

        else{
        cout<<"Only [y] and [n] is allow !"<<endl; // if user naughty not picking y and n !
        cout<<string(20,'-')<<endl;
        }
    }
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
    
    fruitCount = i;

    // check item 
    // for(int x = 0; x < i; x++){
    //     cout << fruitlist[x].name << " " 
    //          << fruitlist[x].price << " "
    //          << fruitlist[x].stock << " "
    //          << fruitlist[x].sold <<"added"<< endl;
    // }
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
    
    canCount = i;

    //check item 
    // for(int x = 0; x < i; x++){
    //     cout << canlist[x].name << " " 
    //          << canlist[x].price << " "
    //          << canlist[x].stock << " "
    //          << canlist[x].sold <<"added"<< endl;
    // }
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
    
    drinkCount = i;

    //check item 
    // for(int x = 0; x < i; x++){
    //     cout << drinklist[x].name << " " 
    //          << drinklist[x].price << " "
    //          << drinklist[x].stock << " "
    //          << drinklist[x].sold <<"added"<< endl;
    // }
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
    
    snackCount = i;

    //check item 
    // for(int x = 0; x < i; x++){
    //     cout << snackslist[x].name << " " 
    //          << snackslist[x].price << " "
    //          << snackslist[x].stock << " "
    //          << snackslist[x].sold <<" added"<< endl;
    // }
};

void start_stock(){
    start_can_stock();
    start_drinks_stock();
    start_snack_stock();
    start_fruit_stock();
    clear_screen();
    cout<<string(30,'=')<<endl;
    cout<<string(7,' ')<<"WELCOME TO AEON"<<endl;    
    cout<<string(30,'=')<<endl;
    cout<<"\n";
}

char interface(){
    char choices = ' ' ; 
    cout << "========================" << endl;
    cout << "      AEON SYSTEM" << endl;
    cout << "========================" << endl;
    cout << "A. Put into cart" << endl;
    cout << "B. View Cart" << endl;
    cout << "C. Check out" << endl;
    cout << "D. Check member credit" << endl;
    cout << "Q. Exit" << endl;
    cout << "========================" << endl;
    cout << "Enter choice: ";
    cin>>choices;
    return choices ; 
}   

char interface_admin(){
    char choices = ' ';
    cout << "\n";
    cout << "============================" << endl;
    cout << "      AEON ADMIN PANEL      " << endl;
    cout << "============================" << endl;
    cout << "A. View Stock               " << endl;
    cout << "B. Update Stock             " << endl;
	cout << "C. Update Price             " << endl;
    cout << "D. Add New Item             " << endl;
    cout << "E. Remove Item              " << endl;
    cout << "F. Generate Sales Report    " << endl;
    cout << "G. Check Member Credential  " << endl;
    cout << "Q. Exit                     " << endl;
    cout << "============================" << endl;
    cout << "Enter choice: ";
    cin >> choices;
    return choices;
}

void stock_check_fruits(){
    string line = "" , name ="" , stock ="" , sold = "" ,price = "";
    ifstream infile("fruitstock.txt");
    cout<<left<<setw(12)<<" "<<"FRUITS ITEM STOCK"<<endl;
    cout<<string(40,'-')<<endl;
    cout << left 
     << setw(15) << "ITEM NAME"<<"|"
     << setw(10) << "STOCK QTY"<<"|"
     << setw(10) << "ITEM SOLD" << endl;
     cout<<string(40,'-')<<endl;
    while (getline(infile,line))
    {   
        stringstream ss(line);
        getline(ss,name,',');
        getline(ss,price,',');
        getline(ss,stock,',');
        getline(ss,sold,',');

        cout << left 
        << setw(15) << name<<"|"
        << setw(10) << stock<<"|"
        << setw(10) << sold << endl;
    }
    cout<<string(40,'-')<<endl;
}

void stock_check_can(){
    string line = "" , name ="" , stock ="" , sold = "" ,price = "";
    ifstream infile("canfoodstock.txt");
    cout<<left<<setw(12)<<" "<<"CAN ITEM STOCK"<<endl;
    cout<<string(40,'-')<<endl;
    cout << left 
     << setw(15) << "ITEM NAME"<<"|"
     << setw(10) << "STOCK QTY"<<"|"
     << setw(10) << "ITEM SOLD" << endl;
     cout<<string(40,'-')<<endl;
    while (getline(infile,line))
    {   
        stringstream ss(line);
        getline(ss,name,',');
        getline(ss,price,',');
        getline(ss,stock,',');
        getline(ss,sold,',');

        cout << left 
        << setw(15) << name<<"|"
        << setw(10) << stock<<"|"
        << setw(10) << sold << endl;
    }
    cout<<string(40,'-')<<endl;
}

void stock_check_drinks(){
    string line = "" , name ="" , stock ="" , sold = "" ,price = "";
    ifstream infile("drinksstock.txt");
    cout<<left<<setw(12)<<" "<<"DRINKS ITEM STOCK"<<endl;
    cout<<string(40,'-')<<endl;
    cout << left 
     << setw(15) << "ITEM NAME"<<"|"
     << setw(10) << "STOCK QTY"<<"|"
     << setw(10) << "ITEM SOLD" << endl;
     cout<<string(40,'-')<<endl;
    while (getline(infile,line))
    {   
        stringstream ss(line);
        getline(ss,name,',');
        getline(ss,price,',');
        getline(ss,stock,',');
        getline(ss,sold,',');

        cout << left 
        << setw(15) << name<<"|"
        << setw(10) << stock<<"|"
        << setw(10) << sold << endl;
    }
    cout<<string(40,'-')<<endl;
}

void stock_check_snack(){
    string line = "" , name ="" , stock ="" , sold = "" ,price = "";
    ifstream infile("snackstock.txt");
    cout<<left<<setw(12)<<" "<<"SNACKS ITEM STOCK"<<endl;
    cout<<string(40,'-')<<endl;
    cout << left 
     << setw(15) << "ITEM NAME"<<"|"
     << setw(10) << "STOCK QTY"<<"|"
     << setw(10) << "ITEM SOLD" << endl;
     cout<<string(40,'-')<<endl;
    while (getline(infile,line))
    {   
        stringstream ss(line);
        getline(ss,name,',');
        getline(ss,price,',');
        getline(ss,stock,',');
        getline(ss,sold,',');

        cout << left 
        << setw(15) << name<<"|"
        << setw(10) << stock<<"|"
        << setw(10) << sold << endl;
    }
    cout<<string(40,'-')<<endl;
}


void stock_check(){
    cout<<string(3,'\n');
    stock_check_fruits();
    stock_check_can();
    stock_check_drinks();
    stock_check_snack();
    cout<<"all stocks checked complete!"<<endl; 
};

void update_stock() {
    int category = 0;
    cout << "\n";
    cout << "============================" << endl;
    cout << "       UPDATE STOCK         " << endl;
    cout << "============================" << endl;
    cout << "1. Fruits" << endl;
    cout << "2. Canned Food" << endl;
    cout << "3. Drinks" << endl;
    cout << "4. Snacks" << endl;
    cout << "============================" << endl;
    cout << "Select category: ";
    cin >> category;

    // determine which list and file to use
    item* list = nullptr;
    string filename = "";
    int size = 0;

    if (category == 1) {
        list = fruitlist;
        filename = "fruitstock.txt";
        size = fruitCount;
    } else if (category == 2) {
        list = canlist;
        filename = "canfoodstock.txt";
        size = canCount;
    } else if (category == 3) {
        list = drinklist;
        filename = "drinksstock.txt";
        size = drinkCount;
    } else if (category == 4) {
        list = snackslist;
        filename = "snackstock.txt";
        size = snackCount;
    } else {
        cout << "Invalid category!" << endl;
        return;
    }

    // display items in selected category
    cout << "\n";
    cout << string(40, '-') << endl;
    cout << left << setw(5) << "NO"
         << setw(20) << "ITEM NAME"
         << setw(10) << "STOCK" << endl;
    cout << string(40, '-') << endl;
    for (int i = 0; i < size; i++) {
        cout << left << setw(5) << i + 1
             << setw(20) << list[i].name
             << setw(10) << list[i].stock << endl;
    }
    cout << string(40, '-') << endl;

    // select item to update
    int itemNo = 0;
    cout << "Select item number to update: ";
    cin >> itemNo;

    if (itemNo < 1 || itemNo > size) {
        cout << "Invalid item number!" << endl;
        return;
    }

    // input new stock quantity
    int addQty = 0;
    cout << "Current stock for " << list[itemNo-1].name
         << " : " << list[itemNo-1].stock << endl;
    cout << "Enter quantity to add: ";
    cin >> addQty;

    if (addQty <= 0) {
        cout << "Invalid quantity! Must be more than 0." << endl;
        return;
    }

    // update stock
    list[itemNo-1].stock += addQty;
    cout << "Stock updated! New stock for "
         << list[itemNo-1].name << " : "
         << list[itemNo-1].stock << endl;

    // write back to file
    write_stock_file(filename, list, size);
}

void update_price() {
    int category = 0;
    cout << "\n";
    cout << "============================" << endl;
    cout << "       UPDATE PRICE         " << endl;
    cout << "============================" << endl;
    cout << "1. Fruits" << endl;
    cout << "2. Canned Food" << endl;
    cout << "3. Drinks" << endl;
    cout << "4. Snacks" << endl;
    cout << "============================" << endl;
    cout << "Select category: ";
    cin >> category;

    if (category < 1 || category > 4) {
        cout << "Invalid category!" << endl;
        return;
    }

    item* list = nullptr;
    string filename = "";
    int size = 0;

    if (category == 1) {
        list = fruitlist;
        filename = "fruitstock.txt";
        size = fruitCount;
    } else if (category == 2) {
        list = canlist;
        filename = "canfoodstock.txt";
        size = canCount;
    } else if (category == 3) {
        list = drinklist;
        filename = "drinksstock.txt";
        size = drinkCount;
    } else if (category == 4) {
        list = snackslist;
        filename = "snackstock.txt";
        size = snackCount;
    }

    // display items
    cout << "\n";
    cout << string(45, '-') << endl;
    cout << left << setw(5)  << "NO"
         << setw(20) << "ITEM NAME"
         << setw(15) << "CURRENT PRICE" << endl;
    cout << string(45, '-') << endl;
    for (int i = 0; i < size; i++) {
        cout << left << setw(5)  << i + 1
             << setw(20) << list[i].name
             << "RM " << fixed << setprecision(2)
             << list[i].price << endl;
    }
    cout << string(45, '-') << endl;

    // select item
    int itemNo = 0;
    cout << "Select item number to update price: ";
    cin >> itemNo;

    if (itemNo < 1 || itemNo > size) {
        cout << "Invalid item number!" << endl;
        return;
    }

    // show current price
    cout << "Current price for " << list[itemNo-1].name
         << " : RM " << fixed << setprecision(2)
         << list[itemNo-1].price << endl;

    // input new price
    double newPrice = 0;
    cout << "Enter new price (RM): ";
    cin >> newPrice;

    if (newPrice <= 0) {
        cout << "Invalid price!" << endl;
        return;
    }

    // update price in array
    list[itemNo-1].price = newPrice;

    // write back to file
    write_stock_file(filename, list, size);

    cout << "\nPrice updated successfully!" << endl;
    cout << list[itemNo-1].name << " new price : RM "
         << fixed << setprecision(2) << newPrice << endl;
}

void remove_item() {
    int category = 0;
    cout << "\n";
    cout << "============================" << endl;
    cout << "        REMOVE ITEM         " << endl;
    cout << "============================" << endl;
    cout << "1. Fruits" << endl;
    cout << "2. Canned Food" << endl;
    cout << "3. Drinks" << endl;
    cout << "4. Snacks" << endl;
    cout << "============================" << endl;
    cout << "Select category: ";
    cin >> category;

    if (category < 1 || category > 4) {
        cout << "Invalid category!" << endl;
        return;
    }

    // determine which list and file to use
    item* list = nullptr;
    string filename = "";
    int size = 0;

    if (category == 1) {
        list = fruitlist;
        filename = "fruitstock.txt";
        size = fruitCount;
    } else if (category == 2) {
        list = canlist;
        filename = "canfoodstock.txt";
        size = canCount;
    } else if (category == 3) {
        list = drinklist;
        filename = "drinksstock.txt";
        size = drinkCount;
    } else if (category == 4) {
        list = snackslist;
        filename = "snackstock.txt";
        size = snackCount;
    }

    // display items
    cout << "\n";
    cout << string(40, '-') << endl;
    cout << left << setw(5)  << "NO"
         << setw(20) << "ITEM NAME"
         << setw(10) << "STOCK" << endl;
    cout << string(40, '-') << endl;
    for (int i = 0; i < size; i++) {
        cout << left << setw(5)  << i + 1
             << setw(20) << list[i].name
             << setw(10) << list[i].stock << endl;
    }
    cout << string(40, '-') << endl;

    // select item to remove
    int itemNo = 0;
    cout << "Select item number to remove: ";
    cin >> itemNo;

    if (itemNo < 1 || itemNo > size) {
        cout << "Invalid item number!" << endl;
        return;
    }

    // confirm before removing
    char confirm = ' ';
    cout << "Are you sure you want to remove "
         << list[itemNo-1].name << "? (y/n): ";
    cin >> confirm;

    if (confirm != 'y' && confirm != 'Y') {
        cout << "Remove cancelled." << endl;
        return;
    }

    // shift items up to fill the gap
    string removedName = list[itemNo-1].name;
    for (int i = itemNo - 1; i < size - 1; i++) {
        list[i] = list[i + 1];
    }
    // update global count
    if (category == 1) fruitCount -= 1;
    else if (category == 2) canCount -= 1;
    else if (category == 3) drinkCount -= 1;
    else if (category == 4) snackCount -= 1;

    // write back to file
    write_stock_file(filename, list, size - 1);

    cout << "\n" << removedName
         << " has been removed successfully!" << endl;
}

void write_stock_file(string filename, item list[], int size) {
    ofstream outfile(filename);
    if (!outfile) {
        cout << "Error: Cannot open " << filename << " for writing!" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        outfile << list[i].name << ","
                << list[i].price << ","
                << list[i].stock << ","
                << list[i].sold << "\n";
    }
    outfile.close();
    cout << "Stock file updated successfully!" << endl;
}

void add_item() {
    int category = 0;
    cout << "\n";
    cout << "============================" << endl;
    cout << "         ADD NEW ITEM       " << endl;
    cout << "============================" << endl;
    cout << "1. Fruits" << endl;
    cout << "2. Canned Food" << endl;
    cout << "3. Drinks" << endl;
    cout << "4. Snacks" << endl;
    cout << "============================" << endl;
    cout << "Select category: ";
    cin >> category;

    if (category < 1 || category > 4) {
        cout << "Invalid category!" << endl;
        return;
    }

    // determine which list and file to use
    item* list = nullptr;
    string filename = "";
    int* size = nullptr;

    if (category == 1) {
        list = fruitlist;
        filename = "fruitstock.txt";
        size = &fruitCount;
    } else if (category == 2) {
        list = canlist;
        filename = "canfoodstock.txt";
        size = &canCount;
    } else if (category == 3) {
        list = drinklist;
        filename = "drinksstock.txt";
        size = &drinkCount;
    } else if (category == 4) {
        list = snackslist;
        filename = "snackstock.txt";
        size = &snackCount;
    }

    // input new item details
    string newName = "";
    double newPrice = 0;
    int newStock = 0;

    cout << "\nEnter item name (no spaces, use _ ): ";
    cin >> newName;

    cout << "Enter item price (RM): ";
    cin >> newPrice;
    if (newPrice <= 0) {
        cout << "Invalid price!" << endl;
        return;
    }

    cout << "Enter stock quantity: ";
    cin >> newStock;
    if (newStock <= 0) {
        cout << "Invalid quantity!" << endl;
        return;
    }

    // add to array
    list[*size].name  = newName;
    list[*size].price = newPrice;
    list[*size].stock = newStock;
    list[*size].sold  = 0;
    *size += 1;

    // write back to file
    write_stock_file(filename, list, *size);

    cout << "\nItem added successfully!" << endl;
    cout << "Name  : " << newName  << endl;
    cout << "Price : RM " << fixed << setprecision(2) << newPrice << endl;
    cout << "Stock : " << newStock << endl;
}


//check member credential
void check_member_credential(){
    ifstream infile("member_detail.txt");
    string line , user , pwd , credit; 
    cout<<string(30,'=')<<endl;
    cout<<string(5 , ' ')<<"CHECK MEMBER CREDENTIAL"<<endl;
    cout<<string(30, '=')<<endl;
    cout<<left<<setw(15)<<"USERNAME"<<setw(10)<<"PASSWORD"<<setw(10)<<"CREDIT"<<endl;
    while (getline(infile , line))
    {   
        stringstream ss(line);
        getline(ss,user,',');
        getline(ss,pwd,',');
        getline(ss,credit,',');
        cout<<left<<setw(15)<<user<<setw(10)<<pwd<<setw(10)<<credit<<endl;
    }
    cout<<string(30,'=')<<endl;
}

//check member credit
void  check_member_credit(string username){
    string line , user , pwd , credit;
    ifstream infile("member_detail.txt");
    while (getline(infile , line))
    {
        stringstream ss(line);
        getline(ss,user,',');
        getline(ss,pwd,',');
        getline(ss,credit,',');

        if (username == user)
        {   
            cout<<string(30,'=')<<endl;
            cout<<string(9,' ')<<"MEMBER CREDIT"<<endl;
            cout<<string(30,'=')<<endl;
            cout<<user<<"\t :"<<credit<<endl;
            break;
        }
        if (username == "guest")
        {
            cout<<string(30,'=')<<endl;
            cout<<string(9,' ')<<"MEMBER CREDIT"<<endl;
            cout<<string(30,'=')<<endl;
            cout<<"Guest dont have credits !"<<endl;
            break;
        }
    }
}



//sales report generate
void sales_report() {
    cout << "\n";
    cout << "============================" << endl;
    cout << "       SALES REPORT         " << endl;
    cout << "============================" << endl;

    // fruit sales
    cout << left << setw(12) << " " << "FRUITS" << endl;
    cout << string(45, '-') << endl;
    cout << left << setw(20) << "ITEM NAME"
         << setw(10) << "SOLD"
         << setw(10) << "REVENUE (RM)" << endl;
    cout << string(45, '-') << endl;
    double totalRevenue = 0;
    for (int i = 0; i < fruitCount; i++) {
        double revenue = fruitlist[i].price * fruitlist[i].sold;
        totalRevenue += revenue;
        cout << left << setw(20) << fruitlist[i].name
             << setw(10) << fruitlist[i].sold
             << setw(10) << fixed << setprecision(2) << revenue << endl;
    }

    // canned food sales
    cout << "\n";
    cout << left << setw(12) << " " << "CANNED FOOD" << endl;
    cout << string(45, '-') << endl;
    cout << left << setw(20) << "ITEM NAME"
         << setw(10) << "SOLD"
         << setw(10) << "REVENUE (RM)" << endl;
    cout << string(45, '-') << endl;
    for (int i = 0; i < canCount; i++) {
        double revenue = canlist[i].price * canlist[i].sold;
        totalRevenue += revenue;
        cout << left << setw(20) << canlist[i].name
             << setw(10) << canlist[i].sold
             << setw(10) << fixed << setprecision(2) << revenue << endl;
    }

    // drinks sales
    cout << "\n";
    cout << left << setw(12) << " " << "DRINKS" << endl;
    cout << string(45, '-') << endl;
    cout << left << setw(20) << "ITEM NAME"
         << setw(10) << "SOLD"
         << setw(10) << "REVENUE (RM)" << endl;
    cout << string(45, '-') << endl;
    for (int i = 0; i < drinkCount; i++) {
        double revenue = drinklist[i].price * drinklist[i].sold;
        totalRevenue += revenue;
        cout << left << setw(20) << drinklist[i].name
             << setw(10) << drinklist[i].sold
             << setw(10) << fixed << setprecision(2) << revenue << endl;
    }

    // snacks sales
    cout << "\n";
    cout << left << setw(12) << " " << "SNACKS" << endl;
    cout << string(45, '-') << endl;
    cout << left << setw(20) << "ITEM NAME"
         << setw(10) << "SOLD"
         << setw(10) << "REVENUE (RM)" << endl;
    cout << string(45, '-') << endl;
    for (int i = 0; i < snackCount; i++) {
        double revenue = snackslist[i].price * snackslist[i].sold;
        totalRevenue += revenue;
        cout << left << setw(20) << snackslist[i].name
             << setw(10) << snackslist[i].sold
             << setw(10) << fixed << setprecision(2) << revenue << endl;
    }

    // grand total
    cout << string(45, '=') << endl;
    cout << left << setw(30) << "TOTAL REVENUE"
         << "RM " << fixed << setprecision(2) << totalRevenue << endl;
    cout << string(45, '=') << endl;
}


//cart -------
void pick_item(){
    int category = 0 , index = 0 ,q = 0;
    cout << "Select category:\n";
    cout << "1. Fruits\n2. Canned Food\n3. Drinks\n4. Snacks\n";
    cout<< "Select Your Item Category :";
    cin>>category;

    switch (category)
    {
    case 1:
    //pick fruits
        for (int i = 0; i < fruitCount; i++)
        {
            cout<<i+1<<" . "<< fruitlist[i].name << "\t RM" <<fruitlist[i].price<<endl;
        }
        cout<< "Select Item : ";
        cin >> index ;
        cout << "How much "<< fruitlist[index-1].name << " you need :"<<endl;
        cin >> q ;
        if (fruitlist[index-1].stock > q)
        {
            add_to_cart(fruitlist,index-1 , q) ; 
        }
        else{cout<<fruitlist[index-1].name<<" not enough stock , Sorry !"<<endl; } 
        break;
    case 2:
    //pick canned food
        for (int i = 0; i < canCount; i++)
        {
            cout<<i+1<<" . "<< canlist[i].name << "\t RM" <<canlist[i].price<<endl;
        }
        cout<< "Select Item : ";
        cin >> index ;
        cout << "How much "<< canlist[index-1].name << " you need :"<<endl;
        cin >> q ;
        if (canlist[index-1].stock > q)
        {
            add_to_cart(canlist,index-1 , q) ; 
        }
        else{cout<<canlist[index-1].name<<" not enough stock , Sorry !"<<endl; }
        break;
    case 3:
    //pick drinks
        for (int i = 0; i < drinkCount; i++)
        {
            cout<<i+1<<" . "<< drinklist[i].name << "\t RM" <<drinklist[i].price<<endl;
        }
        cout<< "Select Item : ";
        cin >> index ;
        cout << "How much "<< drinklist[index-1].name << " you need :"<<endl;
        cin >> q ;
        if (drinklist[index-1].stock > q)
        {
            add_to_cart(drinklist,index-1 , q) ; 
        }
        else{cout<<drinklist[index-1].name<<" not enough stock , Sorry !"<<endl; }
        break;
    case 4:
    //pick snacks
        for (int i = 0; i < snackCount; i++)
        {
            cout<<i+1<<" . "<< snackslist[i].name << "\t RM" <<snackslist[i].price<<endl;
        }
        cout<< "Select Item : ";
        cin >> index ;
        cout << "How much "<< snackslist[index-1].name << " you need :"<<endl;
        cin >> q ;
        if (snackslist[index-1].stock > q)
        {
            add_to_cart(snackslist,index-1 , q) ; 
        }
        else{cout<<snackslist[index-1].name<<" not enough stock , Sorry !"<<endl; } 
        break;
    
    default:
        cout<<"Sorry we dont provide these item thank you !"<<endl;
        break;
    }
}
//add to cart
void add_to_cart(item list[], int index , int qty)
{   
    //add item into it
	cart[cartSize].name = list[index].name;
	cart[cartSize].price = list[index].price;
	cart[cartSize].quantity = qty ;
    cart[cartSize].category = &list[index];
	
	cartSize++;
	
	cout<< "Item added to cart!\n";
}



//view cart
void view_cart()
{
	cout << "\n======== CART ========\n";
	
	for (int i = 0; i < cartSize; i++)
	{
		cout 	<< i+1 << ". "
				<< cart[i].name<<"\t"
				<< "RM" << cart[i].price<<"\t"
				<< " x " << cart[i].quantity<<"\t" <<"RM"<< cart[i].price * cart[i].quantity << endl;
	}
}


// checkout
void checkout()
{
	double total = 0;
	
	cout << "\n======== RECEIPT ========\n";
	
	for (int i=0; i < cartSize; i++)
	{
		double subtotal = cart[i].price * cart[i].quantity;
		
		cout 	<< cart[i].name
				<< " RM " << cart[i].price
				<< " x "  << cart[i].quantity
				<< " =  RM "  << subtotal << endl;
				
		total += subtotal;
	}
    //item deduct

	cout << "====================\n";
	cout << "TOTAL: RM" << total << endl;
	
	double pay;
	cout << "Payment: RM";
	cin >> pay;
	
	if (pay >= total){
        cout << "Change: RM" << pay - total << endl;
        for (int i = 0; i < cartSize; i++)
        {
            cart[i].category ->stock -= cart[i].quantity;
            cart[i].category ->sold += cart[i].quantity;

        }
        //update stock
        update_file();
    }
		
	else
		cout << "Not enough money!\n";
		
	cartSize = 0;
	cout << "Thank You For Purchased!\n";
}

void update_file()
{
    // Fruits
    {
        ofstream outfile("fruitstock.txt");
        for (int i = 0; i < fruitCount; i++)
        {
            outfile << fruitlist[i].name << ","<< fruitlist[i].price << ","<< fruitlist[i].stock << ","<< fruitlist[i].sold << endl;
        }
    }

    // Canned
    {
        ofstream outfile("canfoodstock.txt");
        for (int i = 0; i < canCount; i++)
        {
            outfile << canlist[i].name << ","<< canlist[i].price << ","<< canlist[i].stock << ","<< canlist[i].sold << endl;
        }
    }

    // Drinks
    {
        ofstream outfile("drinksstock.txt");
        for (int i = 0; i < drinkCount; i++)
        {
            outfile << drinklist[i].name << ","<< drinklist[i].price << ","<< drinklist[i].stock << ","<< drinklist[i].sold << endl;
        }
    }
    // Snacks
    {
        ofstream outfile("snackstock.txt");
        for (int i = 0; i < snackCount; i++)
        {
            outfile << snackslist[i].name << ","<< snackslist[i].price << ","<< snackslist[i].stock << ","<< snackslist[i].sold << endl;
        }
    }
}

void clear_screen(){
    #ifdef _WIN32  // Check if the operating system is Windows
        system("cls");
    #endif
};

void pause(){
    cout<<"Press enter to continue"<<endl;
    cin.ignore();
    cin.get(); 
    clear_screen();
}

