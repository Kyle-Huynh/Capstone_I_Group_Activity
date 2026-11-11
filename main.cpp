#include <iostream>
#include <string>
#include <limits>
#include "facility.h"
#include "reservation.h"
#include "person.h"
using namespace std;

const int NUM_ROOMS = 3;
const int NUM_TIMES = 3;
const int NUM_EQUIPMENT = 3;
const int BOOKING_LENGTH_HOURS = 2;
const int CANCELLED = -1;

const int OPTION_EQUIPMENT = 1;
const int OPTION_SECURITY = 2;
const int OPTION_EVENT = 3;
const int OPTION_DONE = 4;
const int OPTION_CANCEL = 5;

const string DATES[NUM_DAYS] = {"November 11, 2026", "November 16, 2026", "November 18, 2026"};
const string TIMES[NUM_TIMES] = {"12:00 PM - 2:00 PM", "1:00 PM - 3:00 PM", "2:00 PM - 4:00 PM"};
const int START_HOURS[NUM_TIMES] = {12, 13, 14};

int readChoice(int lastOption) {
    int choice;
    cin >> choice;
    while (choice < 1 || choice > lastOption) {
        // If the input runs out, pick the last option (cancel/back) instead of asking forever
        if (cin.eof()) {
            return lastOption;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Not a valid option, try again: ";
        cin >> choice;
    }
    return choice;
}

int chooseFromList(const string& title, const string options[], int count) {
    cout << "========== " << title << " ==========" << endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << options[i] << endl;
    }
    cout << count + 1 << ". Cancel Reservation" << endl;
    cout << "=========================" << endl;

    int choice = readChoice(count + 1);
    if (choice == count + 1) {
        return CANCELLED;
    }
    return choice - 1;
}

Facility* chooseRoom(Facility rooms[], int day, int startHour, int endHour) {
    cout << "========== Select Room ==========" << endl;
    for (int i = 0; i < NUM_ROOMS; i++) {
        cout << i + 1 << ". " << rooms[i].getLocation() << " (Capacity: " << rooms[i].getCapacity() << ") - ";
        if (rooms[i].isFree(day, startHour, endHour)) {
            cout << "Available" << endl;
        } else {
            cout << "Not Available" << endl;
        }
    }
    cout << NUM_ROOMS + 1 << ". Cancel Reservation" << endl;
    cout << "=========================" << endl;

    int choice = readChoice(NUM_ROOMS + 1);
    while (choice != NUM_ROOMS + 1 && !rooms[choice - 1].isFree(day, startHour, endHour)) {
        cout << "That room is already booked at this time, pick another: ";
        choice = readChoice(NUM_ROOMS + 1);
    }
    if (choice == NUM_ROOMS + 1) {
        return nullptr;
    }
    return &rooms[choice - 1];
}

string readEventDetails() {
    cout << "Enter event details: ";
    // Skip the leftover Enter from the last number typed, otherwise getline would read an empty line
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string details;
    getline(cin, details);
    while (details.empty() && !cin.eof()) {
        cout << "Event details can't be empty, try again: ";
        getline(cin, details);
    }
    return details;
}

void chooseEquipment(Reservation& request, Equipment equipment[]) {
    cout << "========== Select Equipment ==========" << endl;
    for (int i = 0; i < NUM_EQUIPMENT; i++) {
        cout << i + 1 << ". " << equipment[i].get_name() << " (" << equipment[i].get_qty() << " available)" << endl;
    }
    cout << NUM_EQUIPMENT + 1 << ". Back" << endl;
    cout << "=========================" << endl;

    int choice = readChoice(NUM_EQUIPMENT + 1);
    if (choice == NUM_EQUIPMENT + 1) {
        return;
    }
    Equipment& item = equipment[choice - 1];
    request.req_equipment(&item);
    cout << item.get_name() << " requested" << endl;
}

