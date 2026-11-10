using namespace std;

#include <iostream>

int main () {
    int x;

    cout << "========== Booking ==========" << endl;
    cout << "1. Find Room" << endl;
    cout << "2. Find Equipment" << endl;
    cout << "3. Find Security" << endl;
    cout << "4. Exit" << endl;
    cout << "=========================" << endl;

    cin >> x;

    if (x == 1){
        cout << "BOOKING ROOM" << endl;
    } else if (x == 2){
        cout << "BOOKING EQUIPMENT" << endl;
    } else if (x == 3){
        cout << "BOOKING SECURITY" << endl;
    } else if (x == 4){
        return 0;
    } else {
        cout << "Not a valid option" << endl;
    }
