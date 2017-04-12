//Обход графа поиском в глубину

#include <iostream>
#include <fstream>
#include <list>
#include <exception>
#include <new>
using namespace std;

class Graph
{
    int V; //количество вершин
    //list<int> *adj;//список смежности графа
    int **adj;//матрица смежности
public:
    Graph(int V);//конструктор
    void addEdge(int v, int w);//добавление ребра в граф
    void DFS(int s);//обход
};

Graph::Graph(int V)
{
    this->V = V;
    //adj = new list<int>[V];
    adj = new int*[V];
    for (int i = 0; i < V; i++)
    {
        adj[i] = new int[V];
    }
}

void Graph::addEdge(int v, int w)
{
    //adj[v].push_back(w);//добавили вершину w в смежные к вершине v
    adj[v][w] = 1;
}

void Graph::DFS(int v)
{
    bool *visited = new bool[V];//масив с отметками о посещении вершин
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;//сначала все вершины непосещенные
    }

    list<int> stack;
    stack.push_back(v);//помещаем первую вершину в стек

    //Пока стек не опустеет, достаем вершину, есил ее еще не посещали, отмечаем ее как посещенную,
    //помещаем в стек смежные с ней вершины
    while (!stack.empty())
    {
        v = stack.back();
        stack.pop_back();
        if (!visited[v])
        {
            cout << "vertex: " << v;
            visited[v] = true;
            for (int i = 0; i < V; ++i)
            {
                if (adj[v][i] == 1)
                {
                    stack.push_back(i);
                }
            }
        }
        //Выводим состояние стека
        cout  << " stack state: ";
        list<int>::iterator i;
        for (i = stack.begin(); i != stack.end(); ++i)
        {
            cout << *i << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    fstream gr;//открыли файл
    gr.open("graph.txt");//прописать путь к файлу
    int v, e;
    gr >> v;//считали из файла количество вершин
    gr >> e;//и количество ребер

    Graph g(v);
    int v1, v2;
    for (int i = 0; i < e; i++)
    {
        gr >> v1;//считали начало
        gr >> v2;//и конец ребра
        g.addEdge(v1, v2);//добавили ребро в список смежности
    }

    gr.close();

    cout << "Following is Depth First Traversal \n";
    g.DFS(0);//обход графа поиском в глубину начиная с вершины 0

    return 0;
}
