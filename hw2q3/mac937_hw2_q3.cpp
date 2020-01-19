#include <iostream>

const int MINUTES_PER_HOUR = 60;
const int HOURS_PER_DAY = 24;

int main() {
    int john_minutes, john_hours, john_days;
    int bill_minutes, bill_hours, bill_days;
    std::cout << "Please enter the number of days John has worked: ";
    std::cin >> john_days;
    std::cout << "Please enter the number of hours John has worked: ";
    std::cin >> john_hours;
    std::cout << "Please enter the number of minutes John has worked: ";
    std::cin >> john_minutes;
    std::cout << std::endl;
    std::cout << "Please enter the number of days Bill has worked: ";
    std::cin >> bill_days;
    std::cout << "Please enter the number of hours Bill has worked: ";
    std::cin >> bill_hours;
    std::cout << "Please enter the number of minutes Bill has worked: ";
    std::cin >> bill_minutes;
    std::cout << std::endl;
    int total_minutes = john_minutes + bill_minutes;
    int total_hours = john_hours + bill_hours;
    int total_days = john_days + bill_days;
    total_hours = total_hours + (total_minutes / MINUTES_PER_HOUR);
    total_minutes = total_minutes % MINUTES_PER_HOUR;
    total_days = total_days + (total_hours / HOURS_PER_DAY);
    total_hours = total_hours % HOURS_PER_DAY;
    std::cout << "The total time both of them worked together is: "
              << total_days << " days, "
              << total_hours << " hours and "
              << total_minutes << " minutes.\n";
    return 0;
}
