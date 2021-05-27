#ifndef MAIN_H
#define MAIN_H

class BinarySearchTree
{
public:
    struct Node
    {
        int data = 0;
        Node* left = nullptr;
        Node* right = nullptr;
    };
    Node* root = nullptr;
    void push(int data, Node** node);
    void print(Node* tree);
    void free(Node* tree);
    void compareTree(Node* tree, Node* tree2);
    void copyTree(Node* tree, Node** treeCopy);
};

#endif