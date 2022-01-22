#include <iostream>
#include <cstring>
using namespace std;333
int id=0;
class salesperson
{
	char items_purchased[20];
	char Cus_Name[30];
	char Total_Price[20];
	public:
		void getdata()
		{
			
			cout << "\nEnter Name : \n";
			cin >> Cus_Name ;
			cout << "Enter no. of items Purchased : \n";
			cin >> items_purchased ;
			cout << "Enter Total Price : \n";
			cin >> Total_Price ;
		}
		void display ()
		{
			id++;	
			cout << "        " << id << "              " ;
			cout << Cus_Name ;
			for(int i = 1 ; i < 26 - strlen(Cus_Name); i++)
			{
				cout<<" " ;
			}
			cout << "   "<<items_purchased ;
			for(int i = 1 ; i < 19 - strlen(items_purchased); i++)
			{
				cout<<" " ;
			}
			cout << "      "<< Total_Price << "   \n" ;
		}
};


int main()
{
	int n;
	salesperson customer[10];
	cout << "How many Customers Do you want to Enter ?\n";
	cin >> n;
	cout << "\n--------------------------------------------------------------------------------------------------------" ;
	cout << "\n                                   ENTER THE CUSTOMERS DETAILS             " ;
	cout << "\n--------------------------------------------------------------------------------------------------------\n" ;
	for(int i=0;i<n;i++)
	{
		customer[i].getdata();
	}	
	cout << "\n-------------------------------------------------------------------------------------------------------\n" ;
	cout <<   "                                           CUSTOMERS DETAILS                   " ;
	cout << "\n-------------------------------------------------------------------------------------------------------\n" ;
	
	cout << "   Customer ID   " << "      Customer Name      " << "    Items Purchased   " << "          Grand Total   \n" ;
	for(int i=0;i<n;i++)
	{
		customer[i].display();
	}
	return 0;
	getchar();
}











