#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>

#define MAX 100
#define MAXQUEUE 100
struct node {
    int data;
    struct node *next;
};
struct stack {
  int items[MAX];
  int top;
};
typedef struct stack st;
int count = 0;

struct node *front = NULL;
struct node *rear = NULL;

int insert(int data){
    // Queue is empty 
    if(front==NULL){
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        front = rear = new;
    }
    // Queue is not empty
    else {
        struct node *new= (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;
        rear->next = new;
        rear = new;
    }
}

int display(){

    // Queue is empty
    if(front==NULL){
        printf("Queue is empty \n");
        return 1;
    }
    printf("\n");
    printf("Queue: ");
    struct node *index = front;
    while(index!=NULL){
        printf("%d - ", index->data);
        index = index->next;
    }

    printf("\n");

    return 1;
}
//stack
void push(st *s, int newitem) {
  if (s->top == MAX - 1) {
    printf("stack dolu");
  } else {
    s->top++;
    s->items[s->top] = newitem;
  }
  count++;
}
//stack oluşturma
void createEmptyStack(st *s) 
{
    s->top = -1; 
}
//stack yazdırma
void printStack(st *s) {
  printf("Stack: ");
  for (int i = 0; i < count; i++) {
    printf("%d - ", s->items[i]);
  }
  printf("\n");
}

int main(){
    st *s = (st *)malloc(sizeof(st));
  createEmptyStack(s);
    int max=100;
    while (max--) {
    int random = rand() % 1000 + 1;
    insert(random);
  }
  //queue stack'e  eklendi
    struct node *index = front;
    while(index!=NULL){
        push(s, index->data);
        index = index->next;
    }
  display();
  printf("\n");
  printStack(s);
}