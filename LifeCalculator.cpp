#include <iostream>
#include <ctime>

using namespace std;

// Function to calculate age
void calculateAge(int birthYear, int birthMonth, int birthDay) {
    // Get current time
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    // Calculate age
    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;
    
    int ageYears = currentYear - birthYear;
    int ageMonths = currentMonth - birthMonth;
    int ageDays = currentDay - birthDay;

    // Adjust age if birth month or day is later in the current month
    if (ageDays < 0) {
        ageMonths--;
        ageDays += 30; // Assume each month has 30 days for simplicity
    }
    if (ageMonths < 0) {
        ageYears--;
        ageMonths += 12;
    }

    // Print age
    cout << "Your age is: " << ageYears << " years, " << ageMonths << " months, and " << ageDays << " days." << endl;
}

int main() {
    int year, month, day;
    
    // Get birthdate
    cout << "Enter your birth year: ";
    cin >> year;
    cout << "Enter your birth month: ";
    cin >> month;
    cout << "Enter your birth day: ";
    cin >> day;

    // Calculate age
    calculateAge(year, month, day);

    return 0;
}