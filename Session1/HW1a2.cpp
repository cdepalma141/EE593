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


class Bitvec {

private:
    uint64_t size;
    uint64_t words;
    uint64_t* bits;


public:
    Bitvec(uint64_t n, bool b) : words((n+63)/64), size(n), bits(new uint64_t[words]){
        uint64_t val = b ? 0xFFFFFFFFFFFFFFFF :0;
        for (uint64_t i = 0; i<= words; i++)
            bits[i] = val;
    }
    ~Bitvec() {delete [] bits;}
    Bitvec(const Bitvec& orig) = delete;
    Bitvec& operator =(const Bitvec& orig) = delete;
/*
00000000000x0000 want x true
0000000000000001 << pos
0000000000010000 and with this



*/


    void set( uint64_t i) {
        bits[i >> 6] |= 1L << (i % 64); //same as i/64 since its right shifting 2^6 and 'anding' with the lower six bits of the 16 bit words is same as i % 64
    }
/*
00000000000x0000 want x false
1111111111111111 << pos
1111111111101111 and with this



*/
    void clear( uint64_t i) {
        bits[i/ 64] &= ~(1L << (i % 64));

    }

    bool test(uint64_t i) {
        return (bits[i / 64] & (1L << (i % 64))) != 0;
    }
};


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

    auto c = uint64_t(sqrt(b)) + 1;
    Bitvec Primes(c, true);
    Bitvec Primes1((b-a+1), true);
    Primes.clear(0);
    Primes.clear(1);
    int count = 0;


    for (uint64_t i = 2; i < c; i+=1) {
        if (Primes.test(i) == 1) {
            for (uint64_t j = i * i; j < c; j += i) {
                Primes.clear(j);
            }
        }
    }

//    for (int i = 0; i < c + 1; i++) {
//        cout << Primes.test(i) << "\t";
//    }
//
//    cout << '\n';

    for (uint64_t i = 2; i < c; i++) {
        if (Primes.test(i) == 1) {
            uint64_t start = (a)/i*i;
            for (uint64_t j = start; j <= b; j += i) {
                if(j >= a && (j-a) <= b-a)
                Primes1.clear(j-a);
            }
        }
    }

//
//    for (int i = 0; i < b-a+1; i++) {
//        cout << Primes1.test(i) << "\t";
//    }
//
//    cout << '\n';

    for (uint64_t i = a; i < c; i++) {
       if(Primes.test(i) ==1)
           Primes1.set(i-a);
       else if(Primes.test(i) ==0)
           Primes1.clear(i-a);
    }

//    for (int i = 0; i < b-a+1; i++) {
//        cout << Primes1.test(i) << "\t";
//    }
//
//    cout << '\n';

    for (uint64_t i = 0; i <= b-a; i++) {
        if (Primes1.test(i) == 1)
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