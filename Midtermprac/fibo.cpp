//
// Created by Connor DePalma on 10/15/18.
//

#include <iostream>

using namespace std;
uint64_t fibo (uint64_t n) {
    static uint64_t mem[500] = {0};

    if (n <= 2)
        return 1;
    if(mem[n] != 0)
        return mem[n];
    return mem[n] = fibo(n-1) + fibo(n-2);

}

int main(){
    cout << fibo(30);
}