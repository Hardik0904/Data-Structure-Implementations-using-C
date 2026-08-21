#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int* data;
    struct node* left;
    struct node* right; 
} node;

node* create_node(int value){
    node* new_node=(node*)malloc(sizeof(node));
    if(!new_node){
        perror("no memory allocated");
        exit(EXIT_FAILURE);
    }
    new_node->data=(int*)malloc(sizeof(int));
    if(!new_node->data){
        perror("data memory not allocated");
        exit(EXIT_FAILURE);
    }
    *new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

//insert new node
node* insert(node* root, int value){
    if(root==NULL){
        return create_node(value);
    }
    node* temp=root;
    while(1){
        if(*temp->data>value && temp->left!=NULL){
            temp=temp->left;
        }
        else if(*temp->data<value && temp->right!=NULL)
        temp=temp->right;
        else if(*temp->data==value){
            printf("duplicate value not allowed");
            return root;
        }
        else break;
    }
    node* new_node=create_node(value);
    if(*temp->data>value)
    temp->left=new_node;
    else temp->right=new_node;
    return root;
}

//search in tree
node* search(node* root, int value){
    if(root==NULL){
        return NULL;
    }
    node* temp=root;
    while(temp!=NULL && *temp->data!=value){
        if(*temp->data<value){
            temp=temp->right;
        }
        else temp=temp->left;
    }
    if(temp!=NULL && *temp->data==value) return temp;
    else return NULL;
}

//inorder traversal
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", *root->data);
    inorder(root->right);
}

//pre-order traversal
void preorder(node* root){
    if(root==NULL) return;
    printf("%d ", *root->data);
    preorder(root->left);
    preorder(root->right);
}

//post-order
void postorder(node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", *root->data);
}

//search min
node* find_min(node* root){
    if(root==NULL) return NULL;
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

//delete element
node* delete(node *root, int value) {
    node *parent;
    node *temp;
    node *child;
    node *successor;

    if (root == NULL) {
        return NULL;
    }

    parent = NULL;
    temp = root;

    /* Find node and its parent */
    while (temp != NULL && *temp->data != value) {

        parent = temp;

        if (value < *temp->data) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    /* Node not found */
    if (temp == NULL) {
        printf("Node not found\n");
        return root;
    }


    /* CASE 1: No children */
    if (temp->left == NULL && temp->right == NULL) {

        /* Deleting root */
        if (parent == NULL) {
            erase(temp);
            return NULL;
        }

        if (parent->left == temp) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }

        erase(temp);

        return root;
    }


    /* CASE 2: Exactly one child */
    if (temp->left == NULL || temp->right == NULL) {

        if (temp->left != NULL) {
            child = temp->left;
        }
        else {
            child = temp->right;
        }

        /* Deleting root */
        if (parent == NULL) {
            erase(temp);
            return child;
        }

        if (parent->left == temp) {
            parent->left = child;
        }
        else {
            parent->right = child;
        }

        erase(temp);

        return root;
    }


    /* CASE 3: Two children */

    /* Find inorder successor */
    successor = find_min(temp->right);

    /* Copy successor's value */
    *temp->data = *successor->data;

    /*
     * Now delete the successor.
     * Successor can have at most one child.
     */
    if (successor->right != NULL) {

        child = successor->right;
    }
    else {

        child = NULL;
    }

    /*
     * Find successor's parent.
     * Start from temp's right subtree.
     */
    parent = temp;

    while (parent->left != successor &&
           parent->right != successor) {

        if (*successor->data < *parent->data) {
            parent = parent->left;
        }
        else {
            parent = parent->right;
        }
    }

    if (parent->left == successor) {
        parent->left = child;
    }
    else {
        parent->right = child;
    }

    erase(successor);

    return root;
}