//
// Created by Connor DePalma on 10/17/18.
//

#include <iostream>

using namespace std;

class LLdb{
private:
    class Node{
    public:
        int v;
        Node* next;
        Node* prev;
        Node(int v, Node* next, Node* prev) : v(v), next(next), prev(prev){}

    };

    Node* head;
    Node* tail;

public:

    LLdb() : head(nullptr), tail(nullptr) {}

    void addStart(int val) {

        if(head != nullptr) {
            Node *temp = new Node(val, head, nullptr);
            head->prev = temp;
            head = temp;
        }
        else {
            delete tail;
            head = tail = new Node(val, nullptr, nullptr);
        }
    }

    void removeStart() {
        if(head == nullptr) {
           return;
        }
        if(head == tail){
            delete head;
            head = tail = nullptr;
            return;
        }
        Node*p = head;
        p->prev = nullptr;
        head = head->next;
        delete p;

    }

    void addEnd(int val) {
        if (tail != nullptr){
            Node* temp = new Node(val, nullptr, tail);
            tail->next = temp;
            tail = temp;
            return;
        }
        delete head;
        head = tail = new Node(val, nullptr, nullptr);






    }

    void removeEnd(){
        if(tail == nullptr){
            return;
        }

        if(tail == head){
            delete tail;
            head = tail = nullptr;
            return;
        }
        if(tail != nullptr) {
            Node*temp = tail->prev;
            delete tail;
            temp->next = nullptr;
        }




    }


    friend ostream& operator<<(ostream& s, const LLdb& b){
        for(Node*p = b.head; p != nullptr; p = p->next)
            s << p->v << ' ';
        return s;
    }
};

int main() {
    LLdb a;
    for(int i = 0; i < 10; i ++)
        a.addStart(i);
    cout << a << '\n';
    a.removeEnd();
    cout << a;
    a.addStart(4);
    a.removeStart();
    cout << a;

//    cout << a.getval(8);
    cout << '\n';

    cout << '\n';

    LLdb b;

//    cout << a.isEmpty();
    cout << '\n';
//    cout << b.isEmpty();
}
