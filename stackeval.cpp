
#include <iostream>
#include<cstring>
#include<string>
#include <cstdio>
using namespace std;
#define max 20

class stack
{
    int top;
public:
    int a[max];


    stack() { 
	     top=-1; 
	}

    void push(int item);
    int pop();
    void display();
    int isfull();
    int isempty();
};



int stack::isempty()
{
        if(top==-1)  return -1;
        return 0;
}


int stack::isfull()
{
        if(top==max-1)  return 1;
        return 0;
}



void stack::push(int item)
{
        if(isfull())    cout<<"Stack is full\n";
        else            a[++top]=item;
}



int stack::pop()
{
        int item;

        if(isempty())   cout<<"Stack is empty\n";
        else            item=a[top--];

        return item;
}



int eval_postfix(char ss[])
{
    stack stc;


        for(int i = 0;i<strlen(ss);i++)
        {

                if(ss[i] == ' ' || ss[i] == ',') continue;

                else if(ss[i] == '+' || ss[i] == '-' || ss[i] == '*' || ss[i] == '/')
                {
                        int operand2 = stc.pop();
                        int operand1 = stc.pop();
                        int result;
                if(ss[i] == '+')        result =operand1 + operand2;
                else if(ss[i] == '-')   result =operand1 - operand2;
                else if(ss[i] == '*')   result =operand1 * operand2;
                else if(ss[i] == '/')   result =operand1 / operand2;
                        stc.push(result);
                }
                else if( isdigit(ss[i]) )
                {
                        int operand = 0;
                        while(i<strlen(ss) && isdigit(ss[i]))
                        {
                                operand = (operand*10) + (ss[i] - '0');
                                i++;
                        }
                        i--;

                        stc.push(operand);
                }
        }
        return stc.pop();

}



int main()
{
        char ss[max];

        cout<<"Enter the expression:\n";
        //cin.getline(, ss);
        gets(ss);
        cout<<"\n After evaluating postfix expresion is :";
        cout<<eval_postfix(ss);
        return 0;
}
