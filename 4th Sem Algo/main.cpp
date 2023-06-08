#include <iostream>

using namespace std;
class Queue
{
    public:
        int a[100];
        int front, rear;
        Queue()
        {
            front = -1;
            rear = 0;
        }
        bool isEmpty()
        {
            if (front == rear)
            return true;
            else
            return false;
        }
        void enqueue(int x)
        {
            if (rear == 99)
            cout << "Queue is full";
            else if (rear == 0)
            {
                a[rear++] = x;
                front = 0;
            }
            else
            {
                a[rear++] = x;
            }
        }
        int dequeue()
        {
            if (isEmpty())
                cout << "Queue is Emtpy";
            else
            {
                return (a[front++]);
            }
            return -1;
        }
        void display()
        {
            int i;
            cout << "\nQueue : ";
            for (i = front; i <= rear; i++)
            cout << a[i] <<" ";
        }
};
void transpose(int v,int a[][10]){
    cout<<"1. Transpose of the graph:"<<endl;
    for(int i=1;i<v+1;i++){
        for(int j=1;j<v+1;j++){
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }
}
void dfs(int ver, int adj[10][10],int visited[], int v)
{
    int j;
    cout << ver << " ";
    visited[ver]=1;
    for(j = 1; j<v+1; j++)
    {
        if(!visited[j]&&adj[ver][j]==1)
            dfs(j, adj, visited, v);
    }
}
void mv(int v,int a[][10]){
    int vis[v+1];
    for(int i=1;i<v+1;i++){
        int flag=1;
        for(int j=0;j<v+1;j++){
            vis[j]=0;
        }
        dfs(i,a,vis,v);
        for(int j=1;j<v+1;j++){
            if(!vis[j]){
                flag=0;
            }
        }
        if(flag==1){
            cout<<i<<" ";
        }
    }
}
void bfs(int a[10][10], int source, int v, int visited[])
{
    Queue q;
    q.enqueue(source);
    int pop;
    while (!q.isEmpty())
    {
        pop = q.dequeue();
        cout<<(pop)<<" ";
        for (int i=1; i<v+1; i++)
        {
            if (a[pop][i] == 1 && visited[i] == 0)
            {
            visited[i] = 1;
            q.enqueue(i);
            }
        }
    visited[pop] = 1;
    }
}
//7 7 1 2 1 4 1 5 2 3 4 3 4 7 5 6
int main()
{
    int v,e;
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
    cout<<"Adjacency matrix of inputed graph:"<<endl;
    for(int i=1;i<v+1;i++){
        for(int j=1;j<v+1;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    transpose(v,mat);
    cout<<"DFS traversal, input start vertex:";
    int ver;
    cin>>ver;
    int visited[v+1]={0};
    dfs(ver,mat,visited,v);
    cout<<endl;
    int visit[v+1]={0};
    cout<<"BFS traversal:";
    bfs(mat,ver,v,visit);
    cout<<"Mother vertices:";
    mv(v,mat);
    return 0;
}

