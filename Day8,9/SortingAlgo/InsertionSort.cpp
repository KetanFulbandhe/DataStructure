#include<iostream>
using namespace std;
void InsertionSort(int arr[],int size)
{
    int i,j,newelement;
    for(i=0;i<size;i++)
    {
        j=i+1,newelement=arr[j];
        while(j>0 && newelement<arr[j-1])
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=newelement;
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
    InsertionSort(arr,size);
    for(int k=0;k<size;k++)
        cout<<arr[k]<<" ";
    return 0;
}