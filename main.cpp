#include <iostream>
#include <fstream>
#include<cstdlib>


using namespace std;

class Bank_rec{
private:

    char firstName[20];
    char lastName[20];
    char idNumber[20];
    float deposit;
    float withdrawal;
    float balance;
    int accountNumber;

public:
    void register_account();
    void deposit_cash();
    void withdraw_cash();
    void check_balance();
    void write_rec();
    void show_rec();
    void read_rec();

};
void Bank_rec::register_account(){
    cout<<"Enter your name: ";
    cin>>firstName;
    cout<<"Enter your Last Name: ";
    cin>>lastName;
    cout<<"Enter your Id Number: ";
    cin>>idNumber;

    withdrawal=0.00;
    balance=0.00;
    deposit=0.00;
    accountNumber=rand();
    cout<<"---------------------------------"<<endl;
    cout<<"Your account Number is: "<<idNumber<<accountNumber<<endl;
    cout<<"---------------------------------"<<endl;

}
void Bank_rec::show_rec(){
    cout<<"First Name: "<<firstName<<endl;
    cout<<"Last Name: "<<lastName<<endl;
    cout<<"Id Number: "<<idNumber<<endl;
    cout<<"Account Number: "<<idNumber<<accountNumber<<endl;
    cout<<"Withdrawals: "<<withdrawal<<endl;
    cout<<"Balance: "<<balance<<endl;
    cout<<"Deposits: "<<deposit<<endl;
    cout<<"--------------------------------"<<endl;
}


void Bank_rec::write_rec(){
    ofstream offile;
    offile.open("records.txt",ios::binary|ios::app);
    register_account();
    offile.write(reinterpret_cast<char*>(this),sizeof(*this));
    offile.close();
}
void Bank_rec::read_rec(){
    ifstream iffile;
    iffile.open("records.txt",ios::binary);
    if(!iffile)
    {
        cout<<"Error opening file! File Not found"<<endl;
        return;
    }
   while(!iffile.eof())
   {
        if(iffile.read(reinterpret_cast<char*>(this),sizeof(*this))>0){
        show_rec();
    }
   }
    iffile.close();

}

int main()
{
    Bank_rec A;
    int choice;

    while(true)
    {
            cout<<"\n **********KCB KENYA TERMINAL SERVICES*********"<<endl;
    cout<<"Select your desired service"<<endl;
    cout<<"\t1 -->Register for an acount"<<endl;
    cout<<"\t2 -->Exit "<<endl;
    cout<<"\t3 -->Show all records"<<endl;
    cout<<"\n Enter your choice"<<endl;
    cin>>choice;


    switch(choice)
        {
        case 1:
            A.write_rec();
            break;
        case 2:
            exit(0);
            break;
        case 3:
            A.read_rec();
            break;
        default:
            cout<<"You Entered invalid Choice"<<endl;
            exit(0);
        }
    }
    system("pause");
    return 0;
}
