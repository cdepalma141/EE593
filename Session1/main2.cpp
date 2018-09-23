//
// Created by Connor DePalma on 9/16/18.
//

#include <iostream>
#include <cmath>
#include <vector>
//0 to 10 mill very quick
//100 mill very quick too
//0 to 1 bill takes minutes not good
using namespace std;

int ES (uint64_t a, uint64_t b) {
    int count = 0;
    vector<uint8_t > bits;
    vector<uint8_t> bits1;

    auto c = uint64_t(sqrt(b)) + 1;

    bits.assign(c, 1);
    bits1.assign(b-a+1,1);
    bits[0] = 0;
    bits[1] = 0;
//
//    for (uint64_t i = 0; i < b-a+1; i++) {
//        cout << bits1[i] << '\t';
//
//    }

    //cout << '\n';

    for (uint64_t i = 2; i < c; i+=1) {
        if (bits[i]) {
            for (uint64_t j = i * i; j < c; j += i) {
                bits[j] = 0;
            }
        }
    }

//    for (uint64_t i = 0; i < c; i++) {
//        cout << bits[i] << '\t';
//
//    }
//
//    cout << '\n';


    for (uint64_t i = 2; i < c; i++) {
        if (bits[i]) {
            uint64_t start = a/i*i;
//            if (start < a)
//                start = i;
            for (uint64_t j = start; j < b+1; j += i) {
               if(j-a >= 0 && j-a < b-a+1)
                bits1[j-a] = 0;
                //if i is prime test if its divisible by i
            }
        }
    }

//    cout << '\n';
//
////
//    for (uint64_t i = 0; i < e.size(); i++) {
//        cout << e[i] << "\t";
//   }
//
//    cout << '\n';
//
//    for (uint64_t i = 0; i < b-a+1; i++) {
//        cout << bits1[i] << "\t";
//    }
//
//    cout << '\n';


    for (uint32_t i = 0; i < b-a+1; i++) {
        if (bits1[i])
            count++;
    }

//    if (Prime[b])
//     return count-1;

        return count;

}

int main (){
    uint64_t   a,b;
    cin >> a;
    cin >> b;

    cout << ES(a, b);
    cout << "\n\n";
}