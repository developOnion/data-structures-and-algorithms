#pragma once

#include <iostream>
#include "./Queue.hpp"

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode *lchild;
    TreeNode *rchild;

    TreeNode(T val)
    {
        this->data = val;
        this->lchild = nullptr;
        this->rchild = nullptr;
    }
};

template <typename T>
class BinaryTree
{
private:
    void preOrderHelper(TreeNode<T> *curr)
    {
        if (curr != nullptr)
        {
            std::cout << curr->data << " ";
            preOrderHelper(curr->lchild);
            preOrderHelper(curr->rchild);
        }
    }

    void inOrderHelper(TreeNode<T> *curr)
    {
        if (curr != nullptr)
        {
            inOrderHelper(curr->lchild);
            std::cout << curr->data << " ";
            inOrderHelper(curr->rchild);
        }
    }

    void postOrderHelper(TreeNode<T> *curr)
    {
        if (curr != nullptr)
        {
            postOrderHelper(curr->lchild);
            postOrderHelper(curr->rchild);
            std::cout << curr->data << " ";
        }
    }

public:
    TreeNode<T> *root;

    BinaryTree()
    {
        this->root = nullptr;
    }

    void createTreeFromArr(T arr[], int len)
    {
        this->root = new TreeNode<T>(arr[0]);
        Queue<TreeNode<T> *> q;
        q.enqueue(root);

        int i = 1;
        TreeNode<T> *p;
        TreeNode<T> *tmp;
        while (!q.isEmpty() && i < len)
        {
            // insert left child
            p = q.dequeue();
            tmp = new TreeNode<T>(arr[i]);
            i++;
            p->lchild = tmp;
            q.enqueue(tmp);

            if (i < len)
            {
                // insert right child
                tmp = new TreeNode<T>(arr[i]);
                i++;
                p->rchild = tmp;
                q.enqueue(tmp);
            }
        }
    }

    void preOrder()
    {
        preOrderHelper(this->root);
        std::cout << "\n";
    }

    void inOrder()
    {
        inOrderHelper(this->root);
        std::cout << "\n";
    }

    void postOrder()
    {
        postOrderHelper(this->root);
        std::cout << "\n";
    }
};