#include<iostream>
using namespace std;
void QuickSort(int arr[],int start,int End)
{
    int i,j,pivot,t;
    i=start;
    j=End;
    pivot=start;
    while (i<j)
    {
        while (arr[i]<arr[pivot])
            i++;
        while(arr[j]>arr[pivot])
            j--;
        if(i<j)
        {
            t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }       
    }
    if(i<End)
        QuickSort(arr,i+1,End);

    if(start<j)
       QuickSort(arr,start,j-1);
    
}
int main()
{
    int size;
    cout<<"Enter the size of array ";
    cin>>size;
    int arr[size];
    cout<<"Enter Elements: ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Sorted elements are: "<<endl;
    QuickSort(arr,0,size-1);
    for(int k=0;k<size;k++)
        cout<<arr[k]<<" ";
    return 0;
}