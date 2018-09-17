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

int ES (uint64_t b) {
    int count = 0;
    vector<int> e;
    vector<bool> bits;

    auto c = uint64_t(sqrt(b));
   // cout << c << '\n';
    bits.assign(b, true);
    bits[0] = false;
    bits[1] = false;
//
//    for (uint64_t i = 0; i < bits.size(); i++) {
//        cout << bits[i] << '\t';
//
//    }

    cout << '\n';

    for (uint32_t i = 2; i < c+1 ; i++) {

//        if (i * i > c + 1)
//            continue;

        if (bits[i]) {
            for (uint32_t j = i * i; j < b + 1; j += i) {
//cout << j << '\t';
                bits[j] = false;
                e.push_back(j);
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
//    for (uint64_t i = 0; i < b+1; i++) {
//        cout << bits[i] << "\t";
//    }
//
//    cout << '\n';


    for (uint32_t i = 0; i < b; i++) {
        if (bits[i])
            count++;
    }

//    if (Prime[b])
//     return count-1;

        return count;

}

int main (){
    cout << ES(10000000);
}