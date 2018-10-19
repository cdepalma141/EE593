//
// Created by Connor DePalma on 10/14/18.
//

//
// Created by Connor DePalma on 10/14/18.
//
#include <iostream>

using namespace std;

class LL {
private:

    class Node {
    public:
        int v;
        Node* next;
        Node( int v , Node* next) : v(v) , next(next) {}
    };

    Node* head;
    Node* tail;

public:

    LL(): head(nullptr), tail(nullptr) {}

    ~LL() {
        if(head == nullptr)
            return;
        for(Node*p = head; p!=nullptr;) {
            Node *q = p;
            p = p->next;
            delete q;
        }
    }

//    LL(const LL& orig){
//        if(orig.head == nullptr) {
//            head = tail = nullptr;
//            return;
//        }
//
//        head =new Node(orig.head->v, nullptr);
//        Node*q = head;
//        Node*p;
//        for(p = orig.head->next; p!=nullptr; p = p ->next, q = q->next)
//            q->next = new Node(p->v, nullptr);
//
//        p->next = nullptr;
//
//
//    }
//
//    LL& operator =(const LL& orig){
//        LL copy(orig);
//        swap(head, copy.head);
//        return *this;
//    }

    void addStart(int val){
        if (head == nullptr){
            delete tail;
            head = tail = new Node(val, nullptr);
            return;
        }
        head = new Node(val, head);

    }

    void removeStart() {
        if(head == tail){
            delete head;
            head = tail = nullptr;
            return;
        }
        if (head == nullptr)
            return;

        Node*p = head;
        head = head->next;
        delete p;
    }

    void addEnd(int val) {
        if(tail == nullptr) {
            delete head;
            head =tail = new Node(val, nullptr);
            return;
        }
        tail->next = new Node(val, nullptr);

    }

    void removeEnd(){
        if(head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node*q = head->next;
        Node*p;
        for(p = head; q->next != nullptr; p=q, q = q->next)
            ;
        delete q;
        p->next = nullptr;

    }

    friend ostream& operator<<(ostream& s, const LL& orig) {
        for(Node*p = orig.head; p!= nullptr; p = p->next)
            s << p->v << ' ';
        return s;
    }
};


int main() {
    LL a;
    for(int i = 0; i < 10; i ++)
        a.addStart(i);

    a.addEnd(80);
    a.addStart(2);
    a.removeEnd();
    a.removeEnd();
    a.removeStart();

    cout << a;
}