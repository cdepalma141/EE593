//
// Created by Connor DePalma on 8/30/18.
//


#include <iostream>

using namespace std;


//nCr = n!/(r!(n-r)!)
//52C6 = 52!/6!(46!) = divide by the large fact  n! is O(n)
//worst case is n/2



double choose(double n, double r){

    double a;
    double d;

    if (n >= r) {
        if (n - r < r && n != r) {
            a = r;
            d = n - r;
            for (int i = n - r - 1; i > 1; i--)
                d *= i;
        } else if (n == r) {
        d = n;
        a = n - 1;
        }
        else {
            a = (n - r);
            d = r;
            for (int i = r - 1; i > 1; i--)
                d *= i;
        }

    }

    else {
        cout <<  "r should not be greater than n";
        return 0;
    }



    for (int i = n-1; i > a; i--){
        n *= i;
    }

    return n/d;

}



int main(){
    double n, r;
    cout << "Enter n and r: \n";
    cin >> n;
    cin >> r;
    cout << choose(n,r) << '\n';

    //cout << choose(n,r) << '\n'; //nCr // O(n)

    //n<500 r<n ,
    //choose (52,10), (52,15) , (52

}
