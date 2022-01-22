#include <iostream>
using namespace std ;

class temp_city
{
	private:
		int temp[7] ;
		string city ;
		float sum   ;
		int max ;
		int min ;
	public:
		void getdata() ;
		void averagetemp() ;
		void tempmax() ;
		void tempmin() ;
		void globe_city() ;		
};

void temp_city :: getdata()
{
	cout << "\n--------------------------------------------------------" ;
	cout << "\n             Enter the Name of the city                 " ;
	cout << "\n--------------------------------------------------------\n" ;
	cin >> city ;
	for(int i=0 ; i<7 ; i++)
	{
		cout << "\nEnter the temperature of day : " <<i+1 << " " ;
		cin >>  temp[i] ;
	    sum = sum + temp[i] ;
	    if(max < temp[i])
	    {
			max = temp[i] ;
		}
		if(min > temp[i] )
		{
			min = temp[i] ;
		}
	}
	cout <<"\n" ;
	
}

void temp_city :: averagetemp()
{
	cout << "\n\nThe average temperature of the week for " << city << "is : " ;
	cout << sum/7 ;	
}


void temp_city :: tempmax()
{
	cout << "\n\nThe maximum temperature of the week for " << city << "is : " ;
	cout << max ;
}
		


void temp_city :: tempmin()
{
	cout << "\n\nThe minimum temperature of the week for " << city << "is : " ;
	cout << min ;
}		

void temp_city :: globe_city()
{
	if(sum/7 > 38)
	{
		cout << city <<" Average temp = " << sum/7 <<"\n";
	}
}
			
int main()
{
	int a ;
	char ch; 
	temp_city city[5] ;
	for(int i=0 ; i<5 ; i++)
	{
		city[i].getdata() ;
	} 
	do
	{
    cout << "\n--------------------------------------------------------" ; 
	cout << "\nPress 1 for getting average temperature of the week " ;
	cout << "\nPress 2 for getting maximum temperature of the week " ;
	cout << "\nPress 3 for getting minimum temperature of the week " ;
	cout << "\nPress 4 Cities with average temprature more than 38 degrees " ;
	cout << "\n--------------------------------------------------------\n" ;
	cin >>  a ;
	
	switch(a)
	{
		case 1:
			
		for(int i=0 ; i<5 ; i++)
		{
			city[i].averagetemp() ; 
		}
	break;
	case 2:

		for(int i=0 ; i<5 ; i++)
		{
			city[i].tempmax() ;
		}
	break;
	case 3:
		
	
		for(int i=0 ; i<5 ; i++)
		{
			city[i].tempmin() ;
		}
	break;
	case 4:
	cout << "\n----------------------------------------------------" ;
	cout << "\nCities with average temprature more than 38 degrees " ;
	cout << "\n----------------------------------------------------" ;
	for(int i=0 ; i<5 ; i++)
		{
			city[i].globe_city();
		}
		break;
		
		default:
			cout<<"wrong choice!!";
		}
	cout<< "\n\ndo you want to add more data\n" ;
	cin >> ch ;
    }
	while(ch=='y') ;
	return 0 ;
	getchar();
}



/*--------------------------------------------------------------------------------------------------------------------------------------------/* 
															OUTPUT
--------------------------------------------------------
             Enter the Name of the city
--------------------------------------------------------
nasik

Enter the temperature of day : 1 34

Enter the temperature of day : 2 45

Enter the temperature of day : 3 36

Enter the temperature of day : 4 38

Enter the temperature of day : 5 39

Enter the temperature of day : 6 40

Enter the temperature of day : 7 41


--------------------------------------------------------
             Enter the Name of the city
--------------------------------------------------------
pune

Enter the temperature of day : 1 32

Enter the temperature of day : 2 34

Enter the temperature of day : 3 33

Enter the temperature of day : 4 35

Enter the temperature of day : 5 36

Enter the temperature of day : 6 37

Enter the temperature of day : 7 38


--------------------------------------------------------
             Enter the Name of the city
--------------------------------------------------------
mumbai

Enter the temperature of day : 1 32

Enter the temperature of day : 2 33

Enter the temperature of day : 3 34

Enter the temperature of day : 4 35

Enter the temperature of day : 5 36

Enter the temperature of day : 6 37

Enter the temperature of day : 7 35


--------------------------------------------------------
             Enter the Name of the city
--------------------------------------------------------
nagpur

Enter the temperature of day : 1 32

Enter the temperature of day : 2 34

Enter the temperature of day : 3 43

Enter the temperature of day : 4 43

Enter the temperature of day : 5 45

Enter the temperature of day : 6 47

Enter the temperature of day : 7 42


--------------------------------------------------------
             Enter the Name of the city
--------------------------------------------------------
aurangabad

Enter the temperature of day : 1 36

Enter the temperature of day : 2 383

Enter the temperature of day : 3 37

Enter the temperature of day : 4 34

Enter the temperature of day : 5 36

Enter the temperature of day : 6 41

Enter the temperature of day : 7 43


--------------------------------------------------------
Press 1 for getting average temperature of the week
Press 2 for getting maximum temperature of the week
Press 3 for getting minimum temperature of the week
Press 4 Cities with average temprature more than 38 degrees
--------------------------------------------------------
1


The average temperature of the week for nasikis : 39

The average temperature of the week for puneis : 35

The average temperature of the week for mumbaiis : 34.5714

The average temperature of the week for nagpuris : 40.8571

The average temperature of the week for aurangabadis : 87.1429

do you want to add more data
y

--------------------------------------------------------
Press 1 for getting average temperature of the week
Press 2 for getting maximum temperature of the week
Press 3 for getting minimum temperature of the week
Press 4 Cities with average temprature more than 38 degrees
--------------------------------------------------------
2


The maximum temperature of the week for nasikis : 45

The maximum temperature of the week for puneis : 38

The maximum temperature of the week for mumbaiis : 37

The maximum temperature of the week for nagpuris : 47

The maximum temperature of the week for aurangabadis : 383

do you want to add more data
y

--------------------------------------------------------
Press 1 for getting average temperature of the week
Press 2 for getting maximum temperature of the week
Press 3 for getting minimum temperature of the week
Press 4 Cities with average temprature more than 38 degrees
--------------------------------------------------------
3


The minimum temperature of the week for nasikis : 32

The minimum temperature of the week for puneis : 32

The minimum temperature of the week for mumbaiis : 0

The minimum temperature of the week for nagpuris : 1

The minimum temperature of the week for aurangabadis : 34

do you want to add more data
y

--------------------------------------------------------
Press 1 for getting average temperature of the week
Press 2 for getting maximum temperature of the week
Press 3 for getting minimum temperature of the week
Press 4 Cities with average temprature more than 38 degrees
--------------------------------------------------------
4

----------------------------------------------------
Cities with average temprature more than 38 degrees
----------------------------------------------------
nasik Average temp = 39
nagpur Average temp = 40.8571
aurangabad Average temp = 87.1429


do you want to add more data
/*
/*--------------------------------------------------------------------------------------------------------------------------------------------*/ 
