//
// Created by Connor DePalma on 10/15/18.
//

#include <iostream>
#include <cmath>
using namespace std;
uint64_t ES(uint64_t a){
    bool primes[a];
    for (int i = 0; i <a; i++)
        primes[i] = true;
    primes[0] = false;
    primes[1] = false;

    for(int i = 2; i < sqrt(a); i++) {
        if (primes[i]) {
            for (int j = i * i; j < a; j += i)
                primes[j] = false;
        }
    }

    uint64_t count = 0;

    for (int i = 0; i < a; i++) {
        if (primes[i])
            count++;
    }

    return count;
}

int main(){
    cout << ES(1000000);
}