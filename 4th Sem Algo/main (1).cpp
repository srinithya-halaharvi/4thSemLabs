#include <iostream>

using namespace std;
int k=0,flag=0,len=0;
class que{
public:
    int f,r;
    int a[20];
    que(){
        f=r=0;
    }
    void enqu(int x){
        a[r++]=x;
    }
    bool isempty(){
        if(f==r)
            return true;
        else
            return false;
    }
    int dequ(){
        return a[f++];
    }
};
void dfs(int a,int adj[][10],int visited[],int v){
    if(a%2!=0)
        cout<<a<<" ";
    visited[a]=1;
    for(int i=1;i<v+1;i++){
        if(!visited[i] && adj[a][i]==1){
            dfs(i,adj,visited,v);
        }
    }
}
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
void bfs(int a,int adj[][10],int visited[],int v){
    que q1;
    q1.enqu(a);
    int pop;
    while(!q1.isempty()){
        pop=q1.dequ();
        if(pop%2==0)
            cout<<pop<<" ";
        for(int i=1;i<v+1;i++){
            if(!visited[i] && adj[pop][i]==1){
                visited[i]=1;
                q1.enqu(i);
            }
        }
        visited[pop]=1;
    }

}
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
    cout<<"Input start vertex:";
    int ver;
    cin>>ver;
    cout<<"DFS traversal:"<<endl;
    int visited[v+1]={0};
    dfs(ver,mat,visited,v);
    cout<<endl<<"BFS traversal:"<<endl;
    int visit[v+1]={0};
    bfs(ver,mat,visit,v);
    cout<<endl<<"Enter source and dest vertex:";
    int source,dest; cin>>source>>dest;
    //path(mat,v,source,dest);
    fp(mat,v,source,dest);
    return 0;
}
