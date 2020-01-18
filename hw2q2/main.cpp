#include <iostream>

const int DENOMINATIONS[] = {25, 10, 5, 1};
const char* DENOMINATION_NAMES[] = {"quarters", "dimes", "nickels", "pennies"};
const int DENOMINATIONS_COUNT = 4;

int main() {
    std::cout << "Please enter your amount in the format of dollars and cents separated by a space:\n";
    int n_dollars, n_cents, total_cents;
    std::cin >> n_dollars >> n_cents;
    std::cout << n_dollars << " dollars and " << n_cents << " cents are:\n";
    total_cents = (n_dollars * 100) + n_cents;
    for (int i = 0; i < DENOMINATIONS_COUNT; i++)
    {
        int n_coins = total_cents / DENOMINATIONS[i];
        if (i == (DENOMINATIONS_COUNT - 1))
        {
            std::cout << " and ";
        }
        else if (i > 0)
        {
            std::cout << ", ";
        }
        std::cout << n_coins << " " << DENOMINATION_NAMES[i];
        total_cents -= (n_coins * DENOMINATIONS[i]);
    }
    return total_cents;
}
