#include<stdio.h>
#include<stdlib.h>
#define MAX 100
FILE* fp,*fp1;
int que[MAX];
int front=0,rear=0;
void back()
{
    for(int i=front;i<rear;i++)
        fprintf(fp1,"%d\n",que[i]);
}
void enqueue()
{
   if(rear==MAX-1)
   {
       printf("Queue is empty\n");
       return;
   }
   fscanf(fp,"%d",&que[rear]);
   rear++;
}

void dequeue()
{
   if(front==rear)
   {
       printf("Queue is empty\n");
       return;
   }
   printf("%d is dequeued\n",que[front]);
   front++;
}

void display()
{
    if(front==rear)
    {
        printf("The queue is empty\n");
        return;
    }
  for(int i=front;i<rear;i++)
  {
      printf("%d ",que[i]);
  }
}

int main()
{
    fp1=fopen("MYST1.txt","w");
    fp=fopen("MYST.txt","r");
    printf("THESE ARE STACK BASIC OPERATIONS\n");
    rewind(fp);
    int oper;
    while(1)

    {
        printf("ENTER YOUR CHOICE\n1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\n");

        scanf("%d",&oper);
        switch(oper)
        {

        case 1 :
            enqueue();
            break;
        case 2 :
            dequeue();
            break;

        case 3 :
            display();
            break;
        case 4 :
            back();
            exit(0);
        default:
            printf("ENTER THE VALID CHOICE\n");
        }
    }

}
