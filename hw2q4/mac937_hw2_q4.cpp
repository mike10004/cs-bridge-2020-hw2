#include <iostream>

using namespace std;

int main() {
    int operand1, operand2;
    double operand1Double, operand2Double;
    cout << "Please enter two positive integers, separated by a space:\n";
    cin >> operand1 >> operand2;
    operand1Double = operand1;
    operand2Double = operand2;
    cout.setf(ios::fixed);
    cout.precision(1);
    cout << operand1 << " + " << operand2 << " = " << (operand1 + operand2) << endl;
    cout << operand1 << " – " << operand2 << " = " << (operand1 - operand2) << endl;
    cout << operand1 << " * " << operand2 << " = " << (operand1 * operand2) << endl;
    cout << operand1 << " / " << operand2 << " = " << (operand1Double / operand2Double) << endl;
    cout << operand1 << " div " << operand2 << " = " << (operand1 / operand2) << endl;
    cout << operand1 << " mod " << operand2 << " = " << (operand1 % operand2) << endl;
    return 0;
}
