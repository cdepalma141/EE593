/*
 *  HW8 - Expression Tree
 *  Connor DePalma.
 *  I pledge my honor that I have abided by the Stevens Honor System.
 *
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <cmath>


using namespace std;


class BinaryTree {
private:
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

        virtual string get() = 0;

        virtual string getStr() = 0;

        virtual double getVal() = 0;

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

        double getVal() {
            return val;
        }

        string getStr(){
            return "";
        }

        string get(){
            return "C";
        }

    };

    class Var : public Expr {
    private:
        string var;
    public:

        Var(string var) : var(var) {}

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

        double getVal() {
            return -1;
        }

        string getStr(){
            return var;
        }

        string get() {
            return "V";
        }
    };


    class Add : public Expr {
    public:

        Add(Expr* lf, Expr* rt) : Expr(lf, rt) {}

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
            if(right != nullptr)
                right->postorder();
            if(left != nullptr)
                left->postorder();
            cout << '+';
        }

        double eval() {
            if(left != nullptr && right != nullptr){
                return right->eval() + left->eval();
            }
        }

        double getVal() {
            return -1;
        }

        string getStr(){
            return "";
        }

        string get(){
            return "+";
        }

    };

    class Sub : public Expr {
    public:

        Sub(Expr* lf, Expr* rt) : Expr(lf, rt) {}

        void inorder() {
            if (right != nullptr)
                right->inorder();
            cout << '-';
            if (left != nullptr)
                left->inorder();
        }
        void preorder() {
            cout << '-';
            if(right!= nullptr)
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
                return right->eval() - left->eval();
            }

        }

        double getVal() {
            return -1;
        }

        string getStr(){
            return "";
        }

        string get(){
            return "-";
        }

    };

    class Mult : public Expr {
    public:

        Mult(Expr* lf, Expr* rt) : Expr(lf, rt) {}

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
                return right->eval() * left->eval();
            }
        }

        double getVal() {
            return -1;
        }

        string getStr(){
            return "";
        }

        string get(){
            return "*";
        }
    };

    class Div : public Expr {
    public:

        Div(Expr* lf, Expr* rt) : Expr(lf, rt) {}

        void inorder() {
            if (right != nullptr)
                right->inorder();
            cout << '/';
            if (left != nullptr)
                left->inorder();
        }
        void preorder() {
            cout << '/';
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
            cout << '/';
        }


        double eval() {
            if(left != nullptr && right != nullptr) {
                return right->eval() / left->eval();
            }
        }

        double getVal() {
            return -1;
        }

        string getStr(){
            return "";
        }

        string get(){
            return "/";
        }
    };

    class Sqrt : public Expr {
    public:

        Sqrt(Expr* lft) : Expr(lft) {}

        void inorder() {
            cout << "sqrt";
            if (left != nullptr)
                left->inorder();
        }
        void preorder() {
            cout << "sqrt";
            if(left != nullptr)
                left->preorder();
        }
        void postorder() {
            if(left != nullptr)
                left->postorder();
            cout << "sqrt";
        }


        double eval() {
            if(left != nullptr) {
                return sqrt(left->eval());
            }
        }

        double getVal() {
            return -1;
        }

        string getStr(){
            return "";
        }

        string get(){
            return "sqrt";
        }
    };

    class Neg : public Expr {
    public:

        Neg(Expr* lft) : Expr(lft) {}

        void inorder() {
            cout << "neg";
            if (left != nullptr)
                left->inorder();
        }
        void preorder() {
            cout << "neg";
            if(left != nullptr)
                left->preorder();
        }
        void postorder() {
            if(left != nullptr)
                left->postorder();
            cout << "neg";
        }

        double eval() {
            if(left != nullptr) {
                return (-1)*left->eval();
            }
        }

        double getVal() {
            return -1;
        }

        string getStr(){
            return "";
        }

        string get(){
            return "neg";
        }
    };


    Expr* root;

    stack<Expr*> stack;


public:



    BinaryTree() : root(nullptr) {}


    void insert(const string& v) {
        stringstream ss(v);
        double dbl;
        if (v == "+") {
            Expr *node1 = stack.top();
            stack.pop();
            Expr *node2 = stack.top();
            stack.pop();
            root = new Add(node1, node2);
            stack.push(root);
            return;
        } else if (v == "*") {
            Expr *node1 = stack.top();
            stack.pop();
            Expr *node2 = stack.top();
            stack.pop();
            root = new Mult(node1, node2);
            stack.push(root);
            return;
        } else if (v == "-") {
            Expr *node1 = stack.top();
            stack.pop();
            Expr *node2 = stack.top();
            stack.pop();
            root = new Sub(node1, node2);
            stack.push(root);
            return;
        } else if (v == "/") {
            Expr *node1 = stack.top();
            stack.pop();
            Expr *node2 = stack.top();
            stack.pop();
            root = new Div(node1, node2);
            stack.push(root);
            return;
        } else if (v == "sqrt") {
            Expr *node1 = stack.top();
            stack.pop();
            root = new Sqrt(node1);
            stack.push(root);
            return;
        } else if (v == "neg") {
            Expr *node1 = stack.top();
            stack.pop();
            root = new Neg(node1);
            stack.push(root);
            return;
        } else if (ss >> dbl) {
            string s{v, '\0'};
            double x = stod(s);
            stack.push(new Const(x));
            return;
        } else {
            stack.push(new Var(v));
            return;
        }
    }


    void inorder() {
        if(root == nullptr)
            return;
        root->inorder();
        cout << '\n';
    }

    void preorder(){
        if(root == nullptr)
            return;
        root->preorder();
        cout << '\n';

    }

    void postorder(){

        if(root == nullptr)
            return;
        root->postorder();
        cout << '\n';
    }

    double eval() {
        if(root == nullptr)
            return -1;
        return root->eval();

    }

    Expr* optimize(Expr* p) {
        p = root;
        if (p == nullptr)
            return nullptr;

        else if(p->get() == "sqrt") {
            if(p->left->get() == "C") {
                Expr* e = new Const(sqrt(p->left->getVal()));
                p->left = e;
                p = e;
            }
        }

        else if(p->get() == "neg") {
            if(p->left->get() == "C") {
                Expr* e = new Const((-1)*p->left->getVal());
                p->left = e;
                p = e;
            }
        }

        else if (p->right->get() == "-"){
            Expr* e = p->left;
            Expr* f = p;
            p = optimizemin(p->right);
            if(f->get() == "+"){
                Expr* r = new Add(e, p);
                return optimizeadd(r);
            } else if(f->get() == "-"){
                Expr* r = new Sub(e, p);
                return optimizemin(r);
            } else if(f->get() == "*"){
                Expr* r = new Mult(e, p);
                return optimizemult(r);
            }
        }

        else if (p->right->get() == "+"){
            Expr* e = p->left;
            Expr* f = p;
            p = optimizeadd(p->right);
            if(f->get() == "+"){
                Expr* r = new Add(e, p);
                return optimizeadd(r);
            } else if(f->get() == "-"){
                Expr* r = new Sub(e, p);
                return optimizemin(r);
            } else if(f->get() == "*"){
                Expr* r = new Mult(e, p);
                return optimizemult(r);
            }
        }
        else if (p->right->get() == "*"){
            Expr* e = p->left;
            Expr* f = p;
            p = optimizemult(p->right);
            if(f->get() == "+"){
                Expr* r = new Add(e, p);
                return optimizeadd(r);
            } else if(f->get() == "-"){
                Expr* r = new Sub(e, p);
                return optimizemin(r);
            } else if(f->get() == "*"){
                Expr* r = new Mult(e, p);
                return optimizemult(r);
            }
        }

        else if (p->left->get() == "-"){
            Expr* e = p->right;
            Expr* f = p;
            p = optimizemin(p->left);
            if(f->get() == "+"){
                Expr* r = new Add(p, e);
                return optimizeadd(r);
            } else if(f->get() == "-"){
                Expr* r = new Sub(p, e);
                return optimizemin(r);
            } else if(f->get() == "*"){
                Expr* r = new Mult(p, e);
                return optimizemult(r);
            }
        }

        else if (p->left->get() == "+"){
            Expr* e = p->right;
            Expr* f = p;
            p = optimizeadd(p->left);
            if(f->get() == "+"){
                Expr* r = new Add(p, e);
                return optimizeadd(r);
            } else if(f->get() == "-"){
                Expr* r = new Sub(p, e);
                return optimizemin(r);
            } else if(f->get() == "*"){
                Expr* r = new Mult(p, e);
                return optimizemult(r);
            }
        }
        else if (p->left->get() == "*"){
            Expr* e = p->right;
            Expr* f = p;
            p = optimizemult(p->left);
            if(f->get() == "+"){
                Expr* r = new Add(p, e);
                return optimizeadd(r);
            } else if(f->get() == "-"){
                Expr* r = new Sub(p, e);
                return optimizemin(r);
            } else if(f->get() == "*"){
                Expr* r = new Mult(p, e);
                return optimizemult(r);
            }
        }

        else if (p->get() == "+") {
            p = optimizeadd(p);
        }
        else if (p->get() == "-") {
            p = optimizemin(p);
        }

        else if (p->get() == "*") {
            p = optimizemult(p);
        }

        return root = p;
    }

    Expr* optimizemin(Expr* p) {
        if (p->left->get() == "C") {
            if (p->right->get() == "C") {
                Expr *e = new Const(p->right->getVal() - p->left->getVal());
                p->right = e;
                p->left = e;
                p = e;
            }

        } else if (p->left->get() == "V") {
            if (p->right->get() == "V") {
                if (p->right->getStr() == p->left->getStr()) {
                    Expr *e = new Const(0);
                    p->right = e;
                    p->left = e;
                    p = e;
                }
            }
        }
        return root = p;

    }

    Expr* optimizeadd(Expr* p) {

        if (p->left->get() == "C") {
            if (p->right->get() == "C") {
                Expr *e = new Const(p->right->getVal() + p->left->getVal());
                p->right = e;
                p->left = e;
                p = e;
            } else if (p->right->get() == "V") {
                if (p->left->getVal() == 0) {
                    Expr *e = p->right;
                    p->right = e;
                    p->left = e;
                    p = e;
                }

            }
        } else if (p->left->get() == "V") {
            if (p->right->getVal() == 0) {
                Expr *e = p->left;
                p->right = e;
                p->left = e;
                p = e;
            }
        }
        return root = p;


    }

    Expr* optimizemult(Expr* p) {
        if ((p->left->get() != "V" && p->left->get() != "C") || (p->right->get() != "V" && p->right->get() != "C")) {
            if (p->left->getVal() == 0 || p->right->getVal() == 0) {
                Expr *e = new Const(0);
                p->right = e;
                p->left = e;
                p = e;
            }
        } else if (p->left->get() == "C") {
            if (p->right->get() == "C") {
                Expr *e = new Const(p->right->getVal() * p->left->getVal());
                p->right = e;
                p->left = e;
                p = e;
            } else if (p->right->get() == "V") {
                if (p->left->getVal() == 0) {
                    Expr *e = new Const(0);
                    p->right = e;
                    p->left = e;
                    p = e;
                } else if (p->left->getVal() == 1) {
                    Expr *e = p->right;
                    p->right = e;
                    p->left = e;
                    p = e;

                }

            }
        } else if (p->left->get() == "V") {
            if (p->right->getVal() == 0) {
                Expr *e = new Const(0);
                p->right = e;
                p->left = e;
                p = e;
            } else if (p->right->getVal() == 1) {
                Expr *e = p->left;
                p->right = e;
                p->left = e;
                p = e;

            }
        }

        return root = p;


    }

    Expr* getRoot() {
        return root;
    }

};


int countLines(const string& s) {
    ifstream in(s);
    string line;
    int ct = 0;
    while (getline(in, line)){
        if(line.length() != 0) {
            ct++;
        }
    }
    return ct;
}

int main() {
    int numLines = countLines("hw8inp.dat");

    BinaryTree* b = new BinaryTree[numLines];
    ifstream in("hw8inp.dat");
    string line;
    int ct = 0;
    while (getline(in, line)){
        if(line.length() != 0) {
            istringstream ls(line);
            string token;
            while (ls >> token) {
                b[ct].insert(token);
            }
            ct++;
        }
    }

    for (int i = 0; i < numLines; i++) {
        cout << "\n\n\ninorder: ";
        b[i].inorder();
        cout << '\n' << "preorder: ";
        b[i].preorder();
        cout << '\n' << "postorder: ";
        b[i].postorder();
        b[i].optimize(b[i].getRoot());
        cout << '\n' << "optimized inorder: ";
        b[i].inorder();
        cout << '\n' << "evaluated: ";
        cout << b[i].eval();

    }


}