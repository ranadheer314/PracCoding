#include<iostream>
#include <list>

using namespace std;

class Graph
{
    int V;
    list<int>* adj;
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
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    list<int> queue;
    list<int>::iterator i;
    visited[s] = true;
    queue.push_front(s);
    while (!queue.empty()) {
        int current=queue.front();
        cout << current << "->";
        queue.pop_front();
        for (i = adj[current].begin(); i != adj[current].end(); i++) {
            if (visited[*i] == false) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main() {
    int v = 4;
    Graph g(v);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(2);
    Graph g1(7);
    g1.addEdge(1, 2);
    g1.addEdge(2, 1);
    g1.addEdge(1, 3);
    g1.addEdge(3, 1);
    g1.addEdge(2, 4);
    g1.addEdge(4, 2);
    g1.addEdge(2, 5);
    g1.addEdge(5, 2);
    g1.addEdge(4, 5);
    g1.addEdge(5, 4);
    g1.addEdge(4, 6);
    g1.addEdge(6, 4);
    g1.addEdge(6, 5);
    g1.addEdge(5, 6);
    g1.addEdge(3, 5);
    g1.addEdge(5, 3);
    cout << endl;
    g1.BFS(1);


    //I think it cant print all the possible BFS traversals using this method
    //

    return 0;
}
