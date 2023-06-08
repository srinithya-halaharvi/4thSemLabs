#include <iostream>

using namespace std;

void merge(int arr[],int barr[],int carr[]){
    cout<<"s"<<endl;
    int i=0,j=0,k=0;
    int b= sizeof(barr)/sizeof(barr[0]);
    int c= sizeof(barr)/sizeof(barr[0]);
    while(i<b && j<c){
        if(barr[i]<=carr[i]){
            arr[k]=barr[i];
            cout<<arr[k]<<" ";
            i++;
        }
        else{
            arr[k]=carr[j];
            j++;
            cout<<arr[k]<<" ";
        }
        k++;
    }
    if(i==b){
        arr[k]=carr[j];
    }
    if(j==c){
        arr[k]=barr[i];
    }
    cout<<arr[k];
    cout<<endl;
}
void mergesort(int arr[],int n){
    if(n>1){
        int larr[(n/2)-1],rarr[(n/2)-1];
        int k=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                larr[i]=arr[i];
            }
            else{
                rarr[k++]=arr[i];
            }
        }
        mergesort(larr,n/2);
        mergesort(rarr,n/2);
        merge(arr,larr,rarr);
        /*for(int i=0;i<(n/2);i++){
            cout<<larr[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<(n/2);i++){
            cout<<rarr[i]<<" ";
        }*/
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
    mergesort(arr,n);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
