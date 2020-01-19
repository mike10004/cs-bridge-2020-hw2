#include <iostream>

using namespace std;

const int CENTS_PER_QUARTER = 25;
const int CENTS_PER_DIME = 10;
const int CENTS_PER_NICKEL = 5;
const int CENTS_PER_PENNY = 1;

int main() {
    cout << "Please enter your amount in the format of dollars and cents separated by a space:\n";
    int n_dollars, n_cents, total_cents;
    cin >> n_dollars >> n_cents;
    
    total_cents = (n_dollars * 100) + n_cents;
    int n_quarters, n_dimes, n_nickels, n_pennies;
    n_quarters = total_cents / CENTS_PER_QUARTER;
    total_cents = total_cents - (n_quarters * CENTS_PER_QUARTER);
    n_dimes = total_cents / CENTS_PER_DIME;
    total_cents = total_cents - (n_dimes * CENTS_PER_DIME);
    n_nickels = total_cents / CENTS_PER_NICKEL;
    n_pennies = total_cents - (n_nickels * CENTS_PER_NICKEL);
    
    cout << n_dollars << " dollars and " << n_cents << " cents are:\n";
    cout << n_quarters << " quarters, " 
         << n_dimes << " dimes, "
         << n_nickels << " nickels and "
         << n_pennies << " pennies\n";
    return 0;
}
