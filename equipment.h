#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
using namespace std;

class Equipment {
    public:
        string get_name();
        unsigned short get_qty();

        void set_name();
        void set_qty();

    private:
        string name;
        unsigned short qty;
        bool available[8];


};


#endif