#include "equipment.h"

string Equipment::get_name() const { return name; }
unsigned short Equipment::get_qty() const { return qty; }

void Equipment::set_name(string new_name) { name = new_name; }
void Equipment::set_qty(unsigned short new_qty) { qty = new_qty; }
