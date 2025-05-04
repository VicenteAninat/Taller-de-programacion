#include "Dinic.h"

Dinic::Dinic() {
    this->level = vector<int>(0);
    this->nextEdge = vector<int>(0);
    this->n = 0;
    this->s = 0;
    this->t = 0;
    this->graph = initializeEmptyGraph();
}

Dinic::Dinic(int n) {
    this->level = vector<int>(n);
    this->nextEdge = vector<int>(n);
    this->n = n;
    this->graph = initializeEmptyGraph();
}

Dinic::Dinic(int n, int s, int t) {
    this->level = vector<int>(n);
    this->nextEdge = vector<int>(n);
    this->n = n;
    this->s = s;
    this->t = t;
    this->graph = initializeEmptyGraph();
}

void Dinic::solve() {
    while (bfs()) {
        fill(nextEdge.begin(), nextEdge.end(), 0);
        long long flow;
        while ((flow = dfs(s, INF)) != 0) {
            maxFlow += flow;
        }
    }
}

bool Dinic::bfs() {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (Edge* e : graph[u]) {
            if (e->remainingCapacity() > 0 && level[e->destID] == -1) {
                level[e->destID] = level[u] + 1;
                q.push(e->destID);
            }
        }
    }
    return level[t] != -1;
}

long long Dinic::dfs(int u, long long flow) {
    if (u == t) {
        return flow;
    }
    auto it = graph[u].begin();
    advance(it, nextEdge[u]);
    for (int& i = nextEdge[u]; i < graph[u].size() && it != graph[u].end(); i++, ++it) {
        Edge* e = *it;
        if (e->remainingCapacity() > 0 && level[e->destID] == level[u] + 1) {
            long long remainingCapacity = e->remainingCapacity();
            long long bottleneck = dfs(e->destID, min(flow, remainingCapacity));
            if (bottleneck > 0) {
                e->augment(bottleneck);
                return bottleneck;
            }
        }
    }
    return 0;
}

/*
int Dinic::max_flow() {
    int flow = 0;
    while (bfs2(s, t)) {
        fill(ptr.begin(), ptr.end(), 0);
        while (int pushed = dfs2(s, t, INF)) {
            flow += pushed;
        }
    }
    return flow;
}
*/

/*
bool Dinic::bfs2(int source, int sink) {
    fill(level.begin(), level.end(), -1);
        level[source] = 0;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (Edge* e : graph[u]) {
                if (level[e->destID] == -1 && e->remainingCapacity() > 0) {
                    level[e->destID] = level[u] + 1;
                    q.push(e->destID);
                }
            }
        }
        return level[sink] != -1;
}
*/

/*
long long Dinic::dfs2(int u, int sink, long long flow) {
        if (u == sink) return flow;
        for (auto &it = ptr[u]; it != graph[u].end(); ++it) {
            Edge* e = *it;
            if (level[e->destID] == level[u] + 1 && e->remainingCapacity() > 0) {
                long long remainingCapacity = e->remainingCapacity();
                int new_u = e->destID;
                long long bottleneck = dfs2(new_u, sink, min(flow, remainingCapacity));
                if (bottleneck > 0) {
                    e->augment(bottleneck);
                    return bottleneck;
                }
            }
        }
        return 0;
    }
*/