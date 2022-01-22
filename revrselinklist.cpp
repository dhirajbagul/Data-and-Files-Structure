
#include <iostream>
#include <cstring>

using namespace std;
int i ;
int flag = 0  ;
class information
{
	public : 
	string name ;
	int id , SSC ;
	information *infonext;
	void getdata();
};

void information :: getdata()
{
	cout << "Enter the Name of Student : ";
	cin  >> name;
	cout << "\nEnter the Reg.ID of Student : ";
	cin  >> id ;
	cout << "\nEnter SSC marks : ";
	cin  >> SSC ;
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
	int reverse() ;
};

void college :: student(information C1)
{
	information *temp,*p;
	temp = new information ;
	temp -> name = C1.name ;
	temp -> id = C1.id ;
	temp -> SSC = C1.SSC ;
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
	
void college :: allstudent()
{
	information *x;
	x= head ;
	if(head == NULL)
	cout <<"No data Present \n";
	else
	while(x->infonext != NULL)
	{
		cout << x -> id <<"\t" ;
		cout << x -> name <<"\n" ;
		x=x->infonext ;
	}	
}

int college :: reverse()
{
	information *temp,*prev,*current;
	temp = head ;
	prev = NULL ;
	current = temp ; 
	while(current->infonext)
	{
		temp = temp -> infonext ;
		current -> infonext  = prev ;
		prev = current ;
		current = temp ;
	}
	head = current ;
	return 0 ;
}

int main()
{
	char a;
	information n1 ;
	college c1 ;
	int enter ;
	do
   	{
   		n1.getdata();
   		c1.student(n1);
   		cout << endl <<"Do you want to add one more student\n" ;
		cin >> a ;
	}
	while(a=='y') ;
	c1.allstudent();
	c1.reverse() ;
	c1.allstudent();
}
