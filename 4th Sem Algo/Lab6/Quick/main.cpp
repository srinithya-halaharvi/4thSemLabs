#include <iostream>

using namespace std;
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int temp,start=low;
    int end=high;
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    temp=arr[low];
    arr[low]=arr[end];
    arr[end]=temp;
    return end;
}
void qs(int arr[],int low,int high){
    if(low<high){
        int p=partition(arr,low,high);
        qs(arr,low,p-1);
        qs(arr,p+1,high);
    }
}
int main()
{
    int n;
    cout<<"Enter total number of array elements:"; cin>>n;
    int arr[n];
    cout<<"Enter array elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    qs(arr,0,n-1);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
