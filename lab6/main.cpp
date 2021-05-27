#include <iostream>
#include <time.h>
#include "main.h"

void BinarySearchTree::push(int data, Node** node)
{
    if (*node == nullptr)
    {
        *node = new Node;
        (*node)->data = data;
    }
    else
    {
        if (data < (*node)->data)
        {
            push(data, &((*node)->left));
        }
        else if (data > (*node)->data)
        {
            push(data, &((*node)->right));
        }
    }
    return;
}
void BinarySearchTree::print(Node* tree)
{
    if (!tree) return;
    std::cout << tree->data << " ";
    print(tree->left);
    print(tree->right);
}
void BinarySearchTree::free(Node* tree)
{
    if (!tree) return;
    free(tree->left);
    free(tree->right);
    delete tree;
}
void BinarySearchTree::compareTree(Node* tree, Node* tree2)
{
    if (!tree || !tree2) return;
    if (tree->data < tree2->data)
    {
        std::cout << "< ";
        compareTree(tree->left, tree2->left);
        compareTree(tree->right, tree2->right);
    }
    else if (tree->data > tree2->data)
    {
        std::cout << "> ";
        compareTree(tree->left, tree2->left);
        compareTree(tree->right, tree2->right);
    }
    else
    {
        std::cout << "= ";
        compareTree(tree->left, tree2->left);
        compareTree(tree->right, tree2->right);
    }
    return;
}
void BinarySearchTree::copyTree(Node* tree, Node** treeCopy)
{
    if (!tree) return;
    if (!*treeCopy)
    {
        *treeCopy = new Node;
        (*treeCopy)->data = tree->data;
    }
    else
    {
        if (tree->data < (*treeCopy)->data)
            push(tree->data, &((*treeCopy)->left));
        else if (tree->data > (*treeCopy)->data)
            push(tree->data, &((*treeCopy)->right));
    }
    copyTree(tree->left, treeCopy);
    copyTree(tree->right, treeCopy);
    return;
}

int main()
{
    srand(time(nullptr));
    BinarySearchTree tree;
    BinarySearchTree tree2;
    BinarySearchTree treeCopy;

    for (int i = 0; i < 10; i++)
        tree.push(rand() % 100, &tree.root);
    for (int i = 0; i < 10; i++)
        tree2.push(rand() % 100, &tree2.root);

    tree.print(tree.root);
    std::cout << "\n";
    tree2.print(tree2.root);
    std::cout << "\n";

    tree.compareTree(tree.root, tree2.root);
    std::cout << "\n";
    treeCopy.copyTree(tree.root, &treeCopy.root);

    tree.print(tree.root);
    std::cout << "\n";
    tree2.print(tree2.root);
    std::cout << "\n";
    treeCopy.print(treeCopy.root);
    treeCopy.copyTree(tree2.root, &treeCopy.root);
    std::cout << "\n";
    treeCopy.print(treeCopy.root);

    tree.free(tree.root);
    tree2.free(tree2.root);
    treeCopy.free(treeCopy.root);
}