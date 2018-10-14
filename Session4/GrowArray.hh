#include<iostream>

using namespace std;

class GrowArray {
    private:
        int capacity; // the size of the block of memory
        int size;       // how many are used
        int* p;     //pointer to the block


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
