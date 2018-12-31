//
// Created by Connor DePalma on 10/27/18.
//

#include <iostream>

using namespace std;


class Trie {
private:
    class Node {
    public:
        Node** next;
        bool isWord;

        Node() : isWord(false), next(new Node*[26])
        {
            for(int i = 0; i < 26; i++){
                next[i] = nullptr;
            }
        }

    };

    Node* root;
public:
    Trie() : root(new Node()) {



    }

    void insert(const string& word) {
        Node * p = root;

//        for(int i = 0; i < 1; i++){
//            if(p->next[i] == nullptr)
//                cout << "hey" << '\n';
//        }
//        cout << word.length() << '\n';

        for (int i = 0; i < word.length(); i ++) {
            char letter = word[i];
            int index = letter - 'a';
           // cout << index << '\n';

            if (p->next[index] == nullptr) {
                p->next[index] = new Node();

            }

            p = p->next[index];



        }

        p->isWord = true;



    }

    bool hasWord(const string& word) {
        Node* p = root;
        for (int i = 0; i < word.length(); i++){
           // cout << p->isWord << '\n';
            char letter = word[i];
            int index = letter - 'a';
            if (p->next[index] == nullptr)
                return false;
            p = p->next[index];
        }

        return p->isWord;
    }

    bool prefix(const string& word) {
        Node* p = root;
        for (int i = 0; i < word.length(); i++){
            //cout << p->isWord << '\n';
            char letter = word[i];
            int index = letter - 'a';
            if (p->next[index] == nullptr)
                return false;
            p = p->next[index];
        }
        return true;
    }
};

int main() {
    Trie a;
    a.insert("Hello");
    a.insert("hello");

    a.insert("yes");
    a.insert("Mitochondria");

//
//    cout << '\n';
//
    cout << a.hasWord("yes") << '\n';
    cout << a.hasWord("hello") << '\n';
    cout << a.hasWord("Hell") << '\n';

    cout << a.hasWord("Mitochondria") << '\n';

    cout << a.prefix("ye") << '\n';
    cout << a.prefix("Hell") << '\n';
    cout << a.prefix("Mat");



}
