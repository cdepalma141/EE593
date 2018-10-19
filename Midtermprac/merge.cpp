//
// Created by Connor DePalma on 10/15/18.
//

#include <iostream>

using namespace std;

void merge ( int x[], int L, int R){
    int mid = (R+L)/2;
    int* copy = new int[mid];
    for (int i = L; i < mid; i ++)
        copy[i-L] = x[i];

    int lp = 0;
    int rp = mid;
    int p = L;

    while (lp < mid && rp < R){
        if(copy[lp] < x[rp])
            x[p++] = copy[lp++];
        else
            x[p++] = x[rp++];
    }
    while(lp < mid)
        x[p++] = copy[lp++];
    while(rp < R){
        x[p++] = x[rp++];
    }

    for (int i = 0; i < R-L; i++)
        cout << x[i] << ' ';
}


int main() {

    int x[] = {1, 7, 8 ,9, 10, 1, 2 ,3 ,4 ,5};
    int y[] = {6, 8, 9 ,12, 14, 3, 5 ,7,10 ,11};

    merge(x , 0 , 10);
    cout << '\n';
    merge(y , 0 , 10);
}
