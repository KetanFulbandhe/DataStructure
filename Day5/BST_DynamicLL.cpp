#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;    
};
class BSTDllist
{
    public:
    struct node *root;

    void createDlist()
    {
        root=NULL;
    }
    void insert(node *r,node *n)
    {
       if(root==NULL)
        {
            root=n;
        }
        else
        {
            if(n->data<r->data)
            {
                if(r->left==NULL)
                    r->left=n;
                else
                {
                    return (insert(r->left,n));
                } 
            }
            else
            {
                if(r->right==NULL)
                    r->right=n;
                else
                {
                    return (insert(r->right,n));
                } 
            }            
        }
    }
    void inorder(node *r)
    {
        if(r!=NULL)
        {
            inorder(r->left);
            cout<<r->data<<" ";
            inorder(r->right);
        }
    }
    void preorder(node *r)
    {
        if(r!=NULL)
        {
            cout<<r->data<<" ";
            preorder(r->left);
            preorder(r->right);
        }
    }
    void postorder(node *r)
    {
        if(r!=NULL)
        {
            postorder(r->left);
            postorder(r->right);
            cout<<r->data<<" ";
        }
    }
    int countnode(node *r, int counter)
    {
        if(r!=NULL)
        {
            countnode(r->right,counter);
            counter++;
            countnode(r->left,counter);
        }
        return (counter);
    }
    
};
int main()
{
    BSTDllist bstD;
    int no,i,rec;
    bstD.createDlist();
    cout<<"Enter number of nodes : ";
    cin>>no;
    cout<<"Enter node data: "<<endl;
    for (i=0;i<no;i++)
    {
        cin>>rec;
        node *n;
        n=new node;
        n->data=rec;
        n->right=n->left=NULL;
        bstD.insert(bstD.root,n);
    }
    cout<<"Inorder: ";
    bstD.inorder(bstD.root);
    cout<<"\npreorder: ";
    bstD.preorder(bstD.root);
    cout<<"\npostorder: ";
    bstD.postorder(bstD.root);
    cout<<"\nTotal no of nodes: "<<bstD.countnode(bstD.root,no)-1;
    return 0;
}
