#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;    
};
class DList
{
    public:
    struct node *root;
    void createDlist()
    {
        root=NULL;
    }
    void insertleft(int e)
    {
        node *n;
        n=new node;
        n->data=e;
        n->left=n->right=NULL;
        if(root==NULL)
            root=n;
        else
        {
            n->right=root;
            root->left=n;
            root=n;
        }
    }
    void deleteleft()
    {
        node *t;
        if(root==NULL)
            cout<<"empty";
        else
        {
            t=root;
            root=root->right;
            root->left=NULL;
            cout<<"Deleted: "<<t->data;
            delete t;
        }
    }
    void insertRight(int e)     //normal insert
    {
        node *n,*t;
        n=new node;
        n->data=e;
        n->left=n->right=NULL;
        if(root==NULL)
            root=n;
        else
        {
            t=root;
            while(t->right!=NULL)
                t=t->right;
            t->right=n;
            n->left=t;
        }
    }
    void deleteRight()
    {
        node *t,*t2;
        if(root==NULL)
            cout<<"Empty"<<endl;
        else
        {
            t=root;
            while (t->right!=NULL)
            {
                t=t->right;
            }
            t2=t->left;
            t2->right=NULL;
            cout<<"deleted"<<t->data;
            delete t;
        }
    }
    
    void RevPrint()
    {
        node *t;
        if(root==NULL)
            cout<<"Empty"<<endl;
        else
        {
            t=root;
            while (t->right!=NULL)
            {
                t=t->right;
            }
            while (t!=NULL)
            {
                cout<<t->data<<" ";
                t=t->left;
            }
        }
    }
};
int main()
{
    DList d;
    d.createDlist();
    cout<<"Enter choice: "<<endl;
    int ch,e;
    do
    {
        cout<<"\n1.insert\n2.insertLeft\n3.deleteleft\n4.deleteRight\n5.ReversePrint\n0.Exit\n";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter element: "<<endl;
            cin>>e;
            d.insertRight(e);
            break;
        case 2:
            cout<<"Enter element: "<<endl;
            cin>>e;
            d.insertleft(e);
            break;
        case 3:
            d.deleteleft();
            break;
        case 4:
            d.deleteRight();
            break;
        case 5:
            d.RevPrint();
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