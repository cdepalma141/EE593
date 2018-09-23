//
// Created by Connor DePalma on 9/20/18.
//
#include <iostream>
#include <cmath>

using namespace std;

double f1(double x) {
    return x*x -2;
}


typedef double (*FuncOneVar)(double);

double bisection(FuncOneVar f, double a, double b, double eps){

    double y1 = f(a), y2 = f(b);
    double x;
    do {
        x = (a+b)/2;
        double y = f(x);
        if(y>0)
            b = x;
        else if (y<0)
            a = x;
        else
            return x;


    } while (b-a > eps);
    return x;

}


//bits in double -- 64
//1 bit sign 11 bit exponent mantissa efftive 57 bits