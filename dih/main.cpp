#include <iostream>
#include <cmath>

using namespace std;

double evaluateEquation(double x) {
    return (pow(2, x) - (2 * pow(x, 2)) + 1);
}

double solveByBisection(double a, double b, double epsilon) {
    double left = a;
    double right = b;
    double mid = 0.0;

    while ((right - left) > epsilon) {
        mid = (left + right) / 2.0;
        double f_mid = evaluateEquation(mid);
        
        if (f_mid == 0.0) {
            return mid;
        } else if (f_mid * evaluateEquation(left) < 0) {
            right = mid;
        } else {
            left = mid;
        }
    }

    return (left + right) / 2.0;
}

int main() {
    double a = 0.0;
    double b = 3.0;
    double epsilon = 1e-4;
    double solution = solveByBisection(a, b, epsilon);
    cout << "Solution: " << solution << endl;

    return 0;
}
