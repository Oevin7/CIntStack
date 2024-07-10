#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define DEFAULT_CAPACITY 4

typedef struct {
    int* data;
    int top;
    int capacity;
} IntStack;

IntStack* createStack();
void dropStack(IntStack* stack_to_drop);
void push(IntStack* stack, int value);
int getVal(int index, const IntStack* stack);
int pop(IntStack* stack);
void printStack(const IntStack* stack);
int peek(const IntStack* stack);
int isEmpty(const IntStack* stack);
int search(int value_to_find, const IntStack* stack);
int min(const IntStack* stack);
int max(const IntStack* stack);
void clear(IntStack* stack);
IntStack* deepCopy(IntStack* stack);

int main(void) {

    IntStack* my_stack = createStack();

    if (my_stack == NULL) {
        fprintf(stderr, "Failed to create the stack");
    }

    push(my_stack, 25);
    push(my_stack, 10);
    push(my_stack, 12);
    push(my_stack, 77);

    IntStack* copy = deepCopy(my_stack);

    printf("This is the copy stack:\n");
    printStack(copy);

    clear(my_stack);

    dropStack(my_stack);
    dropStack(copy);

    return 0;
}

IntStack* createStack() {
    IntStack* stack = malloc(sizeof(IntStack));
    if(stack == NULL) {
        fprintf(stderr ,"Could no allocate the IntStack");
        return NULL;
    }

    stack->data = (int*)malloc(DEFAULT_CAPACITY * sizeof(int));
    if(stack->data == NULL) {
        fprintf(stderr, "Could no allocate data for the IntStack.\n");
        free(stack);
        return NULL;
    }

    stack->top = 0;
    stack->capacity = DEFAULT_CAPACITY;

    return stack;

}

void dropStack(IntStack* stack_to_drop) {
    if (stack_to_drop != NULL) {
        if (stack_to_drop->data != NULL) {
            free(stack_to_drop->data);
        }
        free(stack_to_drop);
    }
}

void push(IntStack* stack, const int value) {
    if (stack == NULL) return;

    if (stack->top < stack->capacity) {
        stack->data[stack->top] = value;
        stack->top++;
    }
}

int pop(IntStack* stack) {
    if (stack == NULL) return 0;

    stack->top--;
    int removed_value = stack->data[stack->top];

    return removed_value;

}

int getVal(int index, const IntStack* stack) {
    if (stack == NULL) return 0;

    return stack->data[index];

}

void printStack(const IntStack* stack) {
    for (int i = 0; i < stack->top; i++) {
        printf("Num%d: %d\n", i, stack->data[i]);
    }
}

int peek(const IntStack* stack) {
    return stack->data[stack->top - 1];
}

int isEmpty(const IntStack* stack) {
    if (stack->top == 0) {
        return 1;
    }
    return 0;
}

int search(const int value_to_find, const IntStack* stack) {
    for (int i = 0; i < stack->top; i++) {
        if (stack->data[i] == value_to_find) {
            return i;
        }
    }
    printf("Could not find that value in the stack.");
    return 0;
}

int min(const IntStack* stack) {

    int smallest_val = stack->data[0];

    for (int i = 0; i < stack->top; i++) {
        if (stack->data[i] < smallest_val) {
            smallest_val = stack->data[i];
        }
    }
    return smallest_val;
}

int max(const IntStack* stack) {

    int largest_val = stack->data[0];

    for (int i = 0; i < stack->top; i++) {
        if (stack->data[i] > largest_val) {
            largest_val = stack->data[i];
        }
    }
    return largest_val;
}

void clear(IntStack* stack) {
    stack->top = 0;
}

IntStack* deepCopy(IntStack* stack) {
    if (stack == NULL) return NULL;

    IntStack* copy_stack = createStack();

    for (int i = 0; i < stack->top; i++) {
        copy_stack->data[i] = stack->data[i];
        copy_stack->top++;
    }

    return copy_stack;

}