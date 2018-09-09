#pragma once

class Bitvec {

    private:
        uint32_t size;
        uint64_t* bits;
        
    public:
        Bitvec(uint32_t size, bool b) : size(size), bits(new uint64_t[(size+63)/64]){
            uint64_t val =b ? 0xFFFFFFFFFFFFFFFF :0;
            for (int i =0; i<size; i++)
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
            bits[i >> 6] &= ~(1 << (i & 0x3f)); 

        }

        bool test(uint32_t i)
            return (bits[i/64] & (1 << (i%64))) != 0;}
};

