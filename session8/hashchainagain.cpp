#include <iostream>

using namespace std;

// declaration of node

// hashmap's declaration
class HashMap
{
  private:
    struct hash_node
    {
        int val, key;
        hash_node *next;
        hash_node *prev;
        hash_node(int val, int key, hash_node *next, hash_node *prev) : val(val), key(key), next(next), prev(prev) {}
    };

    const int tablesize = 25;

    hash_node **hashtable, **head;

  public:
    // constructor
    HashMap()
    {
        // create a empty hashtable
        hashtable = new hash_node *[tablesize];
        head = new hash_node *[tablesize];
        for (int i = 0; i < tablesize; i++)
        {
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
    int HashFunc(int key)
    {
        return key % tablesize;
    }

    // searching method
    void find(int key)
    {
        // Applying hashFunc to find
        // index for given key
        int hash_val = HashFunc(key);
        bool flag = false;
        hash_node *entry = hashtable[hash_val];

        // if hashtable at that index has some
        // values stored
        if (entry != nullptr)
        {
            while (entry != nullptr)
            {
                if (entry->key == key)
                {
                    flag = true;
                }
                if (flag)
                {
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
    void remove(int key, int val)
    {
        // Applying hashFunc to find
        // index for given key
        int hash_val = HashFunc(key);
        hash_node *entry = hashtable[hash_val];
        if (entry->key != key || entry == nullptr)
        {
            cout << "Couldn't find any element at this key "
                 << key << endl;
            return;
        }

        // if some values are present at that key &
        // traversing the list and removing all values
        while (entry != nullptr)
        {

            if (entry->val == val)
            {
                if (entry->next == nullptr)
                {
                    if (entry->prev == nullptr)
                    {
                        hashtable[hash_val] = nullptr;
                        head[hash_val] = nullptr;
                        delete entry;
                        break;
                    }
                    else
                    {
                        head[hash_val] = entry->prev;
                        head[hash_val]->next = nullptr;
                        delete entry;
                        entry = head[hash_val];
                        break;
                    }
                }
                else
                {
                    hash_node *temp = new hash_node(entry->next->val, entry->next->key, entry->next->next, entry->prev);
                    hashtable[hash_val] = temp;
                    head[hash_val] = temp;
                    entry = temp;
                    break;
                }
            }
            else
            entry = entry->next;
        }
        cout << "Element was successfully removed at the key "
             << key << endl;
    }

    // inserting method
    void add(int key, int value)
    {
        // Applying hashFunc to find
        // index for given key
        int hash_val = HashFunc(key);
        hash_node *entry = hashtable[hash_val];

        // if key has no value stored
        if (entry == nullptr)
        {
            // creating new node
            entry = new hash_node(value, key, nullptr, nullptr);
            hashtable[hash_val] = entry;
            head[hash_val] = entry;
        }

        // if some values are present
        else
        {
            // traversing till the end of
            // the list
            // while (entry != nullptr)
            //     entry = entry->next;

            // creating the new node
            entry = new hash_node(value, key, nullptr, head[hash_val]);
            head[hash_val]->next = entry;
            head[hash_val] = entry;
        }
        cout << "Value " << value << " was successfully"
                                     " added at key "
             << key << endl;
    }
};

// Driver Code
int main()
{
    HashMap hash;
    hash.add(4, 5);
    hash.add(4, 7);
    hash.add(4,6);
    hash.add(4, 18);

    hash.find(4);

    hash.remove(4, 6);
    hash.remove(4, 7);
    
    hash.find(4);

    return 0;
}