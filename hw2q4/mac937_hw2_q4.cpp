#include <iostream>

using namespace std;

void show_result(int operand1, int operand2, const char* op, int result)
{
    cout << operand1 << " "
              << op << " "
              << operand2 << " = "
              << result << endl;
}

void show_result(int operand1, int operand2, const char* op, double result)
{
    cout << operand1 << " "
              << op << " "
              << operand2 << " = "
              << result << endl;
}

int main() {
    int operand1, operand2;
    cout << "Please enter two positive integers, separated by a space:\n";
    cin >> operand1 >> operand2;
    cout.setf(ios::fixed);
    cout.precision(1);
    show_result(operand1, operand2, "+", operand1 + operand2);
    show_result(operand1, operand2, "–", operand1 - operand2);
    show_result(operand1, operand2, "*", operand1 * operand2);
    double div_result = double(operand1) / double(operand2);
    show_result(operand1, operand2, "/", div_result);
    show_result(operand1, operand2, "div", operand1 / operand2);
    show_result(operand1, operand2, "mod", operand1 % operand2);
    return 0;
}
