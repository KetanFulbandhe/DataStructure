#include<iostream>
using namespace std;
int size=6, *arr,front,rear;
class myqueue
{
    public:
    myqueue()
    {
        arr=new int[size];
        front=-1;
        rear=-1;
    }
    int isFull()
    {
        if((front==0 && rear==size-1)||(front==rear+1))
            return 1;
        else
            return 0;
        
    }
    int isEmpty()
    {
        if((front==0 && rear==size-1))
            return 1;
        else
            return 0;
    }
    void pushfront(int e)
    {
        if(isFull())
            cout<<"Full\n";
        else
        {
            if(front==-1)
                front=rear=0;
            else if (front==0)
            {
                front=size-1;
            }
            else
                --front;

            arr[front]=e;          
        }
    }
    void pushback(int e)
    {
        if(isFull())
            cout<<"Full";
        else
        {
            if(front==-1)
                front=rear=0;
            else if (rear==size-1)
            {
                rear=0;
            }
            else
            {
                ++rear;
            }
            arr[rear]=e;           
        }
    }
    void popfront()
    {
        if(isEmpty())
            cout<<"empty";
        else
        {
            if(front==rear)
            {
                front=rear=-1;
                cout<<"pop: "<<arr[front];
            }
            else if(front==size-1)
            {
                front=0;
                cout<<"pop: "<<arr[front];
            }
            else
                cout<<"pop: "<<arr[++front];
        }
    }
    void popback()
    {
        if(isEmpty())
            cout<<"Empty";
        else
        {
            if(front==rear)
            {
                front=rear=-1;
                cout<<"pop "<<arr[rear];
            }
            else if (rear==0)
            {
                rear=size-1;
                cout<<"Pop: "<<arr[rear];
            }
            else
                cout<<"Pop: "<<arr[--rear];
        }       
    }
    void Front()
    {
        if(isEmpty())
        {
            cout<<front<<"Empty"<<endl;
        }
        else
        {
            cout<<"Front"<<arr[front];
        }
    }
    void Back()
    {
        if(isEmpty())
        {   
            cout<<"Empty";
        }
        else
        {
           cout<<"Back: "<<arr[rear];
        }
        
    }
};
int main()
{
    myqueue mq;
    int ch,e;
    cout<<"Enter choice:\n";
    do
    {
        cout<<"\n1.pushfront\n2.pushback\n3.popfront\n4.popfront\n5.Front\n6.Back\n0.Exit\n";
        cin>>ch;
        switch (ch)
        {
        case 1:
                cout<<"Enter data:"<<endl;
                cin>>e;
                mq.pushfront(e);
            break;
        case 2:
            
                cout<<"Enter data:"<<endl;
                cin>>e;
                mq.pushback(e);
            break;
        case 3:
            mq.popfront();
            break;
        case 4:
            mq.popback();
            break;
        case 5:
            mq.Front();
            break;
        case 6:
            mq.Back();
            break;
        case 0:
			cout<<"\nExiting\n";
			break;
        default:
            break;
        }

    }while(ch!=0);
    return 0;
}