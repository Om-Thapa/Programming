#include<stdio.h>
#include<stdlib.h> //For Dynamic Memory Allocation
#include<unistd.h> //For using Time Delay Function
struct node{
    int info;
    struct node *next;
};

struct node *head;

void createList(int x){

    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->info=x;
    new->next=NULL;
    head=new;
    
}

void insertAtHead(int x){

    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->info=x;

    if(head==NULL){
        head=new;
        new->next=NULL;
    }else{
        new->next=head;
        head=new;
    }

}

void insertAtTop(int x){

    struct node *curr=head;
    struct node *new=(struct node *)malloc(sizeof(struct node));

    while( curr->next!=NULL){
        curr=curr->next;
    }

    curr->next=new;
    new->next=NULL;
    new->info = x;

}

void insertAtK(int k, int x){

    struct node *new=(struct node *)malloc(sizeof(struct node));
    struct node *curr=head;
    new->info=x;

    for( int i=1 ; i<k ; i++ )
    curr=curr->next;
    new->next=curr->next;
    curr=new;

}

void deleteFromTop(struct node *s){

    struct node *curr=s;
    struct node *prev=NULL;

    while( curr->next!=NULL){
        prev=curr;
        curr=curr->next;
    }

    prev->next=NULL;

}

void treverse(struct node *s){

    struct node *curr=s;

    while(curr!=0){
        printf("%d ",curr->info);
        curr=curr->next;
    }

    printf("\n");
}

void main(){

    printf("Given Menu :\n");
    printf("a. To Create List \n");
    printf("b. To Insert at the top\n");
    printf("c. To delete from top\n");
    printf("d. To print all node information\n");
    printf("e. Exit\n");

    char ch;
    scanf(" %c",&ch);
    
    while(ch!='e'){
        int i;
        switch (ch){

        case 'a':
            printf("a.Enter info : \n");
            scanf("%d",&i);
            createList(i);
            printf("Creating List......\n");
            sleep(1);
            break;

        case 'b':
            printf("b. Enter info : \n");
            scanf("%d",&i);
            insertAtTop(i);
            printf("Inserting..........\n");
            sleep(1);
            break;

        case 'c':
            deleteFromTop(head);
            printf("Deleting..........\n");
            sleep(1);
            break;

        case 'd':
            treverse(head);
            printf("Traversed..........\n");
            sleep(1);
            break;

        default:
            printf("Invalid Input \n");
            sleep(1);
            break;
        }
        
        printf("a. To Create List \n");
        printf("b. To Insert at the top\n");
        printf("c. To delete from top\n");
        printf("d. To print all node information\n");
        printf("e. Exit\n");
        scanf(" %c",&ch);

    }
}