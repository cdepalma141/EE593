//
// Created by Connor DePalma on 9/2/18.
//

#include <iostream>

using namespace std;

int main() {


   double n, r, d;
    cin >> n;
    cin >> r;
    d = n-r;

    if (d != 0) {
        for (int i = n - r - 1; i > 1; i--) {
            d *= i;
        }
    }
    else
        d = 1;


    for (int i = r-1; i > 1; i--){
            r *= i;
    }
    for (int i = n-1; i > 1; i--){
            n *= i;
    }

    cout << d << '\n';
    cout << n << '\n';
    cout << r << '\n';

    cout << n/(r*d) << '\n';

};