#ifndef DINIC_H
#define DINIC_H

#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <deque>
#include "Graph.h"

class Dinic : public Graph {
public:
    Dinic(int n, int source, int t) : Graph(n, source, t), s(source) {
        level.resize(n);
        next.resize(n);
        graph.resize(n);
    }

    std::vector<int> level;
    std::vector<int> next;
    int t;
private:
    std::vector<int> level;
    int s;
    const long long INF = LLONG_MAX;
    const long long INF = LLONG_MAX;
    long long maxFlow = 0;

    void solve() {
        while (bfs()) {
            std::fill(next.begin(), next.end(), 0);
            for (long long f = dfs(s, INF); f != 0; f = dfs(s, INF)) {
                maxFlow += f;
            }
        }
    }

    bool bfs() {
        std::fill(level.begin(), level.end(), -1);
        std::deque<int> q;
        q.push_back(s);
        level[s] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop_front();
            for (Edge* edge : graph[node]) {
                if (edge->remainingCapacity() > 0 && level[edge->to] == -1) {
                    level[edge->to] = level[node] + 1;
                    q.push_back(edge->to);
                }
            }
        }
        return level[t] != -1;
    }

    long long dfs(int at, long long flow) {
        if (at == t) return flow;
        const int numEdges = graph[at].size();
        for (; next[at] < numEdges; next[at]++) {
            Edge* edge = graph[at][next[at]];
            if (edge->remainingCapacity() > 0 && level[edge->to] == level[at] + 1) {
                long long bottleNeck = dfs(edge->to, std::min(flow, edge->remainingCapacity()));
                if (bottleNeck > 0) {
                    edge->augment(bottleNeck);
                    return bottleNeck;
                }
            }
        }
        return 0;
    }
};

#endif