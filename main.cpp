#include <iostream>
#include <fstream>
#include<cstdlib>

using std::fstream;
using std::ofstream;
using std::ifstream;
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
    void add_deposits();
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
    deposit=0.00;
    balance=0.00;
    withdrawal=0.00;


    int choice;
    int idNum=(int)idNumber;
    accountNumber=rand()+10000;
    cout<<"---------------------------------"<<endl;
    cout<<"Your account Number is: "<<accountNumber<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<" Do you Wish to Deposit Any amount ? "<<endl;
    cout<<"\t1-->Yes"<<endl;
    cout<<"\t2--No"<<endl;
    cin>>choice;



    switch(choice)
    {
    case 1:
        cout<<"Enter the Amount To Deposit: ";
        cin>>deposit;
        balance=deposit;
         cout<<"Your new balance is: "<<balance<<endl;
        show_rec();
         cout<<"Dear "<<firstName<<" Thank You for Registering with us\n"<<endl;
       cout<<"_________________________________________________________"<<endl;
        break;
    case 2:
        show_rec();
        cout<<"Dear "<<firstName<<" Thank You for Registering with us\n"<<endl;
       cout<<"_________________________________________________________"<<endl;

        break;
    default:
        exit(0);
    }



}
void Bank_rec::show_rec(){

    cout<<"First Name: "<<firstName<<endl;
    cout<<"Last Name: "<<lastName<<endl;
    cout<<"Id Number: "<<idNumber<<endl;
    cout<<"Account Number: "<<accountNumber<<endl;
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

void Bank_rec::add_deposits(){

    cout<<"Enter amount to Deposit: ";
    cin>>deposit;
    deposit=deposit;
    balance=deposit;
    show_rec();

}
void Bank_rec::deposit_cash(){
    int n;
    fstream iofile;
    iofile.open("records.txt",ios::binary|ios::in);
    if(!iofile)
    {
        cout<<"Error openning file "<<endl;
        return;
    }
    iofile.seekg(0,ios::end);
    int count=iofile.tellg()/sizeof(*this);
    cout<<"Deposits Procedure"<<endl;
    cout<<"___________________________\n\n"<<endl;
    cout<<"Enter your AccountNo: ";
    cin>>n;
    iofile.seekg((n-1)*sizeof(*this));
    iofile.read(reinterpret_cast<char*>(this),sizeof(*this));
    cout<<"Records of Account "<<n<<endl;
    show_rec();
    iofile.close();
    iofile.open("records.txt",ios::out|ios::binary|ios::in);
    iofile.read(reinterpret_cast<char*>(this),sizeof(*this));
    add_deposits();
    iofile.read(reinterpret_cast<char*>(this),sizeof(*this));



}
int main()
{
    Bank_rec A;
    int choice;
    cout<<"\n\t\t\t **********KCB KENYA TERMINAL SERVICES*********"<<endl;
    cout<<"\t ---------------------------------------------------------------------\n\n";
    cout<<"\t\t\tSelect your desired service\n"<<endl;
    while(true)
    {

    cout<<"\t1 -->Register for an acount"<<endl;
    cout<<"\t2 -->Exit "<<endl;
    cout<<"\t3 -->Show all records"<<endl;
    cout<<"\t4 -->Deposit Cash"<<endl;
    cout<<"\t\n Enter your choice"<<endl;
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
        case 4:
            A.deposit_cash();
            break;
        default:
            cout<<"--------------------------------"<<endl;
            cout<<"You Entered invalid Choice!!"<<endl;
            cout<<"--------------------------------"<<endl;

        }
    }
    system("pause");
    return 0;
}
