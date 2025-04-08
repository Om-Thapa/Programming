//Implement Hashing

#include <stdio.h>
#include <stdlib.h>

struct node{
    int *arr, size, count;
    float load_factor;
};

struct node* createHashTable(int size) {
    struct node* n = (struct node*)malloc(sizeof(struct node));

    n->arr = (int *)malloc(size * sizeof(int));
    n->count = 0;
    n->load_factor = 0.0;
    n->size = size;

    for (int i = 0; i < size; i++) {
        n->arr[i] = -1;
    }

    return n;
}

int hash(int key, int size) {

    int s = 0;
    for( ; key; key /= 10, s+= key%10);

    return s % size;
}

void insert(struct node* s, int key, int value){

    s->load_factor = (float)s->count / s->size;

    if(s->load_factor >= 0.75){
        s->arr = (int *)realloc(s->arr, (s->size * 2) * sizeof(int));

        for(int i=s->size; i < s->size * 2; i++){
            s->arr[i] = -1;
        }

        s->size *= 2;
        s->load_factor = (float)s->count / s->size;
        printf("New size: %d\n", s->size);
    }
    
    int idx = hash(key, s->size);

    if(s->arr[idx] == -1) {
        s->arr[idx] = value;
        s->count++;
    } else {
        printf("Collision occurred\n");
    }
}

void printValue(struct node* s, int key){
    int idx = hash(key, s->size);

    if(s->arr[idx] == -1) {
        printf("No value found for key %d\n", key);
        return;
    }

    printf("Value at index %d: %d\n", idx, s->arr[idx]);
}

void main(){

    char ch;
    struct node* s = NULL;
    int key, value, i;

    printf("Given Menu :\n");
    printf("a. To Create Hash Table\n");
    printf("b. To Insert element\n");
    printf("c. To print value with given key\n");
    printf("d. Exit\n");
    
    scanf(" %c", &ch);
    while (ch != 'd') {
        switch (ch) {
            case 'a':
                printf("Enter the size of hash table: ");
                scanf("%d", &i);
                s = createHashTable(i);

                break;
            case 'b':
                printf("Enter the key and value :\n");
                scanf("%d %d", &key, &value);
                insert(s, key, value);
            
                break;
            case 'c':
                printf("Enter the key\n");
                scanf("%d", &key);
                printValue(s, key);

                break;
            
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("Given Menu :\n");
        printf("a. To Create Hash Table\n");
        printf("b. To Insert element\n");
        printf("c. To print value with given key\n");
        printf("d. Exit\n");
        
        scanf(" %c", &ch);
    }
}