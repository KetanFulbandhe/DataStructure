#include<iostream>
using namespace std;
int sequentialSearch(int arr[],int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if(key==arr[i])
            return i;
    }
    return -1;
}
int main()
{
    int key,size;
    cout<<"enter size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the element: "<<endl;
    for(int i=0;i<size;i++)
        cin>>arr[i];
    cout<<"Enter key to be search: "<<endl;
    cin>>key;
    int res=sequentialSearch(arr,size,key);
    
    (res>=0)?cout<<"found at: "<<res+1:cout<<"Not Found";

    return 0;
}