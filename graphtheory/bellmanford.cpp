//
// Created by Connor DePalma on 11/29/18.
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class GraphList {
private:
    class Edge {
        int v2;
        double w;
    public:
        Edge(int v2, double w) : v2(v2), w(w){}
    };

    list<vector<Edge>> edges;

public:
    GraphList(int V) : edges(new list.sixe(idk)) {
        for(int i = 0; i < V; i++){

        }
    }


    void set ( int i, int j, double w) {


    }

    double get(int i , int j) {

    }
};

