#ifndef FACILITY_H
#define FACILITY_H

#include <string>
using namespace std;

class facility {
    private:
        int id;
    public:
        int capacity;
        string location;
        int[] avaiableTimes;
};

#endif