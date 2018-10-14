//
// Created by Connor DePalma on 10/13/18.
//
#include <iostream>
#include <vector>
using namespace std;


int main() {

    uint32_t **p;

    p = new uint32_t *[10];

    for (uint32_t i = 0; i < 10; i++) {
        p[i] = new uint32_t[10];
        for(int j = 0; j < 10; j++)
            p[i][j] = 0;
    };



    for (uint32_t i = 0; i < 10; i++) {
        for (uint32_t j = 0; j < 10; j++)
            cout << p[i][j] << ' ';

        cout << '\n';
    };
}


//    int y;
//    int x;
//
//    std::vector<std::vector<int>> array2d(10, std::vector<int>(10));
//
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = 0; j < 10; j++)
//        {
//            array2d[i][j] = 0;
//        }
//    }
//
//    array2d[2][3] = 5;
//
//    for (uint32_t i = 0; i < 10; i++) {
//        for (uint32_t j = 0; j < 10; j++)
//            cout << array2d[i][j] << ' ';
//
//        cout << '\n';
//    };
