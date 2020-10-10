#include<iostream>
using namespace std; 

 int s[100],tos=-1;

  void push(int e)
  {
    tos++;
    s[tos]=e;
   }
  int pop ()
   {
    return s[tos];
   }
  int  main()
  {
    int num, rem=0,itm,e;
    cout<<"Enter number: ";
	cin>>num;
    while(num>0)
    {
       rem=num%2;
       push(rem);
       num/=2;
    }

    for(int i=tos;tos>-1;tos--)
    {
     itm=pop();
     cout<<itm;
    }
  }
