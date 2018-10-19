#include<iostream>

using namespace std;

class BadGrowArray {
private:
    int size;
    int* p;


public:
    BadGrowArray(): size(0), p(nullptr) {}


    void instertEnd(int v) {//O(n)
        int* old = p; //O(1)
        p = new int[size + 1];  //O(1) in cpp //O(n) java
        for(int i = 0; i < size; i++) //O(n) //O(size)
            p[i] = old[i];
        p[size++] = v;//O(1)
        delete [] old;//O(1)
    }


    void insertStart(int v) {
        int* old = p;
        p = new int[size + 1];
        p[0] = v;
        for(int i = 1; i <= size; i++)
            p[i] = old[i-1];
        size++;
        delete [] old;
    }

    void insert(int pos, int v){ //O(n)
//        int* old = p;
//        p = new int[size + 1];
//
//        for(int i = 0; i < pos; i++) //O(n) together
//            p[i] = old[i];
//        p[pos] = v;
//        for(int i = pos + 1; i <= size; i++) //O(n)
//            p[i] = old[i-1];
//        size++;
//        delete [] old;

        for(int i = size+1; i > pos; i--)
            p[i] = p[i-1];
        p[pos] = v;
        size++;

    }

    void removeStart() {
        for(int i =0; i < size -1; i++)
            p[i] = p[i+1];
        size--;
    }

    void removeEnd() {
        size--;
    }

    friend ostream& operator <<(ostream& s, const BadGrowArray& b) {
        for ( int i = 0; i < b.size; i++)
            s << b.p[i] << ' ';
        return s;
    }
};



int main() {
    BadGrowArray b;
    for(int i = 0; i < 10; i++)
        b.insertStart(i); // 1+2+3+4+5+.....+n   //O(n^2)
//    for(int i = 0; i < 10; i++)
//        b.instertEnd(i); // 1+2+3+4+5+.....+n   //O(n^2)
//
//    cout << b << '\n';
//
//    for(int i = 0; i < 10; i++)
//        b.removeEnd();
//    b.removeEnd();
    b.insert(9,9);
    cout << b << '\n';
}