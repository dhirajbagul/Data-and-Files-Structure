*//============================================================================
// Name        : ASSIGMENT-2DFS@324.cpp
// Author      : dhiraj bagul
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================/*

#include <iostream>
#include <cstring>

using namespace std;
int i ;
int flag = 0  ;
class information
{
	char name[30]];
	int id,SSC,HSC,CET;
	information *infonext;
	void getdata();
	float avg();
};

void information :: getdata()
{
	cout << "Enter the Name of Student : ";
	cin  >> name;
	cout << "\nEnter the Reg.ID of Student : ";
	cin  >> id ;
	cout << "\nEnter SSC marks : ";
	cin  >> SSC ;
	cout << "\nEnter HSC marks : ";
	cin  >> HSC ;
	cout << "\nEnter SSC marks : ";
	cin  >> CET;
}

float information :: avg()
{
	return ((SSC+HSC+CET)/3);
}

class college
{
	public:
	information *head;
	college()
	{
		head = NULL;
	}
	void student(information C1);
	void display();
	void allstudent();
};



void college :: student(information C1)
{
	information *temp,*p;
	temp = new information ;
	temp -> name = C1.name ;
	temp -> id = C1.id ;
	temp -> SSC = C1.SSC ;
	temp -> HSC = C1.HSC ;
	temp -> CET = C1.CET ;
	temp -> infonext = NULL ;
	if(head == NULL)
	{
		head = temp ;
	}
	else
	{	
		p=head;
		while(p-> infonext)
		{
			p = p -> infonext ;
		}
		p -> infonext = temp ;
	}
}
	


void college :: display()
{
	information *x;
	x= head ;
	while(x->id != i)
	{
	x=x->infonext ;
	if(x->id == x)
	{
		flag = 1;
	}
	}
	if (flag == 1)
	{
	    cout << x->name << "is alloted to the  branch \n " ;
	}
}


void college :: allstudent()
{
	information *x;
	x= head ;
	if(head == NULL)
	cout <<"No data Present \n";
	else
	while(x->id != i)
	{
		for(int i = 1 ; i < 26 - strlen(x->name) ; i++)
		{
			cout<<" " ;	
		}
		x=x->infonext ;
	}	
}

int main()
{
	char a,b;
	information n1 ;
	college c1,m1,e1 ;
	int enter ;
	do
	{
		cout << "-------------------------------------------------------\n " ;
		cout << " Press 1 to add data of the student \n";
		cout << " Press 2 to search Student in the department \n" ;
		cout << " Press 3 to display  Student data \n" ;
		cout << " Press 4 to display mechanical student data \n" ;
		cout << " Press 5 to display mechanical student data \n" ;
		cout << "-------------------------------------------------------\n " ;
		cin >> i ;
   		switch (enter)
   		{
   		case (1):
    	do
    	{
    		n1.getdata();
    		float x = n1.avg() ;
    		if(x>90)
    		{
    			c1.student(n1);
    		}
    		else if(x>70)
    		{
    			m1.student(n1);
    		}	
    		else if(x>60)
    		{
    			e1.student(n1);
    		}
    		cout << endl <<"Do you want to add one more student\n" ;
    		cin >> a
    	} 
    	while (a=='y');
   		break ;
   		case (2):
    		cout << " \nEnter the id of the student you want to search ";
			cin >> i;
				c1.display();
			if(flag==0)
				m1.display1();
			else if(flag==0)
				e1.display2();
			else
				cout<<"\nThe Student not found \n";
   	    break;
   		case (3):
   			cout << "\n-------------------------------------------------------------------------------------------------------\n" ;
			cout <<   "                                  COMPUTER STUDENT DETAILS                   " ;
			cout << "\n-------------------------------------------------------------------------------------------------------\n" ;
			cout << "   Student ID    " << "-      Student Name      ";
    		c1.allstudent();
    	break;
   		case (4):
    		cout << "\n-------------------------------------------------------------------------------------------------------\n" ;
    		cout <<   "                                  MECHANICAL STUDENT DETAILS                   " ;
    		cout << "\n-------------------------------------------------------------------------------------------------------\n" ;
    		cout << "   Student ID    " << "-      Student Name      ";
    		m1.allstudent();
        	break;
   		case (5):
       		cout << "\n-------------------------------------------------------------------------------------------------------\n" ;
    		cout <<   "                                  ELECTRONICS STUDENT DETAILS                   " ;
    		cout << "\n-------------------------------------------------------------------------------------------------------\n" ;
    		cout << "   Student ID    " << "-      Student Name      ";
       		e1.allstudent();
        break;

   		default  :
    		cout <<"Enter the valid choice \n" ;
   		break ;
   }
}
while (b == 'y');
return 0;
}
