// Program to implement stack using linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if(top == NULL)
        return -1;

    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int peek() {
    if(top == NULL)
        return -1;
    return top->data;
}

int empty() {
    if(top == NULL)
        return 1;
    return 0;
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", peek());

    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());

    printf("Is empty: %d\n", empty());

    return 0;
}