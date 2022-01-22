#include<iostream>
#include<string>
#include<cstring>
#include<graphics.h>
using namespace std;

class node
{
public:
	string name,contact;
	int Atom;
	node* right,*left;
};
class Dictionary
{
public:
	int total;
	node *root;
	Dictionary()
	{
		total=0;
		root=NULL;
	}
	node* create(string name,string contact);
	void insert();
	node* search(node* root,string key);
	void search2(node* temp,int key);
	void insert_tree(node *root,node *temp);
	void display(node* root);
	void display_node(node* temp);
};
node* Dictionary::create(string name,string contact)
{
	node* temp;
	temp=new node;
	temp->name=name;
	temp->contact=contact;
	cout<<"ENter atomic no.  : ";
	cin>>temp->Atom;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}
void Dictionary::insert()
{	string name,contact;
	cout<<"Enter name        : ";
	cin>>name;
	cout<<"Enter Symbol of element  : ";
	cin>>contact;
	node *temp=create(name,contact);
	if(root==NULL)
	{
		root = temp;
	}
	else
	{
		insert_tree(root,temp);
	}
}
void Dictionary::insert_tree(node *root,node *temp)
{
	if(root->name[0] < temp->name[0])
	{
		if(root->right==NULL)
		{
			root->right=temp;
		}
		else
		{
			insert_tree(root->right,temp);
		}
	}
	else
	{
		if(root->left==NULL)
		{
			root->left=temp;
		}
		else
		{
			insert_tree(root->left,temp);
		}
	}
}
void Dictionary:: display(node* root)
{
	if(root!=NULL)
	{
		display(root->left);
		cout<<"\n\t"<<root->name<<"\t\t"<<root->contact<<"\t\t"<<root->Atom<<endl;
		display(root->right);
	}
}

