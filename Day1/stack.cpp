#include<iostream>

using namespace std;
int s[100],maxsize,tos;
int stack(int size)
{
	maxsize=size;
	tos=-1;
}
void push(int e)
{
	tos++;
	s[tos]=e;
}
int isFull()
{
	if(tos==maxsize-1)
		return 1;
	else
		return 0;
}
int pop()
{
	int temp;
	temp=s[tos];
	tos--;
	return (temp);
}
int isEmpty()
{
	if(tos==-1)
		return 1;
	else
		return 0;
}
int atTop()
{
	return s[tos];
}
int printStack()
{
	int i;
	for(i=tos;i>-1;i--)
	{
		cout<<s[i];	
	}
}
int main()
{
	int ch,e,size;
	cout<<"Enter Size: ";
	cin>>size;
	stack(size);
	do
	{
		cout<<"\n1.push\n2.pop\n3.atTop\n4printStack\n0.Exit\n";		
		cin>>ch;
		switch(ch)
		{
		case 1:
			if(isFull()==1)
				cout<<"\n\nFull";
			else
			{
				for(int i=0;i<size;i++)
				{
				cout<<"Enter Data: ";
				cin>>e;
				push(e);
			}
			}
			break;
		case 2:
			if(isEmpty()==1)
				cout<<"\nEmpty\n";
			else
			{
				e=pop();
				cout<<"Poped: "<<e<<"\n\n";
			}
			break;
		case 3:
			if(isEmpty()==1)
				cout<<"\nEmpty\n";
			else
			{
				e=atTop();
				cout<<"\nAt Top "<<e<<"\n\n";
			}
			break;
		case 4:
			if(isEmpty()==1)
				cout<<"\nEmpty\n";
			else
			{
				printStack();
			}
			break;
		case 0:
			cout<<"\nExiting\n";
			break;
		default:
			cout<<"\n\nError";
			break;		
		}
		}while(ch!=0);

	return 0;
}
