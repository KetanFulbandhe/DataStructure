#include<iostream>
#include<string.h>

using namespace std; 
int top,maxsize;
char s[100];
int stack(int size)
{
	maxsize=size;
	top=-1;
}
void push(char c)
{
	if(top==(maxsize-1))
	{
    	cout<<"Full";
    	return;
	}
	s[++top]=c;
}
 
char pop()
{
    if(top == -1)
    {
        exit(0);
    }
    return s[top--];
}
 
int main()
{
    char str[20];
    int i;
    cout<<"Enter string ";
    cin>>str;
    for(i=0;i<strlen(str);i++)
        push(str[i]);
            
    for(i=0;i<strlen(str);i++)
        str[i]=pop();
            
    cout<<"Reverse String: "<<str;
    return 0;
}
 

