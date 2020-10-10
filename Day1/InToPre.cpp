#include<iostream>
#include<string.h>
using namespace std;
char s[100];
int maxsize,tos;
void stack(int n)
{
	maxsize=n;
	tos=-1;
}
void push(char e)
{
	tos++;
	s[tos]=e;
	//cout<<s;
}
char pop()
{
	char temp;
	temp=s[tos];
	tos--;
	return temp;
}
int isEmpty()
{
	if(tos==-1)
		return 1;
	else
		return 0;
}
int Preced(char c)
{
	if(c=='+'||c=='-')
		return 1;
	if(c=='*'||c=='/'||c=='%')
		return 2;
	if(c=='^')
		return 3;
	else
		return 0;
}
int main()
{
	char inFx[100],preFx[100],c;
	int pi=0,i;
	cout<<"Enter Infix: ";
	cin>>inFx;
	int k=strlen(inFx);
	//cout<<"infix length"<<k;
	stack(k);
	
	for(int i=k-1;i>=0;i--) //right to left
	{
		c=inFx[i];
		switch(c)
		{
			case ')':
				push(c);
				//cout<<"stack"<<s;
				break;
			
			case '(':
				while(s[tos]!=')')
				{
					preFx[pi]=pop();
					pi++;
				}
				pop();
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				while((Preced(s[tos])>Preced(c)) && (isEmpty()!=1))
				{
					preFx[pi]=pop();
					pi++;
					//cout<<"here"<<strlen(preFx);
				}
				push(c);
				break;
			default:
				preFx[pi]=c;
				pi++;
				break;
		}
	}
	while(isEmpty()!=1)
	{
		preFx[pi]=pop();
		pi++;
		//cout<<strlen(preFx);
	}
	for(int j=strlen(preFx)-1;j>=0;j--)
	{
		cout<<preFx[j];
	}
	//cout<<"Len"<<strlen(preFx);
	
}
