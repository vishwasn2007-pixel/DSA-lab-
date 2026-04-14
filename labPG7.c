// Program to find lowest common ancestor in a binary tree
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* find_lca(struct TreeNode* root, int n1, int n2) {
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    struct TreeNode* left = find_lca(root->left, n1, n2);
    struct TreeNode* right = find_lca(root->right, n1, n2);

    if(left != NULL && right != NULL)
        return root;

    if(left != NULL)
        return left;

    return right;
}

int main() {
    struct TreeNode* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int n1 = 4, n2 = 5;

    struct TreeNode* lca = find_lca(root, n1, n2);

    if(lca != NULL)
        printf("LCA: %d\n", lca->data);

    return 0;
}