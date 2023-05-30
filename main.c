#include <assert.h>
#include <stdio.h>
#include <time.h>

const int N_ELEMENTS = 200000;
const int N_REPEAT = 100;

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

clock_t benchmark_push() {
    Stack *stack = new_stack();
    clock_t start = clock();
    for (int i = 0; i < N_ELEMENTS; i++) {
        push(stack, rand());
    }
    return clock() - start;
}

clock_t benchmark_pop() {
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

clock_t benchmark_iter_v1() {
    Stack *stack = new_stack();
    for (int i = 0; i < N_ELEMENTS; i++) {
        push(stack, rand());
    }

    clock_t start = clock();
    iter_and_add_one(stack);
    return clock() - start;
}

clock_t benchmark_iter_v2() {
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

clock_t run_benchmark(clock_t (*example_fn)()) {
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
    printf("Push:     %lu\n", run_benchmark(benchmark_push));
    printf("Pop:      %lu\n", run_benchmark(benchmark_pop));
    printf("Iter v1:  %lu\n", run_benchmark(benchmark_iter_v1));
    printf("Iter v2:  %lu\n", run_benchmark(benchmark_iter_v2));
}
