#include<iostream>
#include<iomanip>
#define max 100
using namespace std;

class Account
{
   int Acno;
   char Acholders_name[max];
   char Address[max];
   int Contact_No;
   float Amount;
	
   public:
  
      void getdata();
      void showdata();
      int searchdata(int);
      void deposit(int);
      void withdraw(int);
};

void Account :: getdata()
{
   cout<<"\n Reading Record "<<endl;
   cout<<"\n Enter account number : ";
   cin>>Acno;
   cout<<"\n Enter account holder's name : ";
   fflush(stdin);
   gets(Acholders_name);
	
   cout<<"\n Enter address : ";
   fflush(stdin);
   gets(Address);
	
   cout<<"\n Enter contact number : ";
   cin>>Contact_No;
	Amount=0;
}

void Account :: showdata()
{
   cout<<"\n Showing Record "<<endl;
   cout<<"\nAccount Number"<<setw(30)<<"Account Holder's Name"<<setw(20)<<"Address"<<setw(20)<<"Contact Number"<<setw(20)<<"Balance Amount\n";
   cout<<" "<<Acno<<setw(30)<<Acholders_name<<setw(30)<<Address<<setw(20)<<Contact_No<<setw(20)<<"Rs."<<Amount<<endl;
}

int Account :: searchdata(int tempaccno)
{
   if(Acno==tempaccno)
      return 1;
	
   else
      return 0;
}

void Account :: deposit(int tempamt)
{
   Amount=Amount+tempamt;
   cout<<"\n Your current updated account balance in "<<Acno<<" : Rs."<<Amount<<endl;
}

void Account :: withdraw(int tempamt)
{
   if(tempamt > Amount)
   {
      cout<<"\n Insuficient balance \n";
      return;
   } 
	
   Amount=Amount-tempamt;
   cout<<"\n Your current updated account balance in "<<Acno<<" : Rs."<<Amount<<endl;
}

int main()
{
   Account A[100];
   int ch,n;
	
   cout<<"\n Enter number of records : ";
   cin>>n;
	
   do
   {
      cout<<"\n ***** BANK ACCOUNT RECORD ***** \n";
      cout<<"\n 1. Read \n 2. Display \n 3. Deposit \n 4. Withdraw \n 5. Search \n 0. Exit \n";
      cout<<"\n Enter choice : ";
      cin>>ch;
  
      switch(ch)
      {
         case 1:
            for(int i=0; i<n; i++)
               A[i].getdata();
            break;
   
         case 2:
            for(int i=0; i<n; i++)
               A[i].showdata();
            break;
    
         case 3:
            int tempacc,k;
    
            cout<<"\n Enter account number of account you want to search for : ";
            cin>>tempacc;

            for(int i=0; i<n; i++)
            {
               k=A[i].searchdata(tempacc);
     
               if(k==1)
               {
                  int tempamt;
      
                  cout<<"\n Enter amount to be deposited : ";
                  cin>>tempamt;
      
                  A[i].deposit(tempamt);
                  break;
               }
            }

            if(k!=1)
               cout<<"\n Account not found \n";
            
            break;
    
         case 4:
            cout<<"\n Enter account number of account you want to search for : ";
            cin>>tempacc;
    
            for(int i=0; i<n; i++)
            {
               k=A[i].searchdata(tempacc);
     
               if(k==1)
               {
                  int tempamt;
      
                  cout<<"\n Enter amount to be deposited : ";
                  cin>>tempamt;
      
                  A[i].withdraw(tempamt);
                  break;
               }
            }
    
            if(k!=1)
               cout<<"\n Account not found \n";
            break;
   
         case 5:
            cout<<"\n Enter account number of account you want to search for : ";
            cin>>tempacc;
    
            for(int i=0; i<n; i++)
            {
               k=A[i].searchdata(tempacc);
     
               if(k==1)
               {
                  A[i].showdata();
                  break;
               }
            }
    
            if(k!=1)
               cout<<"\n Account not found \n";
            break;
    
         case 0:
            cout<<"\n Exiting...Good Bye...! \n";
            break;
    
         default:
            cout<<"\n Wrong choice \n";
      }
      
   }while(ch!=0);
	
   return 0;
}

