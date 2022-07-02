#include<iostream>
#include<list>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addedge(int v, int w);
    void BFS(int s);
};
Graph::Graph(int V)
{
    this -> V = V;
    adj = new list<int>[V];
}
void Graph:: addedge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::BFS(int s)
{
    bool *visited = new bool [V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    
    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    Graph g(9);
    g.addedge(1,2);
    g.addedge(1,4);
    g.addedge(2,3);
    g.addedge(2,6);
    g.addedge(3,5);
    g.addedge(3,7);
    g.addedge(7,5);
    g.addedge(5,2);
    g.addedge(5,6);
    g.addedge(6,1);
    g.addedge(4,6);
    
    cout << "BFS of given graph is \n";
    g.BFS(1);
    return 0;
}