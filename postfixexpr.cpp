#include<iostream>
using namespace std;
#include<cstring>
# define max  50 
#include<math.h>

class stack
{
	public:
		int stk[max] ;
		int top ;
	public : 
		stack()
		{
			top = -1 ;
		}
		void push(int);
		int pop();
};

void stack :: push(int a)
{
	top++ ;
	stk[top] = a ;
}

int stack :: pop()
{
	int b = stk[top--] ;
	return b ;
}

int evaluate(char s)
{
	stack s1 ; 
	int n1 , n2 , n3 ;
	char ch ; 
	int a = 0 ;
	int i = 0 ;
	while(s[i])
	{
		if(s[i] == ' ' || ch == '\t' || ch == '\n' || ch == ',' )
		{
			continue ;
		}
		else if(isdigit(ch))
		{
			int b ;
			while(i < s.length() && isdigit(s[i]))
			{
				ch = s[i] ;
				if(isdigit(ch))
				{
					b = b - '0' ;
					a = a*10 + b ;
				}
				i++ ;
			}
			i--;
			s1.push(a);
		}
		else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
				n1 = s1.pop( ) ;
				n2 = s1.pop( ) ;
				switch ( ch )
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
					case '$' :
						n3 = pow ( n2 , n1 ) ;
						break ;
					default :
						cout << "Unknown operator" ;
						exit ( 1 ) ;
				}
				s1.push ( n3 ) ;
		}
		i++ ;
	}
	return ( s1.pop() ) ;
}
	
int main()
{
	char s[max] ; 
	cout<< "\nEnter the Postix expression to evaluate : \n" ;
	gets(s)
	cout << "\nThe Evaluation of the given postfix expression is : " ;
	cout << evaluate(s) ;
	return 0 ;	
}












 
 
