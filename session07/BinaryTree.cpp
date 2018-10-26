//
// Created by Connor DePalma on 10/25/18.
//


#include <iostream>

using namespace std;

class BinaryTree {
private:
    class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node(int v, Node* left, Node* right) : val(v), left(left), right(right) {}

        void add(int v){
            if(this->val < v){
                if(this->right != nullptr)
                    this->right->add(v);
                else {
                    this->right = new Node(v, nullptr, nullptr);
                    return;
                }
            }
            else{
                if (this->left != nullptr)
                    this->left->add(v);
                else{
                    this->left = new Node(v, nullptr, nullptr);
                    return;
                }
            }
        }

        void inorder(){
            if(left != nullptr)
                left->inorder();
            cout << val;
            if(right != nullptr)
                right->inorder();
        }

        void preorder(){
            cout << val;
            if(left != nullptr)
                left->inorder();
            if(right != nullptr)
                right->inorder();
        }

        void postorder(){
            if(left != nullptr)
                left->inorder();
            if(right != nullptr)
                right->inorder();
            cout << val;
        }

    };
    Node* root;
public:

    BinaryTree() : root(nullptr) {}

    void add(int v) {
        if(root == nullptr) {
            root = new Node(v, nullptr, nullptr);
            return;
        }

        Node* p = root;
        while (true) {
            if (p->val > v) {
                if (p->left == nullptr) {
                    p->left = new Node(v, nullptr, nullptr);
                    return;
                } else
                    p = p->left;
            }
            if (p->right == nullptr) {
                p->right = new Node(v, nullptr, nullptr);
                return;
            } else
                p = p->right;
        }

    }

    void addRecursive(int v) {
        if(root == nullptr){
            root = new Node(v, nullptr, nullptr);
            return;
        } else
            root->add(v);
    }

    void remove(int v) {

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

};


int main() {

    BinaryTree t;
    int d[] = {3,1,4,1,5,9,2,6,5,3,5};

    for (int i = 0; i < 11; i++){
        t.addRecursive(d[i]);
    }
    t.inorder();
    t.preorder();
    t.postorder();
}