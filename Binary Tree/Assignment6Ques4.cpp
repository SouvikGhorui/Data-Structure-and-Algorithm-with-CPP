#include<iostream>
#include<vector>
using namespace std;


class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        left = NULL;
        right = NULL;
        val = data;
    }
};


int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void preOrder(Node* root){
    if(root == NULL) return;
    cout<<root->val<<endl;
    preOrder(root->left);
    preOrder(root->right);
}

void deletelargest(Node* &root){
    if(root == NULL) return;

    Node** curr = &root;
    while((*curr) ->right != NULL){
        curr = &((*curr) ->right);
    }
    Node* toDelete = *curr;
    *curr = (*curr) ->left;
    delete toDelete;
}

int main(){
    vector<int> p = {50, 40, -1, -1, -1};
    Node* root = buildTree(p);
    preOrder(root);
    cout<<"Deleting largest element"<<endl;
    deletelargest(root);
    preOrder(root);
    return 0;
}
