//
// Created by Connor DePalma on 9/16/18.
//

#include <iostream>

using namespace std;

class Bitvec {

private:
    uint32_t size;
    uint32_t words;
    uint64_t* bits;


public:
    Bitvec(uint32_t n, bool b) : words((n+63)/64), size(n), bits(new uint64_t[words]){
        uint64_t val = b ? 0xFFFFFFFF :0;
        for (uint32_t i = 0; i<= words; i++)
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


    void set( uint32_t i) {
        bits[i >> 6] |= 1 << (i & 0x3f); //same as i/64 since its right shifting 2^6 and 'anding' with the lower six bits of the 16 bit words is same as i % 64
    }
/*
00000000000x0000 want x false
1111111111111111 << pos
1111111111101111 and with this



*/
    void clear( uint32_t i) {
        bits[i/ 64] &= ~(1 << (i % 32));

    }

    bool test(uint32_t i) {
        return (bits[i / 64] & (1 << (i % 32))) != 0;
    }
};

int main(){
    Bitvec b(0, true);

    for (uint32_t i = 0; i < 100 ; i++ )
        cout << b.test(i) << '\t';
    cout << '\n';

    b.clear(4);
    b.clear(32);
    for (uint32_t i = 0; i < 64 ; i++ )
        cout << b.test(i) << '\t';
}