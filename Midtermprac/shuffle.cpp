//
// Created by Connor DePalma on 10/16/18.
//

#include <iostream>
#include <random>

using namespace std;

void FY(int x[], int n){
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

    for(int i = n-1; i > 0; i--) {
        std::uniform_int_distribution<> dis(0, i);
        int pick = dis(gen);
        swap(x[i], x[pick]);
    }
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
}









int main() {

    int x[] = {1,2,3,4,5,6,7,8,9,10};
    FY(x,10);
}

