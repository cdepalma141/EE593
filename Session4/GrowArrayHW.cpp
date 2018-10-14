#include<iostream>

using namespace std;
//add complexities for each method
class GrowArray {
    private:
        int capacity; // the size of the block of memory
        int size;       // how many are used
        int* p;     //pointer to the block
        void checkGrow(){
            
        };

    public:
        GrowArray() {}
        GrowArray(int initialSize) {}
        
        void insertEnd(int v) {//O(1)
        
        }
        

        void insertStart(int v) {
            
        }

        void insert(int pos, int v){ //O(n)
            int* old = p; 
           
        }

        void removeStart() {
          
        }

        void removeEnd() {
           
        }

        friend ostream& operator <<(ostream& s, const GrowArray& b) {
            for ( int i = 0; i < b.size; i++)
                s << b.p[i] << ' ';
            return s;
        }
};



int main() {
    GrowArray b;
    for(int i = 0; i < 10; i++)
        b.insertEnd(i); // 1+2+3+4+5+.....+n   //O(n^2)
    for(int i = 0; i < 10; i++)
        b.insertStart(i); // 1+2+3+4+5+.....+n   //O(n^2)
    cout << b << '\n';
    for(int i = 0; i < 10; i++)
        b.removeStart();
    b.removeEnd();
    cout << b << '\n';
}