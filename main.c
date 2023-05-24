#include <assert.h>
#include <stdio.h>
#include <time.h>

const int N_ELEMENTS = 20000;
const int N_REPEAT = 1000;

void test() {
    Stack *stack = new_stack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    assert(pop(stack) == 3);
    assert(pop(stack) == 2);
    push(stack, 4);
    iter_and_add_one(stack);
    assert(pop(stack) == 5);
    assert(pop(stack) == 2);
}

clock_t example1() {
    Stack *stack = new_stack();
    clock_t start = clock();
    for (int i = 0; i < N_ELEMENTS; i++) {
        push(stack, rand());
    }
    return clock() - start;
}

clock_t example2() {
    Stack *stack = new_stack();
    for (int i = 0; i < N_ELEMENTS; i++) {
        push(stack, rand());
    }
    clock_t start = clock();
    for (int i = 0; i < N_ELEMENTS; i++) {
        pop(stack);
    }
    return clock() - start;
}

clock_t example3() {
    Stack *stack = new_stack();
    for (int i = 0; i < N_ELEMENTS; i++) {
        push(stack, rand());
    }

    clock_t start = clock();
    iter_and_add_one(stack);
    return clock() - start;
}

clock_t example4() {
    Stack *stack = new_stack();
    Stack *other = new_stack();
    for (int i = 0; i < N_ELEMENTS; i++) {
        push(stack, rand());
        for (int j = 0; j < 20; j++) {
            push(other, rand());
        }
    }

    clock_t start = clock();
    iter_and_add_one(stack);
    return clock() - start;
}

clock_t run_example(clock_t (*example_fn)()) {
    clock_t total_elapsed = 0;
    for (int i = 0; i < N_REPEAT; i++) {
        total_elapsed += example_fn();
    }
    return total_elapsed / N_REPEAT;
    printf("%lu\n", total_elapsed / N_REPEAT);
}

/* main code */
int main() {
    srand(time(NULL));
    test();
    printf("Push:     %lu\n", run_example(example1));
    printf("Pop:      %lu\n", run_example(example2));
    printf("Iter v1:  %lu\n", run_example(example3));
    printf("Iter v2:  %lu\n", run_example(example4));
}
