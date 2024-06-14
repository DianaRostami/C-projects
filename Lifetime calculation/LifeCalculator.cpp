#include <iostream>
#include <ctime>

using namespace std;

// تابع برای محاسبه سن به روز
void calculateAge(int birthYear, int birthMonth, int birthDay) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;

    // محاسبه سن به روز
    int ageInDays = 0;
    while (birthYear < currentYear || birthMonth < currentMonth || birthDay < currentDay) {
        ageInDays++;
        birthDay++;

        if ((birthMonth == 4 || birthMonth == 6 || birthMonth == 9 || birthMonth == 11) && birthDay == 31) {
            birthMonth++;
            birthDay = 1;
        } else if (birthMonth == 2 && ((birthYear % 4 == 0 && birthDay == 30) || (birthYear % 4 != 0 && birthDay == 29))) {
            birthMonth++;
            birthDay = 1;
        } else if (birthDay == 32) {
            birthMonth++;
            birthDay = 1;
        }

        if (birthMonth == 13) {
            birthYear++;
            birthMonth = 1;
        }
    }

    // محاسبه مدت زمان گذشته به دقیقه و ثانیه
    int ageInMinutes = ageInDays * 24 * 60;
    int ageInSeconds = ageInMinutes * 60;

    cout << "Your age in days is: " << ageInDays << endl;
    cout << "Your age in minutes is: " << ageInMinutes << endl;
    cout << "Your age in seconds is: " << ageInSeconds << endl;
}

int main() {
    int birthYear, birthMonth, birthDay;
    cout << "Enter your birth year: ";
    cin >> birthYear;
    cout << "Enter your birth month: ";
    cin >> birthMonth;
    cout << "Enter your birth day: ";
    cin >> birthDay;

    calculateAge(birthYear, birthMonth, birthDay);

    return 0;
}
