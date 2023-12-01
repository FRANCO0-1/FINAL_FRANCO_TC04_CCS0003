#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Booking {
    string date;
    string contactInfo;
    char package;
    int paymentMethod; // 1 - credit card, 2 - cash, 3 - gcash
    bool isWalkIn;
};

vector<vector<Booking>> weeklyBookings(7); // Store bookings for each day of the week (index 0-6)

bool isDayFullyBooked(int dayIndex) {
    return weeklyBookings[dayIndex].size() >= 30;
}

bool isDateAvailable(int dayIndex) {
    return dayIndex >= 0 && dayIndex < 7 && !isDayFullyBooked(dayIndex);
}

// Function to book for a photoshoot
void bookForPhotoshoot() {
    int dayIndex;
    cout << "What day would you like to shoot? (Enter day index: 0-6) ";
    cin >> dayIndex;

    if (!isDateAvailable(dayIndex)) {
        cout << "Sorry, the date is not available or fully booked. Please choose another date." << endl;
        return;
    }

    Booking newBooking;
    newBooking.date = to_string(dayIndex); // Storing day index as string for simplicity
    cout << "Please enter your contact info: ";
    cin >> newBooking.contactInfo;

    cout << "Please choose a package (A, B, C): ";
    cin >> newBooking.package;

    cout << "Choose a form of payment (1 - Credit Card, 2 - Cash, 3 - GCash): ";
    cin >> newBooking.paymentMethod;

    newBooking.isWalkIn = false; // Not a walk-in

    weeklyBookings[dayIndex].push_back(newBooking);
    cout << "Thank you for choosing Studio POP, please proceed to the cashier." << endl;
}

// Function for walk-in clients
void walkIn() {
    int dayIndex;
    cout << "What day is it today? (Enter day index: 0-6) ";
    cin >> dayIndex;

    if (!isDateAvailable(dayIndex)) {
        cout << "I'm sorry, it seems we are fully booked for today." << endl;
        return;
    }

    Booking newBooking;
    newBooking.date = to_string(dayIndex); // Storing day index as string for simplicity

    cout << "Please choose a package (A, B, C): ";
    cin >> newBooking.package;

    cout << "Choose a form of payment (1 - Credit Card, 2 - Cash, 3 - GCash): ";
    cin >> newBooking.paymentMethod;

    newBooking.isWalkIn = true;

    weeklyBookings[dayIndex].push_back(newBooking);
    cout << "Thank you for choosing Studio POP, please proceed to the cashier." << endl;
}

// Function to display menu packages
void displayPackages() {
    cout << "Packages:" << endl;
    cout << "A-800 (Toga shoot with 8x10 unframed photo)" << endl;
    cout << "B-1300 (Toga shot and creative shot with framed 8x10 toga photo and wallet size creative photo)" << endl;
    cout << "C-1999 (Toga shot and creative shot with 10x12 framed toga photo and wallet size of toga and creative photos)" << endl;
}

int main() {
    char option;
    do {
        cout << "Welcome to Studio POP, how may I help you?" << endl;
        cout << "1. Book for a photoshoot" << endl;
        cout << "2. Walk-in" << endl;
        cout << "3. See menu packages" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
        case '1':
            bookForPhotoshoot();
            break;
        case '2':
            walkIn();
            break;
        case '3':
            displayPackages();
            break;
        case '4':
            cout << "Exiting... Thank you for visiting Studio POP." << endl;
            break;
        default:
            cout << "Invalid option. Please choose again." << endl;
            break;
        }
    } while (option != '4');

    return 0;
}

