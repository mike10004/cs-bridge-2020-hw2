#include <iostream>

const int UNITS = 3;
const char* UNIT_NAMES[] = {"days", "hours", "minutes"};
const int MINUTES_PER_UNIT[] = {24 * 60, 60, 1};
const int INDEX_DAYS = 0;
const int INDEX_HOURS = 1;
const int INDEX_MINUTES = 2;

/**
 * Calculates the number of minutes in a duration that specifies
 * days, hours, and minutes.
 * @param duration an array of length UNITS
 * @return total minutes in the duraiton
 */
int calculate_minutes(int* duration)
{
    int total = 0;
    for (int i = 0; i < UNITS; i++)
    {
        total += (MINUTES_PER_UNIT[i] * duration[i]);
    }
    return total;
}

/**
 * Read a duration from standard input.
 * @param person name of the person
 * @param duration array of length UNITS
 */
void read_duration(const char* person, int* duration)
{
    for (int i = 0; i < UNITS; i++)
    {
        std::cout << "Please enter the number of " << UNIT_NAMES[i] << " " << person << " has worked: ";
        std::cin >> duration[i];
    }
    std::cout << std::endl;
}

void minutes_to_duration(int minutes, int* duration)
{
    for (int i = 0; i < UNITS; i++)
    {
        duration[i] = minutes / MINUTES_PER_UNIT[i];
        minutes -= (duration[i] * MINUTES_PER_UNIT[i]);
    }
}

int main() {
    int duration_john[UNITS];
    int duration_bill[UNITS];
    read_duration("John", duration_john);
    read_duration("Bill", duration_bill);
    int minutes_john = calculate_minutes(duration_john);
    int minutes_bill = calculate_minutes(duration_bill);
    int duration_total[UNITS];
    minutes_to_duration(minutes_john + minutes_bill, duration_total);
    std::cout << "The total time both of them worked together is: "
              << duration_total[INDEX_DAYS] << " days, "
              << duration_total[INDEX_HOURS] << " hours and "
              << duration_total[INDEX_MINUTES] << " minutes.\n";
    return 0;
}
