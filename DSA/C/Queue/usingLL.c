#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct node {
    int info;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
    int size, capacity;
};

struct queue *createQueue(int n) {
    struct queue *new = (struct queue *)malloc(sizeof(struct queue));
    if (new == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    new->head = new->tail = NULL;
    new->capacity = n;
    new->size = 0;
    return new;
}

void Enqueue(struct queue *s, int n) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new->info = n;
    new->next = NULL;
    
    if (s->head == NULL) {
        s->head = s->tail = new;
    } else {
        s->tail->next = new;
        s->tail = new;
    }
    s->size++;
}

void Dequeue(struct queue *s) {
    if (s->head == NULL) return;

    struct node *temp = s->head;
    s->head = s->head->next;
    if (s->head == NULL) {
        s->tail = NULL;
    }
    free(temp);
    s->size--;
}

void peek(struct queue *s) {
    if (s->head == NULL) {
        printf("Queue is Empty\n");
    } else {
        printf("Front Element : %d\n", s->head->info);
    }
    sleep(1);
}

void display(struct queue *s) {
    if (s->head == NULL) {
        printf("Queue is Empty\n");
    } else {
        struct node *cur = s->head;
        while (cur != NULL) { // Fix: Loop till cur is NULL
            printf("%d ", cur->info);
            cur = cur->next;
        }
        printf("\n");
        printf("Traversed........\n");
    }
    sleep(1);
}

void clearAll(struct queue *s) {
    while (s->head != NULL) {
        Dequeue(s);
    }
}

int main() {
    char ch;
    struct queue *Q = NULL;

    printf("Given Menu :\n");
    printf("a. To Create Queue\n");
    printf("b. To Insert element\n");
    printf("c. To Delete element at Rear\n");
    printf("d. To print element at Front\n");
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
                Q = createQueue(i);
                if (Q != NULL) {
                    printf("Creating Queue......\n");
                }
                sleep(1);
                break;
            case 'b':
                if (Q == NULL) {
                    printf("Queue is not created yet\n");
                    break;
                }
                if (Q->size == Q->capacity) {
                    printf("Queue Overflow \n");
                    sleep(1);
                    break;
                }
                printf("b. Enter element to insert:\n");
                scanf("%d", &i);
                Enqueue(Q, i);
                printf("Inserting..........\n");
                sleep(1);
                break;
            case 'c':
                if (Q == NULL) {
                    printf("Queue is not created yet\n");
                    break;
                }
                if (Q->head == Q->tail) {
                    free(Q->head); // Free memory if only one element
                    Q->head = Q->tail = NULL;
                    sleep(1);
                    break;
                }
                Dequeue(Q);
                printf("Deleting Front Element..........\n");
                sleep(1);
                break;
            case 'd':
                if (Q == NULL) {
                    printf("Queue is not created yet\n");
                    break;
                }
                peek(Q);
                break;
            case 'e':
                if (Q == NULL) {
                    printf("Queue is not created yet\n");
                    break;
                }
                display(Q);
                break;
            case 'f':
                if (Q == NULL) {
                    printf("Queue is not created yet\n");
                    break;
                }
                clearAll(Q);
                printf("Queue cleared\n");
                break;
            default:
                printf("Invalid Input\n");
                break;
        }

        printf("Given Menu :\n");
        printf("a. To Create Queue\n");
        printf("b. To Insert element\n");
        printf("c. To Delete element at Rear\n");
        printf("d. To print element at Front\n");
        printf("e. To print all elements\n");
        printf("f. To delete all elements\n");
        printf("g. Exit\n");

        scanf(" %c", &ch);
    }

    return 0;
}
