#include <iostream>
#include <set>
using namespace std;
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
        mat[d][s]=1;
    }
    cout<<"Adjacency matrix of inputed graph:"<<endl;
    for(int i=1;i<v+1;i++){
        for(int j=1;j<v+1;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    if(hasCycle(mat,v)){
        cout<<"Cyclic Graph"<<endl;
    }
    else
        cout<<"Not cyclic graph"<<endl;
    return 0;
}
