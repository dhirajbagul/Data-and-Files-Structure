#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
int id=0;
stuct salesperson
{
	char items_purchased[20];
	char Cus_Name[30];
	char Total_Price[20];
	
};


int main(void)
{
	int n;
	salesperson customer[10];
	printf("How many Customers Do you want to Enter ?\n");
	cin >> n;
	printf "\n--------------------------------------------------------------------------------------------------------" ;
	printf("\n                                     ENTER THE CUSTOMERS DETAILS             " ) ;
	printf("\n--------------------------------------------------------------------------------------------------------\n" ;
	for(int i=0;i<n;i++)
	{
		customer[i].getdata();
	}	
	printf( "\n-------------------------------------------------------------------------------------------------------\n" ;
	printf(   "                                           CUSTOMERS DETAILS                  \n" ;
	printf( "\n-------------------------------------------------------------------------------------------------------\n" ;
	
	printf( "   Customer ID          Customer Name           Items Purchased              Grand Total   \n" ;
	for(int i=0;i<n;i++)
	{
		customer[i].display();
	}
	return 0;
	getchar();
}