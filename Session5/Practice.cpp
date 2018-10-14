//
// Created by Connor DePalma on 10/10/18.
//

#include<iostream>
#include <fstream>
#include<sstream>

using namespace std;
class Convex {


private:
    double xmax;
    double xmin;
    double ymax;
    double ymin;
    int size;
    int** hull;


public:
    class LL {
    private:

        class Node {
        public:
            int v;
            Node *next;

            Node(int v, Node *next) : v(v), next(next) {}
        };

        Node *head;

    public:

        LL() : head(nullptr) {}

        ~LL() {
            for (Node *p = head; p != nullptr;) {
                Node *q = p;
                p = p->next;
                delete q;
            }
        }


        LL(const LL &orig) {
            if (orig.head == nullptr) {
                head = nullptr;
                return;
            }
            head = new Node(orig.head->v, nullptr);
            Node *q = head;
            Node *p;
            for (p = orig.head->next; p != nullptr; p = p->next, q = q->next) {
                q->next = new Node(p->v, nullptr);
            }

        }

        LL &operator=(const LL &orig) {
            LL copy(orig);
            swap(head, copy.head);
            return *this;
        }

        void addStart(int val) {
            head = new Node(val, head);
        }

        void addEnd(int val) {
            if (head == nullptr) {
                head = new Node(val, nullptr);
                return;
            }
            Node *p;
            for (p = head; p->next != nullptr; p = p->next);
            p->next = new Node(val, nullptr);

        }

        void removeEnd() {
            Node *p;
            Node *q;

            if (head == nullptr)
                return;

            if (head->next == nullptr) {
                delete head;
                head = nullptr;
                return;
            }

            for (p = head, q = p->next; q->next != nullptr; p = q, q = q->next);
            delete q;
            p->next = nullptr;
        }

        void removeStart() {
            if (head == nullptr)
                return;
            Node *p = head;
            head = head->next;
            delete p;

        }

        void insert(int pos, int val) {
            Node *p = head;
            for (int i = 0; i < pos - 1; i++)
                p = p->next;

            Node *temp = new Node(val, p->next);
            p->next = temp;


        }

        friend ostream &operator<<(ostream &s, const LL &b) {
            for (Node *p = b.head; p != nullptr; p = p->next)
                s << p->v << ' ';
            return s;
        }


    };

    Convex(int size) : size(size), xmax(0), xmin(0), ymax(0), ymin(0), hull(new int*[size]) {
        for (int i = 0; i < size; ++i) {
            hull[i] = new int[size];
        }
    }


    ~Convex(){}

    void read(const string& s) {
        double x;
        double y;
        int count = 0;
        ifstream f(s);
        string linebuffer;
        while(!f.eof()) {
            getline(f, linebuffer);
            istringstream line(linebuffer);
            double a, b;
            line >> x >> y;
            if(x > xmax) {
                if (x < xmin)
                    xmin = x;
                xmax = x;
            }
            if(y > ymax) {
                if (y < ymin)
                    ymin = y;
                ymax = y;
            }
            if (y < ymin)
                ymin = y;
            if(x < xmin)
                xmin = x;
            if (xmax > x > 0)
                xmin = x;
            if (ymax > y > 0)
                ymin = y;

        }
        cout << xmax << ' ' << ymax;
        cout << '\n';
        cout << xmin << ' ' << ymin;



    }



};


int main(){
//    Convex::LL a;
//    for(int i = 0; i < 22; i++)
//        a.addEnd(i);
//    a.removeStart();
//    a.removeEnd();
//    a.insert(4, 67);
//    cout << a;
//    cout << '\n';
//    Convex::LL b;
//    b = a;
//    cout << b;
    Convex c(16);
    c.read("/Users/connordepalma/Documents/Git/EE593/Session5/points.dat");



}