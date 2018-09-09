//
// Created by Connor DePalma on 8/30/18.
//

#include<iostream>

using namespace std;


uint64_t fibo(int n) {
    static uint64_t memo[50] = {0}; //can never evaluate more than 50 times (100 maybe)

    if(n<=2)
        return 1;
    if(memo[n] != 0)
        return memo[n];
    return memo[n] = fibo(n-1) + fibo(n-2);
}


int main(){

    int n;
    cin >> n;
    cout << fibo(n);


}
// reg fibo recursive is BAD gets exp worse when inc n (2^n)



