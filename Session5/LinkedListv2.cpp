//
// Created by Connor DePalma on 10/4/18.
//

#include <iostream>

using namespace std;
template<typename T>
class LinkedList {
private:
    class Node { // doesn't know anything about outer class
    public:
        T v;
        Node* next;
        Node(T v, Node* n) : v(v), next(n) {}
//        ~Node(){ //recursive order n so not good
//            delete next;
//        }


    };
    Node* head;//LinkedList::


public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        for(Node* p = head; p != nullptr; ) {
            Node* q = p;
            p = p->next;
            delete q;
        }
    }

    LinkedList(const LinkedList& orig) {
        if(orig.head == nullptr) {
            head = nullptr;
            return;
        }
        head = new Node(orig.head->v, nullptr); // need to create head for new list
        Node * q = head;
        for (Node*p = orig.head->next; p!= nullptr; p = p->next, q = q->next){
            q->next = new Node(p->v, nullptr);
        }

    }

    LinkedList& operator=(const LinkedList& orig) {
        LinkedList copy(orig); // calls copy constructor
        swap(head, copy.head);
        return *this;

    }

    void addEnd(const T& v) {
        if (head == nullptr) {
            head = new Node(v, nullptr);
            return;
        }
        //head is not null list has at least one element
        Node* p;
        for(p = head; p->next != nullptr; p = p->next)
            ;
        p->next = new Node(v, nullptr);
    }

    void addStart(const T& v) {
        head = new Node(v, head);
    }

    void removeEnd() {
        Node* p;
        Node* q;
        if(head == nullptr){
            return;
        }

        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        //there are at least two elements in the list
        for(p = head, q = p->next; q->next != nullptr; p=q,  q = q->next)
            ;
        delete q;
        p->next = nullptr;

    }

    void removeStart() {
        Node* temp = head;
        head = head-> next;
        delete temp;
    }

    friend ostream& operator<< (ostream& s, const LinkedList& b) {
        for(Node* p = b.head; p!= nullptr; p = p->next)
            s << p->v  << ' ';
        return s;
    }

};

int main(){
    LinkedList<int> a;
    for(int i = 0; i < 22; i++)
        a.addEnd(i);
    cout << a;

}