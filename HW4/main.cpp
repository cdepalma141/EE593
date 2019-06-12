#include <iostream>

using namespace std;

class GrowArray {
private:
    int used;       // how many are used
    int capacity; // the size of the block of memory
    int* p;     //pointer to the block
    void checkGrow(){
        if(used >= capacity){
            int* temp = p;
            p = new int[capacity = capacity*2 + 1];
            for(int i = 0; i < used; i++)
                p[i] = temp[i];
            delete [] temp;
        }
    };

public:

    GrowArray(int initialSize) : used(0), capacity(initialSize), p(new int[capacity]) {}

    GrowArray() : GrowArray(100) {}

    ~GrowArray() {
        delete[] p;
    }

    GrowArray(const GrowArray& orig) : used(orig.used), capacity(orig.capacity), p(new int[capacity]) {
        for (int i = 0; i < used; i++)
            p[i] = orig.p[i];
    }

//    GrowArray& operator =(const GrowArray& orig) {
//        if(this != &orig) {
//            used = orig.used;
//            capacity = orig.capacity;
//            p = new int[capacity];
//            for (int i = 0; i < used; i++)
//                p[i] = orig.p[i];
//        }
//        return *this;
//    }

    GrowArray& operator=(const GrowArray& orig) {
        GrowArray copy(orig);
        swap(copy.p, p);
        used = orig.used;
        capacity = orig.capacity;
        return *this;
    }

    GrowArray(GrowArray&& orig) : used(orig.used), capacity(orig.capacity), p(orig.p){
        orig.p = nullptr;
    }



    void insertEnd(int v) {//O(1)
        checkGrow();
        p[used++] = v;
    }


    void insertStart(int v) {
        checkGrow();
        for(int i = used+1; i > 0; i--)
            p[i] = p[i-1];
        p[0] = v;
        used++;
    }

    void insert(int pos, int v){ //O(n)
        checkGrow();
        int* old = p;
        p = new int[used+1];

        for(int i = 0; i < pos; i++) //O(n) together
            p[i] = old[i];

        p[pos] = v;

        for(int i = pos + 1; i < used + 1; i++) //O(n)
            p[i] = old[i-1];
        used++;
        delete [] old;
    }

    void removeStart() {
        for(int i =0; i < used -1; i++)
            p[i] = p[i+1];
        used--;
    }

    void removeEnd() {
        used--;
    }

    friend ostream& operator <<(ostream& s, const GrowArray& b) {
        for (int i = 0; i < b.used; i++)
            s << b.p[i] << ' ';
        return s;
    }
};



int main() {
    GrowArray b;
    GrowArray c(100);

    for(int i = 0; i < 10; i++)
        b.insertEnd(i);
    GrowArray a = b;// 1+2+3+4+5+.....+n   //O(n^2)

    for(int i = 0; i < 10; i++)
        b.insertStart(i); // 1+2+3+4+5+.....+n   //O(n^2)
    cout << b << '\n';
    c = b;
    for(int i = 0; i < 10; i++)
        b.removeStart();
    b.removeEnd();
    b.removeStart();


    b.insert(3, 7);
    b.insert(2, 78);
    cout << b << '\n';
    cout << a << '\n';
    cout << c << '\n';
}