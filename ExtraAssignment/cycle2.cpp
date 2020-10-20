#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

Node* push(Node *root,int data)
{
    Node* temp=new Node(data);
    if(root==NULL)
    {
        root=temp;
    }
    else{
      Node *t=root;
      while(t->next!=NULL)
      {
        t=t->next;
      }

       t->next=temp;
    }
    return root;
}

Node* rotate(Node* root, int k) {

    if (!root||!root->next||k==0)
    return root;
    Node *t2=root;
    int len = 1;
    while (t2->next)
    {
        len++;             //count the length of LinkedList.
        t2 = t2->next;
    } 
    t2->next = root;     //connect last node to first to make circular.
    k=len-k%len;    //to find actual number of rotation.
    while (k--)
    {
        t2=t2->next;
    }
    root=t2->next;
    t2->next=NULL;
   return root; 
   }

void print(Node* r)
{
   if(r==NULL)
   {
       cout<<"Empty list";

   }
   {
       Node *temp=r;
       while(temp!=NULL)
       {
           cout<<temp->data<<" ";
           temp=temp->next;
       }
   }
}
int main()
{
    Node *root=NULL;
    int n,k;
    cout<<"enter the size of linkedlist and  k :";
    cin>>n>>k;
    cout<<"Enter data: ";
    for(int i=0; i<n; i++)
    {
      int e;
      cin>>e;
      root=push(root,e);
    }
   cout<<"List is: ";
   print(root);
   cout<<"\nrotating...\n"<<endl;
   root=rotate(root,k);
   print(root);
    return 0;
} 