//Enqueue(), Dequeue(), Peek(), display()
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

struct queue{
    int info, front, rear, capacity;
    int *arr;
};

struct queue *createQueue(int n){
    struct queue *new=(struct queue *)malloc(sizeof(struct queue));
    new->capacity=n;
    new->front=new->rear=-1;
    new->arr=(int *)malloc(n*sizeof(int));
    return new;
}

void Enqueue(struct queue *s, int n){
    if(s->front==-1)
        s->front++;
    s->rear++;
    s->arr[s->rear]=n;
}

void Dequeue(struct queue *s){
    s->rear--;
}

void peek(struct queue *s){
    if( s->front==-1 ){
        printf("Queue is Empty\n");
    }else{
        printf("Front Element : %d\n",s->arr[s->front]);
    }
    sleep(1);
}

void display(struct queue *s){
    if( s->front==-1 ){
        printf("Queue is Empty\n");
    }else{
        for( int i = s->front; i <= s->rear ; i++)
        printf("%d ",s->arr[i]);
        printf("\n");                
        printf("Traversed..........\n");
    }
    sleep(1);
}

void clearAll(struct queue *s){
    s->front=s->rear=-1;
    printf("Clearing all data..........\n");
    sleep(1);
}

int main() {
    char ch;
    struct queue* Q = NULL;

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
                printf("Creating Queue......\n");
                sleep(1);
                break;
            case 'b':
                if (Q == NULL) {
                    printf("Queue is not created yet\n");
                    break;
                }
                if(Q->rear==Q->capacity-1){
                    printf("Queue Overflow \n");
                    sleep(1);
                    break;
                }
                printf("b. Enter element to insert: \n");
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
                if(Q->front==Q->rear){
                    Q->front=Q->rear=-1;
                    sleep(1);
                    break;
                }
                Dequeue(Q);
                printf("Deleting..........\n");
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