//
// Created by Connor DePalma on 10/25/18.
//
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


class Expr {
protected:
    Expr* left;
    Expr* right;
    Expr* parent;
public:

    virtual void inorder() const = 0;

    virtual void preorder() const = 0;

    virtual void postorder() const = 0;

    virtual double eval() const = 0;
};

class Const : public Expr {
private:
    double val;
public:
    double eval() { return val; }

};

class Var : public Expr {
public:
    double eval() { return 0; }
};

class Operator : public Expr {

};

class Add : public Operator {

};

class Sub : public Operator {

};

class Mult : public Operator {

};

class Div : public Operator {

};

class Sqrt : public Operator {

};

class Neg : public Operator{

};


int main() {
    //(x+1) * (x-x)
    //x 1 + x x - * // using a stack nice
    // binary + - * / unary - sqrt
    ifstream in("/Users/connordepalma/Documents/Git/EE593/session07/equations.dat");
    string line;
    while (getline(in, line)){
        istringstream ls(line);
        string token;
        while(ls >> token) {
            cout << token << ' ';
        }
        cout << "\n\n";
    }


}