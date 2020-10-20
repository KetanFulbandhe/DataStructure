#include<iostream>
using namespace std;
int start,End,mid;
int size,key;
int binarySearch(int arr[],int start,int end,int key)
{ 
    if (end>=start) { 
        int mid=start+(end-start)/2; 
        if (arr[mid]==key) 
            return mid; 

        if (arr[mid]>key) 
            return binarySearch(arr,start,mid-1,key); 

        return binarySearch(arr,mid + 1, end, key); 
    }
    return -1; 
} 

int main()
{
    
    cout<<"Enter Size: ";
    cin>>size;
    cout<<"Enter key to be search";
    cin>>key;
    int arr[size];
    cout<<"Enter data in sorted manner: ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    start=arr[0];
    End=arr[size-1];
    int res=binarySearch(arr,0,size-1,key);
    (res==-1)?cout<<"Not found : ":cout<<"Found at: "<<res+1;
    return 0;
}