#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>
#include<process.h>


const int Size=5;
int i=0;
int x=Size;
class Bank_Account
{
	static int Count;                   //Static Data member
	int AccNo;
	char Name[20];
	float Balance;

 public:
	Bank_Account()
	{
		AccNo=00;
		strcpy(Name,"N-I-L");
		Balance=00000;
		Count++;
	}

	int getaccno()
	{
		return AccNo;
	}

	int getbalance()
	{
		return Balance;
	}

	void enter()
	{
		cout<<"\n\n\tEnter the AccNo   : ";
		cin>>AccNo;
		cout<<"\tEnter the name    : ";
		gets(Name);
		cout<<"\tEnter the balance : ";
		cin>>Balance;
	}
	void withdraw(float amt)
	{
		Balance=Balance-amt;
	}

	void deposit(float amt)
	{
		Balance=Balance+amt;
	}
	void show()
	{     cout<<'\t'<<setw(7)<<AccNo<<setw(19)<<Name<<setw(11)<<Balance<<endl;
	   /* cout<<AccNo<<'\t'<<name<<"\t\t"<<Balance<<'\t'<<endl;*/
	}
	static void showcount()
	{
	     cout<<Count;
	}
};
int Bank_Account::Count;

void Account_Holder();                                //F u
void Add_account(Bank_Account B[]);                    //  n c
void Display_Account(Bank_Account B[]);                //    t i
void Main_menu(Bank_Account B[]);                                     //      o n
void Admin_top();                                     //
void Admin_menu(Bank_Account B[]);                     //P r o
int Search_Account(Bank_Account B[],int Svalue);       //    t o
void Account_Holder_Top();                            //      t y
void Account_Holder(Bank_Account B[]);                 //        p e

void Add_account(Bank_Account B[])          //
{       int opt;
	clrscr();
	Admin_top();
	for(int i=0;i<Size;i++)
	{         clrscr();
		  B[i].enter();
		  cout<<"\n\n\n\tType |1| to  add another account : ";
		  cin>>opt;
		  if(!(opt==1))
			break;
	}
}

void Display_Account(Bank_Account B[])     //
{       clrscr();
	Admin_top();
	cout<<"\n\n\t\t\tACCOUNT HOLDER LIST\n";
	cout<<"\n\t====================================================\n";
	cout<<"\t| AccNo |"<<"     Name        | "<<"  Balance  |"<<endl;
	cout<<"\t====================================================\n";

	for(i=0;i<x;i++)
	{
		  B[i].show();
		  getch();
	}
	cout<<"\t====================================================\n";
	getch();
}

void Main_menu(Bank_Account B[])              //
{       int opt=0;
	Menu:
	clrscr();
	/*cout<<"#################################################################\n";
	cout<<"#################################################################\n";
	cout<<"(1)	Admin	         \n";
	cout<<"(2)	Account Holder   \n";
	cout<<"(3)	Shut Down	 \n";
	cout<<"#################################################################\n";*/
	cout<<"\n                                            ";
	cout<<"\n        |              C.  S.   B A N K       ";
	cout<<"\n     -  -                          - your money is our responsiblity...    ";
	cout<<"\n        |                                     ";
	cout<<"\n                                          \n";
	cout<<"\n#########################################################################\n";
	cout<<"\n         W e l c o m e            |   Log  in  as                        ";
	cout<<"\n             t o                  | 	(1) Administrator                 ";
	cout<<"\n  O n l i n e    B a n k i n g    |   	(2) Account Holder		  \n\n";
	cout<<"\n#########################################################################\n";
	cout<<"To exit press (3)\n\n";
	cout<<"Choose your option : ";
	cin>>opt;
	if(opt==1)
	{
		Admin_menu(B);
	}
	else if(opt==2)
	{
		Account_Holder(B);
	}
	else if(opt==3)
	{
		exit(0);
	}
	goto Menu;
}

