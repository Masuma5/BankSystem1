//bank system project
//Masuma Alqattan 2210003617
//Manar Albazbooz 2210003584
//maymonah Al ahmad 2210040201
//khadijah alahmar 2210003523

#include<iostream> 
#include <cstdlib> //random function
#include<fstream> //files
#include <ctime> //random
 
using namespace std; 
 int pass,input, option ; //global variables 
struct customer 
{ 
    int account_no; 
    char name[80]; 
    int balance; //to show the balance
}; 
 
 
void accept(struct customer[], int *n); 
void display(struct customer[], int *n); 


void display(){
	cout<<" \n                        \t WELCOME TO THE BANK SYSTEM                   \t \n ";
	
}; 
int edit(struct customer[], int &n, int &number); 
void deposit(struct customer[], int&n, int &number, int &atm); 
void withdraw(struct customer [], int &n, int &number, int &atm); 
void choice() 
{ 
 cout<<"\n select an option please: \n "<<" 1- desposit. \n"<<" 2- withdraw.  \n 3-to end the process ,press 0.:\t"; 
} 
 
     
 
int main() 
{ 
    srand(time(0)); //to generate random balance to the user (spesfic range (0-500000))
 
 
    string name; 
     
    ofstream employeefile ;
	employeefile.open("employee.txt" , ios::app); //write the employees names to the file
	
    ofstream usersfile;
    
	usersfile.open ("user.txt" , ios::app); //write the users names&passwords to the file
    
	ifstream ufile; //reading the users names&passwords from the file
  
    display(); 
    
   cout<<"Enter your nmae please: \t"; 
   cin>>name; 
   cout<<" \n********** WELCOME mrs-mr "<<name<<" ********** \n Enter your  password (4 digit only) : \t"; 
   cin>>pass; 
    
    
   while (pass>9999 || pass<1000) //spesfic range for passowrd(4 digits)
   { 
   cout <<"Password doesn't have four digits." << endl; 
   cout <<"Enter your password again.\t" ; 
   cin>>pass; 
   } 
    
    
   cout<<"\n If you are an employee please enter (1) , and if you are a user click (0) please \t "; 
   cin>>input; 
   cout<<"********************************************************************************************************"; 
 
 
   if(input==1) 
   { 
 struct customer data[20]; //data array from customer struct
    
	int n, choice, account_no, amount, index; 
 
   cout<<"\n **********Banking System************\n\n"; 
   cout<<"Number of customer records you want to enter? : "; 
    cin >>n; //number of records
     
     accept(data, &n); //recieve address from pointer 
     employeefile << name <<endl ;  //write the name inside the file
     
     
    
     
    do 
    { 
 
        cout<<"\nBanking System Menu :\n"; 
        
        cout<<"Press 1 to display all records.\n"; 
        
        cout<<"Press 2 to edit an account  .\n"; 
        
        cout<<"Press 3 to deposit amount.\n"; 
        
        cout<<"Press 4 to withdraw amount.\n"; 
        
        cout<<"Press 5 to display names and password for usars.\n"; 
        
        cout<<"Press 0 to exit\n"; 
        
        cout<<"\nEnter choice(0-5) : "; 
        cin>>choice; 
         
         
        switch (choice) //EMPLOYEE
        { 
     
      case 1: 
                display(data, &n); 
                break; 
                
                
            case 2: 
               cout<< "Enter account number to edit : "; 
                cin>>account_no; 
                 
                 
                index = edit(data, n, account_no); 
                if (index ==  -1) 
                { 
                    cout<<"Record not found : "; 
                } 
                else 
                { 
                    cout<<" Number:"<<endl; 
                     cin>> data[index].account_no; 
                    cout<<" Name:"<<endl; 
                       cin>>data[index].name; 
                        cout<<" balance:"<<endl; 
                        cin>>data[index].balance; 
                } 
                break; 
                 
                 
            case 3: 
                cout<<"Enter account number : "; 
                cin>>account_no;
                
                cout<<"Enter amount to deposit : "; 
                cin>>amount; 
                
                deposit(data, n, account_no, amount); 
                break; 
                 
                 
            case 4: 
                cout<<"Enter account number : "<<endl; 
                cin>>account_no; 
                cout<<"Enter amount to withdraw : "<<endl; 
                cin>>amount; 
                withdraw(data, n, account_no, amount);    
     
   case 5: 
   ufile.open("user.txt");    
   while (ufile >> name) //to reading all the file
   { 
    cout << name << endl ; //reading the user name
   } 
   ufile.close(); 
   break;
   
        }    
    } 
     
     
    while (choice != 0); 
} 
   else if(input==0) 
 { 

 int i=(1+rand() % 500000); 
    cout<<"\n your total balance : \t "<<i<<" SR"<<endl; 
    usersfile << name << " , " << pass <<endl ;//writing the name& passoword from user 
 

do 
 { 
 
choice(); //FOR USER
cin>>option; 

switch (option) 
  { 
 case 1: 
  int am; 
  cout<<"\n enter the desposit amount :  "; 
  cin>>am;

cout<<"\n your total balance now : ";
i=i+am;
  cout<<i; 
  break; 
   
 case 2: 
  int with; 
   cout<<"\n enter the withdraw amount :  "; 
  cin>>with; 
  cout<<"\n your total balance now : "; 
  i=i-with;
  cout<<i; 
  
  break;   
  choice(); 
  } 
 } 
  
  
while(option!=0); 
} 
   else 
   cout<<"\n you have entered incorrect data , try again.. "; 
 
 return 0; 
  
} 
 
void accept( customer list[80], int *n) 
{ 
    int i; 
    for (i = 0; i <*n; i++) 
    { 
        cout<<"\nEnter data for Record #"<< i + 1<<endl; 
 
        cout<<"Enter account_no :"<<endl; 
        cin>>list[i].account_no; 
 
        cout<<"Enter name : "<<endl; 
        cin>>list[i].name; 
        list[i].balance = 0; 
    }  
      
} 
 
  void display(struct customer list[80], int *poi) 
{ 
    int i; 
 
    cout<<"account_no\tName\t\tBalance\n"; 
    for (i = 0; i <*poi; i++) 
    { 
       cout<<list[i].account_no<<"\t\t"; 
       cout<<list[i].name<<" \t\t"; 
       cout<<list[i].balance<<endl; 
        
    } 
   
} 
 
 int edit(struct customer list[80], int &n, int &number) 
{ 
    int i; 
 
    for (i = 0; i<n; i++) 
    { 
        if (list[i].account_no == number) 
        { 
            return i; 
        }  
    } 
    return  - 1; 
} 
    
    
    void deposit(struct customer list[], int &n, int &number, int &amt) 
{ 
    int i = edit(list, n, number); 
    if (i ==  - 1)
    { 
        cout<<"Record not found"<<endl; 
    }  
    else 
    { 
        list[i].balance += amt; 
    } 
} 
 
     
   void withdraw(struct customer list[], int &n, int &number, int &amt) 
{ 
    int i = edit(list, n, number); 
    if (i ==  - 1) 
    { 
        cout<<"Record not found\n"; 
    }  
    else if (list[i].balance < amt) 
    { 
        cout<<"Insufficient balance\n"; 
    } 
    else 
    { 
        list[i].balance -= amt; 
    } 
}
