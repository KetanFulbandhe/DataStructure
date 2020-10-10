#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;    
};
class LinkedList
{
public:
    struct node *root;

    void createLinkedList()
    {
        root=NULL;
    }
    void insertLeft(int e)
    {
        node *n;
        n=new node;
        n->data=e;
        n->next=NULL;
        if(root==NULL)
            root=n;
        else
        {
            n->next=root;//1
            root=n;//2
        }
    }
    void insertRight(int e)
    {
        node *n,*t;
        n=new node;
        n->data=e;
        n->next=NULL;
        if(root==NULL)
            root=n;
        else
        {
            t=root;//1
            while (t->next!=NULL)  //2 
            t=t->next;
            t->next=n;//3
        }
    }
    void deleteLeft()
    {
        node *t;
        if(root==NULL)
        {
            cout<<"List Empty";
        }
        else
        {
            t=root;//1
            root=root->next;//2
            cout<<"\nDeleted"<<t->data;
            delete t;//3
        }
        
    }
    void deleteRight()
    {
        node *t,*t2;
        if(root==NULL)
            cout<<"List Empty"<<endl;
        else
        {
            t=t2=root;//1
            while (t->next!=NULL)//2
            {
                t2=t;
                t=t->next;
            }
            t2->next=NULL;//3
            cout<<"Delete "<<t->data<<endl;
            delete t;//4
        }
    }
    void printList()
    {
        node *t;
			if(root==NULL)
			cout<<"Empty"<<endl;
			else
			{
				t=root;//1
				while(t!=NULL)
				{
					cout<<"\n"<<t->data;
					t=t->next;
				}
			}
    }
    int search(int key)
		{
			node *t;
			if(root==NULL)
			{
		 	cout<<"list empty";
		 	return -1;
			}
		 	else
		 	{
		 		t=root; //1
		 		while(t != NULL)
		 		{
		 			if(t->data==key)
		 			{
		 				cout<<"\nfound :" <<key;
		 			return 1;
		 			}
		 			t=t->next;
				 }
				cout<<"\n not found";
		 		return 0;
			 }
			
		}
    void DeleteElement(int key)
    {
        node *t,*t2;
        if(root==NULL)
            cout<<"Empty List";
        else
        {
            t=t2=root;
            while (t!=NULL && t->data!=key)
            {
                t2=t;
                t=t->next;
            }
            if(t!=NULL)
            {
                if(t==root)
                    root=root->next;
                else if (t->next==NULL)
                    t2->next=NULL;
                else
                {
                    t2->next=t->next;
                }
                cout<<"Deleted: "<<t->data;
                delete t;               
            }
            else
            {
                cout<<"Not Found";
            }
        }
    }
};
int main()
{
    LinkedList L1;
    int ch,e;
    L1.createLinkedList();
    cout<<"Enter choice: "<<endl;
    do
	{
		cout<<"\n1.insert\n2.insertRight\n3.deleteLeft\n4.deleteRight\n5.printList\n6.search\n7.DeleteSpecific\n0.Exit\n";
        cin>>ch;
		switch(ch)
		{
		case 1:
            cout<<"Enter element: "<<endl;
            cin>>e;
			L1.insertLeft(e);
			break;
		case 2:
            cout<<"Enter element: "<<endl;
            cin>>e;
			L1.insertRight(e);
			break;
		case 3:
            L1.deleteLeft();
			break;
		case 4:
            L1.deleteRight();
			break;
        case 5:
            L1.printList();
			break;
        case 6:
        	cout<<"Enter element to search: "<<endl;
            cin>>e;
            L1.search(e);
			break;
        case 7:
        cout<<"Enter element to Delete: "<<endl;
            cin>>e;
            L1.DeleteElement(e);
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
