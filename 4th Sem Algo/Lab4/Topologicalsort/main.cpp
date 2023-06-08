#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int v,e;
    queue<int> q1;
    cout<<"Enter No. of vertices and edges:";
    cin>>v>>e;
    int mat[10][10];
    for(int i=0;i<v+1;i++){
        for(int j=0;j<v+1;j++)
            mat[i][j]=0;
    }
    for(int i=0;i<e;i++){
        int u,v;
        cout<<"Enter the source and destination vertices:";
        cin>>u>>v;
        mat[u][v]=1;
    }
    int in_degree[v+1]={0};
    for(int i=1;i<v+1;i++){
        for(int j=1;j<v+1;j++)
            in_degree[i]=in_degree[i]+mat[j][i];
    }
    for(int i=1;i<v+1;i++){
        if(in_degree[i]==0){
            q1.push(i);
        }
    }
    while(!(q1.empty())){
        int p=q1.front();
        q1.pop();
        cout<<p<<" ";
        for(int i=1;i<v+1;i++){
            if(mat[p][i]==1){
                in_degree[i]=in_degree[i]-1;
                if(in_degree[i]==0){
                    q1.push(i);
                }
            }
        }
    }
}
