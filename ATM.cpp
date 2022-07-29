#include <iostream>
#include<conio.h>
#include<string>
using namespace std;
class atm{
private:
    string acc_no;
    string name;
    int pin;
    double balance;
    string mobile_no;
public:
    void setData(string accno,string na,int pi, double bal, string mobil){
        acc_no=accno;
        name=na;
        pin=pi;
        balance=bal;
        mobile_no=mobil;
    }
    string getacc(){
    return acc_no;
    }
    string getnam(){
        return name;
    }
    double getbalance(){
        return balance;
    }
    int getpin(){
        return pin;
    }
    string getmobile(){
        return mobile_no;
    }
    void setmobile(string newm, string oldm){
        if(oldm==mobile_no){
            mobile_no=newm;
            cout<<endl<<"Successfully Updated Mobile number :";
            _getch();

        }else cout<<endl<<"Incorrect Old Mobile number :";
    }
    void cashwithdraw(int amount){
        if(amount>0&&amount<balance){
            balance-=amount;
            cout<<endl<<"Please collect your cash";
            cout<<endl<<"Remaining Balance :"<<balance<<endl;
            _getch();

        }
        else {
            cout<<endl<<"Invalid Input or Insufficient Balance";
            _getch();

        }
    }

    };
int main()
{
   int choice=0,enterpin;
    string enteraccno;
    system(" cls ");
    atm user1;
    user1.setData("12345678","Rajith",111,10000,"12345789");
    do{
        system("cls");
        cout<<endl<<"******WELCONE TO ATM******"<<endl;
        cout<<endl<<"Enter your account number :";
        cin>>enteraccno;
        cout<<endl<<"Enter Pin :";
        cin>>enterpin;
        if(enteraccno==user1.getacc()&&enterpin==user1.getpin()){
            do{
                int amount=0;
                string oldmobile,newmobile;
                system("cls");
                cout<<"Select Otion"<<endl;
                cout<<"1 Get Balance"<<endl;
                cout<<"2 Withdraw Cash"<<endl;
                cout<<"3 Get Details"<<endl;
                cout<<"4 Change Mobile Number"<<endl;
                cout<<"5 Exit"<<endl;
            int cas;
            double ba=user1.getbalance();
            cin>>cas;
            switch(cas){
            case 1:
                cout<<endl<<"Your account balance is :"<<ba<<endl;
                _getch();
                break;
            case 2:
                cout<<"Enter the amount :";
                cin>>amount;
                user1.cashwithdraw(amount);
                _getch();
                break;
            case 3:
                cout<<endl<<"*** User Details are :- ";
                cout<<endl<<"-> Account no "<<user1.getacc();
                cout<<endl<<"-> Name "<<user1.getnam();
                cout<<endl<<"-> Balance "<<user1.getbalance();
                cout<<endl<<"-> Mobile number "<<user1.getmobile();
                _getch();
                break;
            case 4:
                cout<<endl<<"Enter Old number :";
                cin>>oldmobile;
                cout<<endl<<"Enter New number :";
                cin>>newmobile;
                user1.setmobile(newmobile,oldmobile);
                _getch();
                break;
            case 5:
                exit(0);
            default:
                cout<<endl<<"Entered Invalid option";
            }
            }while(1);

        }else{
            cout<<"Invalid Login"<<endl;
            _getch();
        }
    }while(1);
    return 0;
}
