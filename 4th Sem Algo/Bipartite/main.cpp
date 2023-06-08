#include <iostream>
#include <queue>
using namespace std;

bool isBipartite(int arr[][20], int v){
    int barr[v+1];
    barr[1]=1;
    for(int i=2;i<v+1;i++){
        barr[i]=-1;
    }
    queue<int> q1;
    q1.push(1);
    while(!q1.empty()){
        int u=q1.front();
        q1.pop();
        if(arr[u][u]==1)
            return false;
        for(int i=1;i<v+1;i++){
            if(arr[u][i] && barr[i]==-1){
                barr[i]=1-barr[u];
                q1.push(i);
            }
            else if(arr[u][i] && barr[i]==barr[u])
                return false;
        }
    }
    return true;
}
int main()
{
    int v,e;
    cout<<"Enter No. of vertices and edges:";
    cin>>v>>e;
    int mat[20][20];
    for(int i=0;i<v+1;i++){
        for(int j=0;j<v+1;j++)
            mat[i][j]=0;
    }
    for(int i=0;i<e;i++){
        int a,b;
        cout<<"Enter the source, destination vertex:";
        cin>>a>>b;
        mat[a][b]=1;
        mat[b][a]=1;
    }
    if(isBipartite(mat,v))
        cout<<"Bipartite Graph";
    else
        cout<<"Not a bipartite graph";
}
