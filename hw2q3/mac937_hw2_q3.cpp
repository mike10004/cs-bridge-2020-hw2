#include <iostream>
#include <climits>

const int UNITS = 3;
const char* UNIT_NAMES[] = {"days", "hours", "minutes"};
const int MINUTES_PER_UNIT[] = {24 * 60, 60, 1};
const int UNIT_DIVISORS[] = {INT_MAX, 24, 60};
const int INDEX_DAYS = 0;
const int INDEX_HOURS = 1;
const int INDEX_MINUTES = 2;

/**
 * Calculates the number of minutes in a duration that specifies
 * days, hours, and minutes.
 * @param duration an array of length UNITS
 * @return total minutes in the duraiton
 */
int calculate_minutes(const int* duration)
{
    int total = 0;
    for (int i = 0; i < UNITS; i++)
    {
        total += (MINUTES_PER_UNIT[i] * duration[i]);
    }
    return total;
}

void minutes_to_duration(int minutes, int* duration)
{
    for (int i = 0; i < UNITS; i++)
    {
        duration[i] = minutes / MINUTES_PER_UNIT[i];
        minutes -= (duration[i] * MINUTES_PER_UNIT[i]);
    }
}

/**
 * Sums two durations. All argument arrays must be of length UNITS.
 * @param d1 array representing a duration
 * @param d2 array summand representing a duration
 * @param sum destination array 
 */
void add_durations(const int* d1, const int* d2, int* sum)
{
    if (getenv("ELEMENTARY") != nullptr && atoi(getenv("ELEMENTARY")) == 1) 
    {
        int carried = 0;
        for (int i = UNITS - 1; i >= 0; i--) {
            int unit_sum = d1[i] + d2[i] + carried;
            int remainder = unit_sum % UNIT_DIVISORS[i];
            sum[i] = remainder;
            carried = unit_sum / UNIT_DIVISORS[i];
        }
    } else {
        int minutes1 = calculate_minutes(d1);
        int minutes2 = calculate_minutes(d2);
        minutes_to_duration(minutes1 + minutes2, sum);
    }
}

/**
 * Read a duration from standard input.
 * @param person name of the person
 * @param duration destination array of length UNITS
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

int main() {
    int duration_john[UNITS];
    int duration_bill[UNITS];
    read_duration("John", duration_john);
    read_duration("Bill", duration_bill);
//    int minutes_john = calculate_minutes(duration_john);
//    int minutes_bill = calculate_minutes(duration_bill);
    int duration_total[UNITS];
//    minutes_to_duration(minutes_john + minutes_bill, duration_total);
    add_durations(duration_john, duration_bill, duration_total);
    std::cout << "The total time both of them worked together is: "
              << duration_total[INDEX_DAYS] << " days, "
              << duration_total[INDEX_HOURS] << " hours and "
              << duration_total[INDEX_MINUTES] << " minutes.\n";
    return 0;
}
