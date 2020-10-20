#include<iostream>
using namespace std;
int size=10,top1=-1,top2=size;
int arr[10];
class twostack
{
    public:
    void push1(int data)
    {
        if(top1==size-1 || top1==top2-1)
            cout<<"Full"<<endl;
        else
        {
            top1++;
            arr[top1]=data;
        }
    }
    void push2(int data)
    {
        if(top2<0|| top2==top1+1)
            cout<<"Full"<<endl;
        else
        {
            top2--;
            arr[top2]=data;
        }  
    }
    int pop1()
    {
        int popele=-1;
        if(top1==-1)
            cout<<"Empty"<<endl;
        else
        {
            popele=arr[top1];
            top1--;
        }
        return popele;
    }
    int pop2()
    {
        int popele2=-1;
        if(top2==size)
            cout<<"Empty"<<endl;
        else
        {
            popele2=arr[top2];
            top2++;
        }
        return popele2;
    }
    void print()
    {
        cout<<"top1 "<<top1<<" "<<"top2 "<<top2<<endl;
    }
};
int main()
{
    twostack ts;
    ts.print();
    ts.pop1();
    ts.pop2();
    ts.push1(1);
    ts.push2(10);
    ts.push1(1);
    ts.push2(10);
    ts.push1(1);
    ts.push2(10);
    ts.push1(1);
    ts.push2(10);
    ts.print();
    ts.push1(1);
    ts.push2(10);

    ts.pop1();
    ts.pop2();
    
}