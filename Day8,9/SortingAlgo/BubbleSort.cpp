#include<iostream>
using namespace std;

void BubbleSort(int arr[],int n)
{
    int i,j,t;
    for(int i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
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
    BubbleSort(arr,size);
    for(int k=0;k<size;k++)
        cout<<arr[k]<<" ";
    return 0;
}