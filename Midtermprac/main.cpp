//
// Created by Connor DePalma on 10/11/18.
//

#include <iostream>

using namespace std;

template<typename T>
class DoubleLL {
private:
    class Node {
    public:
        T val;
        Node *next;
        Node *prev;

        Node(const T &v, Node *n, Node *p) : val(v), next(n), prev(p) {}

    };

    Node *head;

public:

    DoubleLL() : head(nullptr) {}

    T get(int i) const {
        Node *p = head;
        for (; i > 0 && p != nullptr; i--)
            p = p->next;
        return p->val;
    }


    void addFirst(const T &v) {
        if (head == nullptr)
            head = new Node(v, nullptr, nullptr);
        Node*temp = new Node(v, head, nullptr);
        head->prev = temp;
        head = temp;
    }

//    void addLast(const T &v) {
//        if (tail != nullptr) {
//            Node*temp = new Node(v, nullptr, tail);
//            temp->val=v;
//            tail->next = temp;
//            tail = temp;
//        }
//        else {
//            delete head;
//            head = tail = new Node(v, nullptr, nullptr);
//        }
//
//
//    }







    class Const_Iterator {
    private:
        Node *current;
    public:
        Const_Iterator(DoubleLL<T> &list) : current(list.head) {}

        bool hasNext() const {
            return current != nullptr;
        }

        void next() {
            current = current->next;
        }

        T getVal() {
            return current->val;
        }
    };
    class Iterator {
    private:
        Node *current;
    public:
        Iterator(DoubleLL<T> &list) : current(list.head) {}

        bool hasNext() const {
            return current != nullptr;
        }

        void next() {
            current = current->next;
        }

        T& getVal() {
            return current->val;
        }
    };
};





int main(){
    DoubleLL<int> list;
    for(int i = 0; i < 10; i ++)
        list.addFirst(i);

    for(DoubleLL<int>::Const_Iterator i(list); i.hasNext(); i.next() ) //O(n) , reg get in loop from DLL would be n^2
        cout<< i.getVal() << ' ';


}