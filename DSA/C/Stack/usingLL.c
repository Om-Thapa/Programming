//createStack(),push(),pop(),peek(),display(),clearAll()
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

struct node{
    int info;
    struct node *next;
};

struct stack {
    struct node *head;
    int top,maxSize;
};

struct stack * createStack(int n){
    struct stack *new=(struct stack *)malloc(sizeof(struct stack));
    new->head=NULL;
    new->top=-1;
    new->maxSize=n;
    return new;
}

void push(struct stack *s,int n){
    s->top++;
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->info=n;
    new->next=s->head;
    s->head=new;
}

void pop(struct stack *s){
    s->head=s->head->next;
    s->top--;
}

void peek(struct stack *s){
    if(s->head==NULL){
        printf("Stack is Empty \n");
        return;
    }
    printf("Top Element : %d\n",s->head->info);
}

void display(struct stack *s){
    if(s->head==NULL){
        printf("Stack is Empty \n");
        return;
    }
    struct node *cur=s->head;
    while(cur->next!=NULL){
        printf("%d ",cur->info);
        cur=cur->next;
    }
    printf("%d\n",cur->info);
}

void clearAll(struct stack *s){
    s->head=NULL;
}

int main() {
    char ch;
    struct stack* S = NULL;
    printf("Loading Menu........\n");
    sleep(1.2);
    printf("Menu :\n");
    printf("a. To Create Stack\n");
    printf("b. To Insert element\n");
    printf("c. To Delete element at Top\n");
    printf("d. To print element at top\n");
    printf("e. To print all elements\n");
    printf("f. To delete all elements\n");
    printf("g. Exit\n");

    scanf(" %c", &ch);
    while (ch != 'g') {
        int i;
        switch (ch) {
            case 'a':
                printf("a. Enter Max Size : \n");
                scanf("%d", &i);
                S = createStack(i);
                printf("Creating Stack......\n");
                sleep(1);
                break;
            case 'b':
                if (S == NULL) {
                    printf("Stack is not created yet\n");
                    break;
                }
                if(S->top==S->maxSize-1){
                    printf("Stack Overflow\n");
                    sleep(1);
                    break;
                }
                printf("b. Enter element to insert: \n");
                scanf("%d", &i);
                push(S, i);
                printf("Inserting..........\n");
                sleep(1);
                break;
            case 'c':
                if (S == NULL) {
                    printf("Stack is not created yet\n");
                    break;
                }
                if(S->head==NULL){
                    printf("Stack is Empty \n");
                    sleep(1);
                    break;
                }
                pop(S);
                printf("Deleting...........");
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
                printf("Try again\n");
                sleep(1);
                break;
        }

        printf("Given Menu :\n");
        printf("a. To Create Stack\n");
        printf("b. To Insert element\n");
        printf("c. To Delete element at Top\n");
        printf("d. To print element at top\n");
        printf("e. To print all elements\n");
        printf("f. To delete all elements\n");
        printf("g. Exit\n");

        scanf(" %c", &ch);
    }

    return 0;
}