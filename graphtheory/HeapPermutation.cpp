//
// Created by Connor DePalma on 12/1/18.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Permutation {
private:
    int n;
    int* v;
    void doit() {
        for (int i = 0; i < n; i ++){
            cout << v[i] << '\t';
        }
        cout << '\n';


    }

    void swap(int i, int j){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

    void heapgenerate(int n) {
        if (n == 0)
            doit();

        for (int c = 0; c < n; c++){
            heapgenerate(n-1);
            swap(n%2 == 0 ? 0:c, n-1);
        }
    }

    void simplegenerate(int n) {
        if(n == 0)
            doit();
        
        for(int c = 0; c < n; c++){
            swap(c,n-1);
            simplegenerate(n-1);
            swap(c,n-1);

        }
    }



public:
    Permutation(int n) : n(n), v(new int[n]){
        for (int i = 0; i < n; i ++){
            v[i] = i;
        }
        simplegenerate(n);
    }
};


//int main() {
//
//    int x[] = {1,2,3,4};
//    char a[] = {'a', 'b', 'c', 'd'};
//    vector<int> b;
//    do {
//        cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << '\n';
//
//
//    } while(next_permutation(x, x+4));
//
//}

int main() {
    Permutation p(4);
}