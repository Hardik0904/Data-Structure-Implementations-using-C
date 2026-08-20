#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int* data;
    struct tree* left;
    struct tree* sibling;
}tree;

tree* create_node(int value){
    tree* T=(tree*)malloc(sizeof(tree));
    if(!T){
        perror("memory cannot be allocated");
        exit(EXIT_FAILURE);
    }
    T->left=NULL;
    T->sibling=NULL;
    T->data=(int*)malloc(sizeof(int));
    if(!T->data){
        perror("memory not allocated");
        exit(EXIT_FAILURE);
    }
    *T->data=value;
    return T;
}

//insert new child
void insert_child(tree* parent, int value){
    tree* t=create_node(value);
    if(parent->left==NULL) parent->left=t;
    else{
        tree* temp=parent->left;
        while(temp->sibling!=NULL){
            temp=temp->sibling;
        }
        temp->sibling=t;
    }
}

//delete an element
void delete_node(tree *parent, tree *child)
{
    tree *prev;
    tree *last_child;

    /* Case 1: child is the first child of parent */
    if (parent->left == child) {

        /* Child has no children */
        if (child->left == NULL) {
            parent->left = child->sibling;
        }

        /* Child has children */
        else {
            last_child = child->left;

            /* Find last child of child */
            while (last_child->sibling != NULL) {
                last_child = last_child->sibling;
            }

            /* Attach child's siblings after child's children */
            last_child->sibling = child->sibling;

            /* Parent now points to child's first child */
            parent->left = child->left;
        }
    }

    /* Case 2: child is not the first child */
    else {
        prev = parent->left;

        /* Find the sibling immediately before child */
        while (prev != NULL && prev->sibling != child) {
            prev = prev->sibling;
        }

        /* Child was not found */
        if (prev == NULL) {
            return;
        }

        /* Child has no children */
        if (child->left == NULL) {
            prev->sibling = child->sibling;
        }

        /* Child has children */
        else {
            last_child = child->left;

            /* Find last child */
            while (last_child->sibling != NULL) {
                last_child = last_child->sibling;
            }

            /* Attach child's old siblings */
            last_child->sibling = child->sibling;

            /* Previous sibling now points to child's children */
            prev->sibling = child->left;
        }
    }

    /* Free only the node itself */
    free(child->data);
    free(child);
}