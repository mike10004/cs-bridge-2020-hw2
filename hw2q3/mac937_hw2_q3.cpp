#include <iostream>

using namespace std;

const int MINUTES_PER_HOUR = 60;
const int HOURS_PER_DAY = 24;

int main() {
    int john_minutes, john_hours, john_days;
    int bill_minutes, bill_hours, bill_days;
    cout << "Please enter the number of days John has worked: ";
    cin >> john_days;
    cout << "Please enter the number of hours John has worked: ";
    cin >> john_hours;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> john_minutes;
    cout << endl;
    cout << "Please enter the number of days Bill has worked: ";
    cin >> bill_days;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> bill_hours;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> bill_minutes;
    cout << endl;
    int total_minutes = john_minutes + bill_minutes;
    int total_hours = john_hours + bill_hours;
    int total_days = john_days + bill_days;
    total_hours = total_hours + (total_minutes / MINUTES_PER_HOUR);
    total_minutes = total_minutes % MINUTES_PER_HOUR;
    total_days = total_days + (total_hours / HOURS_PER_DAY);
    total_hours = total_hours % HOURS_PER_DAY;
    cout << "The total time both of them worked together is: "
              << total_days << " days, "
              << total_hours << " hours and "
              << total_minutes << " minutes.\n";
    return 0;
}
