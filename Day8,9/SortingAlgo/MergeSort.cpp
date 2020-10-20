#include<iostream>
#include <stdexcept>
using namespace std;
int size;
void  myMerger(int* ,int ,int ,int);
void MergeSort(int arr[],int start,int End)
{
    int mid;
    if(start<End)
    {
        mid=(start+End)/2;
        MergeSort(arr,start,mid);
        MergeSort(arr,mid+1,End);
        myMerger(arr,start,mid,End);
    }
}
void myMerger(int arr[],int start,int mid,int End)
{
    int i,j,temp[size],ti;
    i=start;
    j=mid+1;
    ti=start;
    while (i<=mid && j<=End)
    {
        if(arr[i]<arr[j])
            temp[ti++]=arr[i++];
        else
            temp[ti++]=arr[j++];
    }
    while (i<=mid)
    {
        temp[ti++]=arr[i++];
    }
    while (j<=End)
    {
        temp[ti++]=arr[j++];
    }    
    for(int k=start;k<=End;k++)
        arr[k]=temp[k];
}
int main()
{
    cout<<"Enter the size of array ";
    cin>>size;
    int arr[size];
    cout<<"Enter Elements: ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Sorted elements are: "<<endl;
    MergeSort(arr,0,size-1);

    for(int k=0;k<size;k++)
        cout<<arr[k]<<" ";
    return 0;
}