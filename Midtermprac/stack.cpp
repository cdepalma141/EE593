//
// Created by Connor DePalma on 10/11/18.
//
#include <iostream>
class Stack {
private:
    int * stack;
    int sp;
public:
    Stack(int n) : stack(new int[n]), sp(0) {}

    void push(int v) {
        stack[sp] = v;
        sp++;
    }

    int pop()  {
        return stack[--sp];
    }

    bool isEmpty() const {
        return sp == 0;
    }
};


int main() {
    Stack a(5);

    a.push(3);

    std::cout << a.isEmpty();



}