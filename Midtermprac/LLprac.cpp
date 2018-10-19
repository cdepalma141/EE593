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

public:

    LL(): head(nullptr) {}

    ~LL() {
        if(head == nullptr)
            return;
        for(Node*p = head; p!=nullptr;) {
            Node *q = p;
            p = p->next;
            delete q;
        }
    }

    LL(const LL& orig){
        if(orig.head == nullptr) {
            head = nullptr;
            return;
        }

        head = new Node(orig.head->v, nullptr);
        Node*q = head;
        Node*p;
        for(p = orig.head->next; p!=nullptr; p = p ->next, q = q->next)
            q->next = new Node(p->v, nullptr);

        p->next = nullptr;


    }

    LL& operator =(const LL& orig){
        LL copy(orig);
        swap(head, copy.head);
        return *this;
    }

    void addStart(int val){
        head = new Node(val, head);
    }

    void removeStart() {
        if(head == nullptr)
            return;
        Node*p = head;
        head = head->next;
        delete p;
    }

    void addEnd(int val) {
        if(head == nullptr) {
            head = new Node(val, nullptr);
            return;
        }
        Node*p = head;
        for(; p->next != nullptr; p = p->next )
            ;
        p->next = new Node(val, nullptr);
    }

    void removeEnd(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        Node*q = head;
        Node*p;
        for(p = q->next; p->next != nullptr; p = p->next, q = q->next)
            ;
        delete p;
        q->next = nullptr;

    }

    int getval(int pos) {
        if(head == nullptr)
            return -1;
        Node*p = head;
        for(int i = 0; i < pos-1; i++)
            p = p->next;
        return p->next->v;

    }

    bool isEmpty(){
        return head == nullptr;
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
        a.addEnd(i);

    a.removeEnd();
    a.addStart(4);

    cout << a.getval(8);
    cout << '\n';
    cout << a;
    cout << '\n';

    LL b;

    cout << a.isEmpty();
    cout << '\n';
    cout << b.isEmpty();
}