#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct  Stack));
    stack->capacity = capacity;
    stack->top = - 1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int is_empty(struct Stack* stack) {
    return stack->top == - 1;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (is_empty(stack)) return -1;
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if (is_empty(stack)) return -1;
    return stack->array[stack->top];
}

int max_his(const int tab[], struct Stack* stack, int n);
void count_columns(int **input, int **output, int n);

int main() {

    int **A = (int **)malloc(100*sizeof(int *));
    for (int i = 0; i < 100; i++) { A[i] = (int *)calloc(100, 100*sizeof(int)); }

    int **B = (int **)malloc(100*sizeof(int *));
    for (int i = 0; i < 100; i++) { B[i] = (int *)calloc(100, 100*sizeof(int)); }

    int n, final_max, max;
    final_max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &A[i][j]);
        }
    }

    count_columns(A, B, n);
    free(A);

    struct Stack* stack = createStack(101);
    for (int i = 0; i < n; ++i) {
        max = max_his(B[i], stack, n);
        if (max > final_max) { final_max = max; }
    }
    free(B);
    printf("%d", final_max);
    return 0;
}

void count_columns(int **input, int **output, int n) {
    int col;
    int counter;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            counter = 0;
            col = 0;
            while (i - col > -1) {
                if (input[i - col][j] == 1) { break; }
                counter++;
                col++;
            }
            output[i][j] = counter;
        }
    }
}

int max_his(const int (*tab), struct Stack* stack, int n) {
    int max_area = 0;
    int area;
    int i;
    for (i = 0; i < n;) {
        if (is_empty(stack) == 1 || tab[peek(stack)] <= tab[i]) {
            push(stack, i++);
        } else {
            int top = pop(stack);
            if (is_empty(stack) == 1) {
                area = tab[top] * i;
            } else {
                area = tab[top] * (i - peek(stack) - 1);
            }
            if (area > max_area) { max_area = area; }
        }
    }
    while (is_empty(stack) == 0) {
        int top = pop(stack);
        if (is_empty(stack) == 1) {
            area = tab[top] * i;
        } else {
            area = tab[top] * (i - peek(stack) - 1);
        }
        if (area > max_area) { max_area = area; }
    }

    return max_area;
}
