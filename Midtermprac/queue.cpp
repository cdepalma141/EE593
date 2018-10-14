//
// Created by Connor DePalma on 10/11/18.
//

class Stack {
private:
    LL a; // head only one direction // w/ tail just rev order of list to make it faster
public:
    void push(int v) {
        a.addStart(v);
    }
    int pop() {
        return a.removeEnd(); // would make return val
    }
    bool isEmpty() const {
        return a.size() == 0; // make in class
    };
};