node* Dictionary :: search(node *root,string key)
{
	if(root->name==key)
	{
		return root;
	}
	else if(root->name > key)
	{
		if(root->left==NULL)
		{
			cout<<"Item not found"<<endl;
			return NULL;
		}
		return search(root->left,key);
	}
	else if(root->name < key)
	{
		if(root->right==NULL)
		{
			cout<<"Item not found"<<endl;
			return NULL;
		}
		return search(root->right,key);
	}
	else if(root->left == NULL && root->right == NULL)
	{
		cout<<"Item not found"<<endl;
		return NULL;
	}
	return NULL;
}
void Dictionary :: display_node(node* root)
{
	if(root!=NULL)
	{
			cout<<"Element found"<<endl<<endl;
			cout<<"\n\t\tAtomic No      : "<<root->Atom<<endl;
			cout<<"\t\tName           : "<<root->name<<endl;
			cout<<"\t\tSymbol         : "<<root->contact<<endl;
	}
}
void Dictionary :: search2(node* root,int key)
{
	if(root!=NULL)
	{
		search2(root->left,key);
		if(root->Atom == key)
		{
			cout<<"\n\t\tAtomic No      : "<<root->Atom<<endl;
			cout<<"\t\tName           : "<<root->name<<endl;
			cout<<"\t\tSymbol         : "<<root->contact<<endl;
		}
		search2(root->right,key);
	}
}
void PT_click()
{
	char* Arr_beg[]={"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar"};
	char* arr_beg[]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18"};
	char* Arr[]={"k","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xn","Cs","Ba","La","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Ti","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fi","Mc","Lv","Ts","Og"};
	char* arr[]={"19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89","104","105","106","107","108","109","110","111","112","113","114","115","116","117","118"};
	char* AR_L[]={"Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu"};
	char* AR_A[]={"Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"};
	char* ar_l[]={"58","59","60","61","62","63","64","65","66","67","68","69","70","71"};
	char* ar_a[]={"90","91","92","93","94","95","96","97","98","99","100","101","102","103"};
	initwindow(1600,1000);
	int i=0;
	setcolor(8);
	outtextxy(450,50,"Welcome to periodic Table");
			setcolor(12);
			
		// First 18 elements
		
	rectangle(10,50,90,110);
	setcolor(8);
	outtextxy(10+55,50+35,Arr_beg[i]);		
			setcolor(6);						
	outtextxy(15,55,arr_beg[i]);
	i++;
	
			setcolor(12);			
	rectangle(10+80*17,50,90+80*17,110);
	setcolor(8);
	outtextxy(15+80*17+50,55+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(15+80*17,55,arr_beg[i]);
	i++;
	
			setcolor(12);		
	rectangle(10,110,90,170);
	setcolor(8);
	outtextxy(15+50,115+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(15,115,arr_beg[i]);
	i++;
	
			setcolor(12);		
	rectangle(90,110,170,170);
	setcolor(8);
	outtextxy(95+50,115+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(95,115,arr_beg[i]);
	i = 10;
	
			setcolor(12);		
	rectangle(10,170,90,230);
	setcolor(8);
	outtextxy(15+50,175+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(15,175,arr_beg[i]);
	i++;
	
			setcolor(12);
	rectangle(90,170,170,230);
	setcolor(8);
	outtextxy(95+50,175+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(95,175,arr_beg[i]);
	i=9;
	
			setcolor(12);
	rectangle(10+80*17,110,90+80*17,170);
	setcolor(8);
	outtextxy(15+80*17+50,115+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(15+80*17,115,arr_beg[i]);
	i=8;
	
			setcolor(12);
	rectangle(10+80*16,110,90+80*16,170);
	setcolor(8);
	outtextxy(15+80*16+50,115+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(15+80*16,115,arr_beg[i]);
	i--;
	
			setcolor(12);
	rectangle(10+80*15,110,90+80*15,170);
	setcolor(8);
	outtextxy(15+80*15+50,115+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(15+80*15,115,arr_beg[i]);
	i--;
	
			setcolor(12);
	rectangle(10+80*14,110,90+80*14,170);
	setcolor(8);
	outtextxy(15+80*14+50,115+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(15+80*14,115,arr_beg[i]);
	i--;
	
			setcolor(12);
	rectangle(10+80*13,110,90+80*13,170);
	setcolor(8);
	outtextxy(15+80*13+50,115+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(15+80*13,115,arr_beg[i]);
	i--;
	
			setcolor(12);
	rectangle(10+80*12,110,90+80*12,170);
	setcolor(8);
	outtextxy(15+80*12+50,115+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(15+80*12,115,arr_beg[i]);
	i=17;
	
			setcolor(12);
	rectangle(10+80*17,170,90+80*17,230);
	setcolor(8);
	outtextxy(15+80*17+50,175+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(15+80*17,175,arr_beg[i]);
	i--;
	
			setcolor(12);
	rectangle(10+80*16,170,90+80*16,230);
	setcolor(8);
	outtextxy(15+80*16+50,175+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(15+80*16,175,arr_beg[i]);
	i--;
	
			setcolor(12);
	rectangle(10+80*15,170,90+80*15,230);
	setcolor(8);
	outtextxy(15+80*15+50,175+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(15+80*15,175,arr_beg[i]);
	i--;
	
			setcolor(12);
	rectangle(10+80*14,170,90+80*14,230);
	setcolor(8);
	outtextxy(15+80*14+50,175+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(15+80*14,175,arr_beg[i]);
	i--;
	
			setcolor(12);
	rectangle(10+80*13,170,90+80*13,230);
	setcolor(8);
	outtextxy(15+80*13+50,175+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(15+80*13,175,arr_beg[i]);
	i--;
	
			setcolor(12);
	rectangle(10+80*12,170,90+80*12,230);
	setcolor(8);
	outtextxy(15+80*12+50,175+30,Arr_beg[i]);
			setcolor(6);
	outtextxy(15+80*12,175,arr_beg[i]);
	
	setcolor(12);
	rectangle(900+50+50,700,980+50+50,770);
	setcolor(8);
	outtextxy(905+50+70,705+20,"EXIT");
	setcolor(12);
	rectangle(350+50+50,700,430+50+50,770);
	setcolor(8);
	outtextxy(355+50+50,705,"Input");
	outtextxy(355+50+50,725,"Name");
	outtextxy(355+50+50,750,"& Search");
	setcolor(12);
	rectangle(150+50+50,700,230+50+50,770);
	setcolor(8);
	outtextxy(155+50+50,705,"Input");
	outtextxy(155+50+50,725,"No. &");
	outtextxy(155+50+50,750,"Search");
	setcolor(12);
	rectangle(650+50+50,700,730+50+50,770);
	setcolor(8);
	outtextxy(655+50+50,720,"Display");
	outtextxy(655+50+50,740,"All");
	int ch;
	int xc,yc;
	xc=10;
	yc=230;
	int at=0;
	for (int rows=0;rows<4;rows++)
	{
		for(int count=0;count<18;count++)
		{
			rectangle(xc,yc,xc+80,yc+60);
			setcolor(6);
			outtextxy(xc+5,yc+5,arr[at]);
			setcolor(8);
			outtextxy(xc+55,yc+35,Arr[at]);
			at++;
			setcolor(12);
			xc=xc+80;
		}
		xc=10;
		yc=yc+60;
    }
    
	xc=170;yc = yc+60;at=0;setcolor(12);
	while(at<14)
	{
			rectangle(xc,yc,xc+80,yc+60);
			setcolor(6);
			outtextxy(xc+5,yc+5,ar_l[at]);
			setcolor(8);
			outtextxy(xc+55,yc+35,AR_L[at]);
			at++;
			setcolor(12);
			xc=xc+80;
	}
	
	xc=170;
	yc = yc+60;
	at=0;
	setcolor(12);
	while(at<14)
	{
			rectangle(xc,yc,xc+80,yc+60);
			setcolor(6);
			outtextxy(xc+5,yc+5,ar_a[at]);
			setcolor(8);
			outtextxy(xc+55,yc+35,AR_A[at]);
			at++;
			xc=xc+80;
			setcolor(12);
	}

}
int main()
{
	cout<<"      Welcome"<<endl;
	Dictionary D;
	string key;
	char* AR_L[]={"Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu"};
	char* AR_A[]={"Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"};
	char* ar_l[]={"58","59","60","61","62","63","64","65","66","67","68","69","70","71"};
	char* ar_a[]={"90","91","92","93","94","95","96","97","98","99","100","101","102","103"};
	int key2=5;
	int ch;
	do
	{
		D.insert();
		cout<<"Enter 1 to insert again"<<endl;
		cin>>ch;	
	}while(ch==1);
	
	PT_click();
	
	int ch2=0;
	do{
	int x=0,y=0;
	while(1)
	{
		if(ismouseclick(WM_LBUTTONDOWN))
	{
		
		getmouseclick(WM_LBUTTONDOWN,x,y);
		clearmouseclick(WM_LBUTTONDOWN);
		outtextxy(650,800,"                             ");
		break;
	}	
	}
	int zx=650;
	int zy=750;	
	if((y>=530 && y<=590) && (x<=1290 && x>=170))
	{
		cout<<"f-block element"<<endl;
		int n=0;
		while(x>=170)
		{
			x=x-80;
			n++;
		}
	//	outtextxy(zx,zy+50,AR_L[n-1]);
	//	outtextxy(zx+25,zy+50,ar_l[n-1]);
	int search_atom = n+57;
	D.search2(D.root,search_atom);
	}
	
	if((y<=650 && y>=590) && (x<=1290 && x>=170))
	{
		cout<<"f-block element"<<endl;
		int n=0;
		while(x>=170)
		{
			x=x-80;
			n++;
		}
	//	outtextxy(zx,zy+50,AR_A[n-1]);
	//	outtextxy(zx+25,zy+50,ar_a[n-1]);
		int search_atom = n+89;
		D.search2(D.root,search_atom);
	}
	if(y<=110 && y>= 50 && x>=10 && x<=90)
	{
		cout<<"s-block element"<<endl;
		int search_atom = 1;
		D.search2(D.root,search_atom);
	}
	if(y<=110 && y>= 50 && x>=1370 && x<=1450)
	{
		cout<<"p-block element"<<endl;
		int search_atom = 2;
		D.search2(D.root,search_atom);
	}
	if(y<=170 && y>= 110 && x>=10 && x<=90)
	{
		cout<<"s-block element"<<endl;
		int search_atom = 3;
		D.search2(D.root,search_atom);
	}
	if(y<=170 && y>= 110 && x>=90 && x<=170)
	{
		cout<<"s-block element"<<endl;
		int search_atom = 4;
		D.search2(D.root,search_atom);
	}
	if(y<=170 && y>= 110 && x>=960 && x<=1050)
	{
		cout<<"p-block element"<<endl;
		int search_atom = 5;
		D.search2(D.root,search_atom);
	}
	if(y<=170 && y>= 110 && x>=1050 && x<=1130)
	{
		cout<<"p-block element"<<endl;
		int search_atom = 6;
		D.search2(D.root,search_atom);
	}
	if(y<=170 && y>= 110 && x>=1130 && x<=1210)
	{
		cout<<"p-block element"<<endl;
		int search_atom = 7;
		D.search2(D.root,search_atom);
	}
	if(y<=170 && y>= 110 && x>=1210 && x<=1290)
	{
		cout<<"p-block element"<<endl;
		int search_atom = 8;
	}
	if(y<=170 && y>= 110 && x>=1290 && x<=1370)
	{
		cout<<"p-block element"<<endl;
		int search_atom = 9;
		D.search2(D.root,search_atom);
	}
	if(y<=170 && y>= 110 && x>=1370 && x<=1450)
	{
		cout<<"p-block element"<<endl;
		int search_atom = 10;
		D.search2(D.root,search_atom);
	}
	if(y<=230 && y>= 170 && x>=10 && x<=90)
	{
		cout<<"s-block element"<<endl;
		int search_atom = 11;
		D.search2(D.root,search_atom);
	}
	if(y<=230 && y>= 170 && x>=90 && x<=170)
	{
		cout<<"s-block element"<<endl;
		int search_atom = 12;
		D.search2(D.root,search_atom);
	}
	if(y<=230 && y>= 170 && x>=960 && x<=1050)
	{
		cout<<"p-block element"<<endl;
		int search_atom = 13;
		D.search2(D.root,search_atom);
	}
	if(y<=230 && y>= 170 && x>=1050 && x<=1130)
	{
		cout<<"p-block element"<<endl;
		int search_atom = 14;
		D.search2(D.root,search_atom);
	}
	if(y<=230 && y>= 170 && x>=1130 && x<=1210)
	{
		cout<<"p-block element"<<endl;
		int search_atom = 15;
		D.search2(D.root,search_atom);
	}
	if(y<=230 && y>= 170 && x>=1210 && x<=1290)
	{
		cout<<"p-block element"<<endl;
		int search_atom = 16;
	}
	if(y<=230 && y>= 170 && x>=1290 && x<=1370)
	{
		cout<<"p-block element"<<endl;
		int search_atom = 17;
		D.search2(D.root,search_atom);
	}
	if(y<=230 && y>= 170 && x>=1370 && x<=1450)
	{
		cout<<"p-block element"<<endl;
		int search_atom = 18;
		D.search2(D.root,search_atom);
	}
	
	if(y<=470 && y>=230 && x<=1450 && x>=10)
	{
		if(x<=190)
		cout<<"s-block element"<<endl;
		if(x>=190 && x<=970)
		cout<<"d-block element"<<endl;
		if(x>=970)
		cout<<"p-block element"<<endl;
		int row=0,column=0;
		while(x>=10)
		{
			row+=1;
			x-=80;
		}
		while(y>=230)
		{
			column+=1;
			y-=60;
		}
		int search_atom = column*18 + row;
		if(search_atom>57)
		{
			search_atom+=14;
		}
		if(search_atom>=90)
		{
			search_atom+=14;
		}
		
	D.search2(D.root,search_atom);
	}
	if((x>=900+50+50 && x<=980+50+50)&&(y>=700 && y<=770))
 	{
		ch2=1;
		outtextxy(zx,zy+50,"Thank You                                             ");
		delay(2000);
//		exit(1);
	}
	if((x>=350+50+50 && x<=430+50+50)&&(y>=700 && y<=800))
 	{
		node* search_add;
		outtextxy(zx,zy+50,"Thank You ..Press Alt + tab                            ");
		cout<<"Enter Element Name"<<endl;
		string search_name;
		cin>>search_name;
		search_add = D.search(D.root,search_name);
  		D.display_node(search_add);
		outtextxy(zx,zy+50,"                                                       ");
  		ch2=0;
	}
	if(x>=650+50+50 && x<=730+50+50 && y<=770  && y>=700 )
	{
		cout<<"                     *** ALL ELEMENTS ***"<<endl;
		D.display(D.root);
	}
	if(x>=150+50+50 && x<=230+50+50 && y<=770  && y>=700 )
	{
		int searchNo;
		cout<<"Enter Atomic No. You Want to search"<<endl;
		cin>>searchNo;
		if(searchNo>=119)
		{
			cout<<"Inappropriate Index"<<endl;
		}
		else
		{
			D.search2(D.root,searchNo);
		}
	}
}while(ch2!=1);
D.display(D.root);
}
/*                        OUTPUT
      Welcome
Enter name        : Hydrogen
Enter Symbol of element  : H
ENter atomic no.  : 1
Enter 1 to insert again
1
Enter name        : Helium
Enter Symbol of element  : He
ENter atomic no.  : 2
Enter 1 to insert again
1
Enter name        : Lithium
Enter Symbol of element  : Li
ENter atomic no.  : 3
Enter 1 to insert again
1
Enter name        : Berellium
Enter Symbol of element  : Be
ENter atomic no.  : 4
Enter 1 to insert again
1
Enter name        : Boron
Enter Symbol of element  : B
ENter atomic no.  : 5
Enter 1 to insert again
1
Enter name        : Carbon
Enter Symbol of element  : C
ENter atomic no.  : 6
Enter 1 to insert again
1
Enter name        : Nitrogen
Enter Symbol of element  : N
ENter atomic no.  : 7
Enter 1 to insert again
1



											// Such like this All 118 elements are needed


Enter name        : Moscovium
Enter Symbol of element  : Mc
ENter atomic no.  : 115
Enter 1 to insert again
1
Enter name        : Livermorium
Enter Symbol of element  : Lv
ENter atomic no.  : 116
Enter 1 to insert again
1
Enter name        : Tennessine
Enter Symbol of element  : Ts
ENter atomic no.  : 117
Enter 1 to insert again
1
Enter name        : Oganesson
Enter Symbol of element  : Og
ENter atomic no.  : 118
Enter 1 to insert again
0
d-block element

                Atomic No      : 29
                Name           : Copper
                Symbol         : Cu
p-block element

                Atomic No      : 7
                Name           : Nitrogen
                Symbol         : N
d-block element

                Atomic No      : 30
                Name           : Zinc
                Symbol         : Zn
d-block element

                Atomic No      : 77
                Name           : Iridium
                Symbol         : Ir
d-block element

                Atomic No      : 79
                Name           : Gold
                Symbol         : Au
s-block element

                Atomic No      : 12
                Name           : Magnesium
                Symbol         : Mg
Enter Atomic No. You Want to search
37

                Atomic No      : 37
                Name           : Rubidium
                Symbol         : Rb
Enter Element Name
Nitrogen
Element found


                Atomic No      : 7
                Name           : Nitrogen
                Symbol         : N
                     *** ALL ELEMENTS ***

        Americium               Am              95

        Acitinium               Ac              89

        Astatine                At              85

        Antimony                Sb              51

        Arsenic         As              33

        Argon           Ar              18

        Aluminium               Al              13

        Bohrium         Bh              107

        Berkelium               Bk              97

        Bismuth         Bi              83

        Barium          Ba              56

        Bormium         Br              35

        Boron           B               5

        Berellium               Be              4

        Copernicium             Cn              112

        Californium             Cf              98

        Curium          Cm              96

        Cerium          Ce              58

        Cesium          Cs              55

        Cadmium         Cd              48

        Copper          Cu              29

        Cobalt          Co              27

        Chromium                CR              24

        Calcium         Ca              20

        Chlorine                Cl              17

        Carbon          C               6

        Darmstadtium            Ds              110

        Dubnium         Db              105

        Dysprosium              Dy              66

        Einstenium              Es              99

        Erbium          Er              68

        Europium                Eu              63

        Flerovium               Fl              114

        Fermium         Fm              100

        Francium                Fr              87

        Florine         F               9

        Gold            Au              79

        Gadolinium              Gd              64

        Germenium               Ge              32

        Gallium         Ga              31

        Halfnium                Hf              72

        Holmium         Ho              67

        Helium          He              2

        Hydrogen                H               1

        Iridium         Ir              77

        Iodine          I               53

        Indium          In              49

        Iron            fe              26

        Kromium         Kr              36

        Livermorium             Lv              116

        Lawrencium              Lr              103

        Lead            Pb              82

        Lutetium                Lu              71

        Lanthanum               La              57

        Lithium         Li              3

        Moscovium               Mc              115

        Maiternium              Mt              109

        Mendelivium             Md              101

        Mercury         Hg              80

        Molybdenum              Mo              42

        Mananese                Mn              25

        Magnesium               Mg              12

        Nihonium                Nh              113

        Nobelium                No              102

        Neptunium               Np              93

        Neodymium               Nd              60

        Niobium         Nb              41

        Nickel          Ni              28

        Neon            Ne              10

        Nitrogen                N               7

        Oganesson               Og              118

        Osmium          Os              76

        Oxygen          O               8

        Plutonium               Pu              94

        Protactinium            Pa              91

        Polonium                Po              84

        Platinum                Pt              78

        Promethium              Pm              61

        Preceodymium            Pr              59

        Palladium               Pd              46

        Potassium               K               19

        Phosphorous             P               15

        Roentgenium             Rg              111

        Rutherfordium           Rf              104

        Radium          Ra              88

        Radon           Rn              86

        Rhenium         Re              75

        Rhodium         Rh              45

        Ruthenium               Ru              44

        Rubidium                Rb              37

        Seaborgium              Sg              106

        Samarium                Sm              62

        Silver          Ag              47

        Strontium               Sr              38

        Selenium                Se              34

        Scandium                Sc              21

        Sulphur         S               16

        Silicon         Si              14

        Sodium          Na              11

        Tennessine              Ts              117

        Thallium                Tl              81

        Tungsten                W               74

        Tantalum                Ta              73

        Thulium         Tm              69

        Terbium         Tb              65

        Tellurium               Te              52

        Tin             Sn              50

        Technetium              Tc              43

        Titanium                TI              22

        Uranium         U               92

        Vanadium                V               23

        Xenon           Xe              54

        Ytterbium               Yb              70

        Yttrium         Y               39

        Zirconium               Zr              40

        Zinc            Zn              30

        hassium         Hs              108
--------------------------------
Process exited after 56.99 seconds with return value 0
Press any key to continue . . .

*/
