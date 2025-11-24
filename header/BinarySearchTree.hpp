#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T val)
    {
        this->data = val;
        this->left = this->right = nullptr;
    }
};

template <typename T>
class BinarySearchTree
{
private:
    void inorderHelper(TreeNode<T> *curr)
    {
        if (curr == nullptr)
            return;

        inorderHelper(curr->left);
        std::cout << curr->data << " ";
        inorderHelper(curr->right);
    }

public:
    TreeNode<T> *root;

    BinarySearchTree()
    {
        this->root = nullptr;
    }

    void inorder()
    {
        inorderHelper(this->root);
        std::cout << "\n";
    }

    TreeNode<T> *insert(TreeNode<T> *p, T val)
    {
        TreeNode<T> *tmp;

        if (p == nullptr)
        {
            return new TreeNode<T>(val);
        }

        if (val < p->data)
        {
            p->left = insert(p->left, val);
        }
        else if (val > p->data)
        {
            p->right = insert(p->right, val);
        }

        return p;
    }
};

#endif