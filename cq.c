#include<stdio.h>
#define max 5
int front=-1,rear=-1;
char queue[max];
void cqinsert();
void cqdelete();
void cqdisplay();
void main()
{
int ch;
while(1)
{
printf("Circular Operations\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
printf("Enter your choice\n");
scanf("%d%*c",&ch);
switch(ch)
{
case 1: cqinsert();
break;
case 2: cqdelete();
break;
case 3: cqdisplay();
break;
case 4: exit(0);
default: printf("Invalid Choice\n");
}
}
}
void cqinsert()
{
char x;
printf("Enter the character\n");
scanf("%c",&x);
if((front==0 && rear==max-1) || (front==rear+1))
{
printf("Circular Queue is Full or Overflow\n");
return;
}
if(front==-1 && rear==-1)
front=rear=0;
else
{
if(rear==max-1)
rear=0;
else
rear++;
}
queue[rear]=x;
}
void cqdelete()
{
char y;
if(front==-1 && rear==-1)
{
printf("Circular Queue is Empty or Underflow\n");
return;
}
y=queue[front];
if(front==rear)
front=rear=-1;
else
{
if(front==max-1)
front=0;
else
front++;
}
printf("The deleted element is %c\n",y);
}
void cqdisplay()
{
int i;
if(front==-1 && rear==-1)
{
printf("Queue is Empty\n");
return;
}
printf("The Queue Contents are\n");
for(i=front; i!=rear; i=(i+1)%max)
printf("%c\n",queue[i]);
printf("%c\n",queue[rear]);
}
