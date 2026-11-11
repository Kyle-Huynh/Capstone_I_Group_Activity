#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <vector>
#include "facility.h"
#include "equipment.h"
using namespace std;

class Person;

const char STATUS_OPENED = 'O';
const char STATUS_FILTERED = 'F';
const char STATUS_REQUESTED = 'R';
const char STATUS_APPROVED = 'A';
const char STATUS_DENIED = 'D';
const char STATUS_CANCELLED = 'C';

const char SUPPORT_NONE = 'N';
const char SUPPORT_SECURITY = 'S';
const char SUPPORT_EVENT = 'E';
const char SUPPORT_BOTH = 'B';

class Reservation {
    public:
        Reservation() : status(STATUS_OPENED), location(nullptr), requester(nullptr), support(SUPPORT_NONE) {}

        bool apply_filter(string new_date, string new_time);
        bool submit();
        bool cancel();
        void add_support(char new_support);

        void req_equipment(Equipment* item);
        void req_equipment();
        
        void set_status(char new_status);
        void set_location(Facility* new_loc);
        void set_requester(Person *new_requester);
        void set_reason(string new_reason);
        void set_date(string new_date);
        void set_time(string new_time);
        void set_support(char new_support);
        void add_approved(Equipment* new_approved);

        char get_status() const;
        Facility* get_location() const;
        Person* get_requester() const;
        string get_reason() const;
        string get_date() const;
        string get_time() const;
        char get_support() const;
        vector<Equipment*> get_requested() const;
        vector<Equipment*> get_approved() const;
    private:
        char status;
        Facility* location;
        Person* requester;
        string reason;
        string date;
        string time;
        char support;
        vector<Equipment*> requested;
        vector<Equipment*> approved;
};


#endif