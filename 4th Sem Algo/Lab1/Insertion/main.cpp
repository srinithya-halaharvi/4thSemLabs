#include <iostream>

using namespace std;
int c=0;
void insertion(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        c++;
        int key=arr[i]; c++;
        int j=i-1; c++;
        while(j>=0 && arr[j]>key)
        {
            c++;
            arr[j+1]=arr[j];  c++;
            j=j-1; c++;
        }
        c++;
        arr[j+1]=key; c++;
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
    insertion(arr,n);
    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Total number of steps: "<<c;
    return 0;
}
