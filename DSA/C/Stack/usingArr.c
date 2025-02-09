#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Stack {
    int top;
    int capacity;
    int *arr;
};

// Create stack
struct Stack* createStack(int n) {
    struct Stack* S = (struct Stack*)malloc(sizeof(struct Stack)); 
    S->top = -1;
    S->capacity = n;
    S->arr = (int *)malloc(n * sizeof(int));
    return S;
}

// Push element onto stack
struct Stack* push(struct Stack* S, int x) {
    if (S->top == S->capacity - 1) {
        printf("Stack Overflow\n");
        return S;
    } else {
        S->top++;
        S->arr[S->top] = x;
        return S;
    }
}

// Pop element from stack
struct Stack* pop(struct Stack* S) {
    if (S->top == -1) {
        printf("Stack Underflow\n");
        return S;
    } else {
        S->top--;
        return S;
    }
}

// Print the top element
void peek(struct Stack* S) {
    if (S->top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element: %d\n", S->arr[S->top]);
}

// Display all elements in the stack
void display(struct Stack* S) {
    if (S->top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = 0; i <= S->top; i++) {
            printf("%d ", S->arr[i]);
        }
        printf("\n");
    }
}

//Delete all element
void clearAll(struct Stack *S){
    S->top=-1;
}

int main() {
    char ch;
    struct Stack* S = NULL;

    printf("Given Menu :\n");
    printf("a. To Create Stack\n");
    printf("b. To Insert element\n");
    printf("c. To Delete element\n");
    printf("d. To print element at top\n");
    printf("e. To print all elements\n");
    printf("f. To delete all elements\n");
    printf("g. Exit\n");

    scanf(" %c", &ch);
    while (ch != 'g') {
        int i;
        switch (ch) {
            case 'a':
                printf("a. Enter capacity: \n");
                scanf("%d", &i);
                S = createStack(i);
                printf("Creating List......\n");
                sleep(1);
                break;
            case 'b':
                if (S == NULL) {
                    printf("Stack is not created yet\n");
                    break;
                }
                if(S->top==S->capacity-1){
                    printf("Stacl Overflow \n");
                    break;
                }
                printf("b. Enter element to insert: \n");
                scanf("%d", &i);
                S = push(S, i);
                printf("Inserting..........\n");
                sleep(1);
                break;
            case 'c':
                if (S == NULL) {
                    printf("Stack is not created yet\n");
                    break;
                }
                S = pop(S);
                printf("Deleting..........\n");
                sleep(1);
                break;
            case 'd':
                if (S == NULL) {
                    printf("Stack is not created yet\n");
                    break;
                }
                peek(S);
                printf("Traversed..........\n");
                sleep(1);
                break;
            case 'e':
                if (S == NULL) {
                    printf("Stack is not created yet\n");
                    break;
                }
                display(S);
                printf("Traversed..........\n");
                sleep(1);
                break;
            case 'f':
                if (S == NULL) {
                    printf("Stack is not created yet\n");
                    break;
                }
                clearAll(S);
                printf("Cleared all data..........\n");
                sleep(1);
                break;

            default:
                printf("Invalid Input\n");
                break;
        }

        printf("Given Menu :\n");
        printf("a. To Create Stack\n");
        printf("b. To Insert element\n");
        printf("c. To Delete element\n");
        printf("d. To print element at top\n");
        printf("e. To print all elements\n");
        printf("f. To delete all elements\n");
        printf("g. Exit\n");

        scanf(" %c", &ch);
    }

    return 0;
}