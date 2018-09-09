
public class Bitvec {

    private int size;
    private long[] bits;
        
    public Bitvec(int size, boolean b) {
        this.size = size;
        final int WORDSIZE = (size +63)/64;
        this.bits = new long [WORDSIZE];
            uint64_t val =b ? 0xFFFFFFFFFFFFFFFFL :0;
            for (int i =0; i<WORDSIZE; i++)
                bits[i] = val;
        }
       
/*
00000000000x0000 want x true
0000000000000001 << pos
0000000000010000 and with this



*/


        public void set( int i) {
            bits[i >> 6] |= 1 << (i & 0x3f); //same as i/64 since its right shifting 2^6 and 'anding' with the lower six bits of the 16 bit words is same as i % 64
        }
/*
00000000000x0000 want x false
1111111111111111 << pos
1111111111101111 and with this



*/
        public void clear( int i) {
            bits[i >> 6] &= ~(1 << (i & 0x3f)); 

        }

        public bool test(int i){
            return (bits[i/64] & (1 << (i%64))) != 0;
        }

        public static void main (String[]args){
            Bitvec b = new Bitvec(1024, false);
            System.out.println(b.test(i));
            b.test(128);
            System.out.println(b.test(128));
        }
}
