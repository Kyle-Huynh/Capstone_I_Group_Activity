#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include "facility.h"
using namespace std;

class person {
    public:
        string get_name() const;
        string get_email() const;
        string get_id() const;

        virtual void view_reservations() const;
        virtual void view_events() const;

        string set_name();
        virtual void request_reservation();
    private:
        string name;
        string email;
        unsigned int id;
        string password;
        vector<unsigned int> reservations;



};

class student_rep: public person {
    public:
        void request_reservation();
        void view_reservations() const;
        void view_events() const;
        string get_org() const;
        void set_org();
    private:
        string org;
};

class facility_coord: public person {
    public:
        bool add_facility();
        bool edit_facility();
        bool delete_facility();

        void request_reservation();
        void view_reservations() const;
        void view_events() const;
    private:
        vector<facility> facilities;
};

class sys_admin: public person {
    public:
        void view_usage() const;
        void request_reservation();
        void view_reservations() const;
        void view_events() const;
    private:
        
};

class event_approver: public person {
    public:
        void request_reservation();
        void view_reservations() const;
        void view_events() const;
        void approve();
    private:
        

};
#endif