#include <fstream>
#include "State.h"

class Read {
    public:

    Read();

    State* readFile(string fileName);
};