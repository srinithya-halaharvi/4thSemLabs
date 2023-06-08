#include <iostream>

using namespace std;
int count=0;
int search(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        count++;
        count++;
        if(arr[i]==x){
            count++;
            return i;
        }
    }
    count++;
    count++;
    return -1;
}
int main()
{
    int n,ele;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter element to be searched:";
    cin>>ele;
    int ret=search(arr,n,ele);
    if(ret!=-1){
        cout<<"Element found at position: "<<ret<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    cout<<"Total number of steps: "<<count<<endl;
    return 0;
}

