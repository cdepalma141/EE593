/*
 * HW - Linked List class
 *
 * Connor DePalma.
 *
 * I pledge my honor that I have abided by the Stevens Honor System.
 *
 */

#include <iostream>
#include <sstream>
#include <fstream>

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

    double size;

public:

    LL(): head(nullptr), tail(nullptr), size(0) {}

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
            head = tail = nullptr;
            return;
        }

        head =new Node(orig.head->v, nullptr);
        if(orig.head == orig.tail){
            head  = tail;
            return;
        }
        Node*q = head;
        Node*p;
        for(p = orig.head->next; p!=nullptr; p = p ->next, q = q->next)
            q->next = new Node(p->v, nullptr);
        tail = q;
        size = orig.size;

    }

    LL& operator =(const LL& orig){
        LL copy(orig);
        swap(head, copy.head);
        swap(tail, copy.tail);
        size = orig.size;
        return *this;
    }

    void addStart(int val){
        if (head == nullptr){
            delete tail;
            size++;
            head = tail = new Node(val, nullptr);
            return;
        }
        head = new Node(val, head);
        size++;

    }

    void removeStart() {
        if(head == tail){
            delete head;
            head = tail = nullptr;
            size--;
            return;
        }
        if (head == nullptr)
            return;

        Node*p = head;
        head = head->next;
        delete p;
        size--;
    }

    void addEnd(int val) {
        if(tail == nullptr) {
            delete head;
            head =tail = new Node(val, nullptr);
            size++;
            return;
        }
        Node* temp = new Node(val, nullptr);
        tail->next = temp;
        tail = temp;
        size++;


    }

    void removeEnd(){
        if(head == tail) {
            delete head;
            head = tail = nullptr;
            size--;
            return;
        }

        Node*q = head->next;
        Node*p;
        for(p = head; q->next != nullptr; p=q, q = q->next)
            ;
        delete q;
        p->next = nullptr;
        tail = p;
        tail->next = nullptr;
        size--;

    }

    void remIndex(int pos) {

        if (head == nullptr) {
            return;
        }
        if(head == tail) {
            delete head;
            head = tail = nullptr;
            size--;
            return;
        }

        if(pos == 0){
            removeStart();
            return;
        }

        Node*q = head->next;
        Node*p = head;
        for(int i = 1; i < pos; i++){
            if(q->next == nullptr)
                return;
            q = q->next;
            p = p->next;
        }
        p->next = q->next;
        delete q;
        size--;



    }

    void read(const string& s) {
        double x;
        ifstream f(s);
        string linebuffer;
        while (getline(f, linebuffer)) {
            if (linebuffer.length() != 0) {

                istringstream line(linebuffer);
                line >> x;

            }

        }

        for(int i = 1; i < x+1; i ++)
            addEnd(i);

    }

    void remIndices(){
        for(int i = size; i >= 0 ; i--){
            if(i%3 == 0 || i == 0) {
                remIndex(i);
            }
        }
    }

    LL revList(){
        LL newList;
        for(Node*p = head; p!=nullptr; p=p->next) {
            newList.addStart(p->v);
        }

        return newList;

    }

    double getSize(){
        return size;
    }

    friend ostream& operator<<(ostream& s, const LL& orig) {
        for(Node*p = orig.head; p!= nullptr; p = p->next)
            s << p->v << ' ';
        return s;
    }
};




int main() {
    LL a;
    a.read("linkedlist.dat");
    cout << a << '\n';
    a.remIndices();
    cout << a << '\n';
    a.remIndices();
    cout << a << '\n';
    cout << a.revList() << '\n'; // doesn't change a

}