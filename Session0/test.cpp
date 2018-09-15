//
// Created by Connor DePalma on 9/15/18.
//

#include <iostream>
#include <random>
#include <iomanip>

using namespace std;
// 6.5 seconds for choose just returning 0
//19.7 seconds for 100 mil trials without memoization


double choose(int n, int r){
    static double nCr[501][501] = {0};


    if (r == 1 || r == n-1)
        return  nCr[n][r] = n;

    if (n == 0)
        return nCr[n][r] = 1;

    if (r == 0)
        return nCr[n][r] = 1;

    if (n==r)
        return nCr[n][r] = 1;

    if (nCr[n][r] != 0) {
        cout << "hey\n";
        return nCr[n][r];
    }

    return nCr[n][r] = choose(n-1,r) + choose(n-1,r-1); //based off of fibonacci pattern



}

int main(){
    uint64_t n,r;

    cin >> n;
    cin >> r;
    cout << setprecision(15);
    cout << choose(n,r)<< '\n';
}