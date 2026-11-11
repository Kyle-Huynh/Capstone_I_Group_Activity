#include <iostream>
#include <string>
#include "facility.h"
#include "reservation.h"
#include "person.h"
using namespace std;

/* Function to select time, currently not used in main function
void selectTime() {
    cout << "========== Select Time ==========" << endl;
    cout << "1. 12:00 PM - 2:00 PM" << endl;
    cout << "2. 1:00 PM - 3:00 PM" << endl;
    cout << "3. 2:00 PM - 4:00 PM" << endl;
    cout << "4. Exit" << endl;
    cout << "=========================" << endl;
}
*/

/* Function to select date, currently not used in main function
void selectDate() {
    cout << "========== Select Date ==========" << endl;
    cout << "1. November 11, 2026" << endl;
    cout << "2. November 16, 2026" << endl;
    cout << "3. November 18, 2026" << endl;
    cout << "4. Exit" << endl;
    cout << "=========================" << endl;
    selectTime();
}
*/

// Work Flow so far: Select Room -> Select Date -> Select Time -> Confirm Reservation
int main () {
    int selectedRoom, selectedDate, selectedTime;

    // Replace code with classes we used after we get the work flow sorted
    facility libraryRoom;
    libraryRoom.setId(1);
    libraryRoom.setLocation("Library Room 238");
    facility toomeyRoom;
    toomeyRoom.setId(2);
    toomeyRoom.setLocation("Toomey Room 112");
    facility csRoom;
    csRoom.setId(3);
    csRoom.setLocation("CS Room 220");
    

    cout << "========== Starting Reservation ==========" << endl;
    cout << "1. " << libraryRoom.getLocation << endl;
    cout << "2. Toomey Room 112" << toomeyRoom.getLocation << endl;
    cout << "3. CS Room 220" << csRoom.getLocation << endl;
    cout << "4. Cancel Revervation" << endl;
    cout << "=========================" << endl;

    cin >> selectedRoom << endl;
    

    if (selectedRoom > 0 && selectedRoom < 4) {
        cout << "========== Select Date ==========" << endl;
        cout << "1. November 11, 2026" << endl;
        cout << "2. November 16, 2026" << endl;
        cout << "3. November 18, 2026" << endl;
        cout << "4. Cancel Reservation" << endl;
        cout << "=========================" << endl;
        cin >> selectedDate << endl;

        cout << "========== Select Time ==========" << endl;
        cout << "1. 12:00 PM - 2:00 PM" << endl;
        cout << "2. 1:00 PM - 3:00 PM" << endl;
        cout << "3. 2:00 PM - 4:00 PM" << endl;
        cout << "4. Cancel Reservation" << endl;
        cout << "=========================" << endl;
        cin >> selectedTime << endl;

        cout << "========== Additional Support ==========" << endl;
        cout << "1. Request Special Equipment" << endl;
        cout << "2. Request Security Support" << endl;
        cout << "3. Request Event Support" << endl;
        cout << "4. Done" << endl;
        cout << "5. Cancel Reservation" << endl;
        cout << "=========================" << endl;

    } else {
        cout << "Not a valid option" << endl;
    }
}