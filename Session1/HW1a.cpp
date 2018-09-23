/*
 * HW1a - Compute Primes
 *
 * Connor DePalma.
 *
 * I pledge my honor that I have abided by the Stevens Honor System.
 *
 */


#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;
/*
 * Tests with -O2:
 *
 * 9,998,999,999,999 to 9,999,999,999,999 in 13.6 seconds (this should be max possible for testing since the
 * max size of the array is 10^9 and the value of b is just below 10^14)
 *
 * 2,000,000,000,000 to 2,000,000,100,000 in 0.013 seconds
 *
 * Can't test to see if returned values are correct for such large numbers but online sources confirm
 * that the values achieved with this for 0 to 10,000,000 (664,579 primes) and random lower
 * number sets like 8000 to 67890 (5,754 primes) seem to be correct.
 *
 *
 * I left in cout statements that I used for testing to see what values the function was choosing to be prime.
 *
 * I attempted to use bit vectors with the same format as this function but it wasn't nearly as fast with the way
 * I was able to do it but the assignment didn't require it.
 *
 */

int ES(uint64_t a, uint64_t b) {

    auto c = uint64_t(sqrt(b));
    bool *Prime = new bool[c + 1];
    bool *Prime1 = new bool[b-a + 1];

    int count = 0;

    for (uint64_t i = 2; i < c + 1; i++)
        Prime[i] = true;

    for (uint64_t i = 0; i < b-a+1; i++)
        Prime1[i] = true;

    for (uint64_t i = 2; i < c + 1; i+=1) {
        if (Prime[i]) {
            for (uint64_t j = i * i; j < c+1; j += i) {
                Prime[j] = false;
            }
        }
    }

//    for (int i = 0; i < c + 1; i++) {
//        cout << Prime[i] << "\t";
//    }
//
//    cout << '\n';

    for (uint64_t i = 2; i < c + 1; i++) {
        if (Prime[i]) {
            uint64_t start = (a)/i*i;
            for (uint64_t j = start; j < b +1; j += i) {
                if(j >= a && (j-a) < b-a+1)
                Prime1[j-a] = false;
            }
        }
    }

//
//    for (int i = 0; i < b-a+1; i++) {
//        cout << Prime1[i] << "\t";
//    }
//
//    cout << '\n';

    for (uint64_t i = a; i < c+1; i++)
        Prime1[i-a] = Prime[i];

//    for (int i = 0; i < b-a+1; i++) {
//        cout << Prime1[i] << "\t";
//    }
//
//    cout << '\n';

    for (uint64_t i = 0; i < b-a+1; i++) {
        if (Prime1[i])
            count++;
    }

    return count;
}



int main() {
    uint64_t a,b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    cout << "There are " << ES(a, b) << " primes between " << a << " and " << b << '\n';
}