/*Name:Nikhil K Kesapure
Block:B3 Batch:B32
Subject:DFS
Practical Assignment 4:PhoneBook Directory*/

#include<iostream>
using namespace std;
#include<cstring>
#include<string.h>
class node
{
	public:
        char name[20];
        unsigned long long int mobileno;
        node *left,*right;
};
class tree:public node
{
	public:
        node *root;
        tree()
        {
            root=NULL;
        }
        void create();
        void insertnode(node*,node*);
        void inorderdisp(node*);
        node* search(node*,char name[20]);
        void update(node*,char name[20]);
        node* deletenode(node*,char name[20]);
        node* mininorder(node*);
};
void tree::create()
{
        node *temp;
        temp=new node;
        cout<<"\n\tEnter the name:";
        cin>>temp->name;
        cout<<"\n\tEnter the mobile no:";
        cin>>temp->mobileno;
        temp->left=NULL;
        temp->right=NULL;
        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            insertnode(root,temp);
        }
}
void tree::insertnode(node* root,node* temp)
{
        if(strcmp(temp->name,root->name)<0)//if temp->name is less than root->name
        {
                if(root->left==NULL)
                {
                    root->left=temp;
                }
                else
                {
                    insertnode(root->left,temp);
                }
        }
        else
        {
                if(strcmp(temp->name,root->name)>0)
                {
                        if(root->right==NULL)
                        {
                                root->right=temp;
                        }
                        else
                        {
                                insertnode(root->right,temp);
                        }
                }
        }
}
void tree::inorderdisp(node *root)
{	
        if(root==NULL)
        {
            return;
        }
        inorderdisp(root->left);
        cout<<"\n";
        cout.width(18);
        cout<<root->name;
        cout.width(23);
        cout<<root->mobileno<<endl;
        inorderdisp(root->right);
}
node* tree::search(node* root,char name[20])
{
        while(root!=NULL)
        {
                if(strcmp(root->name,name)==0)
                {
                		cout<<"\n\tMobile number of user : "<<root->mobileno<<endl;
                        return root;
                }
                else
                {
                        if(strcmp(root->name,name)>0)
                        {
								root=root->left;
                        }
                        else
                        {
                                root=root->right;
                        }
                }

        }
        cout<<"\n\tNo match found"<<endl;
        return NULL;
}
void tree::update(node* root,char name[20])
{
		node* up;
		unsigned long long int mob;
       	up=search(root,name);
       	if(up==NULL)
       	{
       		//print nothing
		   }
		   else{
       		cout<<"\n\n\tEnter the new mobile no.:";
       		cin>>mob;
       		up->mobileno=mob;
       		cout<<"\n\tContact Updated"<<endl;
       	}
}
node* tree::deletenode(node* temp,char name[20])
{
	if(temp==NULL)
	{
		cout<<"\nName not Found"<<endl;
		return temp;
	}
	else if(strcmp(name,temp->name)<0)
	{
		temp->left=deletenode(temp->left,name);
		return temp;
	}
	else if(strcmp(name,temp->name)>0)
	{
		temp->right=deletenode(temp->right,name);
		return temp;
	}
	else
	{
		if(temp->left==NULL && temp->right==NULL)
		{
			node*  del;
			del=temp;
			delete del;
			cout<<"\n\tContact Deleted"<<endl;
			return NULL;
			/*delete temp;
			temp=NULL;
			return temp;*/
		}
		else if(temp->left==NULL)
		{
			node* p;
			p=temp;
			temp=temp->right;
			delete p;
			cout<<"\n\tContact Deleted"<<endl;
			return temp;
		}
		else if(temp->right==NULL)
		{
			node* p;
			p=temp;
			temp=temp->left;
			delete p;
			cout<<"\n\tContact Deleted"<<endl;
			return temp;
		}
		else
		{
			node* t;
			t=mininorder(temp->right);
			strcpy(temp->name,t->name);
			temp->right=deletenode(temp->right,t->name);
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
        tree t;
        int choice;
        char item[20];
        do{
                cout<<"\n-----------PHONEBOOK DIRECTORY---------------\n";
                cout<<"\n\t1.ADD CONTACT";
                cout<<"\n\t2.DISPLAY CONTACTS";
                cout<<"\n\t3.SEARCH CONTACT";
                cout<<"\n\t4.UPDATE CONTACT";
                cout<<"\n\t5.DELETE CONTACT";
                cout<<"\n\t6.EXIT"<<endl;
                cout<<"----------------------------------------------\n";
                cout<<"\n\tEnter the choice:";
                cin>>choice;
                switch(choice)
                {
                case 1:
                        t.create();
                        break;
                case 2:
                		cout<<"\n-------------------CONTACTS----------------------";
                		cout<<"\n";
                		cout.width(23);
                		cout<<" CONTACT NAME ";
                		cout.width(21);
                		cout<<" CONTACT NUMBER ";
                        t.inorderdisp(t.root);
                        break;
                case 3:
                        cout<<"\n\tEnter the name to be search:";
                        cin>>item;
                        t.search(t.root,item);
                        break;
                case 4:
                        cout<<"\n\tEnter the name to update details:";
                        cin>>item;
                        t.update(t.root,item);
                        break;
                case 5:
                    	cout<<"\n\tEnter the name you want to delete:";
                    	cin>>item;
                    	t.deletenode(t.root,item);
                    	break;
                case 6:
                		break;
                default:
                        cout<<"\n\tInvalid choice"<<endl;
                        break;
                }
        }while(choice!=6);
        return 0;
}

