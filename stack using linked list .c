#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
int data;
struct node*next;
};
struct node*top=NULL;
bool isEmpty(){
  return top==NULL;
void push(int data){
  struct node*newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=top;
top=newnode;
}
if(isEmpty()){
printf("stack underflow!cannot pop froma nempty stack \n");
return -1;
}
struct node*temp=top;
int data=temp=top;
top=temp->next;
free(temp);
return data;
}
int peek(){
  if(isEmpty()){
printf("stack is empty\n");
return -1;
  }
return top->data;
}
int main(){
  push(10);
push(20);
push(30);
printf("Top element:%d\n",peek());
printf("popped element:%d\n",pop());
printf("popped element:%d\n",pop());
printf("TOp element :%d\n",peek());
return 0;
}
