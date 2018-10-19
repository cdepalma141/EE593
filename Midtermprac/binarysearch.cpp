//
// Created by Connor DePalma on 10/16/18.
//

//
// Created by Connor DePalma on 10/15/18.
//

#include <iostream>
#include <cmath>

using namespace std;


int binary(int x[], int n, int target) {

    int i = 1;
    while (i < n) {
        int j = i;
        while(j>0 && x[j-1] > x[j]) {
            swap(x[j], x[j-1]);
            j--;
        }
        i++;

    }
    for (int a = 0; a< n; a++)
        cout << x[a] << ' ';

    i = 0;
    int j = n-1;
//    int guess = ((i+j)/2);
    while (i <= j) {
        int guess = ((i+j)/2);

        if(x[guess] == target)
            return guess;
        else if(x[guess] < target)
            i = guess + 1;
        else
            j = guess - 1;


    }
    return -1;

}






int main() {

    int x[] = {2, 6, 3, 10, 50, 5, 7, 8, 9, 1};
    cout << binary(x,10, 1);

}

