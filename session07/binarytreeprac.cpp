//
// Created by Connor DePalma on 10/27/18.
//

#include <iostream>

using namespace std;

class BT
{
  private:
    class Node
    {
      public:
        int val;
        Node *left;
        Node *right;
        Node(int val, Node *right, Node *left) : val(val), right(right), left(left) {}

        void recursiveadd(int val)
        {
            if (this->val < val)
            {
                if (this->right == nullptr)
                {
                    this->right = new Node(val, nullptr, nullptr);
                    return;
                }
                else
                {
                    this->right->recursiveadd(val);
                }
            }
            else
            {
                if (this->left == nullptr)
                {
                    this->left = new Node(val, nullptr, nullptr);
                    return;
                }
                else
                {
                    this->left->recursiveadd(val);
                }
            }
        }

        void inorder()
        {
            if (left != nullptr)
                left->inorder();
            cout << val;
            if (right != nullptr)
                right->inorder();
        }
        void preorder()
        {
            cout << val;
            if (left != nullptr)
                left->preorder();
            if (right != nullptr)
                right->preorder();
        }
        void postorder()
        {
            if (left != nullptr)
                left->postorder();
            if (right != nullptr)
                right->postorder();
            cout << val;
        }

        Node *FindMax(Node *entry)
        {
            if (entry == nullptr)
                return nullptr;

            while (entry->right != nullptr)
            {
                entry = entry->right;
                
            }
            return entry;
        }

        Node *DeleteNodeInBST(Node *entry, int val)
        {
            if (entry == nullptr)
                return entry;
            else if (val < entry->val)
                entry->left = DeleteNodeInBST(entry->left, val);
            else if (val > entry->val)
                entry->right = DeleteNodeInBST(entry->right, val);
            else
            {
                //No child
                if (entry->right == nullptr && entry->left == nullptr)
                {
                    delete entry;
                    entry = nullptr;
                }
                //One child
                else if (entry->right == nullptr)
                {
                    Node *temp = entry;
                    entry = entry->left;
                    delete temp;
                }
                else if (entry->left == nullptr)
                {
                    Node *temp = entry;
                    entry = entry->right;
                    delete temp;
                }
                //two child
                else
                {
                    Node *temp = FindMax(entry->left);
                    entry->val = temp->val;
                    entry->left = DeleteNodeInBST(entry->left, temp->val);
                }
            }
            return entry;
        }
    };
    Node * root;

      public:
        BT() : root(nullptr) {}

        void add(int val)
        {
            if (root == nullptr)
            {
                root = new Node(val, nullptr, nullptr);
                return;
            }
            else
                root->recursiveadd(val);
        }

        void deleteNode(int val)
        {
            if (root == nullptr)
                return;
            root = root->DeleteNodeInBST(root, val);
        }

        void inorder()
        {
            if (root == nullptr)
                return;
            root->inorder();
            cout << '\n';
        }
        void preorder()
        {
            if (root == nullptr)
                return;
            root->preorder();
            cout << '\n';
        }
        void postorder()
        {
            if (root == nullptr)
                return;
            root->postorder();
            cout << '\n';
        }
    };

    int main()
    {
        BT a;
        int d[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
        int d1[] = {4, 8, 2, 9, 1, 5, 3};
        for (int i = 0; i < 7; i++)
        {
            a.add(d1[i]);
        }

        a.deleteNode(4);
        a.deleteNode(8);
        a.inorder();
        a.preorder();
        a.postorder();
    }