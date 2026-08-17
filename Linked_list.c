#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int *data;
    struct node *next;
} node;

//initializing the list
node* ll_init(int value){
    node* head=(node*)malloc(sizeof(node));
    if(!head){
        perror("memory cannot be allocated");
        exit(EXIT_FAILURE);
    }
    head->data=(int*)malloc(sizeof(int));
    if(!head->data){
        perror("memory cannot be allocated");
        exit(EXIT_FAILURE);
    }
    *(head->data)=value;
    head->next=NULL;
    return head;
}

//push element at back
void push_back(node **head, int value){
    
    node* new_node=ll_init(value);
    if(*head==NULL){
        *head=new_node;
    }
    node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}

//print ll
void print_ll(node* head){
    node* temp=head;
    while(temp!=NULL){
        printf("%d", *temp->data);
        temp=temp->next;
    }
}

int main(){
    node* newnode=ll_init(3);
    push_back(&newnode, 6);
    push_back(&newnode, 10);
    print_ll(newnode);
}