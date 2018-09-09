//
// Created by Connor DePalma on 9/6/18.
//

#include <iostream>
#include <cmath>
using namespace std;



//bool isPrime(uint64_t n) {
//    for (int i = 2; i <= sqrt(n); i++) { //O(sqrt(n)) Ω(1) since sometimes you know right away that its prime
//        if (n % i == 0)
//            return false;
//    }
//    return true;
//
//
//
//}
//
//int countPrime(uint64_t n){ //O(n*sqrt(n)) // since it does isprime everytime
//    int count = 0;
//    for (uint64_t i =2; i<=n; i++){
//        if(isPrime(i))
//            count++;
//    }
//    return count;
//}

bool isPrime(uint64_t n) {
    for (int i = 3; i <= sqrt(n); i+=2) { //O(sqrt(n)) Ω(1) since sometimes you know right away that its prime
        if (n % i == 0)
            return false;
    }
    return true;

}

int countPrime(uint64_t n){ //O(n*sqrt(n)) // since it does isprime everytime
    int count = 1;
    for (uint64_t i = 3; i<=n; i += 2){
        if(isPrime(i))
            count++;
    }
    return count;
}




int main(){
    uint64_t n;
    cin >> n;
    cout << isPrime(n) << '\n';
}