#include <iostream>
using namespace std;
int stack[100],maxSize,tos=-1;
void initStack(int size)
{
    maxSize=size;
    tos=-1;
}
int isFull()
{
    if (tos==maxSize-1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (tos==-1)
        return 1;
    else
        return 0;
}
int getTop()
{
    return stack[tos];
}
void push(int num)
{
    tos++;
    stack[tos]=num;
}
int pop()
{
    int temp=stack[tos];
    tos--;
    return temp;
}
void printStack()
{
    for (int i=tos;i>=0;i--)
    {
        cout<<"|"<<stack[i]<<"|"<< endl;
        cout<<"---\n";
    }
}

int eval(int left,char op,int right)
{
    if (op=='+')
        return left+right;
    else if (op=='-')
        return left-right;
    else if (op=='*')
        return left * right;
    else if (op=='/')
        return left/right;
    else if (op=='%')
        return left%right;
}

int main()
{
    string post;
    char s[100];

    cout<<"Enter postfix for evaluation: "<<endl;
    cin>>post;
    initStack(post.length());
    for (int i=0;i<post.length();i++)
    {
        char read = post[i];
        //cout<<"read="<<read;
        if (read=='+'||read =='-'||read =='*'||read =='/'||read =='%'||read =='^')
        {
            int right=pop();
            int left=pop();
            push(eval(left,read,right));
        }
        else
        {
            push(read-'0');//char to int conversion
        }
    }
    cout<<getTop();
    return 0;
}
//52+41-*  ->i/p