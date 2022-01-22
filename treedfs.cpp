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
class tree
{
public:
        node *root;
        tree(){root = NULL ;}
        void create();
        void insert(node * root,node *temp);
        void display(node *root);
        void search(node *root, char search_name[20]);
        node* delete_contact(node *root,char delete_name[20]);
        void update(node *root, char search_name[20]);
        node* mininorder(node*);
};
void tree::create()
{
    node *temp;
    temp=new node;
    cout<<"\nEnter the Name:- ";
    cin>>temp->name;
    cout<<"\nEnter the Mobile Number:- ";
    cin>>temp->cno;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        insert(root,temp);
    }
}
void tree::insert(node *root,node *temp)
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
void tree::display(node *root)
{
        node *p;
        p=root;
        if(p!=NULL)
        {
            display(p->left);
            cout<<"\nName of the User :- "<<p->name<<endl;
            cout<<"Mobile NUmber of user :- "<<p->cno<<endl;
            display(p->right);
        }
}
void tree::search(node *root,char search_name[20])
{
    node *k;
    k=root; 
    if(k==NULL)
	{
        cout<<"Empty tree";
    }
    if(strcmp(k->name,search_name)==0){
		cout<<"\nContact no : " << k->cno << endl ;
    }
    else if(strcmp(root->name,search_name)>0)
	{
        if(k->left!=NULL)
		{
            if(strcmp(k->name,search_name)==0)
			{
                cout<<"\nContact no : " << k->cno << endl ;
            }
            else
			{
                search(k->left, search_name);
            }
        }
    }
    else if(strcmp(root->name,search_name)<0)
	{
        if(k->right!=NULL)
		{
            if(strcmp(k->name,search_name)==0)
			{
                cout<<"\nContact no : " << k->cno << endl<<endl ;
            }
            else
			{
                search(k->right,search_name);
        	}
        }
    }
}

void tree::update(node *root,char search_name[20])
{
    node *k;
    k=root ; 
    char new_name[20] ; 
    long long int new_no;
    int ch ; 
    k=root;
    if(k==NULL)
	{
        cout<<"Empty tree";
    }
    if(strcmp(k->name,search_name)==0){	
				cout << "\nEnter New Name : " ;
				cin >> new_no ;
				k->cno = new_no ;
		}
    else if(strcmp(root->name,search_name)>0)
	{
        if(k->left!=NULL)
		{
            if(strcmp(k->name,search_name)==0)
			{
						cout << "\nEnter New Name Number : " ;
						cin >> new_no ;
						k->cno = new_no ;
            }
            else
			{
                update(k->left,search_name) ; 
            }
        }
    }
    else if(strcmp(root->name,search_name)<0)
	{
	        if(strcmp(k->name,search_name)==0)
			{	
				cout << "\nEnter New Phone Number : " ;
				cin >> new_no ;
				k->cno = new_no ;
			}
            }
            else
			{
                update(k->right,search_name) ; 
            }
    }

node* tree :: delete_contact(node *temp,char name[20])
{
if(temp==NULL)
	{
		cout<<"\nName not Found"<<endl;
		return temp;
	}
	else if(strcmp(name,temp->name)<0)
	{
		temp->left=delete_contact(temp->left,name);
		return temp;
	}
	else if(strcmp(name,temp->name)>0)
	{
		temp->right=delete_contact(temp->right,name);
		return temp;
	}
	else
	{
		if(temp->left==NULL && temp->right==NULL)
		{
			node*  p;
			p=temp;
			delete del;
			
			return NULL;
		}
		else if(temp->left==NULL)
		{
			node* p;
			p=temp;
			temp=temp->right;
			delete p;
			cout<<"Contsct is Deleted"<<endl;
			return temp;
		}
		else if(temp->right==NULL)
		{
			node* p;
			p=temp;
			temp=temp->left;
			cout<<p->name<<"Contsct is Deleted"<<endl;
			delete p;
			return temp;
		}
		else
		{
			node* t;
			t=mininorder(temp->right);
			strcpy(temp->name,t->name);
			temp->right=delete_contact(temp->right,t->name);
			return temp;
		}
	}
}
node* tree::mininorder(node* temp)
{
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}

int main()
{
    tree s;
    int a;
    char h,f,search_name[20],del_name[20];
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
					s.display(s.root);
                    break;
            case(3):
				    cout<<"\nEnter the name to be searched";
				    cin>>search_name;
					s.search(s.root, search_name);
                    break;
            case(4):
            		cout<<"\nEnter the name to Update Contact : ";
				    cin>>search_name;
					s.update(s.root, search_name);
                    break;
            case(5):
            		cout << "\nEnter The name to be deleted : " ;
            		cin >> del_name ; 
            		s.delete_contact(s.root,del_name) ;
            		break;
            case(6):
                    break;
            default:
                    cout<<"\nInvalid choice"<<endl;
                    break;
        }
        cout<<"\nPress 'y' to continue: ";
        cin>>f;
    }while(f=='y');
    return 0;
}

