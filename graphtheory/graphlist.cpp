#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class GraphList
{
  private:
    //in Java: Double.POSITIVE_INFINITY
    double INFINITY = 1.0 / 0.0;
    class Edge
    {
      public:
        int to;
        double w;
        Edge *next;
        Edge(int to, double w, Edge *next) : to(to), w(w), next(next) {}
    };
    Edge **edges;
    int V;

  public:
    GraphList(int V) : V(V)
    {
        edges = new Edge *[V];
        for (int i = 0; i < V; i++)
            edges[i] = nullptr;
    }
    ~GraphList()
    {
        Edge **p = edges;
        for (int i = V; i > 0; i--, ++p)
        {
            // delete the linked list...
            Edge *temp;
            for (Edge *q = *p; q != nullptr; q = temp)
            {
                temp = q->next;
                delete q;
            }
        }
        delete[] edges;
    }
    void setEdge(int i, int j, double w)
    {
        for (Edge *e = edges[i]; e != nullptr; e = e->next)
        {
            if (e->to == j)
            {
                e->w = w;
                return;
            }
        }
        edges[i] = new Edge(j, w, edges[i]); // addFirst
    }

//    double adjacent(int i, int j)
//    { //O(V)
//        Edge *n = edges[i];
//        if (n == nullptr)
//            return INFINITY;
//        for (; n != nullptr; n = n->next)
//        {
//            if (n->to == j)
//                return n->w;
//        }
//        return INFINITY;
//    }

    bool adjacent(int i, int j)
    { //O(V)
        Edge *n = edges[i];
        if (n == nullptr)
            return false;
        for (; n != nullptr; n = n->next)
        {
            if (n->to == j)
                return true;
        }
        return false;
    }

    bool DFS(int v)
    {
        stack<int> todo;

        bool visited[V];
        for (int i = 0; i < V; i++){
            visited[i] = false;

        }
        visited[v] = true;
        int count = 1;
        todo.push(v);
        while (!todo.empty())
        {
            int val = todo.top();
            todo.pop();
            cout << val;
            for (Edge *p = edges[val]; p != nullptr; p = p->next)
            {
                int v2 = p->to;
                if (!visited[v2])
                {
                    todo.push(v2);
                    visited[v2] = true;
                    count++;
                }
                
            }
        }
       return count == V;
    }

    bool BFS(int v)
    {
        queue<int> todo;

        bool visited[V];
        for (int i = 0; i < V; i++){
            visited[i] = false;

        }
        visited[v] = true;
        int count = 1;
        todo.push(v);
        while (!todo.empty())
        {
            int v = todo.front();
            todo.pop();
            cout << v;
            for (Edge *p = edges[v]; p != nullptr; p = p->next)
            {
                int v2 = p->to;
                if (!visited[v2])
                {
                    todo.push(v2);
                    visited[v2] = true;
                    count++;
                }

            }
        }
        return count == V;
    }

    void DFSrecursive(int v) {
        bool visited[V];
        for (int i = 0; i < V; i++){
            visited[i] = false;

        }

        DFS2(visited, v);
    }

    void DFS2(bool visited[], int v) {
        visited[v] = true;
        cout << v;
        for(Edge *p = edges[v]; p != nullptr; p = p->next){
                if (!visited[p->to]) {
                    DFS2(visited, p->to);
                }
        }
    }

    void FloydWarshall() {
        double dist[9][9];

        for (int i = 0; i< 9; i ++) {
            for (int j = 0; j < 9; j++) {
                dist[i][j] = INFINITY;
            }
        }
        for (int i = 0; i< V; i ++) {
            for (Edge *p = edges[i]; p != nullptr; p = p->next) {
                    dist[i][p->to] = p->w;
            }
        }

        for (int i = 0; i< V; i ++) {
            for (int j = 0; j < V; j++) {
                if(i == j)
                 dist[i][j] = 0;
            }
        }
        for(int k= 0; k< V; k++){
            for(int i = 0; i< V; i++){
                for(int j = 0; j< V; j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

                }
            }
        }
        cout << dist[3][8];



    }
};


int main()
{
    GraphList g(9);
//     g.setEdge(0,3,4);
//     g.setEdge(3,0,4);
//     g.setEdge(1,3,1);
//     g.setEdge(3,1,1);
//     //g.setEdge(1,2,5);
// //    g.setEdge(2,1,5);
//     g.setEdge(3,2,6);
//     g.setEdge(2,3,6);
//     g.setEdge(2,4,3);
//     g.setEdge(4,2,3);
//     g.setEdge(4,5,3);
//     g.setEdge(5,4,3);

    // g.setEdge(4,6,1);
    // g.setEdge(6,4,1);
    // g.setEdge(4,3,1);
    // g.setEdge(3,4,1); 
    // g.setEdge(4,2,1);
    // g.setEdge(2,4,1);
    // g.setEdge(4,1,1);
    // g.setEdge(1,4,1);
    //  g.setEdge(1,3,1);
    // g.setEdge(3,1,1);
    // g.setEdge(2,1,1);
    // g.setEdge(1,2,1);
    // g.setEdge(2,7,1);
    //  g.setEdge(7,2,1);
    // g.setEdge(7,8,1);
    // g.setEdge(8,7,1);
    //  g.setEdge(3,2,1);
    // g.setEdge(2,3,1);
    //   g.setEdge(7,2,1);
    // g.setEdge(3,5,1);
    // g.setEdge(5,3,1);
    //  g.setEdge(4,6,1);
    // g.setEdge(6,4,1);


     g.setEdge(3,2,1);
    g.setEdge(2,3,1);
    g.setEdge(4,1,1);
    g.setEdge(1,4,1);
     g.setEdge(4,3,1);
    g.setEdge(3,4,1);
    g.setEdge(2,1,1);
    g.setEdge(1,2,1);
    g.setEdge(2,5,1);
     g.setEdge(5,2,1);
    g.setEdge(6,7,1);
    g.setEdge(7,6,1);
     g.setEdge(5,6,1);
    g.setEdge(6,5,1);
      g.setEdge(5,7,1);
    g.setEdge(7,5,1);
   


   // cout << g.adjacent(2,3) << '\n';
    g.DFS(7);
    cout << '\n';
    g.BFS(5) << '\n';
    cout << '\n';
    g.DFSrecursive(7);
    cout << '\n';
    g.FloydWarshall();




}