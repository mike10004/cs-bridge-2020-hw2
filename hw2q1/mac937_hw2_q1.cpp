#include <iostream>

const int CENTS_PER_QUARTER = 25;
const int CENTS_PER_DIME = 10;
const int CENTS_PER_NICKEL = 5;
const int CENTS_PER_PENNY = 1;

int read_int(const char* prompt)
{
    int n;
    std::cout << prompt;
    std::cin >> n;
    return n;
}

int main()
{
    int n_quarters, n_dimes, n_nickels, n_pennies;
    std::cout << "Please enter number of coins:\n";
    n_quarters = read_int("# of quarters: ");
    n_dimes = read_int("# of dimes: ");
    n_nickels = read_int("# of nickels: ");
    n_pennies = read_int("# of pennies: ");
    int total_cents = (n_quarters * CENTS_PER_QUARTER)
            + (n_dimes * CENTS_PER_DIME)
            + (n_nickels * CENTS_PER_NICKEL)
            + (n_pennies * CENTS_PER_PENNY);
    int n_dollars = total_cents / 100;
    int cents_remaining = total_cents % 100;
    std::cout << "The total is " << n_dollars << " and " << cents_remaining << " cents\n";
    return 0;
}
