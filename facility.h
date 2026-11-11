#ifndef FACILITY_H
#define FACILITY_H

#include <string>
using namespace std;

const int NUM_DAYS = 3;
const int OPEN_HOUR = 9;
const int CLOSE_HOUR = 17;
const int HOURS_PER_DAY = CLOSE_HOUR - OPEN_HOUR;

class Facility {
    private:
        int id;
        string name;
        string location;
        int capacity;
        bool availableTimes[NUM_DAYS][HOURS_PER_DAY]; // Array to represent availability from 9 AM to 5 PM (8 hours)
    public:
        // Constructors
        Facility() : Facility(0, "", "", 0) {}

        Facility(int id, const string& name, const string& location, int capacity = 0) : id(id), name(name), location(location), capacity(capacity) {
            for (int day = 0; day < NUM_DAYS; day++) {
                for (int hour = OPEN_HOUR; hour < CLOSE_HOUR; hour++) {
                    availableTimes[day][hour - OPEN_HOUR] = true; // Initialize all times as available
                }
            }
        }

        // Getters
        int getId() const { return id; }
        string getName() const { return name; }
        string getLocation() const { return location; }
        int getCapacity() const { return capacity; }

        // Setters
        void setId(int newId) { id = newId; }
        void setName(const string& newName) { name = newName; }
        void setLocation(const string& newLocation) { location = newLocation; }
        void setCapacity(int newCapacity) { capacity = newCapacity; }

        bool isFree(int day, int startHour, int endHour) const {
            if (day < 0 || day >= NUM_DAYS || startHour < OPEN_HOUR || endHour > CLOSE_HOUR || startHour >= endHour) {
                return false;
            }
            for (int hour = startHour; hour < endHour; hour++) {
                if (!availableTimes[day][hour - OPEN_HOUR]) {
                    return false;
                }
            }
            return true;
        }

        bool book(int day, int startHour, int endHour) {
            if (!isFree(day, startHour, endHour)) {
                return false;
            }
            for (int hour = startHour; hour < endHour; hour++) {
                availableTimes[day][hour - OPEN_HOUR] = false;
            }
            return true;
        }
};

#endif
