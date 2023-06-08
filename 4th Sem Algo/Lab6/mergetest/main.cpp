#include <iostream>

using namespace std;

void merge(int arr[],int l,int r,int mid){
    int nl=mid-l+1;
    int nr=r-mid;
    int larr[nl],rarr[nr];
    for(int i=0;i<nl;i++){
        larr[i]=arr[l+i];
    }
    for(int i=0;i<nr;i++){
        rarr[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<nl && j<nr){
        if(larr[i]<=rarr[i]){
            arr[k]=larr[i];
            i++;
        }
        else{
            arr[k]=rarr[j];
            j++;
        }
        k++;
    }
    while(i<nl){
        arr[k]=larr[i];
        i++;
        k++;
    }
    while(j<nr){
        arr[k]=rarr[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int l,int r){
    int mid;
    if(l<r){
        int mid=(l+(r-1))/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,r,mid);
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
    mergesort(arr,0,n-1);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
