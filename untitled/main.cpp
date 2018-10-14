#include <iostream>

using namespace std;

void InsertionSort(int x[], int n) {
    for (int i =  1; i < n; i++) {
        int temp = x[i];
        for (int j = i - 1; j >= 0; j--) {
            if (x[j] > temp)
                x[j + 1] = x[j];
            else {
                x[j + 1] = temp;
                break;
            }
            x[j] = temp; //TODO: BAD edge case here
        }

    }
    for (int i = 0; i < 10; i++)
        cout << x[i] << '\t';

}









int main() {

    int x[] = {2, 6, 3, 10, 50, 5, 7, 8, 9, 1};
    InsertionSort(x,3);
}