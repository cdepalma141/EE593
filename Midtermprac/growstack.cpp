//
// Created by Connor DePalma on 10/11/18.
//

class Stack {
private:
    Growarray a;
public:
    void push(int v) {
        a.addEnd(v);
    }
    int pop() {
        return a.removeEnd(); // would make return val
    }
    bool isEmpty() const {
        return a.size() == 0; // make in class
    };
};