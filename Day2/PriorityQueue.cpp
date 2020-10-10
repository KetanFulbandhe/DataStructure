#include<iostream>
using namespace std;
int Q[100],maxsize,front,rare;

void createQueue(int size)
{
    maxsize=size;
    front=0;
    rare=-1;
}
void Enqueue(int e)
{
    rare++;
    Q[rare]=e;
    for(int i=front;i<rare;i++)
    {
        for(int j=front;j<rare;j++)
        {
            if(Q[j]>Q[j+1])
            {
                int temp=Q[j];
                Q[j]=Q[j+1];
                Q[j+1]=temp;
            }
        }
    }
}
int Dequeue()
{
    int temp;
    temp=Q[front];
    front++;
    return temp;
}
int isFull()
{
    if(rare==maxsize-1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if(front>rare)
        return 1;
    else
        return 0;
}
void printQueue()
{
    int i;
    for(i=front;i<=rare;i++)
        cout<<">"<<Q[i]<<" "<<endl;
}
int main()
{
    int n,ch,e;
    cout<<"Enter size: "<<endl;
    cin>>n;
    createQueue(n);
    
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
/*
for(int i=front;i<rare;i++)
    {
        for(int j=front;j<rare;j++)
        {
            if(Q[j]>Q[j+1])
            {
                int temp=Q[j];
                Q[j]=Q[j+1];
                Q[j+1]=temp;
            }
        }
    }
 */