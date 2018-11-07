//
// Created by Connor DePalma on 10/25/18.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>


using namespace std;


class Expr {
public:
    Expr* left;
    Expr* right;
public:

    Expr(Expr* lf = nullptr, Expr* rt=nullptr) : left(lf), right(rt) {}


    virtual void inorder() = 0;

    virtual void preorder() = 0;

    virtual void postorder() = 0;

    virtual double eval() = 0;

    virtual char get() = 0;

    void addRecursive(char v);




};

class Const : public Expr {
private:
    double val;
public:
    Const(double val) : val(val) {}
    void inorder() {
        cout << val;
    }
    void preorder() {
        cout << val;
    }
    void postorder() {
        cout << val;
    }
    double eval() { return val; }

    char get(){
        return '1';
    }

};

class Var : public Expr {
private:
    char var;
public:

    Var(char var) : var(var) {}

    void inorder() {
        cout << var;
    }
    void preorder() {
        cout << var;
    }
    void postorder() {
        cout << var;
    }
    double eval() { return 0; }

    char get() {
        return 'v';
    }
};


class Add : public Expr {
public:

    Add(Expr* lf, Expr* rt) : Expr(lf, rt) {}

    void inorder() {
        left->inorder();
        cout << '+';
        right->inorder();
    }
    void preorder() {
        cout << '+';
        left->inorder();
        right->inorder();
    }
    void postorder() {
        if(left != nullptr)
            left->postorder();
        if(right != nullptr)
            right->postorder();
        cout << '+';
    }
    double eval() {
        if(left != nullptr && right != nullptr)
            return left->eval() + right->eval();
    }

    char get(){
        return '+';
    }

};

//class Sub : public Operator {
//
//};

class Mult : public Expr {
public:

    Mult(Expr* lf, Expr* rt) : Expr(lf, rt) {}

    void inorder() {
        left->inorder();
        cout << '*';
        right->inorder();
    }
    void preorder() {
        cout << '*';
        left->preorder();
        right->preorder();
    }
    void postorder() {
        if(left != nullptr)
            left->postorder();
        if(right != nullptr)
            right->postorder();
        cout << '*';
    }

    double eval() {
        if(left != nullptr && right != nullptr)
            return left->eval() * right->eval();
    }

    char get(){
        return '*';
    }
};

//class Div : public Operator {
//
//};
//
//class Sqrt : public Operator {
//
//};
//
//class Neg : public Operator{
//
//};


class BinaryTree {
private:
    Expr* root;

public:

    BinaryTree() : root(nullptr) {}


    void insert(char v) {
        if(root == nullptr){
            if(v == '+')
                root = new Add(nullptr, nullptr);
            if(v == '*')
                root = new Mult(nullptr, nullptr);
        }
        else {
            root->addRecursive(v);
        }
    }

    void inorder() {
        if(root == nullptr)
            return;
        root->inorder(); // needs to be done inside Node class to be recursive
        cout << '\n';
    }

    void preorder(){
        if(root == nullptr)
            return;
        root->preorder(); // needs to be done inside Node class to be recursive
        cout << '\n';

    }

    void postorder(){

        if(root == nullptr)
            return;
        root->postorder(); // needs to be done inside Node class to be recursive
        cout << '\n';
    }

    double eval() {
        if(root == nullptr)
            return -1;
        return root->eval();

    }

};

void Expr::addRecursive(char v) {
    if (this->right != nullptr) {
        if (this->left == nullptr) {
            if (v >= '0' && v <= '9') {
                string s{v, '\0'};
                double x = stod(s);
                this->left = new Const(x);
                return;
            } else if (v == '+' || v == '*') {
                if (v == '*') {
                    this->left = new Mult(nullptr, nullptr);
                    return;
                }
                if (v == '+') {
                    this->left = new Add(nullptr, nullptr);
                    return;
                }
            } else {
                this->left = new Var(v);
            }
        } else {
                this->left->addRecursive(v);
        }
    } else {
        if (this->right == nullptr) {
            if (v >= '0' && v <= '9') {
                string s{v, '\0'};
                double x = stod(s);
                this->right = new Const(x);
                return;
            } else if (v == '+' || v == '*') {
                if (v == '*') {
                    this->right = new Mult(nullptr, nullptr);
                    return;
                }
                else {
                    this->right = new Add(nullptr, nullptr);
                    return;
                }
            } else {
                this->right = new Var(v);
            }
        } else {
                this->right->addRecursive(v);
        }
    }
}

void showstack(stack <char> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << '\n';
}



int main() {
    //(x+1) * (x-x)
    //x 1 + x x - * // using a stack nice
    // binary + - * / unary - sqrt
    BinaryTree b;
    stack<char> a;
    ifstream in("/Users/connordepalma/Documents/Git/EE593/session07/hw8inp.dat");
    string line;
    while (getline(in, line)){
        istringstream ls(line);
        char token;
        while(ls >> token) {
            a.push(token);
        }
        break;
    }


    showstack(a);

    while (!a.empty())
    {
        b.insert(a.top());
        a.pop();
    }

    cout << b.eval();
    cout << '\n';
    b.postorder();
    cout << '\n';



    BinaryTree b1;

    char list[] = {'+','*','4','3','2'};

    for(int i = 0; i < 5; i++) {
        cout << list[i] << ' ';
        b1.insert(list[i]);
    }

    cout << '\n';
    cout << b1.eval();
    cout << '\n';
    b1.postorder();
    cout << '\n';


//    Add c;
//
//    Mult g;
//
//    Const d(4);
//
//    Const e(3);
//
//    Const f(2);
//
//    c.left = &d;
//
//    c.right = &e;
//
//    g.right = &c;
//
//    g.left = &f;
//
//    string s{'9','\0'};
//    cout << stod(s);




}