#include <iostream>

void show_result(int operand1, int operand2, const char* op, int result)
{
    std::cout << operand1 << " "
              << op << " "
              << operand2 << " = "
              << result << std::endl;
}

void show_result(int operand1, int operand2, const char* op, double result)
{
    std::cout << operand1 << " "
              << op << " "
              << operand2 << " = "
              << result << std::endl;
}

int main() {
    int operand1, operand2;
    std::cout << "Please enter two positive integers, separated by a space:\n";
    std::cin >> operand1 >> operand2;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);
    show_result(operand1, operand2, "+", operand1 + operand2);
    show_result(operand1, operand2, "-", operand1 - operand2);
    show_result(operand1, operand2, "*", operand1 * operand2);
    double div_result = double(operand1) / double(operand2);
    show_result(operand1, operand2, "/", div_result);
    show_result(operand1, operand2, "div", operand1 / operand2);
    show_result(operand1, operand2, "mod", operand1 % operand2);
    return 0;
}
