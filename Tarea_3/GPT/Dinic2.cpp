#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

struct Edge {
    int to, rev;
    int capacity;
};

class Dinic {
public:
    Dinic(int n) : n(n), graph(n), level(n), ptr(n) {}

    void add_edge(int u, int v, int cap) {
        graph[u].push_back({v, (int)graph[v].size(), cap});
        graph[v].push_back({u, (int)graph[u].size() - 1, 0}); // Reverse edge with 0 capacity
    }

    int max_flow(int source, int sink) {
        int flow = 0;
        while (bfs(source, sink)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(source, sink, INT_MAX)) {
                flow += pushed;
            }
        }
        return flow;
    }

private:
    int n;
    vector<vector<Edge>> graph;
    vector<int> level;
    vector<int> ptr;

    bool bfs(int source, int sink) {
        fill(level.begin(), level.end(), -1);
        level[source] = 0;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const Edge &e : graph[u]) {
                if (level[e.to] == -1 && e.capacity > 0) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[sink] != -1;
    }

    int dfs(int u, int sink, int flow) {
        if (u == sink) return flow;
        for (int &cid = ptr[u]; cid < graph[u].size(); ++cid) {
            Edge &e = graph[u][cid];
            if (level[e.to] == level[u] + 1 && e.capacity > 0) {
                int pushed = dfs(e.to, sink, min(flow, e.capacity));
                if (pushed > 0) {
                    e.capacity -= pushed;
                    graph[e.to][e.rev].capacity += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
};

int main() {
    int n = 10; // Total number of nodes (0 to 9)

    Dinic dinic(n);

    // Add edges
    dinic.add_edge(0, 1, 10);
    dinic.add_edge(0, 2, 10);
    dinic.add_edge(1, 3, 15);
    dinic.add_edge(2, 4, 25);
    dinic.add_edge(3, 2, 6);
    dinic.add_edge(3, 5, 10);
    dinic.add_edge(3, 7, 5);
    dinic.add_edge(4, 5, 10);
    dinic.add_edge(6, 1, 5);
    dinic.add_edge(8, 0, 100);
    dinic.add_edge(8, 6, 100);
    dinic.add_edge(5, 9, 100);
    dinic.add_edge(7, 9, 100);

    int source = 8;
    int sink = 9;

    cout << "Maximum flow: " << dinic.max_flow(source, sink) << endl;

    return 0;
}
