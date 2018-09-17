#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;
//0 to a bill is possible but pretty slow
// faster than with vector like in main2 ?

int ES(int b) {

    int c = int(sqrt(b));
    bool *Prime = new bool[b + 1];
    int count = 0;

    for (int i = 2; i < b + 1; i++)
        Prime[i] = true;

//    for (int i = 0; i < b + 1; i++) {
//        //cout << Prime[i] << "\t";
//    }

    //cout << '\n';


    for (int i = 2; i < c + 1; i++) {
        if (Prime[i]) {
            for (int j = i * i; j <= b; j += i) {
                Prime[j] = false;
            }
        }
    }

//    for (int i = 0; i <= b; i++) {
//        cout << Prime[i] << "\t";
//    }
//
//    cout << '\n';


    for (int i = 0; i <= b; i++) {
        if (Prime[i])
            count++;
    }


    if (Prime[b])
     return count-1;

    return count;
}

int Erastothenes(int a, int b) {

    int c = int(sqrt(b));
    bool *Prime = new bool[b + 1];
    int count = 0;
 //   cout << ES(a) << '\n';
    int count2 = ES(a);

    for (int i = 2; i < b + 1; i++)
        Prime[i] = true;

//    for (int i = 0; i < b + 1; i++) {
//        cout << Prime[i] << "\t";
//    }
//
//    cout << '\n';


    for (int i = 2; i < c + 1; i++) {
        if (Prime[i]) {
            for (int j = i * i; j <= b; j += i) {
                Prime[j] = false;
            }
        }
    }

//    for (int i = 0; i <= b; i++) {
//        cout << Prime[i] << "\t";
//    }
//
//    cout << '\n';


    for (int i = 0; i <= b; i++) {
        if (Prime[i])
            count++;
    }


    return count - count2;
}



int main() {
    int a, b;
    cin >> a;
    cin >> b;

    cout << Erastothenes(a,b);
    cout << "\n\n";


}