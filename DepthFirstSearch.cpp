#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfsrecursive(vector<int> adj[],bool visited[],int s){
    visited[s]=true;
    cout<< s<<" ";
    for(int k: adj[s]){
        if(visited[k]==false){
            dfsrecursive(adj,visited,k);
        }
    }
}

void dfs(vector<int> adj[],int v,int s){

    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    dfsrecursive(adj,visited,s);
}


int main(){
    int v=7;
    vector<int> adj[v];
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,5);
    addEdge(adj,2,4);
    addEdge(adj,3,5);
    addEdge(adj,4,5);
    addEdge(adj,4,6);
    addEdge(adj,5,6);
    cout<<"DFS of given graph is  "<<endl;
    dfs(adj,v,1);

    return 0;

}
