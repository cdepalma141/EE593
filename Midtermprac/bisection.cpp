//
// Created by Connor DePalma on 10/16/18.
//
#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

double f(double x) { return x*x - 2; } // root is sqrt(2)


typedef double (*FuncOneVar)(double x);

double bisection(FuncOneVar f, double a, double b, double eps) {
    double y1 = f(a);
    double y2 = f(b);
    if(y1*y2 <0)
        ;
    else
        return 1;

    while (abs(b-a) > eps) {
        double guess = (a+b)/2;
        double y = f(guess);
        if(y>0)
            b = guess;
        else if (y<0)
            a = guess;


    }

    return (a+b)/2;




}






int main() {
    for (double eps = .1; eps > 1e-25; eps *= .1) {
        cout << setprecision(25) << bisection(f, 1, -50, eps) << '\n';
        //	cout << bisection(sin, pi, 3*pi, 0.001) << '\n';
    }
}
