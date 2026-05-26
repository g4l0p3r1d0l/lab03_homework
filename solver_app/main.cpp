#include <iostream>
#include "formatter_ex.h"
#include "solver.h"

int main() {
    double a, b, c;
    std::cout << "Enter a, b, c: ";
    std::cin >> a >> b >> c;
    auto roots = solve(a, b, c);
    std::string msg = "Roots: ";
    for (double r : roots) msg += std::to_string(r) + " ";
    std::cout << format_ex(msg) << std::endl;
    return 0;
}
