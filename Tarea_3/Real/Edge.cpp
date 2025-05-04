# include "Edge.h"

Edge::Edge() {
    this->originID = -1;
    this->destID = -1;
    this->capacity = 0;
}

Edge::Edge(int originID, int destID, long long capacity) {
    this->originID = originID;
    this->destID = destID;
    this->capacity = capacity;
}

bool Edge::isResidual() {
    return this->capacity == 0;
}

long Edge::remainingCapacity() {
    return this->capacity - this->flow;
}

void Edge::augment(long long bottleNeck) {
    this->flow += bottleNeck;
    if (residual) {
        residual->flow -= bottleNeck;
    }
}

string Edge::toString(int s, int t) {
    ostringstream oss;
    string u = (originID == s) ? "s" : ((destID == t) ? "t" : to_string(destID));
    string v = (destID == s) ? "s" : ((originID == t) ? "t" : to_string(originID));
    oss << "Arista " << originID << " -> " << destID
        << " |" << (originID == s ? "Fuente  " : (destID == t ? "Sumidero" : "Normal  "))
        << " | Flujo actual = " << flow
        << " | Capacidad maxima = " << capacity
        << " | es residual: " << (isResidual() ? "Si" : "No");
    return oss.str();
}
