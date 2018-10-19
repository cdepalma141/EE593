//
// Created by Connor DePalma on 10/16/18.
//

#include <iostream>

using namespace std;

void makesubheap(int* x, int i){
    if (2*i + 1 <=8) {
        if (x[2 * i + 1] > x[2 * i + 2]) {
            if (x[2 * i + 1] > x[i])
                swap(x[2 * i + 1], x[i]);
            makesubheap(x, 2 * i + 1);
        } else if (x[2 * i + 2] > x[i]) {
            swap(x[2 * i + 2], x[i]);
            makesubheap(x, 2 * i + 2);
        }
    }

}

void makeheap(int* x, int n){
    for(int i = n/2; i > 0; i--)
        makesubheap(x, i);


}


void heapsort(int x[], int n){
    makeheap(x, n);
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
    for(int i = n-1; i > 0; i--) {
        swap(x[0], x[i]);
        makesubheap(x, i-1);
    }


}



int main() {

    int x[] = {2, 6, 3, 10, 50, 5, 7, 8};
    heapsort(x,8);
}