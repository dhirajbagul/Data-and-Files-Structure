#include <iostream>
#include <cstring>
using namespace std ;

class info
{
	public :
		int ssc,hsc,cet;
		string name ;
		string id;
		info *infonext;
		void getinfo() ;
		float average() ;
};

void info :: getinfo()
{
	cout << "\nEnter the name of the Student : " ;
	cin  >> name ;
	cout << "\nEnter the 4 digit Enrollment ID : " ;
	cin  >> id ;
	cout << "\nEnter the HSC marks : " ;
	cin  >> hsc ;
	cout << "\nEnter the SSC marks : " ;
	cin  >> ssc ;
	cout << "\nEnter the CET marks : " ;
	cin >> cet ;
}


float info :: average()
{
	return ((hsc+cet+ssc)/3) ;
}

class college
{
	public :
		info *head ;
		college()
		{
			head = NULL ;
		}
		void insertinfo(info n) ;
		int search(string) ;
		void display() ;				
};

void college :: insertinfo(info n)
{
	info *temp , *p ;
	temp = new info ;
	temp->name = n.name ;
	temp->id = n.id ;
	temp->hsc = n.hsc ;
	temp->cet = n.cet ;
	temp->ssc = n.ssc ;
	temp->infonext = NULL ;
	if(head == NULL)
	{
		head = temp ;
	}
	else
	{
		p = head ;
		while(p->infonext)
		{
			p = p->infonext ;
		}
		p->infonext = temp ;
	}
}

void college :: display()
{
	info *p ;
	p = head ;
	if(p == NULL)
	{
		cout << "\nSorry No data is present " ;
	}
	else
	{
		while(p)
		{
			cout << "\n      ";
			cout << p->id ;
			for(int i = 1 ; i < 18 ; i++)
			{
				cout<<" " ;	
			}
			cout << p->name ;
			cout << "\n";
			p = p->infonext ;
		}
	}
}

int college :: search(string it)
{
	info *p ;
	p = head ;
	int flag = 0 ;
	while(p!=NULL)
	{
		if(p->id==it){
			flag=1 ;
			break;
		}
		else
			p = p->infonext ;
	}
	return flag ;
}




int main()
{
	info n1 ;
	college c1 , m1 , e1;
	int a ;
	char b , c ;
	string m;
	do
	{
		cout << "-------------------------------------------------------------------------" ; 
		cout << "\npress 1 for entering student data " ;
		cout << "\npress 2 to display computer student list " ;
		cout << "\npress 3 to display mechanical student list " ;
		cout << "\npress 4 to display entc student list " ;
		cout << "\nPress 5 for searching the student" ;
		cout << "\n-------------------------------------------------------------------------\n" ;
		cin  >> a ;
		switch(a)
		{
			case (1) :
				do
				{
					n1.getinfo() ;
					int x = n1.average() ;
					if(x>90)
    				{		
    					c1.insertinfo(n1);
    				}
    				else if(x>70)
    				{
   			 			m1.insertinfo(n1);
    				}	
    				else if(x>60)
    				{
    					e1.insertinfo(n1);
    				}
					cout << "\npreess 'y' to add another student " ; 
					cin  >> c;
				}
				while(c == 'y') ;
				break ;
			case (2) :
					cout << "\n-------------------------------------------------------------\n" ;
    				cout <<   "                 COMPUTER STUDENT DETAILS                   " ;
    				cout << "\n-------------------------------------------------------------\n" ;
    				cout << "   Student ID    " << "-      Student Name      ";
					c1.display() ;
					break ;	
			case (3) :
					cout << "\n--------------------------------------------------------------\n" ;
    				cout <<   "                 MECHANICAL STUDENT DETAILS                   " ;
    				cout << "\n--------------------------------------------------------------\n" ;
    				cout << "   Student ID    " << "-      Student Name      ";
					m1.display() ;
					break ;	
			case (4) :
					cout << "\n--------------------------------------------------------------\n" ;
    				cout <<   "                 ENTC STUDENT DETAILS                   " ;
    				cout << "\n--------------------------------------------------------------\n" ;
    				cout << "   Student ID    " << "-      Student Name      ";
					e1.display() ;
					break ;	
			case(5) :
				    cout << "\nEnter the ID of the student to search : " ;
				    cin >> m ;
				    if(c1.search(m)==1)
				    	cout << "\nThe student is present in computer branch " ;
					else if(m1.search(m)==1)
				    	cout << "\nThe student is present in mechanical branch " ;
				    else if(e1.search(m)==1)
				    	cout << "\nThe student is present in etx branch " ;
				    break ;
			default :
				cout << "\nPlease Enter the valid choice" ;
				break;
		}
		cout << "\npreess 'y' to go to main menu " ; 
		cin  >> b;	
	} 
	while(b == 'y');
	return 0 ;
}
 /*-------------------------------------------------------------------------
press 1 for entering student data
press 2 to display computer student list
press 3 to display mechanical student list
press 4 to display entc student list
Press 5 for searching the student
-------------------------------------------------------------------------
1

Enter the name of the Student : dhiraj

Enter the 4 digit Enrollment ID : 4564

Enter the HSC marks : 85

Enter the SSC marks : 95

Enter the CET marks : 96

preess 'y' to add another student y

Enter the name of the Student : nikhil

Enter the 4 digit Enrollment ID : 8526

Enter the HSC marks : 85

Enter the SSC marks : 75

Enter the CET marks : 89

preess 'y' to add another student n

preess 'y' to go to main menu y
-------------------------------------------------------------------------
press 1 for entering student data
press 2 to display computer student list
press 3 to display mechanical student list
press 4 to display entc student list
Press 5 for searching the student
-------------------------------------------------------------------------
2

-------------------------------------------------------------
                 COMPUTER STUDENT DETAILS
-------------------------------------------------------------
   Student ID    -      Student Name
      4564                 dhiraj

preess 'y' to go to main menu y
-------------------------------------------------------------------------
press 1 for entering student data
press 2 to display computer student list
press 3 to display mechanical student list
press 4 to display entc student list
Press 5 for searching the student
-------------------------------------------------------------------------
3

--------------------------------------------------------------
                 MECHANICAL STUDENT DETAILS
--------------------------------------------------------------
   Student ID    -      Student Name
      8526                 nikhil


preess 'y' to go to main menu y
-------------------------------------------------------------------------
press 1 for entering student data
press 2 to display computer student list
press 3 to display mechanical student list
press 4 to display entc student list
Press 5 for searching the student
-------------------------------------------------------------------------
1

Enter the name of the Student : shantanu

Enter the 4 digit Enrollment ID : 7852

Enter the HSC marks : 65

Enter the SSC marks : 65

Enter the CET marks : 65

preess 'y' to add another student n

preess 'y' to go to main menu y
-------------------------------------------------------------------------
press 1 for entering student data
press 2 to display computer student list
press 3 to display mechanical student list
press 4 to display entc student list
Press 5 for searching the student
-------------------------------------------------------------------------
4

--------------------------------------------------------------
                 ENTC STUDENT DETAILS
--------------------------------------------------------------
   Student ID    -      Student Name
      7852                 shantanu

preess 'y' to go to main menu y
-------------------------------------------------------------------------
press 1 for entering student data
press 2 to display computer student list
press 3 to display mechanical student list
press 4 to display entc student list
Press 5 for searching the student
-------------------------------------------------------------------------
5

Enter the ID of the student to search : 7852

The student is present in etx branch
preess 'y' to go to main menu

*/











