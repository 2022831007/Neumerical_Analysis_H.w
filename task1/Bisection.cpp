
#include <bits/stdc++.h>
using namespace std;

double tolerance = 1e-6;
int max_iter = 100;

double f(double x) {
    return 4 * pow(x, 2) + 3 * x - 3;
}
void BisectionTraditional(double a, double b) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval: No sign change in [" << a << ", " << b << "]\n";
        return;
    }

    int iteration = 0;
    double c;

    while ((b - a) >= tolerance && iteration < max_iter) {
        c = (a + b) / 2;
        iteration++;

        if (f(c)==0) break;

        if (f(a) * f(c) < 0){
            b = c;
        }
        else if(f(b)*f(c)<0){
            a = c;
        }
    }

    cout << "Traditional Method:\n";
    cout << "Root : " << fixed << setprecision(6) << c << ", Iterations: " << iteration << endl;
}

bool BetterRange(double &a, double &b) {
    double step = 0.1;
    for (double i = -100; i < 100; i += step) {
        if (f(i) * f(i + step) < 0) {
            a = i;
            b = i + step;
            return true;
        }
    }
    return false;
}
void BisectionBetter() {
    double a, b;

    if (!BetterRange(a, b)) {
        cout << "No sign change found in the range [-100, 100]." << endl;
        return;
    }

    int iteration = 0;
    double c;

    while ((b - a) >= tolerance && iteration < max_iter) {
        c = (a + b) / 2;
        iteration++;

        if (f(c)==0) break;

        if (f(a) * f(c) < 0){
            b = c;
        }
        else if(f(b)*f(c)<0){
            a = c;
        }
    }

    cout << "Better Method:\n";
    cout << "Root : " << fixed << setprecision(6) << c << ", Iterations: " << iteration << endl;
}

int main() {
    BisectionTraditional(0, 1);
    BisectionBetter();
    return 0;
}
