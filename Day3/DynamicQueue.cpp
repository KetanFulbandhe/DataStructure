#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
class DynamicQueue
{
    public:
        node *rear,*front;
        void CreateQueue()
        {
            rear=front=NULL;
        }
        void Enqueue(int e)
        {
            node *n,*t;
            n=new node;
            n->data=e;
            n->next=NULL;
            if(rear==NULL)
                rear=front=n;
            else
            {
                rear->next=n;
                rear=n;
            }
        }
        void Dequeue()
        {
            node *t;
            if(front==NULL)
                cout<<"Empty Queue";
            else
            {
                t=front;
                front=front->next;
                cout<<"\nDequeue: "<<t->data;
                delete t;
            }            
        }
        void printQueue()
        {
            node *t;
            if(front==NULL)
                cout<<"Empty"<<endl;
            else
            {
                t=front;
                while (t!=NULL)
                {
                    cout<<" "<<t->data;
                    t=t->next;
                }
            }
        }
};
int main()
{
    DynamicQueue d;
    d.CreateQueue();
    int ch,e;
    cout<<"Enter Choice: "<<endl;
    do
    {
        cout<<"\n1.Enqueue\n2.De-Queue\n3.printQueue\n0.Exit"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter Element :"<<endl;
            cin>>e;
            d.Enqueue(e);
            break;
        case 2:
            d.Dequeue();
            break;
        case 3:
            d.printQueue();
            break;
        case 0:
            cout<<"\nExiting..."<<endl;
            break;
        default:
        cout<<"\nError...";
            break;
        }
    }
    while(ch!=0);
    return 0;
}