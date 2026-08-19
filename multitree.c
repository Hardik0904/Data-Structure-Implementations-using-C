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