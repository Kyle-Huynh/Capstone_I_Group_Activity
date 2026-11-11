#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include "facility.h"
using namespace std;

class Equipment {
    public:
        Equipment(string new_name = "", unsigned short new_qty = 0) : name(new_name), qty(new_qty) {
            for (int i = 0; i < HOURS_PER_DAY; i++) {
                available[i] = true;
            }
        }

        void set_name(string new_name);
        void set_qty(unsigned short new_qty);

        string get_name() const;
        unsigned short get_qty() const;

    private:
        string name;
        unsigned short qty;
        bool available[HOURS_PER_DAY];


};


#endif
