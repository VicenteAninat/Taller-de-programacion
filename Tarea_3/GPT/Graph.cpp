#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stdexcept>
#include <climits>
#include "Edge.h"

class Graph {
public:
    static const long long INF = LLONG_MAX / 2;

    Graph(int n, int s, int t) : n(n), s(s), t(t), maxFlow(0), solved(false) {
        initializeEmptyFlowGraph();
    }

    void addEdge(int from, int to, long long capacity) {
        if (capacity <= 0) throw std::invalid_argument("Forward edge capacity <= 0");
        Edge* e1 = new Edge(from, to, capacity);
        Edge* e2 = new Edge(to, from, 0);
        e1->residual = e2;
        e2->residual = e1;
        graph[from].push_back(e1);
        graph[to].push_back(e2);
    }

    std::vector<std::vector<Edge*>>& getGraph() {
        execute();
        return graph;
    }

    long long getMaxFlow() {
        execute();
        return maxFlow;
    }

protected:
    int n, s, t;
    long long maxFlow;
    bool solved;
    std::vector<std::vector<Edge*>> graph;

    virtual void solve() = 0;

private:
    void initializeEmptyFlowGraph() {
        graph.resize(n);
    }

    void execute() {
        if (solved) return;
        solved = true;
        solve();
    }
};

#endif