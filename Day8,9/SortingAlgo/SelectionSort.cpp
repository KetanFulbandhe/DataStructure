#include<iostream>
using namespace std;
void SelectionSort(int arr[],int size)
{
    int min,pos,i,j;
    for(i=0;i<size;i++)
    {
        min=arr[i];
        pos=i;
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                pos=j;
            }
        }
        arr[pos]=arr[i];
        arr[i]=min;
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
    SelectionSort(arr,size);
    for(int k=0;k<size;k++)
        cout<<arr[k]<<" ";
    return 0;
}