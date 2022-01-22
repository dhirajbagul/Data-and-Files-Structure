#include<iostream>
using namespace std;
#include<string>
const int max = 50 ;
#include<math.h>
#include<stdlib.h>
class stack
{
	int stk[max] ;
	int top ;
	public :
		int nn ; 
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
	int b = stk[top] ;
	top -- ;
	return b ;
}

int evaluate(char *max)
{
	stack stk1 ; 
	char *ch ;
	ch = max ;
	int n1,n2,n3,i = 0 ; 
	int a ;
	while (*ch)
	{
		if ( *ch == ' ' || *ch == '\t' )
		{
			ch++ ;
			continue ;
		}
		if ( isdigit ( *ch ) )
		{
			stk.nn = *ch - '0' ;
			stk.push ( stk.nn ) ;
		}
		else
		{
			n1 = pop( ) ;
			n2 = pop( ) ;
			switch ( *ch )
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
 
			stk.push ( n3 ) ;
		}
		s++ ;
	}
}

int main()
{
	char exp[max] ;

	cout<< "\nEnter the Postix expression to evaluate : \n" ;
	cin.getline ( expr, max ) ;
	
	cout << "\nThe Evaluation of the given postfix expression is : " ;
	cout << evaluate(expr) ;
	return 0 ;	
}
