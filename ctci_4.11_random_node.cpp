//
//  main.cpp
//  ctci_4_11_random_node
//
//  Created by Omkar Lenka on 17/06/19.
//  Copyright © 2019 omkar lenka. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    int leftSize;
    int rightSize;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->leftSize = 0;
        this->rightSize = 0;
    }
};

Node* getNode(Node* root, int index)
{
    Node* rand_node;
    
    if(root == NULL)
        return root;
    
    if(index < root->leftSize)
        rand_node = getNode(root->left, index);
    else if(index > root->leftSize)
        rand_node = getNode(root->right, index-((root->leftSize)+1));
    else
        rand_node = root;
    
    return rand_node;
}

Node* getRandomNode(Node* root)
{
    int totalSize = root->leftSize + root->rightSize + 1;
    srand(time(NULL));
    int random_node_index = rand() % totalSize;
    
    
    return getNode(root, random_node_index);
}

Node* insertNode(Node* root, int data)
{
    if(root == NULL)
        root = new Node(data);
    
    if(root->data < data)
    {
        root->right = insertNode(root->right, data);
        root->rightSize++;
    }
    else if(root->data > data)
    {
        root->left = insertNode(root->left, data);
        root->leftSize++;
    }
    
    return root;
}

int main() {
    
    Node *root = new Node(10);
    root = insertNode(root,5);
    root = insertNode(root,2);
    root = insertNode(root,7);
    root = insertNode(root,1);
    root = insertNode(root,15);
    root = insertNode(root,12);
    root = insertNode(root,20);
    
    Node* rand_node = getRandomNode(root);
    
    cout << rand_node->data;
    
    return 0;
}

