/* 
A strictly binary tree is a binary tree in which each node has either no children or exactly
two children. A perfect binary tree is a strictly binary tree in which all leaf nodes are at
the same level. Write an algorithm to determine whether a binary tree is:
(a) Strictly binary
(b) Perfect binary
*/

#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
};
class BinaryTree{
public:
    bool isStricklyBinary(Node* node){
        if (node == NULL){
            return true;
        }
        else if ((node->left == NULL) && (node->right) == NULL){
            return true;
        }
        else{
            return isStricklyBinary(node->left) && isStricklyBinary(node->right);
        }
        return false;
    }

    bool isPerfectBinary(Node* node){
        
    }
};


