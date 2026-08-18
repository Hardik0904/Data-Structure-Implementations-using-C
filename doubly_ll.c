#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int *data;
    struct node *next;
    struct node *prev; 
} node;

node* init_dll(int value){
    node* newnode=(node*)malloc(sizeof(node));
    if(!newnode){
        perror("memory cannot be allocated");
        exit(EXIT_FAILURE);
    }
    newnode->data=(int*)malloc(sizeof(int));
    if(!newnode->data){
        perror("data memory cannot be allocated");
        exit(EXIT_FAILURE);
    }
    *(newnode->data)=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

node* push_back(node* head, int value){
    node* newnode=init_dll(value);
    if(head==NULL){
        head=newnode;
        return head;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    return head;
}

void print_dll(node* head){
    node* temp=head;
    while(temp!=NULL){
        printf("%d ", *temp->data);
        temp=temp->next;
    }
}

int main(){
    node* head=init_dll(7);
    head=push_back(head, 8);
    head=push_back(head, 9);
    head=push_back(head, 10);
    head=push_back(head, 5);
    head=push_back(head, 7);
    print_dll(head);
}