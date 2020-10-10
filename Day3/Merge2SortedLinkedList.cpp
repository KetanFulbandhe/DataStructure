#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;    
};
class mergeList
{
public:
    struct node *r1,*r2,*r3;

    void createList()
    {
        r1=r2=r3=NULL;
    }
    node* insert1(int e)
    {
        node *t,*n;
        n=new node;
        n->data=e;
        n->next=NULL;
        if(r1==NULL)
            r1=n;
        else
        {
            t=r1;
            while (t->next!=NULL)
            {
             t=t->next;
            }
            t->next=n;            
        }
        return r1;
    }
    node* insert2(int e)
    {
        node *n,*t;
        n=new node;
        n->data=e;
        n->next=NULL;
        if(r2==NULL)
            r2=n;
        else
        {
            t=r2;
            while (t->next!=NULL)
            {
             t=t->next;
            }
            t->next=n;
        }
        return r2;
    }
    
    void printList()
    {
        node *t;
			if(r3==NULL)
			cout<<"Empty"<<endl;
			else
			{
				t=r3;//1
				while(t!=NULL)
				{
					cout<<" "<<t->data;
					t=t->next;
				}
			}
    }
    void merge(node *r1, node *r2)
    {
        node *n,*last;
        r3=NULL;
        while(r1!=NULL && r2!=NULL)
        {
            n=new node;
            if(r1->data<r2->data)
            {
                n->data=r1->data;
                r1=r1->next;
            }
            else
            {
                n->data=r2->data;
                r2=r2->next;
            }
            n->next=NULL;
            if(r3==NULL)
            {
                r3=last=n;
            }
            else
            {
                last->next=n;
                last=n;
            }
        }
        while(r1!=NULL)
        {
            n=new node;
            n->data=r1->data;
            n->next=NULL;
            r1=r1->next;
            last->next=n;
            last=n;
        }
        while(r2!=NULL)
        {
            n=new node;
            n->data=r2->data;
            n->next=NULL;
            r2=r2->next;
            last->next=n;
            last=n;
        }
        //cout<<r3;
        //return root3;
    }
};
int main()
{
    mergeList L;
    int ch,e,s1,s2;
    node* r3,*r4,*r5;
    L.createList();

    cout<<"Enter choice: "<<endl;
    do
	{
		cout<<"\n1.insert first list\n2.insert second list\n3.merge list\n4.printlist\n0.Exit\n";
        cin>>ch;
		switch(ch)
		{
		case 1:
            cout<<"Enter element: "<<endl;
            cin>>e;
			r3=L.insert1(e);
			break;
		case 2:
            cout<<"Enter element: "<<endl;
            cin>>e;
			r4=L.insert2(e);
			break;
		case 3:
            L.merge(r3,r4);
			break;
		case 4:
            L.printList();
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
