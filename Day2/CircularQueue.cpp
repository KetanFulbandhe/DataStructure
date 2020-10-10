#include<iostream>
using namespace std;
int Q[100],front,rare,maxsize,counter;

void CreateQueue(int size)
{
    maxsize=size;
    front=0;
    rare=-1;
    counter=0;
}
void Enqueue(int e)
{
    rare=(rare+1)%maxsize;
    counter++;
    Q[rare]=e;
}
int Dequeue()
{
    int temp;
    counter--;
    temp=Q[front];
    front=(front+1)%maxsize;
    return temp;
}
int isFull()
{
    if(counter==maxsize)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if(counter==0)
        return 1;
    else
        return 0;
}
void printQueue()
{
    int c,i;
    i=front;
    c=0;
    while(c<counter)
    {
        cout<<Q[i]<<" "<<endl;
        i=(i+1)%maxsize;
        c=c+1;
    }
}
int main()
{
    int n,ch,e;
    cout<<"Enter size: "<<endl;
    cin>>n;
    CreateQueue(n);
    
    do
	{
		cout<<"\n1.Enqueue\n2.Dequeue\n3.printQueue\n0.Exit\n";		
		cin>>ch;
		switch(ch)
		{
		case 1:
			if(isFull()==1)
				cout<<"\n\nFull";
			else
			{
				for(int i=0;i<n;i++)
				{
				cout<<"Enter Data: ";
				cin>>e;
				Enqueue(e);
				}
			}
			break;
		case 2:
			if(isEmpty()==1)
				cout<<"\nEmpty\n";
			else
			{
				e=Dequeue();
				cout<<"Dequeue: "<<e<<"\n\n";
                n=n-(n-1);
			}
			break;
		case 3:
			if(isEmpty()==1)
				cout<<"\nEmpty\n";
			else
			{
				printQueue();
			}
			break;
		case 0:
			cout<<"\nExiting...\n";
			break;
		default:
			cout<<"\n\nError";
			break;		
		}
		}while(ch!=0);
    return 0;
}