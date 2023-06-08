#include <iostream>

using namespace std;
int c=0;
int bsiter(int arr[],int ele,int low,int high){
    while(low<=high){
        c++;
        int mid=(low+high)/2; c++;
        c++;
        if(arr[mid]==ele){
            c++;
            return mid;
        }
        else if(arr[mid]>ele){
            c++;
            high=mid-1; c++;
        }
        else if(arr[mid]<ele){
            low=mid+1; c++;
        }
    }
    c++;
    c++;
    return -1;
}
int bsrecur(int arr[],int ele,int low,int high){
    if(high>=low){
    int mid=(low+high)/2;
    if(arr[mid]==ele){
        return mid;
    }
    else if(arr[mid]<ele){
        bsrecur(arr,ele,mid+1,high);
    }
    else if(arr[mid]>ele){
        bsrecur(arr,ele,low,mid-1);
    }
    }
    else
        return -1;
}
int main()
{
    int n,e,ch,v;
    int arr[20];
    cout<<"No.of elements:";cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter element to be searched:";cin>>e;
    cout<<"Enter to search from iterative-1/recursive-2 method:";cin>>ch;
    switch(ch){
    case 1:
        v=bsiter(arr,e,0,n);
        break;
    case 2:
        v=bsrecur(arr,e,0,n-1);
        break;
    }
    cout<<v<<endl;
    if(v>=0)
        cout<<"Element found at position "<<v<<endl;
    else
        cout<<"Element not found"<<endl;
    cout<<"Total number of steps: "<<c;
    return 0;
}
