#include <iostream>
using namespace std;

void dfs(int graph[][10], int n, int u, bool visited[])
{
    visited[u] = true;
    for (int v = 0; v < n; v++)
    {
        if (graph[u][v])
        {
            if (!visited[v])
                dfs(graph, n, v, visited);
        }
    }
}

bool isConnected(int a[][10], int n)
{
    bool *vis = new bool[n];
    for(int u=0;u<n;u++)
    {
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
        }
        dfs(a, n, u, vis);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
               return false;
            }
        }
    }

    return true;
}
int main()
{
    int mat[10][10];
    int v,e;
    cout<<"Enter number of vertices and edges:"; cin>>v>>e;
    for(int i=0;i<v+1;i++){
        for(int j=0;j<v+1;j++)
            mat[i][j]=0;
    }
    for(int i=0;i<e;i++){
        int s,d;
        cout<<"Enter source and destination vertex:"; cin>>s>>d;
        mat[s][d]=1;
        //mat[d][s]=1;
    }
    if (isConnected(mat, v))
        cout << "The Graph is connected.";
    else
        cout << "The Graph is not connected.";
}
