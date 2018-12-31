#include <iostream>


using namespace std;


// declaration of node


// hashmap's declaration
class HashMap {
private:
    struct hash_node {
        int val;
        const string &key;
        hash_node* next;
        hash_node* prev;
        hash_node(int val, const string & key, hash_node* next, hash_node* prev) : val(val), key(key), next(next), prev(prev) {}
    };

    const int tablesize = 25;

    hash_node **hashtable, **head;
public:
    

    // constructor
    HashMap()
    {
        // create a empty hashtable
        hashtable = new hash_node*[tablesize];
        head = new hash_node*[tablesize];
        for (int i = 0; i < tablesize; i++) {
            hashtable[i] = nullptr;
            head[i] = nullptr;
        }
    }

    // destructor
    ~HashMap()
    {
        delete[] hashtable;
        delete[] head;
    }

    // hash function definition
    uint32_t HashFunc(const string& key) {
        uint32_t sum = key.length();

        return ((sum << 4) + key[key.length() - 1]) % tablesize;
    }


    // searching method
    void find(const string& key)
    {
        // Applying hashFunc to find
        // index for given key
        int hash_val = HashFunc(key);
        bool flag = false;
        hash_node* entry = hashtable[hash_val];

        // if hashtable at that index has some
        // values stored
        if (entry != nullptr) {
            while (entry != nullptr) {
                if (entry->key == key) {
                    flag = true;
                }
                if (flag) {
                    cout << "Element found at key "
                         << key << ": ";
                    cout << entry->val << endl;
                }
                entry = entry->next;
            }
        }
        if (!flag)
            cout << "No Element found at key "
                 << key << endl;
    }

    // removing an element
    void remove(const string& key)
    {
        // Applying hashFunc to find
        // index for given key
        int hash_val = HashFunc(key);
        hash_node* entry = hashtable[hash_val];
        if (entry->key != key || entry == nullptr) {
            cout << "Couldn't find any element at this key "
                 << key << endl;
            return;
        }

        // if some values are present at that key &
        // traversing the list and removing all values
        while (entry != nullptr) {
            if (entry->next == nullptr) {
                if (entry->prev == nullptr) {
                    hashtable[hash_val] = nullptr;
                    head[hash_val] = nullptr;
                    delete entry;
                    break;
                }
                else {
                    head[hash_val] = entry->prev;
                    head[hash_val]->next = nullptr;
                    delete entry;
                    entry = head[hash_val];
                }
            }
            entry = entry->next;
        }
        cout << "Element was successfully removed at the key "
             << key << endl;
    }

    // inserting method
    void add(const string& key, int value)
    {
        // Applying hashFunc to find
        // index for given key
        int hash_val = HashFunc(key);
        hash_node* entry = hashtable[hash_val];

        // if key has no value stored
        if (entry == nullptr) {
            // creating new node
            entry = new hash_node(value, key, nullptr, nullptr);
            hashtable[hash_val] = entry;
            head[hash_val] = entry;
        }

            // if some values are present
        else {
            // traversing till the end of
            // the list
            while (entry != nullptr)
                entry = entry->next;

            // creating the new node
            entry = new hash_node(value, key, nullptr, head[hash_val]);
            head[hash_val]->next = entry;
            head[hash_val] = entry;
        }
        cout << "Value " << value << " was successfully"
                                     " added at key " << key << endl;
    }
};

// Driver Code
int main()
{
    HashMap hash;
    hash.add("lii", 5);
    hash.add("sdfasdf", 8);
    hash.find("lii");
    hash.find("sdfasdf");


    return 0;
}


//class Hashmap {
//private:
//    struct hash_node {
//        int val;
//        const string& key;
//        hash_node* next;
//        hash_node* prev;
//        hash_node(int val, const string& key, hash_node* next, hash_node* prev) : val(val), key(key), next(next), prev(prev) {}
//    };
//
//    uint16_t tablesize;
//
//    hash_node **hashtable, **head;
//public:
//    Hashmap(uint16_t tablesize) : tablesize(tablesize)
//    {
//        hashtable = new hash_node*[tablesize];
//        head = new hash_node*[tablesize];
//        for (int i = 0; i < tablesize; i++) {
//            hashtable[i] = nullptr;
//            head[i] = nullptr;
//        }
//    }
//
//    ~Hashmap()
//    {
//        delete[] hashtable;
//        delete[] head;
//    }
//
//    uint32_t HashFunc(const string& key)
//    {
//        uint32_t  sum = key.length();
//
//        return ((sum << 4) + key[key.length()-1]) % (tablesize);
//    }
//
//    void find(const string& key)
//    {
//
//        cout << tablesize;
//        int hash_val = HashFunc(key);
//        cout << hash_val;
//        bool flag = false;
//        hash_node* entry = hashtable[hash_val];
//
//        // cout << entry->val;
//
//        //cout << entry->val;
//
//        if (entry != nullptr) {
//            while (entry != nullptr) {
//                if (entry->key == key) {
//                    flag = true;
//                }
//                if (flag) {
//                    cout << "Element found at key "
//                         << key << ": ";
//                    cout << entry->val << endl;
//                }
//                entry = entry->next;
//            }
//        }
//        if (!flag)
//            cout << "No Element found at key "
//                 << key << ' ' << hash_val << endl;
//    }
//
//    void print() {
//        for (int i = 0; i < tablesize; i ++) {
//            hash_node* entry = hashtable[i];
//            while (entry != nullptr) {
//                cout << entry->key << ' ';
//                entry = entry->next;
//            }
//        }
//    }
//
//    void add(const string& key, int value)
//    {
//
//        uint32_t hash_val = HashFunc(key);
//        hash_node* entry = hashtable[hash_val];
//
//        if (entry == nullptr) {
//            cout << "YES " << key << ' ' << value << "\n\n";
//            entry = new hash_node(value, key, nullptr, nullptr);
//            cout << hash_val << ' ';
//            hashtable[hash_val] = entry;
//            head[hash_val] = entry;
//        }
//
//        else {
//            while (entry != nullptr)
//                entry = entry->next;
//
//            entry = new hash_node(value, key, nullptr, head[hash_val]);
//            cout << head[hash_val]->key << " <-key of head\n\n";
//            head[hash_val]->next = entry;
//            head[hash_val] = entry;
//        }
//        cout << "Value " << value << " was successfully"
//                                     " added at key " << key <<' '<< hash_val <<endl;
//    }
//};
//
//private:
//class Node {
//public:
//    const string& key;
//    int val;
//    Node(const string& key = "", int val = 0): val(val), key(key){}
//};
//uint32_t BUCKET;    // No. of buckets
//
//vector<Node*> *table;
//public:
//Hashmap(uint32_t b) : BUCKET(b)
//        {
//                table = new vector<Node*>[BUCKET];
//                cout << BUCKET<< "\n\n";
//        }
//
//void add(const string& key, int val)
//{
//
//    int index = hashFunction(key);
//    cout << index << '\n';
//    Node* entry = new Node(key, val);
//    table[index].push_back(entry);
//}
//
//// function to display hash table
//void displayHash() {
//    vector<Node*>::iterator iter;
//
//    for (int i = 0; i < BUCKET; i++) {
//        cout << i;
//        iter = table[i].begin();
//        int count = 0;
//        while(count < 2)
//        {
//            cout << (*iter)->key << ":" << (*iter)->val;
//            count++;
//        }
//    }
//}
//
//
//uint32_t hashFunction(const string& key) {
//    uint32_t sum = key.length();
//
//    return ((sum << 4) + key[key.length() - 1]) % (BUCKET);
//}
