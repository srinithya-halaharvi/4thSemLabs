#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MAX 5000
int minVertex(bool *visited, int *dist, int v) {
    int minIndex, minVal = MAX;

    for (int i = 1; i < v+1; i++) {
        if (!visited[i] && dist[i] < minVal) {
            minVal = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int main() {
    int v,e;
    cout<<"Enter No. of vertices and edges:";
    cin>>v>>e;
    int mat[10][10];
    for(int i=0;i<v+1;i++){
        for(int j=0;j<v+1;j++)
            mat[i][j]=0;
    }
    for(int i=0;i<e;i++){
        int u,v,w;
        cout<<"Enter the source, destination vertex and weight:";
        cin>>u>>v>>w;
        mat[u][v]=w;
    }
    bool *visited = new bool[v+1];
    for (int i = 0; i < v+1; i++)
        visited[i]=false;

    int s;
    cout<<"Enter start vertex: ";
    cin>>s;

    int *dist=new int[v+1];
    dist[s] = 0;
    for (int i = 1; i < v+1; i++){
        if (i!=s)
            dist[i]=MAX;
    }
    for (int j = 1; j < v+1; j++) {
        int cur = minVertex(visited, dist, v);
        visited[cur] = true;
        for (int i = 1; i < v+1; i++){
            if (!visited[i] && mat[cur][i] != 0){
                if (dist[i] > dist[cur] + mat[cur][i])
                    dist[i] = dist[cur] + mat[cur][i];
            }
        }
    }
    cout<<"Dijkstra's Algo"<<endl;
    for (int i = 1; i < v+1; i++) {
        cout << i << "--> ";
        if (dist[i]==MAX)
            cout<<"Unreachable"<<endl;
        else
            cout<<dist[i]<<endl;
    }

    return 0;
}
