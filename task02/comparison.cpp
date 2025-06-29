#include <bits/stdc++.h>
using namespace std;
double Es = 1e-4;
int max_iter = 100;
double f(double x) {
    return 4 * x * x + 3 * x - 3;
}
void RegulaFalsi(double a, double b) {
    if (f(a) * f(b) >= 0) {
        cout << "Regula Falsi: Invalid interval: No sign change in [" << a << ", " << b << "]\n";
        return;
    }
    double c;
    int iteration = 0;

    while ((b - a) >= Es && iteration < max_iter) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        iteration++;
        if (f(c) == 0){
            break;
        }

        if (f(a) * f(c) < 0){
            b = c;
        }
        else if (f(b) * f(c) < 0){
            a = c;
        }
        
    }

    cout << "Regula Falsi Method:\n";
    cout << "Root : " << fixed << setprecision(6) << c<< ", Iterations: " << iteration<< endl;
}
void Bisection(double a, double b) {
    if (f(a) * f(b) >= 0) {
        cout << "Bisection: Invalid interval: No sign change in [" << a << ", " << b << "]\n";
        return;
    }

    int iteration = 0;
    double c;

    while ((b - a) >= Es && iteration < max_iter) {
        c = (a + b) / 2;
        iteration++;

        if (f(c) == 0){
            break;
        }

        if (f(a) * f(c) < 0){
            b = c;
        }
        else if(f(b)*f(c)<0){
            a = c;
        }
    }

    cout << "Bisection Method:\n";
    cout << "Root : " << fixed << setprecision(6) << c<< ", Iterations: " << iteration << endl;
}

int main() {
    double a = 0, b = 1; 

    Bisection(a, b);
    RegulaFalsi(a, b);

    return 0;
}
