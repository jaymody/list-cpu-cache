#include <stdlib.h>

typedef struct Stack {
    int vals[10000000];
    int size;
} Stack;

Stack *new_stack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->size = 0;
    return stack;
}

void push(Stack *stack, int val) {
    stack->vals[stack->size++] = val;
}

int pop(Stack *stack) {
    return stack->vals[--stack->size];
}

void iter_and_add_one(Stack *stack) {
    for (int i = 0; i < stack->size; i++) {
        stack->vals[i] += 1;
    }
}
