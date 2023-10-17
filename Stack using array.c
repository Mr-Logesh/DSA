#include<stdio.h>
#include<stdlib.h>
#define MAX-SIZE 100
int stack[MAX-SIZE];
int top=-1;

bool isEmpty(){
  return top==-1;
}
bool isFULL(){
  return top==MAX-SIZE-1;
void push(int data){
  if(is FULL()){
printf("stack overflow! cannot push %d\n",data);
return;
  }
stack[++top]=data;
}
int pop(){
  if(isEmpty){
printf("stack underflow! cannot pop from an empty stack\n");

return-1;
  }
return stack[top-1];
}
int peek(){
  if(isEmpty()){
printf("stack is empty \n");
return -1;
  }
return stack[top];
}
int main(){
  push(10);
push(20);
push(30);
printf("top element:%d\n",peek());
printf("popped element:%d\n",pop());
printf("popped element:%d\n",pop());
printf("top element:%d\n",peek());

return 0;
}
