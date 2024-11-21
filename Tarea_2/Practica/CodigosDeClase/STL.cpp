#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {

    struct tipo {
        int x;
        int operator+(tipo a) {
            return x + a.x;
        }
        int operator()(int y) {
            return y+x;
        }    
        int operator[](int y) {
            return 2*y+x;
        } 
    };

    tipo a, b;
    a.x = 5;
    b.x = 3;

    cout << a + b << endl;
    cout << a(10) << endl;
    cout << a[10] << endl;


    cout <<"ejemplos de vector" << endl;
    vector<int> A;

    A.push_back(10);
    A.push_back(1);
    A.push_back(5);
    A.push_back(3);

    cout << A[0] << endl;
    cout << A[1] << endl;
    //cout << A[10] << endl; // esto esta malo
    for(int i=0; i<A.size(); i++) {
        cout << A[i] << " ";
    } 
    cout << endl;

    for(auto i: A) {
        cout << i << " ";
    }
    cout << endl;

    // veamos ahora con iteradores
    auto i = A.begin(); // i es "puntero" al inicio de la estructura A
    // probemos que se parece a un puntero

    cout << *i << endl;
    i++;
    cout << *i << endl;

    for(auto j=A.begin(); j!=A.end(); j++) {
        cout << *j << " ";
    }
    cout << endl;

    set<int> z; // arbol red-black de enteros sin repeticion
    z.insert(100);
    z.insert(1);
    z.insert(50);
    z.insert(2);
    z.insert(60);
    z.insert(10);

    for(auto w : z) {
        cout << w << " ";
    }
    cout << endl;

    for(auto w=z.begin(); w!=z.end(); w++) {
        cout << *w << " ";
    }

    cout << endl;

    class State {
        public:
            State(int x) {
                this->x=x;
            }
            int x;
    };

    set<State *> h;

    State *s1 = new State(100);
    State *s2 = new State(1);
    State *s3 = new State(15);
    State *s4 = new State(6);
    
    h.insert(s1);
    h.insert(s2);
    h.insert(s3);
    h.insert(s4);

    for (auto k: h) {
        cout << k->x << " ";
    }
    cout << endl;

    struct Comparador {
        bool operator() (const State* s1, const State* s2) const {
            return s1->x > s2->x;
        }
    };

    set<State*, Comparador> hh;
    hh.insert(s1);
    hh.insert(s2);
    hh.insert(s3);
    hh.insert(s4);

    for (auto k: hh) {
        cout << k->x << " ";
    }
    cout << endl;

}