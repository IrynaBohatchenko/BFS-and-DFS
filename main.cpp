#include <iostream>
#include <list>
#include <fstream>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty())
    {
        s = queue.front();
        cout << "vertex: " << s << " ";
        queue.pop_front();

        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
        cout  << " queue state: ";
        for (i = queue.begin(); i != queue.end(); ++i)
        {
            cout << *i << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    fstream gr;
    gr.open("/home/iryna/workspace/BFS/graph.txt");
    int v, e;
    gr >> v;
    gr >> e;

    Graph g(v);
    int v1, v2;
    for (int i = 0; i < e; i++)
    {
        gr >> v1;
        gr >> v2;
        g.addEdge(v1, v2);
    }

    gr.close();

    cout << "Following is Breadth First Traversal \n";
    g.BFS(0);

    return 0;
}