bool chooseSupport(Reservation& request, Equipment equipment[]) {
    int choice = 0;
    while (choice != OPTION_DONE) {
        cout << "========== Additional Support ==========" << endl;
        cout << OPTION_EQUIPMENT << ". Request Special Equipment" << endl;
        cout << OPTION_SECURITY << ". Request Security Support" << endl;
        cout << OPTION_EVENT << ". Request Event Support" << endl;
        cout << OPTION_DONE << ". Done" << endl;
        cout << OPTION_CANCEL << ". Cancel Reservation" << endl;
        cout << "=========================" << endl;

        choice = readChoice(OPTION_CANCEL);
        if (choice == OPTION_EQUIPMENT) {
            chooseEquipment(request, equipment);
        } else if (choice == OPTION_SECURITY) {
            request.add_support(SUPPORT_SECURITY);
        } else if (choice == OPTION_EVENT) {
            request.add_support(SUPPORT_EVENT);
        } else if (choice == OPTION_CANCEL) {
            return false;
        }
    }
    return true;
}

string supportName(char support) {
    if (support == SUPPORT_SECURITY) {
        return "Security";
    }
    if (support == SUPPORT_EVENT) {
        return "Event";
    }
    if (support == SUPPORT_BOTH) {
        return "Security and Event";
    }
    return "None";
}

void printSummary(const Reservation& request) {
    cout << "========== Reservation Submitted ==========" << endl;
    cout << "Room: " << request.get_location()->getLocation() << endl;
    cout << "Date: " << request.get_date() << endl;
    cout << "Time: " << request.get_time() << endl;
    cout << "Event: " << request.get_reason() << endl;

    cout << "Equipment requested:";
    if (request.get_requested().empty()) {
        cout << " None";
    }
    for (Equipment* item : request.get_requested()) {
        cout << " " << item->get_name();
    }
    cout << endl;

    cout << "Support: " << supportName(request.get_support()) << endl;
    cout << "Status: Requested (waiting for approval)" << endl;
    cout << "=========================" << endl;
}

int cancelReservation(Reservation& request) {
    request.cancel();
    cout << "Reservation cancelled" << endl;
    return 0;
}

// Work Flow so far: Select Date -> Select Time -> Select Room -> Enter Event Details -> Additional Support -> Submit Reservation
int main () {
    Reservation request;

    // Placeholder data: room capacities are made up
    Facility rooms[NUM_ROOMS] = {
        Facility(1, "Library Room", "Library Room 238", 40),
        Facility(2, "Toomey Room", "Toomey Room 112", 120),
        Facility(3, "CS Room", "CS Room 220", 60)
    };

    // Placeholder data: fake existing booking (CS Room 220, November 11, 12-2 PM) to show a room that is not available
    rooms[2].book(0, 12, 14);

    // Placeholder data: equipment names and quantities are made up
    Equipment equipment[NUM_EQUIPMENT] = {
        Equipment("Projector", 2),
        Equipment("Microphone", 4),
        Equipment("Speakers", 2)
    };

    cout << "========== Starting Reservation ==========" << endl;

    int day = chooseFromList("Select Date", DATES, NUM_DAYS);
    if (day == CANCELLED) {
        return cancelReservation(request);
    }

    int timeSlot = chooseFromList("Select Time", TIMES, NUM_TIMES);
    if (timeSlot == CANCELLED) {
        return cancelReservation(request);
    }
    int startHour = START_HOURS[timeSlot];
    int endHour = startHour + BOOKING_LENGTH_HOURS;
    request.apply_filter(DATES[day], TIMES[timeSlot]);

    Facility* room = chooseRoom(rooms, day, startHour, endHour);
    if (room == nullptr) {
        return cancelReservation(request);
    }
    request.set_location(room);

    request.set_reason(readEventDetails());

    if (!chooseSupport(request, equipment)) {
        return cancelReservation(request);
    }

    // Check again right before booking, because someone else could have taken the room while this user was filling out the form
    if (!room->book(day, startHour, endHour)) {
        cout << "Sorry, that room was just booked by someone else" << endl;
        return cancelReservation(request);
    }

    if (!request.submit()) {
        cout << "Something went wrong, the reservation could not be submitted" << endl;
        return 1;
    }
    printSummary(request);
    return 0;
}
