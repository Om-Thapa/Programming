#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct node {
    int info;
    struct node *left, *right;
};

struct node *head;

void createTree(int x) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = x;
    new->left = new->right = NULL;
    head = new;
}

void insertNode(int x) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = x;
    new->left = new->right = NULL;

    if (head == NULL) {
        head = new;
        return;
    }

    struct node *curr = head;
    struct node *prev = NULL;
    while (curr != NULL) {
        prev = curr;
        if (x > curr->info) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    if (x > prev->info) {
        prev->right = new;
    } else {
        prev->left = new;
    }
}

void inOrder(struct node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->info);
    inOrder(root->right);
}

void preOrder(struct node *root) {
    if (root == NULL) return;
    printf("%d ", root->info);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->info);
}

struct node* inOrderSuc(struct node *root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

void deleteNode(int target) {
    if (head == NULL) {
        printf("Tree is Empty\n");
        return;
    }

    struct node *curr = head;
    struct node *prev = NULL;
    struct node *successor = NULL;

    while (curr != NULL && curr->info != target) {
        prev = curr;
        if (target > curr->info) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    if (curr == NULL) {
        printf("Node not found\n");
        return;
    }

    if (curr->left == NULL && curr->right == NULL) {
        if (prev == NULL) {
            head = NULL;
        } else if (prev->left == curr) {
            prev->left = NULL;
        } else {
            prev->right = NULL;
        }
        free(curr);
    } else if (curr->left == NULL || curr->right == NULL) {
        struct node *child = (curr->left != NULL) ? curr->left : curr->right;
        if (prev == NULL) {
            head = child;
        } else if (prev->left == curr) {
            prev->left = child;
        } else {
            prev->right = child;
        }
        free(curr);
    } else {
        successor = inOrderSuc(curr->right);
        int temp = successor->info;
        deleteNode(successor->info);
        curr->info = temp;
    }
}

int main() {
    printf("Given Menu :\n");
    printf("a. To Create Tree\n");
    printf("b. To Insert in the tree\n");
    printf("c. To traverse In-Order\n");
    printf("d. To traverse Pre-Order\n");
    printf("e. To traverse Post-Order\n");
    printf("f. Exit\n");

    char ch;
    scanf(" %c", &ch);

    while (ch != 'f') {
        int i;
        switch (ch) {
            case 'a':
                printf("Enter info: \n");
                scanf("%d", &i);
                createTree(i);
                printf("Creating Tree...\n");
                break;

            case 'b':
                printf("Enter info: \n");
                scanf("%d", &i);
                insertNode(i);
                printf("Inserting...\n");
                break;

            case 'c':
                printf("In-Order Traversal:\n");
                inOrder(head);
                printf("\n");
                break;

            case 'd':
                printf("Pre-Order Traversal:\n");
                preOrder(head);
                printf("\n");
                break;

            case 'e':
                printf("Post-Order Traversal:\n");
                postOrder(head);
                printf("\n");
                break;

            default:
                printf("Invalid Input\n");
                break;
        }

        printf("Given Menu :\n");
        printf("a. To Create Tree\n");
        printf("b. To Insert in the tree\n");
        printf("c. To traverse In-Order\n");
        printf("d. To traverse Pre-Order\n");
        printf("e. To traverse Post-Order\n");
        printf("f. Exit\n");
        scanf(" %c", &ch);
    }

    return 0;
}
