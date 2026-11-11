#ifndef FACILITY_H
#define FACILITY_H

#include <string>
using namespace std;

class Facility {
    private:
        int id;
        string name;
        string location;
        bool availableTimes[8]; // Array to represent availability from 9 AM to 5 PM (8 hours)
    public:
        // Constructors
        Facility() : id(0), name(""), location("") {
            for (int i = 0; i < 8; ++i) {
                availableTimes[i] = true; // Initialize all times as available
            }
        }

        Facility(int id, const string& name, const string& location) : id(id), name(name), location(location) {
            for (int i = 0; i < 8; ++i) {
                availableTimes[i] = true; // Initialize all times as available
            }
        }

        // Getters
        int getId() const { return id; }
        string getName() const { return name; }
        string getLocation() const { return location; }
        
        // Setters
        void setId(int newId) { id = newId; }
        void setName(const string& newName) { name = newName; }
        void setLocation(const string& newLocation) { location = newLocation; }
};

#endif