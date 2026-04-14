// Program to implement binary tree with insertion and preorder traversal
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

struct TreeNode* queue[100];
int front = -1, rear = -1;

void enqueue(struct TreeNode* node) {
    if(front == -1) front = 0;
    queue[++rear] = node;
}

struct TreeNode* dequeue() {
    return queue[front++];
}

void insert(struct TreeNode* root, int data) {
    struct TreeNode* newNode = createNode(data);

    front = rear = -1;
    enqueue(root);

    while(front <= rear) {
        struct TreeNode* temp = dequeue();

        if(temp->left == NULL) {
            temp->left = newNode;
            return;
        } else {
            enqueue(temp->left);
        }

        if(temp->right == NULL) {
            temp->right = newNode;
            return;
        } else {
            enqueue(temp->right);
        }
    }
}

void preorder(struct TreeNode* root) {
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    struct TreeNode* root = createNode(1);

    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

    printf("Preorder Traversal: ");
    preorder(root);

    return 0;
}