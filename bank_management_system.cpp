/***********************************************************************************************
                                      BANK MANAGEMENT SYSTEM 
***********************************************************************************************/
#include<iostream>
#include<cstdlib>
using namespace std;

class Account
{
    protected:
        string name;
        float amount;
        int acc_number;
        int acc_number2;
    public:
        Account()
        {
            name = "0";
            amount = 0;
            acc_number = 0;
            acc_number = 0;
        }    
        void creat_acc()
        {
            cout<<"Enter your name: ";
            cin>>name;
            get_acc_num();
        } 
        
        //this function generate a random numbers
        void get_acc_num()
        {
            srand(time(NULL));//that function shows that we want a random number
            acc_number = rand();//that function generate a random number
            
            //this random number we use as a account number
            cout<<"Your account number is "<<acc_number<<endl;
        }  
        
        //this function display user account details     
        void get_acc_detail()
        {
            //this condition will be check that a user has account or not 
            /* when user account number is 0,that means user has no 
            account and condition get true */
            if(acc_number == 0)
            {
                cout<<"Get your account detail , first creat your account "<<endl;
                //this return statement return no anything but it terminate the function
                return;
            }
            
            repeat://label
            
            cout<<"Enter your account number:";
            cin>>acc_number2;
            
            if(acc_number == acc_number2) 
            {
                
                cout<<"Name = "<<name<<endl;
                cout<<"Account number = "<<acc_number<<endl;
                cout<<"Total amount = "<<amount<<endl;
            }
            else
            {
                cout<<"You entered wrong account number!"<<endl;
                cout<<"Please enter right account number..."<<endl;
                /*when we enter wrong account number , goto statment jump
                the program execution to the repeat label. Program will be 
                continue from repeat label.*/
                goto repeat;
            }  
        }
};
        
class deposit_withdraw:public Account
{
    private:
        float deposit;
        float withdraw;
    public:
        //this function add deposit amount in the original amount 
        void deposit_amount()
        {
            //this condition will be check that a user has account or not
            /* when user account number is 0,that means user has no 
            account and condition get wrong. */
            if(acc_number != 0)
            {
                cout<<"Enter deposit amount:";
                cin>>deposit;
                amount = amount + deposit;
                cout<<"You successfully deposit amount"<<endl;
            }   
            else
            {
                cout<<"For deposit amount ,creat your account"<<endl;
            }    
        }
        
        //this function subtract withdraw amount from original amount 
        void withdraw_amount()
        {
            //this condition will be check that a user has a account or not
            /* when user account number is 0,that means user has no 
            account and condition get wrong. */
            if(acc_number != 0)
            {
                cout<<"Enter withdraw amount:";
                cin>>withdraw;
                if(withdraw <= amount)
                {
                    amount = amount - withdraw;
                    cout<<"You withdraw amount successfully "<<endl;
                }
                else
                {
                    cout<<"you have no enough money "<<endl;
                }
            }
            else
            {
                cout<<"For withdraw amount , creat your account "<<endl;
                cout<<"And credit some money "<<endl<<endl;
            }    
        }    
};   

int main()
{
    deposit_withdraw acc;
    int n;
    
    cout<<"BANK MANAGEMENT SYSTEM........"<<endl;
    
    //we creat a infinite loop.
    //when user want to terminate program,then program will be terminated 
    while(1)
    {
        cout<<endl;
        cout<<"1. Enter 1 for creat bank account"<<endl; 
        cout<<"2. Enter 2 for get your account data"<<endl;
        cout<<"3. Enter 3 for deposit amount"<<endl;
        cout<<"4. Enter 4 for withdraw amount"<<endl;
        cout<<"5. Enter 5 for exit the program"<<endl;
        cout<<endl<<"Enter your choise:";
        cin>>n;
        
        //when user enter 5 , main function will be return 0 and program will be end
        if(n == 5)
        {
            return 0;
        }
        else if(n == 1)
        {
            acc.creat_acc();
        }
        else if(n == 2)
        {
            acc.get_acc_detail();
        }
        else if(n == 3)
        {
            acc.deposit_amount();
        }
        else if(n == 4)
        {
            acc.withdraw_amount();
        }
        else
        {
            cout<<"Invalid choice "<<endl;
        }               
        
    }                
    
}