void Admin_top()                            //
{	cout<<"############################################################ADMIN\n";}
void Admin_menu(Bank_Account B[])            //
{
	label:
	clrscr();
	int opt,AccNumber,index=0;
	Admin_top();
	cout<<"#################################################################\n";
	cout<<"(1)	Add account	\n";
	cout<<"(2)	Display account	\n";
	cout<<"(3)	Delete account	\n";
	cout<<"(4)	Update account	\n";
	cout<<"(5)	No.of account	\n";
	cout<<"(6)	Goto Homepage	\n";
	cout<<"(7)	Shut Down	\n";
	cout<<"#################################################################\n";
	cout<<"Choose your Option : ";
	cin>>opt;
	if(opt==1)
	{
		Add_account(B);
		goto label;
	}
	else if((opt==2)||(opt==3)||(opt==4))
	{
		Display_Account(B);
		if(opt==3)
		{
			cout<<"Enter your Account No. : ";
			cin>>AccNumber;
			index=Search_Account(B,AccNumber);
			if(!(index==0))
			{	for(int i=index; i<x; i++)
				{
					 B[i]=B[i+1];

				}
			}
			else if(index==0)
			{
				cout<<"\nERROR!! 404 Not Found"<<endl;
				getch();
			}
		}
		else if(opt==4)
		{
			cout<<"Enter your Account No. : ";
			cin>>AccNumber;
			index=Search_Account(B,AccNumber);
			if(!(index==0))
			{
				B[index].enter();
			}
			else if(index==0)
			{
				cout<<"\nERROR!! 404 Not Found"<<endl;
				getch();
			}
		}
		goto label;
	}


	else if(opt==5)
	{
		cout<<"Total Number of accounts can be created : ";
		Bank_Account::showcount();
		cout<<endl;
		goto label;
	}
	else if(opt==6)
	{
		cout<<"\n\n\tLoading..... ";
		getch();
		Main_menu(B);
	}
	else if(opt==7)
	{
		exit(0);
	}
}

int Search_Account(Bank_Account B[],int Svalue) //
{
	for(int i=0;i<Size;i++)
	{
		int AccNumber1=B[i].getaccno();
		if(Svalue==AccNumber1)
		{
			break;}

	}
	return i;
}
/*int beg=0;
	int index;
	int end=size;
	int mid;
	int flag=0,i=0;
	while((i<size)||(flag))
	{
		mid=(beg+end)/2;
		int AccNumber=B[mid].getaccno();
		if(Svalue==AccNumber)
		{	flag=1;
			index=mid;
		}
		else if(Svalue>AccNumber)
		{	beg=mid;
		}
		else if(Svalue<AccNumber)
		{	end=mid;
		}
		i++;

	}
	return index;*/

void Account_Holder_Top()                    //
{
	cout<<"###################################################ACCOUNT-HOLDER\n";
	}
void Account_Holder(Bank_Account B[])         //
{       int opt=0,index=0,AccNumber;
	int amt;
	clrscr();
	Account_Holder_Top();
	cout<<"#################################################################\n";
	cout<<"(1)	Balance Enquiry \n";
	cout<<"(2)	Withdraw Money  \n";
	cout<<"(3)	Deposit Money	\n";
	cout<<"(4)	Close My Account\n";
	cout<<"(5)	Modify My Account\n";
	cout<<"(6)	Goto Homepage	\n";
	cout<<"(7)	Exit		\n";
	cout<<"#################################################################\n";
	cout<<"Choose your option : ";
	cin>>opt;
	if((opt==1)||(opt==2)||(opt==3)||(opt==4)||(opt==5))
	{
		cout<<"Enter your Account No.";
		cin>>AccNumber;
		index=Search_Account(B,AccNumber);
		if(opt==1)
		{
			cout<<"Your Balance is  $ "<<B[index].getbalance()<<endl;
		}
		else if(opt==2)
		{
			cout<<"Enter the amount to be withdrawl";
			cin>>amt;
			B[index].withdraw(amt);
		}
		else if(opt==3)
		{
			cout<<"Enter the amount to be deposited";
			cin>>amt;
			B[index].deposit(amt);
		}
		else if(opt==4)
		{	if(!(index==0))
			{	for(int i=index; i<x; i++)
				{
					 B[i]=B[i+1];

				}
			}
			else if(index==0)
			{
				cout<<"\nERROR!! 404 Not Found"<<endl;
				getch();
			}
		}
		else if(opt==5)
		{
			if(!(index==0))
			{
				B[index].enter();
			}
			else if(index==0)
			{
				cout<<"\nERROR!! 404 Not Found"<<endl;
				getch();
			}
		}
	}
	else if(opt==6)
	{
		cout<<"\n\n\tLoading..... ";
		getch();
		Main_menu(B);
	}
	else if(opt==7)
	{	exit(0);
	}
}
void main()
{
	clrscr();
	Bank_Account B[Size];
	Display_Account(B);
	getch();
	Main_menu(B);
	getch();

}
