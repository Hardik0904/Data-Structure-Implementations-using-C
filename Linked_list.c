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
void push_back(node *head, int value){
    
    node* new_node=ll_init(value);
    if(head==NULL){
        head=new_node;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}

//insert at k
node* insert_k(node* head, int k, int value){
    node* new_node=ll_init(value);
    if(k==1){
        new_node->next=head;
        head=new_node;
        return head;
    }
    node* temp=head;
    int cnt=0;
    for(int i=0; i<k-2; i++){
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    return head;
}

//print ll
void print_ll(node* head){
    node* temp=head;
    while(temp!=NULL){
        printf("%d ", *temp->data);
        temp=temp->next;
    }
}

int main(){
    node* newnode=ll_init(3);
    push_back(newnode, 6);
    push_back(newnode, 10);
    node* head=insert_k(newnode, 1, 12);
    print_ll(head);
}