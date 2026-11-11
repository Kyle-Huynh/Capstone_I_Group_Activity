#include "reservation.h"

bool Reservation::apply_filter(string new_date, string new_time) {
    if (status != STATUS_OPENED) {
        return false;
    }
    date = new_date;
    time = new_time;
    status = STATUS_FILTERED;
    return true;
}

bool Reservation::submit() {
    if (status != STATUS_FILTERED || location == nullptr) {
        return false;
    }
    status = STATUS_REQUESTED;
    return true;
}

// State Model II only allows cancelling before the request is submitted
bool Reservation::cancel() {
    if (status != STATUS_OPENED && status != STATUS_FILTERED) {
        return false;
    }
    status = STATUS_CANCELLED;
    return true;
}

void Reservation::add_support(char new_support) {
    if (support == SUPPORT_NONE || support == new_support) {
        support = new_support;
    } else {
        support = SUPPORT_BOTH;
    }
}

void Reservation::set_status(char new_status) { status = new_status; }
void Reservation::set_reason(string new_reason) { reason = new_reason; }
void Reservation::set_date(string new_date) { date = new_date; }
void Reservation::set_time(string new_time) { time = new_time; }
void Reservation::set_support(char new_support) { support = new_support; }
void Reservation::set_location(Facility* new_loc) { location = new_loc; }
void Reservation::set_requester(Person *new_requester) { requester = new_requester; }
void Reservation::add_approved(Equipment* new_approved) { approved.push_back(new_approved); }
void Reservation::req_equipment(Equipment* item) { requested.push_back(item); }

char Reservation::get_status() const { return status; }
Facility* Reservation::get_location() const { return location; }
Person* Reservation::get_requester() const { return requester; }
string Reservation::get_reason() const { return reason; }
string Reservation::get_date() const { return date; }
string Reservation::get_time() const { return time; }
char Reservation::get_support() const { return support; }
vector<Equipment*> Reservation::get_requested() const { return requested; }
vector<Equipment*> Reservation::get_approved() const { return approved; }
