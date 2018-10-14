#include <iostream>

#include<iostream>

using namespace std;

class LL {
private:

    class Node {
    public:
        int v;
        Node* next;

        Node(int v, Node* next) : v(v), next(next) {}
    };

    Node* head;

public:

    LL() : head(nullptr) {}

    ~LL() {
        for(Node* p = head; p->next != nullptr;)
            Node* q = p;
        p = p->next;
        delete q;
    }
    




};