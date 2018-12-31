//
// Created by cdepalma on 11/17/2018.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>


using namespace std;

class Dict {
private:

    class TrieNode {
    public:
        class Hashmap{
        private:
            struct hash_node {
                int val;
                string key;
                hash_node* next;
                hash_node* prev;
                hash_node(int val, string key, hash_node* next, hash_node* prev) : val(val), key(key), next(next), prev(prev) {}
            };

            uint16_t tablesize;

            hash_node **hashtable, **head;
        public:
            Hashmap(uint16_t tablesize) : tablesize(tablesize)
            {
                hashtable = new hash_node*[tablesize];
                head = new hash_node*[tablesize];
                for (int i = 0; i < tablesize; i++) {
                    hashtable[i] = nullptr;
                    head[i] = nullptr;
                }
            }

            ~Hashmap()
            {
                delete[] hashtable;
                delete[] head;
            }

            uint32_t HashFunc(string key)
            {
                uint32_t  sum = key.length();

                return ((sum << 4) + key[key.length()-1]) % (tablesize);
            }

            int findval(string key)
            {

                //cout << tablesize;
                int hash_val = HashFunc(key);
                //cout << hash_val;
                bool flag = false;
                hash_node* entry = hashtable[hash_val];
                // cout << entry->val;

                if (entry != nullptr) {
                    while (entry != nullptr) {
                        if (entry->key == key) {
                            flag = true;
                        }
                        if (flag) {
                            cout << "Element found at key "
                                 << key << ": ";
                            cout << entry->val << endl;
                            return entry->val;
                        }
                        entry = entry->next;
                    }
                }
                if (!flag)
                    cout << "No Element found at key "
                         << key << ' ' << hash_val << endl;


            }

            void print() {
                for (int i = 0; i < tablesize; i ++) {
                    hash_node* entry = hashtable[i];
                    while (entry != nullptr) {
                        cout << entry->key << ' ';
                        entry = entry->next;
                    }
                }
            }

            void add(string key, int value)
            {

                uint32_t hash_val = HashFunc(key);
                hash_node* entry = hashtable[hash_val];

                if (entry == nullptr) {
                  //  cout << "YES " << key << ' ' << value << "\n\n";
                    entry = new hash_node(value, key, nullptr, nullptr);
                   // cout << hash_val << ' ';
                    hashtable[hash_val] = entry;
                    head[hash_val] = entry;
                }

                else {
                    while (entry != nullptr)
                        entry = entry->next;

                    entry = new hash_node(value, key, nullptr, head[hash_val]);
                 //   cout << head[hash_val]->key << " <-key of head\n\n";
                    head[hash_val]->next = entry;
                    head[hash_val] = entry;
                }
//                cout << "Value " << value << " was successfully"
//                                             " added at key " << key <<' '<< hash_val <<endl;
            }
            };





        Hashmap*** next;


        TrieNode() : next(new Hashmap**[26]){
            for(int i = 0; i < 26; i++) {
                next[i] = new Hashmap*[26];
                for(int j = 0; j < 26; j++)
                next[i][j] = nullptr;
            }
        }
    };

    TrieNode * Trie;
    int offset;
    unsigned char* Chars;
    uint16_t wordcount[26][26] = {0};


public:

    Dict() : Trie(new TrieNode), offset(0) {

    }

    int countchars(const string& s){
        int count = 0;
        ifstream in(s);
        string line;
        while(getline(in, line)){
            if(line.length() != 0){
                count += line.length();
            }
        }
        return count;
    }

    void countwords(const string & s){
        ifstream in(s);
        string line;
        while(getline(in, line)){
            if(line.length() != 0){
                istringstream stream(line);
                string fullword;
                stream >> fullword;
                char l1 = fullword[0];
                char l2 = fullword[1];
                int index1 = l1 - 'a';
                int index2 = l2 - 'a';
                wordcount[index1][index2]++;
            }
        }



//        for(int i = 0; i < 26; i ++) {
//            for (int j = 0; j < 26; j++) {
//                if(wordcount[i][j] == 0) {
//
//                }
//            }
//        }


    }

    void read(const string& s) {

        countwords(s);
        int count = countchars(s);

        Chars = new unsigned char[count];
        int next = 0;
        ifstream words(s);
        string word;
        uint32_t offset = 0;
        while(getline(words, word)){
            if(word.length() != 0){
                istringstream ls(word);
                int ct = word.length();
                unsigned char token;
                while(ls >> token) {
                    Chars[next++] = token;
                }
                    //cout << count2 << ' ';
                if (word.length() > 2) {
                    Chars[next - 1] = Chars[next - 1] | 0x80;
                }

                uint32_t origoffset = offset;
                offset += word.length();
                //cout << origoffset << ' ';


                istringstream ls2(word);
                string fullword;
                ls2 >> fullword;
                char l1 = fullword[0];
                char l2 = fullword[1];
                int index1 = l1 - 'a';
                int index2 = l2 - 'a';
//                cout << l1 << ' ' << l2 << '\n';
              //  cout << index1 << ' ' << index2 << ' ';
                uint32_t val = wordcount[index1][index2] + uint32_t (wordcount[index1][index2]*(0.3));

                if(wordcount[index1][index2] != 0) {
                    if (Trie->next[index1][index2] == nullptr)
                        Trie->next[index1][index2] = new TrieNode::Hashmap(val);
                }
                if(word.length() > 2)
                    Trie->next[index1][index2]->add(fullword.substr(2), origoffset);
                else
                    Trie->next[index1][index2]->add(fullword, origoffset);



//                    cout << fullword.substr(2) << ' ';
            }


//                if (fullword.length() > 2)

        }
        //cout << (unsigned char)(Chars[i] xor 0x80) << ' ';

//        for (int i = 0; i < count; i++)
//            cout << Chars[i];

//        for(int i = 0; i < 26; i ++) {
//            for (int j = 0; j < 26; j++) {
//                cout << wordcount[i][j] << ' ';
//            }
//        }
    }


    void find(const string& s) {
        char l1 = s[0];
        char l2 = s[1];
        int index1 = l1 - 'a';
        int index2 = l2 - 'a';
        int val = Trie->next[index1][index2]->findval(s.substr(2));
        unsigned char c;
        int i =val;
        string yeah = "";
        while(true){
            cout << Chars[i++];
            if(Chars[i] > 0x80) {
                cout << (unsigned char)(Chars[i] xor 0x80);
                break;
            }

        }

    }





};

int main() {
    Dict D;

    D.read("C:\\Users\\cdepalma\\CLionProjects\\Hashmap\\dict.txt");

    D.find("zymosimeter");

}