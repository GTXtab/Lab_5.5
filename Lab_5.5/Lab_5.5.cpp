#include <iostream>
#include <cmath>

using namespace std;

double rec_fun(double a, double L, double eps, int& depth) {
    depth++;
    if (abs(a - L) > eps) {
        return rec_fun((1. / 3.) * (2. * a + (8. / pow(a, 2))), L, eps, depth);
    }
    else {
        return a;
    }
}

int main() {
    double eps = 0.00001;
    double a = 1.0;
    double L = 2.0; // границ€ n > 0;
    int depth = 0; // глибина рекурс≥њ

    double result = rec_fun(a, L, eps, depth);

    cout << "Result: a = " << result << ", Depth = " << depth << endl;

    return 0;
}
