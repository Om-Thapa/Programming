#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct node{
    int info;
    struct node *next,*prev;
};

struct node *head;
int size,capacity;

void createList(int n,int x){

    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->info=x;
    capacity=n;
    size=0;
    new->next=new->prev=NULL;
    head=new;

}

void insertAtHead(int x){

    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->info=x;
    new->prev=NULL;
    size++;

    if(head==NULL){
        head=new;
        new->next=NULL;
    }else{
        new->next=head;
        head->prev=new;
        head=new;
    }
}

void insertAtTop(int x){

    struct node *cur = head;
    struct node *new = ( struct node * )malloc( sizeof(struct node) );
    new->info = x;
    new->next = NULL;

    while( cur->next!=NULL ){
        cur = cur->next;
    }

    new->prev = cur;
    cur->next = new; 
    size++;

}

void insertAtK(int k, int x){

    struct node *new = (struct node *)malloc( sizeof(struct node) );
    struct node *cur = head;
    new->info = x;

    for( int i=1 ; i<k-1 ; i++ ){
        cur = cur->next;
    }

    new->prev = cur;
    new->next = cur->next;
    cur->next->prev = new;
    cur->next = new;
    size++;

}

void deleteFromTop(){

    struct node *curr=head;

    while( curr->next!=NULL){
        curr=curr->next;
    }

    if( curr == head ){
        head = NULL;
     }else {
        curr->prev->next=NULL;
    }

    size--;
    free(curr);

}

void treverse(){

    struct node *curr = head;

    while(curr!=NULL){
        printf("%d ",curr->info);
        curr=curr->next;
    }

    printf("\n");

}

void revTraverse(){

    struct node *curr = head;
    while( curr->next != NULL ){
        curr=curr->next;
    }

    while( curr!= NULL){
        printf("%d ",curr->info);
        curr=curr->prev;
    }
    printf("\n");

}

void main(){

    printf("Given Menu :\n");
    printf("a. To Create List \n");
    printf("b. To Insert at the Top\n");
    printf("c. To Insert at the Head\n");
    printf("d. To Insert at the K position\n");
    printf("e. To delete from top\n");
    printf("f. To print all node information\n");
    printf("g. To print all node information in Reversed order\n");
    printf("h. Exit\n");
    
    char ch;
    scanf(" %c",&ch);
    
    while(ch!='h'){

        int i;
        switch (ch){

            case 'a':
                printf("a.Enter info and capacity : \n");
                int c;
                scanf("%d%d",&i,&c);
                createList( c, i );
                printf("Creating List......\n");
                sleep(1);
                break;
            
            case 'b':
                if( size == capacity-1 ){
                    printf("List Overflow\n");
                    sleep(1);
                    break;
                }
                printf("b. Enter info : \n");
                scanf("%d",&i);
                insertAtTop( i );
                printf("Inserting..........\n");
                sleep(1);
                break;
                
            case 'c':
                if( size == capacity-1 ){
                    printf("List Overflow\n");
                    sleep(1);
                    break;
                }
                printf("b. Enter info : \n");
                scanf("%d",&i);
                insertAtHead( i );
                printf("Inserting..........\n");
                sleep(1);
                break;
                
            case 'd':
                if( size == capacity-1 ){
                    printf("List Overflow\n");
                    sleep(1);
                    break;
                }
                printf("b. Enter info and k postion : \n");
                int k;
                scanf("%d%d",&i,&k);
                insertAtK( k, i );
                printf("Inserting..........\n");
                sleep(1);
                break;

            case 'e':
                if( head == NULL){
                    printf("Underflow\n");
                    sleep(1);
                    break;
                }
                deleteFromTop();
                printf("Deleting..........\n");
                sleep(1);
                break;
                
            case 'f':
                treverse();
                printf("Traversed..........\n");
                sleep(1);
                break;
                
            case 'g':
                if( head == NULL){
                    printf("Underflow\n");
                    sleep(1);
                    break;
                }
                revTraverse();
                printf("Traversed..........\n");
                sleep(1);
                break;

            default:
                printf("Invalid Input \n");
                sleep(1);
                break;
        }
        
        printf("Given Menu :\n");
        printf("a. To Create List \n");
        printf("b. To Insert at the Top\n");
        printf("c. To Insert at the Head\n");
        printf("d. To Insert at the K position\n");
        printf("e. To delete from top\n");
        printf("f. To print all node information\n");
        printf("g. To print all node information in Reversed order\n");
        printf("h. Exit\n");
        scanf(" %c",&ch);

    }
}