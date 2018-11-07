//
// Created by Connor DePalma on 10/27/18.
//

#include <iostream>

using namespace std;


class BT {
private:
    class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node(int val, Node* right, Node* left) : val(val), right(right), left(left) {}


        void recursiveadd(int val) {
            if(this->val < val){
                if(this->right == nullptr) {
                    this->right = new Node(val, nullptr, nullptr);
                    return;
                }
                else{
                    this->right->recursiveadd(val);
                }
            }
            else{
                if(this->left == nullptr){
                    this->left = new Node(val, nullptr, nullptr);
                    return;
                }
                else{
                    this->left->recursiveadd(val);
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
                left->preorder();
            if(right != nullptr)
                right->preorder();

        }
        void postorder(){
            if(left != nullptr)
                left->postorder();
            if(right != nullptr)
                right->postorder();
            cout << val;
        }

    };
    Node* root;






public:
    BT() : root(nullptr) {}

    void add(int val) {
        if(root == nullptr) {
            root = new Node(val, nullptr, nullptr);
            return;
        }
        else
            root->recursiveadd(val);

    }


    void inorder() {
        if(root == nullptr)
            return;
        root->inorder();
        cout<< '\n';

    }
    void preorder() {
        if(root == nullptr)
            return;
        root->preorder();
        cout<< '\n';

    }
    void postorder() {
        if(root == nullptr)
            return;
        root->postorder();
        cout<< '\n';
    }


};



int main() {
    BT a;
    int d[] = {3,1,4,1,5,9,2,6,5,3,5};
    int d1[] = {4,8,2,9,1,5,3};
    for (int i = 0; i < 7; i++){
        a.add(d1[i]);
    }

    a.inorder();
    a.preorder();
    a.postorder();
}