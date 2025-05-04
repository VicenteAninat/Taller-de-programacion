#ifndef EDGE_H
#define EDGE_H

#include <string>

class Edge {
public:
    int from, to;
    long long flow, capacity;
    Edge* residual;

    Edge(int from, int to, long long capacity) : from(from), to(to), flow(0), capacity(capacity), residual(nullptr) {}

    bool isResidual() const {
        return capacity == 0;
    }

    long long remainingCapacity() const {
        return capacity - flow;
    }

    void augment(long long bottleNeck) {
        flow += bottleNeck;
        residual->flow -= bottleNeck;
    }

    std::string toString(int s, int t) const {
        std::string u = (from == s) ? "s" : ((from == t) ? "t" : std::to_string(from));
        std::string v = (to == s) ? "s" : ((to == t) ? "t" : std::to_string(to));
        return "Edge " + u + " -> " + v + " | flow = " + std::to_string(flow) + " | capacity = " + std::to_string(capacity) + " | is residual: " + (isResidual() ? "true" : "false");
    }
};

#endif