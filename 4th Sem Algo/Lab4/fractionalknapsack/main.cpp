#include <iostream>

using namespace std;

void descsort(float arr[], int W[], int P[], int n)
{
    int i,j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j] < arr[j+1]){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;

                t=W[j];
                W[j]=W[j+1];
                W[j+1]=t;

                t=P[j];
                P[j]=P[j+1];
                P[j+1]=t;
            }
        }
    }
}
int main()
{
    int n,c,i;
    float profit=0;
    cout << "Enter number of containers: " << endl;
    cin >> n;
    cout << "Enter total Capacity: " << endl;
    cin >> c;

    int W[n], P[n];
    int X[n] = {0};
    float pw[n];
    cout << "Enter the weights:" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> W[i];
        //pos[i] = i;
    }
    cout << "Enter respective profits:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin >> P[i];
        float t= P[i]/W[i];
        pw[i]=t;
    }
    descsort(pw,W,P,n);
    cout<<"Selected items:"<<endl;
    for(i=0;i<n;i++){
        if(W[i]<c){
            c=c-W[i];
            profit=profit+P[i];
            cout<<"Weight="<<W[i]<<" Profit="<<P[i]<<endl;
        }
        else{
            cout<<"Partial weight and profit selected of:"<<endl;
            cout<<"Weight="<<W[i]<<" Profit="<<P[i]<<endl;
            break;
        }
    }
    cout<<"Selected weight="<<c<< " Selected Profit="<<((float)P[i]*((float)c/(float)W[i]))<<endl;
    profit=profit+((float)P[i]*((float)c/(float)W[i]));
    cout<<"Total profit="<<profit;
    return 0;
}
//4 60 40 10 6 24 280 100 20 120
