//============================================================================
// Name        : tree.cpp
// Author      : Dhiraj Bagul
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstring>
using namespace std;
class node
{
public:
    char name[20];
    long long int cno;
    node *left, *right;
};

class phonebook
{
public:
        node *root;
        phonebook(){root = NULL ;}
        void create();
        void insert(node *root,node *temp);
        int display(node *root);
        node search(node *root, char search_name[20]);
        void delete_contact(node *root,char delete_name[20]);
        void update(node *root, char search_name[20]);
};

void phonebook :: create()   
{
	node *temp;
    temp=new node;
    cout<<"Enter the Name:- ";
    cin>>temp->name;
    cout<<"Enter the Mobile Number:- ";
    cin>>temp->cno;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root = temp;
    }
    else
    {
        insert(root,temp);
    }
}

void phonebook :: insert(node *root, node *temp)
{
	if(strcmp(temp->name,root->name)<0)
    {
        if(root->left==NULL)
        {
            root->left=temp;
        }
        else
        {
            insert(root->left,temp);
        }
    }
    else if(strcmp(temp->name,root->name)>0)
    {
        if(root->right==NULL)
        {
        	root->right=temp;
        }
        else
        {
            insert(root->right,temp);
        }
    }
}

int phonebook :: display(node *root)
{
        node *p ;
        p=root ;
        int a ;
        if(root==NULL)
        {
        	return 0 ; 
		}
        else 
		{
			if(p!=NULL)
	        {
	            display(p->left);
	            cout<<p->name<<endl;
	            for(int i =0 ; i<31-strlen(p->name); i++)
	            {
	            	cout << " " ;
				}
	            cout<<p->cno<<endl;
	            display(p->right);
	            return 1 ;
	        } 
	    }
}


int main()
{
    phonebook s;
    int a;
    char h,f,search_name[20];
    do
    {
        cout<<"%-----------------------------------------------------------------%\n" ;
        cout<<"Press 1: To Create New Phonebook"<<endl ;
        cout<<"Press 2: Display All Contacts"<<endl ;
        cout<<"Press 3: To Search Particular Contact"<<endl ;
        cout<<"Press 4: To Update Particular Contact"<<endl ;
        cout<<"Press 5: To Delete Particular Contact"<<endl ;
        cout<<"Press 6: To Exit the Contact list "<<endl ;
        cout<<"Enter Any Choice : ";
        cin>>a ;
        cout<<"\n%-----------------------------------------------------------------%\n" ;
        switch(a)
        {
            case(1):
            	do{
					s.create();
            		cout<<"\nPress 'y' to add another contact ?" ; 
            		cin >> h ; 
            	}while(h=='y');
            	break;
            case(2):
					if(s.display(s.root)==0)
					{
						cout << "Empty PhoneBook , press 1 to add contacts ";
						cout << "Empty phonebook press 1 to create :" ; 
			        	cin  >> a ; 
			        	if(a==1)
			        	{
			        		s.create() ; 
						}
					}
					else
					{
						cout << "------------------------------------------\n" ; 
						cout << "Contact Name              Phone Number \n" ;
						s.display(s.root) ; 
					}
                    break;
            default:
                    cout<<"Invalid choice"<<endl;
                    break;
        }
        cout<<"Press 'y' to continue\n";
        cin>>f;
    }while(f=='y');
    return 0;
}








