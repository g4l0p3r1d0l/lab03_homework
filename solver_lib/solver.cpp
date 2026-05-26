#include "solver.h"
#include <cmath>
#include <vector>

std::vector<double> solve(double a, double b, double c) {
    std::vector<double> roots;
    double d = b*b - 4*a*c;
    if (d < 0) return roots;
    if (d == 0) {
        roots.push_back(-b / (2*a));
    } else {
        roots.push_back((-b + std::sqrt(d)) / (2*a));
        roots.push_back((-b - std::sqrt(d)) / (2*a));
    }
    return roots;
}
