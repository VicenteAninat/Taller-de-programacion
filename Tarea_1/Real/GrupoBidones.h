#include <iostream>
#include "Bidon.h"

using namespace std;

class GrupoBidones{
    public:
    Bidon *bidones[];
    GrupoBidones *parent;
    string operation;
};