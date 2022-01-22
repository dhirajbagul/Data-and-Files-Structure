#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<cstring>
#include<string.h>

class node{
public:
	string name;
	unsigned long long int num;
	string address;
	int days;
	int Bill;
	int OPD_charges;
	node()
	{
		OPD_charges=200;
	}
	node *left,*right;
};

class bst:public node
{
public:
	node *root;
	ofstream F;
	bst(){
		root = NULL;
		F.open("Data.txt");
	}
	node* Insert(node *root,string N,long int mob,string address,int days);
	void visit_inorder(node *n);
	node* getnewnode(string nam,long int mob,string address,int days);
	node* search(node*,string);
	void update(node*,string);
};
node* bst::getnewnode(string nam,long int mob,string address,int days)
{
    node *N=new node;
    N->name=nam;
    N->num=mob;
    N->address=address;
    N->days=days;
    N->left=NULL;
    N->right=NULL;
    return N;
}
node* bst::Insert(node *root,string N,long int mob,string address,int days){
    if(root == NULL){
        root=getnewnode(N,mob,address,days);
        return root;
    }
    else if(N <= root->name){
        root->left=Insert(root->left,N,mob,address,days);
    }
    else{
        root->right=Insert(root->right,N,mob,address,days);
    }
    return root;
}
void bst::visit_inorder(node *n)
{
    if (n==NULL)
        return;
        
    visit_inorder(n->left);
    cout<<"Name :"<<n->name<<endl;
    cout<<"MobileNo.:"<<n->num<<endl;
    cout<<"Address :"<<n->address<<endl;
    cout<<"Stayed days :"<<n->days<<endl;
    cout<<"Bill :"<<n->Bill<<endl;
    F <<" Name :"<<n->name<<endl;
	F <<" MobileNo.: "<<n->num<<endl;
	F <<" Address :"<<n->address<<endl;
	F <<" Stayed Days :"<<n->days<<endl;
	F <<"\n";
    visit_inorder(n->right);
}
node* bst::search(node* n,string nam)
{
        while(n!=NULL)
        {
                if(n->name==nam)
                {
                	cout<<"Name :"<<n->name<<endl;
   					cout<<"MobileNo.:"<<n->num<<endl;
    				cout<<"Address :"<<n->address<<endl;
   					cout<<"No. of Days Stayed in Hospitals:"<<n->days<<endl;	
                    return root;
                }
                else
                {
                        if(nam<=n->name)
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
void bst::update(node* n,string nam)
{
	char ch;
	node* up;
	unsigned long long int mob;
	char addr[50];
	up=search(n,nam);
	   /*if(up==NULL)
       	{
       		//do nothing
		}
		else{*/
       		cout<<"\n\n\tEnter the new mobile no.:";
       		cin>>mob;
       		up->num=mob;
       		cout<<"\n\tMobile number updated Updated"<<endl;
       		cout<<"\nDo you want to update address:";
       		cin>>ch;
       		if(ch=='y')
       		{
       			cout<<"\nEnter the new address:";
       			cin>>addr;
       			up->address=addr;
			   }
       	//}
}
int main(){
    bst tree;
    node *root=NULL;
    string name;
    string addr;
    int days;
    int mob;
    int option;
    int bill;
    do{
    	cout<<"----------------Hospital Management System----------------"<<endl;
    	cout<<"1.Admit Patient"<<endl;
    	cout<<"2.Add to File"<<endl;
    	cout<<"3.Search the patient"<<endl;
    	cout<<"4.Update Patient's info"<<endl;
    	cout<<"5.Discharge the patient"<<endl;
    	cout<<"6.Exit"<<endl;
    	cout<<"Enter the option:";
    	cin>>option;
    	switch(option)
    	{
    		case 1:
    			cout<<"\nPatient's Name: ";
				cin>>name;
				cout<<"\nMobile No.:";
				cin>>mob;
				cout<<"\nAddress :";
				cin>>addr;
				cout<<"\nStayed Days:";
				cin>>days;
				//cout<<"\nBill :"<<root->Bill;
				root=tree.Insert(root,name,mob,addr,days);
				break;
			case 2:
				tree.visit_inorder(root);
				break;
			case 3:
				cout<<"Enter the patient's name:";
				cin>>name;
				tree.search(root,name);
				break;
			case 4:
				cout<<"\nEnter the name of patient:";
				cin>>name;
				tree.update(root,name);
				break;
			case 5:
				break;
		}
	}while(option!=5);
	return 0;
}
