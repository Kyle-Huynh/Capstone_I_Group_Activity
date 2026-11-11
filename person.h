#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include "facility.h"
#include "reservation.h"

//person should not be used at all its just a base class for the subclasses
class Person {
    public:
        Person() : name(""), email(""), id(0), password("") {}

        string get_name() const;
        string get_email() const;
        unsigned int get_id() const;

        virtual void view_reservations() const;
        virtual void view_events() const;

        string set_name(string alias);
        virtual void request_reservation();
    private:
        string name;
        string email;
        unsigned int id;
        string password;
        vector<Reservation*> reservations;
        bool cancel();





};

class Rep: public Person {
    public:
        Rep() : Person(), org("") {}



        void request_reservation();
        void view_reservations() const;
        void view_events() const;
        string get_org() const;
        void set_org(string new_org);
    private:
        string org;
};

class Facility_coord: public Person {
    public:
        bool add_facility(Facility * new_loc);
        bool edit_facility(Facility * loc);
        bool delete_facility(Facility * loc);

        void request_reservation();
        void view_reservations() const;
        void view_events() const;
    private:
        vector<Facility> facilities;
};

class Admin: public Person {
    public:
        void view_usage() const;
        void request_reservation();
        void view_reservations() const;
        void view_events() const;
    private:
        
};

class Approver: public Person {
    public:
        void request_reservation();
        void view_reservations() const;
        void view_events() const;
        void approve();
    private:
        

};
#endif