#include <iostream>
#include <set>
#include <queue>
using namespace std;
int k=0,flag=0;
void dfs(int a,int adj[][10],int visited[],int v){
    //cout<<a<<" ";
    visited[a]=1;
    for(int i=1;i<v+1;i++){
        if(!visited[i] && adj[a][i]==1){
            dfs(i,adj,visited,v);
        }
    }
}
bool isConnected(int adj[][10], int v)
{
    int vis[v+1];
    for(int i=1;i<v+1;i++)
    {
        for(int j=0;j<v+1;j++)
        {
            vis[j] = false;
        }
        dfs(i, adj, vis, v);
        for (int j=1;j<v+1;j++)
        {
            if (!vis[j])
            {
               return false;
            }
        }
    }
    return true;
}
bool dfs1(int adj[][10],int v,int s,set<int>&visited, int parent) {
   visited.insert(s);
   for(int j=1; j<v+1;j++) {
      if(adj[s][j]) {
         if(j==parent)    //if v is the parent not move that direction
            continue;
         if(visited.find(j)!=visited.end())    //if v is already visited
            return true;
         if(dfs1(adj,v,j,visited,s))
            return true;
      }
   }
   return false;
}
bool hasCycle(int adj[][10], int v){
   set<int> visited;       //visited set
   for(int i=0; i<v+1;i++) {
      if(visited.find(i) != visited.end())    //when visited holds v, jump to next iteration
         continue;
      if(dfs1(adj,v,i, visited,-1)) {    //-1 as no parent of starting vertex
         return true;
      }
   }
   return false;
}

void path(int adj[][10], int v, int source, int dest){
    int vis[v] = {0};
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    int flag = 0;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(int i=1;i<v+1;i++){
            if(adj[temp][i]==1 && vis[i]==0){
                q.push(i);
                vis[i]=1;
                if(i==dest){
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1){
            //cout<<q.front();
            break;
        }
    }
    cout<<endl;

    if(flag==1){
        cout<<"Path found"<<endl;
    }
    else{
        cout<<"Path not found"<<endl;
    }
    cout<<endl;


}
/*
int adjacent(int adj[][10],int v,int s,int visited[]){
    for(int i=1;i<v+1;i++){
        if(adj[s][i]==1 && visited[i]==0){
            visited[i]=1;
            return s;
        }
    }
    return -1;
}
int rfp(int adj[][10],int v,int s,int d,int visited[],int p[]){
    visited[s]=1;
    int i;
    while((i=adjacent(adj,v,s,visited))!=-1){
        if(visited[i]==0){
            p[++len]=i;
            if(i==d || rfp(adj,v,i,d,visited,p)){
                return true;
            }
            len--;
        }
    }
    return false;
}
void fp(int adj[][10],int v,int s,int d){
    int p[v+1];
    int visited[v+1]={0};
    if(s==d || rfp(adj,v,s,d,visited,p)){
        p[0]=len-1;
        cout<<"Found path";
    }
    else{
        cout<<"No path";
        //delete p[];
        //p=NULL;
    }
    //delete visited[];
    cout<<len<<endl;
    for(int i=0;i<len;i++){
        cout<<p[i]<<" ";
    }
}
void cyclic(int adj[][10],int v,int s){
    int arr[10];
    int m=0;
    arr[m++]=s;
    for(int i=1;i<v+1;i++){
        if(adj[s][i]==1)
            cyclic(adj,v,i);
    }
}
void path(int adj[][10],int v,int s,int d){
    int vis[v+1]={0};
    int arr[v+1];
    if(findpath(adj,v,s,d,vis,arr)==true){
        cout<<endl<<"Path exists, path traversal:"<<endl;
        for(int i=0;i<k;i++){
            cout<<arr[i]<<" ";
        }
    }
    else{
        cout<<endl<<"Path doesn't exist"<<endl;
    }
}
*/
bool findpath(int adj[][10],int v,int s,int d,int vis[],int arr[]){
    arr[k++]=s;
    vis[s]=1;
    for(int i=1;i<v+1;i++){
        if(!vis[i]&&adj[s][i]==1){
            if(i==d){
                vis[d]=1;
                arr[k++]=d;
                flag=1;
                break;
            }
            findpath(adj,v,i,d,vis,arr);
        }
    }
    if(flag==1){return true;}
    return false;
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
    }
    cout<<"Adjacency matrix of inputed graph:"<<endl;
    for(int i=1;i<v+1;i++){
        for(int j=1;j<v+1;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter source and dest vertex:";
    int source,dest;
    cin>>source>>dest;
    //path(mat,v,source,dest);
    //fp(mat,v,source,dest);
    int vis[v+1]={0};
    int arr[v+1];
    if(findpath(mat,v,source,dest,vis,arr)){
        cout<<"Path found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    if(isConnected(mat,v)){
        cout<<"Connected graph"<<endl;
    }
    else
        cout<<"Not Connected graph"<<endl;
    if(hasCycle(mat,v)){
        cout<<"Cyclic Graph"<<endl;
    }
    else
        cout<<"Not cyclic graph"<<endl;
    return 0;
}
