#include <iostream>

using namespace std;
void Sort(int arr[], int pos[], int p[], int n)
{
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

                temp=pos[j];
                pos[j]=pos[j+1];
                pos[j+1]=temp;

                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
int main()
{
    int n, c;
    int profit=0;
    cout<<"Enter number of containers:";
    cin>>n;
    cout<<"Enter total Capacity:";
    cin>>c;

    int W[n], P[n];
    int X[n]={0};
    int pos[n];

    cout << "Enter the weights:" << endl;
    for(int i=0;i<n;i++)
    {
        cin>>W[i];
        pos[i]=i;
    }
    cout << "Enter respective profits:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>P[i];
    }
    Sort(W,pos,P,n);
    for(int i = 0; i < n ; i++){
        if(W[i]<c){
        X[pos[i]] = 1;
        c=c-W[i];
        profit=profit+P[i];
        }
    }
    cout<<"Selected Items: ";
    for(int i = 0; i < n; i++){
        cout<<X[i]<<" ";
    }
    cout<<endl;
    cout<<"Total profit="<<profit;
}
