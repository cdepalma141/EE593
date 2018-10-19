//
// Created by Connor DePalma on 10/15/18.
//

#include <iostream>

using namespace std;


void InsertionSort(int x[], int n) {
    int i = 1;
    while (i < n) {
        int j = i;
        while(j>0 && x[j-1] > x[j]) {
            swap(x[j], x[j - 1]);
            j--;
        }
        i++;

    }
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
}









int main() {

    int x[] = {2, 6, 3, 10, 50, 5, 7, 8, 9, 1};
    InsertionSort(x,10);
}

