#include <iostream>

using namespace std;
int c=0;
void bubble(int arr[],int n ){
    for(int i=0;i<n-1;i++){
        c++;
        for(int j=0;j<n-i-1;j++){
            c++;
            c++;
            if(arr[j]>arr[j+1]){
                int t=arr[j]; c++;
                arr[j]=arr[j+1]; c++;
                arr[j+1]=t; c++;
            }
        }
        c++;
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
    bubble(arr,n);
    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Total number of steps: "<<c;
    return 0;
}
