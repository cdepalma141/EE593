//
// Created by Connor DePalma on 10/25/18.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>


using namespace std;




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
    class Expr {
    public:
        Expr* parent;
        Expr* left;
        Expr* right;
        //BinaryTree& father;
    public:

        Expr(Expr* p=nullptr, Expr* lf = nullptr, Expr* rt=nullptr) : parent(p), left(lf), right(rt) {}


        virtual void inorder() = 0;

        virtual void preorder() = 0;
        virtual void postorder() = 0;

        virtual double eval() = 0;

        virtual char get() = 0;
        //void addRecursive(char v, BinaryTree& b);




    };

    class Const : public Expr {
    private:
        double val;
    public:
        Const(double val, Expr* p) : val(val), Expr(p) {}
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
            return 'C';
        }

    };

    class Var : public Expr {
    private:
        char var;
    public:

        Var(char var, Expr* p) : var(var), Expr( p) {}

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
            return var;
        }
    };


    class Add : public Expr {
    public:

        Add(Expr* p, Expr* lf, Expr* rt) : Expr(p, lf, rt) {}

        void inorder() {
            if (right != nullptr)
                right->inorder();
            cout << '+';
            if (left != nullptr)
                left->inorder();
        }
        void preorder() {
            cout << '+';
            if(right != nullptr)
                right->preorder();
            if(left != nullptr)
                left->preorder();
        }
        void postorder() {
//***********************put the eval stuff in here to show optimization
            if(right != nullptr)
                right->postorder();
            if(left != nullptr)
                left->postorder();
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

    class Sub : public Expr {
    public:

        Sub(Expr* p, Expr* lf, Expr* rt) : Expr(p, lf, rt) {}

        void inorder() {
            if (right != nullptr)
                right->inorder();
            cout << '-';
            if (left != nullptr)
                left->inorder();
        }
        void preorder() {
            cout << '-';
            if(right != nullptr)
                right->preorder();
            if(left != nullptr)
                left->preorder();
        }
        void postorder() {

            if(right != nullptr)
                right->postorder();
            if(left != nullptr)
                left->postorder();
            cout << '-';
        }

        double eval() {
            if (left != nullptr && right != nullptr) {

                if (left->eval() == 0)
                    return right->eval();
                else if (right->eval() == 0)
                    return left->eval();
                else if(left->eval() == right->eval())
                    return left->eval()*2;
                else
                    return left->eval() * right->eval();
            }

        }



        char get(){
            return '-';
        }

    };

    class Mult : public Expr {
    public:

        Mult(Expr* p, Expr* lf, Expr* rt) : Expr(p, lf, rt) {}

        void inorder() {
            if (right != nullptr)
                right->inorder();
            cout << '*';
            if (left != nullptr)
                left->inorder();
        }
        void preorder() {
            cout << '*';
            if(right != nullptr)
                right->preorder();
            if(left != nullptr)
                left->preorder();
        }
        void postorder() {

            if(right != nullptr)
                right->postorder();
            if(left != nullptr)
                left->postorder();
            cout << '*';
        }

        double eval() {
            if(left != nullptr && right != nullptr) {
                if (left->eval() == 0 || right ->eval() == 0)
                    return 0;
                else if(left->eval() == 1)
                    return right->eval();
                else if(right->eval() == 1)
                    return left->eval();
                else
                    return left->eval() * right->eval();
            }
        }

        char get(){
            return '*';
        }
    };


    Expr* root;

    Expr* parent;

    stack<Expr*> stack;


public:



    BinaryTree() : root(nullptr) {}


    void insert(char v) {
        // push everything and then make tree
            if (v == '+') {
                cout << "yes+";
                Expr *node1 = stack.top();
                stack.pop();
                Expr *node2 = stack.top();
                stack.pop();
                root = new Add(nullptr, node1, node2);
                stack.push(root);
                return;
            } else if (v == '*') {
                cout << "yes*";
                Expr *node1 = stack.top();
                stack.pop();
                Expr *node2 = stack.top();
                stack.pop();
                root = new Mult(nullptr, node1, node2);
                stack.push(root);
                return;
            } else if (v == '-') {
                cout << "yes-";
                Expr *node1 = stack.top();
                stack.pop();
                Expr *node2 = stack.top();
                stack.pop();
                root = new Sub(nullptr, node1, node2);
                stack.push(root);
                return;
            } else if (v >= '0' && v <= '9') {
                cout << "yes" << v;
                string s{v, '\0'};
                double x = stod(s);
                stack.push(new Const(x, nullptr));
                return;
            } else {
                cout << "yesX";
                stack.push(new Var(v, nullptr));
                return;
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

    void showstack()
    {
        while (!stack.empty())
        {
            cout << '\t' << stack.top()->get();
            stack.pop();
        }
        cout << '\n';
    }



};




int main() {
    //(x+1) * (x-x)
    //x 1 + x x - * // using a stack nice
    // binary + - * / unary - sqrt
    BinaryTree b;
//    stack<char> a;
//    ifstream in("/Users/connordepalma/Documents/Git/EE593/session07/hw8inp.dat");
//    string line;
//    while (getline(in, line)){
//        istringstream ls(line);
//        char token;
//        while(ls >> token) {
//            a.push(token);
//        }
//        break;
//    }
//
//
//    showstack(a);

//    while (!a.empty())
//    {
//        b.insert(a.top());
//        a.pop();
//    }

    char d[] = {'3', '4', '+', '2', '*'};

    for(int i = 0; i < 5; i++)
        b.insert(d[i]);

    cout << '\n';

    cout << b.eval();
    cout << '\n';
    b.postorder();
    cout << '\n';
    b.inorder();
    cout << '\n';
    b.preorder();
    cout << '\n';




    BinaryTree b1;

    char list[] = {'2', '3', '4', '*', '+'};


    for(int i = 0; i < 5; i++)
        b1.insert(list[i]);

    cout << '\n';
    cout << b1.eval();
    cout << '\n';
    b1.postorder();
    cout << '\n';
    b1.inorder();
    cout << '\n';
    b1.preorder();
    cout << '\n';
//
//
    BinaryTree b2;

    char list1[] = {'x', 'x', '-', 'a', 'b', '+', '*'};

    for(int i = 0; i < 7; i++)
        b2.insert(list1[i]);

    cout << '\n';
    cout << b2.eval();
    cout << '\n';
    b2.postorder();
    cout << '\n';
    b2.inorder();
    cout << '\n';
    b.preorder();
    cout << '\n';


    BinaryTree b3;

    char list2[] = {'x', '1', '*'};

    for(int i = 0; i < 3; i++)
        b3.insert(list2[i]);

    cout << '\n';
    cout << b3.eval();
    cout << '\n';
    b3.postorder();
    cout << '\n';
    b3.inorder();
    cout << '\n';
    b.preorder();
    cout << '\n';

    BinaryTree b4;

    char list3[] = {'5', 'x', '4', '+', '*'};

    for(int i = 0; i <5; i++)
        b4.insert(list3[i]);

    cout << '\n';
    cout << b4.eval();
    cout << '\n';
    b4.postorder();
    cout << '\n';
    b4.inorder();
    cout << '\n';
    b4.preorder();
    cout << '\n';




}