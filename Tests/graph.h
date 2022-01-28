// AED 2021/2022 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [17/01/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "minHeap.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
        string line; //
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        int dist;
        int pred;
        bool visited;
        string predline;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<Node> nodes; // The list of nodes being represented


private:
    void resetNodePathingValues();
    vector<int> backtrace(int start, int end, vector<string> &stops);

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, string line, int weight = 1);
    vector<int> bfsstops(int v, int fv, vector<string> &stops);
    vector<int> dijkstraPath(int sNode, int endNode, vector<string> &stops);
    vector<int> dijkstraPathLines(int sNode, int endNode, vector<string> &stops);
    void printGraph();
};

#endif
