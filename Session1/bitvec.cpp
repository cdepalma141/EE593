//
// Created by Connor DePalma on 9/16/18.
//

#include <iostream>
#include <vector>
using namespace std;





int main(){
    int count = 0;
   vector<bool> bits;

   bits.assign(1414213, false);


    for (uint64_t i; i < bits.size(); i++) {
        //cout << bits[i] << '\t';
        count++;
    }
    cout << count;

}