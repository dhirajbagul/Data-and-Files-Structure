#include<iostream>
using namespace std;
#include<cstring>
# define max  50 
#include<math.h>

class stack
{
	int top ;
	public : 
		int stk[max] ;
		stack()
		{
			top = -1 ;
		}
		void push(int);
		int pop();
		int full();
	    int empty();
};

void stack::push(int a)
{
        if(full())    	
			cout<<"Stack is full \n" ;
        else    
		{
        	top ++ ;
			stk[top] = a ;
		}	  
}

int stack :: pop()
{
        int a;
        if(empty())   
			cout<<"Stack is empty\n";
        else            
		{
			a = stk[top--] ;
			return a ;
		}
}

int stack :: full()
{
    if(top == max - 1)  
		return 1;
    return 0;
}

int stack :: empty()
{
    if(top==-1)  
		return -1;
    return 0;
}


int evaluate(string s)
{
    stack s1;
    for(int i = 0 ; i<s.length() ; i++)
    {

        if(s[i] == ' ' || s[i] == ',') 
			continue;
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' )  
        {
            int n1 = s1.pop();
            int n2 = s1.pop();
            int n3;
    		switch ( s[i] )
			{
				case '+' :
					n3 = n2 + n1 ;
					break ;
				case '-' :
					n3 = n2 - n1 ;
					break ;
				case '/' :
					n3 = n2 / n1 ;
					break ;
				case '*' :
					n3 = n2 * n1 ;
					break ;
				case '%' :
					n3 = n2 % n1 ;
					break ;
				case '^' :
					n3 = pow ( n2 , n1 ) ;
					break ;
				default :
					cout << "Unknown operator" ;
					exit ( 1 ) ;
			}
                s1.push(n3);
        }
        else if( isdigit(s[i]) )
        {
            int a = 0;
            while(i < s.length() && isdigit(s[i]))
            {
                a = (a*10) + (s[i] - '0') ;
                i++;
            }
            i-- ;
            s1.push(a);
        }
    }
    return s1.pop() ;
}

int main()
{
	string s;
    cout<<"Enter the  postfix expression: \n";
    getline(cin,s) ; 
    cout<<"Answer of the postfix expresion is : ";
    cout<<evaluate(s);
    return 0;
}
