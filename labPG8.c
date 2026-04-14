// Program to find grandchildren of a given node in a binary tree
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

struct TreeNode* findNode(struct TreeNode* root, int key) {
    if(root == NULL)
        return NULL;

    if(root->data == key)
        return root;

    struct TreeNode* left = findNode(root->left, key);
    if(left != NULL)
        return left;

    return findNode(root->right, key);
}

void find_grandchildren(struct TreeNode* root, int key) {
    struct TreeNode* node = findNode(root, key);

    if(node == NULL)
        return;

    if(node->left != NULL) {
        if(node->left->left != NULL)
            printf("%d ", node->left->left->data);
        if(node->left->right != NULL)
            printf("%d ", node->left->right->data);
    }

    if(node->right != NULL) {
        if(node->right->left != NULL)
            printf("%d ", node->right->left->data);
        if(node->right->right != NULL)
            printf("%d ", node->right->right->data);
    }
}

int main() {
    struct TreeNode* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int key = 1;

    printf("Grandchildren: ");
    find_grandchildren(root, key);

    return 0;
}