#include <iostream>

using namespace std;
int c=0;
void selection(int arr[],int n ){
    for(int i=0;i<n-1;i++){
        c++;
        int small=i; c++;
        for(int j=i+1;j<n;j++){
            c++;
            c++;
            if(arr[j]<arr[small]){
                c++;
                small=j;
            }
        }
        c++;
        c++;
        if(small!=i){
            int t=arr[i]; c++;
            arr[i]=arr[small]; c++;
            arr[small]=t; c++;
        }
    }
    c++;
}
int main()
{
    int n;
    int arr[20];
    cout<<"Enter number of elements:";cin>>n;
    cout<<"Enter elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selection(arr,n);
    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Total number of steps: "<<c;
    return 0;
}
