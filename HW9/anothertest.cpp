#include<iostream>
#include <list>
using namespace std;

//class Hash
//{
//    int BUCKET;    // No. of buckets
//
//    // Pointer to an array containing buckets
//    list<string> *table;
//public:
//    Hash(int V);  // Constructor
//
//    // inserts a key into hash table
//    void insertItem(const string& x);
//
//    // deletes a key from hash table
//    // hash function to map values to key
//    uint32_t hashFunction(const string& key)
//    {
//        uint32_t  sum = key.length();
//
//        return ((sum << 4) + key[key.length()-1]) % (BUCKET);
//    }
//
//    void displayHash();
//};
//
//Hash::Hash(int b)
//{
//    this->BUCKET = b;
//    table = new list<string>[BUCKET];
//}
//
//void Hash::insertItem(const string& key)
//{
//    int index = hashFunction(key);
//    table[index].push_back(key);
//}
//
//// function to display hash table
//void Hash::displayHash() {
//    for (int i = 0; i < BUCKET; i++) {
//        cout << i;
//        for (auto x : table[i])
//            cout << " --> " << x;
//        cout << endl;
//    }
//}

class Hashmap{
private:
    class Node {
    public:
        const string& key;
        int val;
        Node(const string& key, int val): val(val), key(key){}
    };
    int BUCKET;    // No. of buckets

    list<Node*> *table;
public:
    Hashmap(int b)
    {
        this->BUCKET = b;
        table = new list<Node*>[BUCKET];
    }

    void insertItem(const string& key, int val)
    {
        int index = hashFunction(key);
        Node* entry = new Node(key, val);
        table[index].push_back(entry);
    }

// function to display hash table
    void displayHash() {
        for (int i = 0; i < BUCKET; i++) {
            cout << i;
            for (auto x : table[i])
                cout << " --> " << x->key << ":" << x->val;
            cout << endl;
        }
    }
    uint32_t hashFunction(const string& key) {
        uint32_t sum = key.length();

        return ((sum << 4) + key[key.length() - 1]) % (BUCKET);
    }
};



// Driver program  
int main()
{
    // array that contains keys to be mapped
    string a[] = {"aalii", "aa", "aardvark"};
    int n = sizeof(a)/sizeof(a[0]);

    // insert the keys into the hash table
    Hashmap h(7);   // 7 is count of buckets in
    // hash table
    for (int i = 0; i < n; i++)
        h.insertItem(a[i] , i);

    // display the Hash table
    h.displayHash();

    return 0;
} 