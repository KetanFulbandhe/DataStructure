#include<iostream>
#include <math.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

class LinkedList
{
	public:
	node *head,*trav;
	int arr[10],i=-1,res=0,power=0;
	void createLinkedList()
	{
		head=NULL;
	}
	void insertRight(int e)
	{
    	node* n=new node();
    	n->data=e;
    	n->next=NULL;
    	 if(head==NULL)
    	 {
    		head=n;
    	 }else
    	 {
    		 trav=head;
    		 while(trav->next!=NULL)
    			 trav=trav->next;
    		 trav->next=n;
    	 }
	}

void printList()
	{
		node *t;
		if(head==NULL)
		cout<<"Empty List";
		else
		t=head;
		do
		{
		    arr[++i]=t->data;
			t=t->next;
		}
		while(t!=NULL);
			int c=i;
		for(int j=0;j<=i;j++)
		{
		    power=pow(2,c--);
		    res=res+arr[j]*power;
		}
		cout<<"no is : "<<res;
	}
};

int main()
{
	LinkedList cl;
	cl.createLinkedList();
	int c,a;
	do
	{
		cout<<"\n1)insertRight:\n2)printList:\n3)Exit:";
		cin>>c;
		switch(c)
		{
			case 1:
				cout<<"Enter Data:";
				cin>>a;
				cl.insertRight(a);
				break;
	
			case 2:
				cl.printList();
				break;
				
			case 3:
				
				break;
				
			default:
				cout<<"Invalid Input";
		}
	}
	while(c!=0);
}