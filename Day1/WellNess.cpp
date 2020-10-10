#include<iostream>
#include<string.h>

using namespace std; 
int tos=-1;
char s[100];
void push(char e)
{
	
	tos=tos+1;
	s[tos]=e;
	/*if(top==(size-1))
	{
    	cout<<"Full";
    	return;
	}
	s[++top]=c;*/
}
 
void pop(char o)
{
	if(o=='}')
	{
		if(s[tos]=='{')
			tos=tos-1;
	}
    /*if(top == -1)
    {
        exit(0);
    }
    return s[top--];*/
}
int isEmpty()
{
	if(tos==-1)
		return 1;
	else
		return 0;
}
void printStack()
{
	//char res[50];
	//if(isEmpty()==1)
	if(tos==-1)
		cout<<"\nOK\n";
	else if(s[tos]=='{')
	{
		for(int i=tos;i>-1;i--)
		{
			s[i];
		}
		cout<<"needed }";
	}
	/*if(s[tos]=='}')
		cout<<"Unexpected";*/
}
int main()
{
    char str[50],e,o;
    cout<<"Enter string ";
    cin>>str;
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
    	if(str[i]=='{')
    	{
    		e=str[i];
    		push(e);
		}
		else if(str[i]=='}')
		{
			o=str[i];
			if(isEmpty()==0)
				pop(o);
			else
			{
				cout<<"} unexpected";
				exit(0);
			}	
				
		}
	}
    printStack();
    return 0;
}
 

