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
        mat[v][u]=w;
    }

    bool *visited = new bool[v+1];
    int *dist=new int[v+1];
    int *parent = new int[v+1];

    for (int i = 1; i < v+1; i++){
        dist[i] = MAX;
        visited[i]=false;
    }
    dist[1] = 0;
    parent[1]=-1;
    for (int i = 1; i < v ; i++) {
        int cur = minVertex(visited,dist, v);
        visited[cur] = true;
        for (int j = 1; j < v+1; j++){
            if (!visited[j] && mat[cur][j] != 0){
                if (dist[j] > mat[cur][j]) {
                    dist[j] = mat[cur][j];
                    parent[j] = cur;
                }
            }
        }
    }
    cout<<"Minimum Spanning tree:"<<endl;
    for (int i = 2; i < v+1; i++)
        cout << min(parent[i], i) << " -> " << max(parent[i], i) << " : " << dist[i] << "\n";

    return 0;
}
