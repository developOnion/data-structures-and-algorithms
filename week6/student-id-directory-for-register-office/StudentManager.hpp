#ifndef STUDENTMANAGER_HPP
#define STUDENTMANAGER_HPP

#include <iostream>

#include "./Student.hpp"

class StudentManager
{
private:
    typedef struct Node
    {
        Student data;
        Node *left;
        Node *right;

        Node(Student student)
        {
            this->data = student;
            this->left = this->right = nullptr;
        }
    } Node;

    Node *root;

    // helper function to do recursive call for addStudent
    Node *addStudentHelper(Node *node, Student newStudent)
    {
        // when node is null mean we found the position to insert
        if (node == nullptr)
            return new Node(newStudent);

        if (node->data.getId() > newStudent.getId())
        {
            // std::cout << "left of ";
            // node->data.toString();
            node->left = addStudentHelper(node->left, newStudent);
        }
        else
        {
            // std::cout << "right of ";
            // node->data.toString();
            node->right = addStudentHelper(node->right, newStudent);
        }

        return node;
    }

    // helper function to do recursive call for inorderPrint
    void inorderPrintHelper(Node *node)
    {
        if (node == nullptr)
            return;

        inorderPrintHelper(node->left);
        node->data.toString();
        inorderPrintHelper(node->right);
    }

    // helper function to do recursive call for searchById
    Node *searchByIdHelper(Node *node, int id)
    {
        if (node == nullptr)
            return nullptr;
        else if (node->data.getId() == id)
        {
            return node;
        }

        if (node->data.getId() > id)
        {
            // std::cout << "left of ";
            // node->data.toString();
            return searchByIdHelper(node->left, id);
        }
        else
        {
            // std::cout << "right of ";
            // node->data.toString();
            return searchByIdHelper(node->right, id);
        }
    }

    Node *deleteStudentByIdHelper(Node *node, int id)
    {
        if (node == nullptr)
            return nullptr;

        // if (node->left == nullptr && node->right == nullptr && node->data.getId() == node->data.getId())
        // {
        //     if (node == this->root)
        //         this->root = nullptr;

        //     delete node;
        //     return nullptr;
        // }

        if (node->data.getId() > id)
            node->left = deleteStudentByIdHelper(node->left, id);
        else if (node->data.getId() < id)
            node->right = deleteStudentByIdHelper(node->right, id);
        else
        {
            Node *tmp;
            if (node->left == nullptr && node->right == nullptr)
            { // no child node
                if (node == this->root)
                    this->root = nullptr;

                delete node;
                return nullptr;
            }
            else if (node->right == nullptr)
            { // only has left child
                tmp = node->left;
                delete node;
                return tmp;
            }
            else if (node->left == nullptr)
            { // only has right child
                tmp = node->right;
                delete node;
                return tmp;
            }
            else
            { // has two children
                if (height(node->left) > height(node->right))
                { // left height deeper choose inorderPredecessor
                    tmp = inorderPredecessor(node->left);
                    node->data = tmp->data;
                    node->left = deleteStudentByIdHelper(node->left, tmp->data.getId());
                }
                else
                { // right height deeper choose inorderSuccessor
                    tmp = inorderSuccessor(node->right);
                    node->data = tmp->data;
                    node->right = deleteStudentByIdHelper(node->right, tmp->data.getId());
                }
            }
        }

        return node;
    }

    void freeTree(Node *node)
    {
        if (node == nullptr)
            return;

        freeTree(node->left);
        delete node;
        freeTree(node->right);
    }

public:
    // constructor
    StudentManager()
    {
        this->root = nullptr;
    }

    // deconstructor
    ~StudentManager()
    {
        freeTree(this->root);
    }

    void addStudent(Student newStudent)
    {
        if (this->root == nullptr)
        { // assign to root if it is the first node
            this->root = addStudentHelper(this->root, newStudent);
            std::cout << "Initailize Root -> ";
            root->data.toString();
            return;
        }

        addStudentHelper(this->root, newStudent);
    }

    void deleteStudentById(int id)
    {
        deleteStudentByIdHelper(this->root, id);
    }

    // search student by id
    Student searchById(int id)
    {
        Node *stu = searchByIdHelper(this->root, id);
        return stu ? stu->data : Student();
    }

    // utils
    void inorderPrint()
    { // print all student inorder traversal
        inorderPrintHelper(this->root);
    }

    // find height from a node
    int height(Node *node)
    {
        if (node == nullptr)
            return 0;
        int l = height(node->left);
        int r = height(node->right);

        return (r > l) ? (r + 1) : (l + 1);
    }

    // search for inorderPredecessor of a given node
    Node *inorderPredecessor(Node *node)
    {
        if (node == nullptr || node->right == nullptr)
            return node;

        return inorderPredecessor(node->right);
    }

    // search for inorderSuccessor of a given node
    Node *inorderSuccessor(Node *node)
    {
        if (node == nullptr || node->left == nullptr)
            return node;

        return inorderSuccessor(node->left);
    }
};

#endif