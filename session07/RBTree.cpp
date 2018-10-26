//
// Created by Connor DePalma on 10/25/18.
//

#include <iostream>

using namespace std;

class RBTree {
private:
    class Node {
    public:
        Node *left;
        Node *right;
        Node* parent;
        int val;
        bool red;
        Node(int v, Node* parent, Node* left, Node* right) : val(v), left(left), right(right), parent(parent){}


    };
    Node* root;
    static Node* parent(Node* n){
        return n->parent;
    }
    static Node* grandparent(Node* n){
        if(n->parent == nullptr)
            return nullptr;
        return n->parent->parent;

    }
    static Node* uncle(Node* n){

    }

    void insertRepairTree(Node* n){
        if(parent(n) == nullptr)
            n->red = false;
        else if(parent(n)->red == false)
            return;
        else if(uncle->red){
            parent(n)-> red = false;
            uncle(n)->red = false;
            grandparent(n)->red = true;
            insertRepairTree(grandparent(n));
        }
        else {
            //look at his its too much not fast enough go on without me
        }
    }
public:
    RBTree() : root(nullptr) {}


    void add(int v){
    if(root == nullptr){
        root = new Node(v, nullptr, nullptr, nullptr);
        return;
    }
    Node* p = root;
    while(true){
        if(p->val > v){
            if (p->left == nullptr){
                p->left = new Node(v, p, nullptr, nullptr);
                insertRepairTree(p->left);
                return;
            }
            p = p->left;
            else{
                if (p->right == nullptr){
                    p->right = new Node(v, p, nullptr, nullptr);
                    insertRepairTree(p->right);
                    return;
                }
            }
            p = p->right;
        }
    }
    }
};

int main() {

}