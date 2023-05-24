#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

Stack *new_stack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, int val) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack) {
    Node *top = stack->top;
    stack->top = stack->top->next;
    int val = top->val;
    free(top);
    return val;
}

void iter_and_add_one(Stack *stack) {
    Node *node = stack->top;
    while (node != NULL) {
        node->val += 1;
        node = node->next;
    }
}
