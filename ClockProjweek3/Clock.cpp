#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void displayMenu();
void displayTime(int, int, int);
void displayTime12HourFormat(int, int, int);
// Menu display
void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Add Hours" << endl;
    cout << "2. Add Minutes" << endl;
    cout << "3. Add Seconds" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}
//instruction on displaying 24 hour format
void displayTime(int hours, int minutes, int seconds) {
    cout << "24-Hour Format: "
        << setfill('0') << setw(2) << hours << ":"
        << setfill('0') << setw(2) << minutes << ":"
        << setfill('0') << setw(2) << seconds << endl;
}
//instructions on displaying 12 hour format
void displayTime12HourFormat(int hours, int minutes, int seconds) {
    string period = "AM";
    int displayHours = hours;

    if (hours >= 12) { //deciding if pm or am
        period = "PM";
        if (hours > 12) { //if past 12 then pm and subract 12 to find pm time ie 13-12 = 1 pm
            displayHours = hours - 12;
        }
    }
    else if (hours == 0) { //if remainder is 12 then 12pm
        displayHours = 12;
    }

    cout << "12-Hour Format: " //correct format and spacing
        << setfill('0') << setw(2) << displayHours << ":"
        << setfill('0') << setw(2) << minutes << ":"
        << setfill('0') << setw(2) << seconds << " " << period << endl;
}
//main loop
int main() {
    int hours, minutes, seconds;
    char choice;

    // Get initial time input from user
    cout << "Enter initial time (hours, minutes, seconds): ";
    cin >> hours >> minutes >> seconds;

    // Loop until user chooses to exit
    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == '1') {
            int addHours;
            cout << "How many hours do you want to add? ";//ask input on added hours
            cin >> addHours;
            hours = (hours + addHours) % 24;
        }
        else if (choice == '2') {
            int addMinutes;
            cout << "How many minutes do you want to add? ";//ask input on added minutes
            cin >> addMinutes;
            minutes += addMinutes;//adding minutes to origional minutes
            hours = (hours + minutes / 60) % 24; //calculating if minutes are over 60 minutes now to add to hours
            minutes = minutes % 60;//finding new minutes with remainder
        }
        else if (choice == '3') {
            int addSeconds;
            cout << "How many seconds do you want to add? ";
            cin >> addSeconds;
            seconds += addSeconds;//adding seconds to origional seconds
            minutes += seconds / 60;//adding minutes if seconds over 60
            seconds = seconds % 60;//finding new seconds ammount with remainder
            hours = (hours + minutes / 60) % 24;//calculating if a new hour was added
            minutes = minutes % 60;//finding new minutes with remainder
        }
        else if (choice == '4') {//if user wants to quit
            break;
        }
        else {
            cout << "Invalid choice, please try again." << endl;//if correct number is not selected
            continue;
        }

        displayTime(hours, minutes, seconds);//output time 24hr
        displayTime12HourFormat(hours, minutes, seconds);//output time 12hr
    }

    return 0;
}

