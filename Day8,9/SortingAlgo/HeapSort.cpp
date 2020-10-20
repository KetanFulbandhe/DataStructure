#include<iostream>
using namespace std;
void HeapSort(int arr[],int size)
{
    int i,j,pc,done,t;
    for(i=size-1;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            pc=j;
            done=0;
            while(pc>0 && pc/2>=0 && done!=1)
            {
                if(arr[pc/2]<arr[pc])
                {
                    t=arr[pc/2];
                    arr[pc/2]=arr[pc];
                    arr[pc]=t;
                    pc=pc/2;
                }
                else
                    done=1;
            }
        }
        t=arr[i];
        arr[i]=arr[0];
        arr[0]=t;
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
    HeapSort(arr,size);
    for(int k=0;k<size;k++)
        cout<<arr[k]<<" ";
    return 0;
}