#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUM 100
#define SIZE 200
#define MAX 12
int top=0;
int stack[MAX];
FILE* pu;
FILE* po;
FILE* oper;
FILE* ran;
FILE* stac;
void push()
{
    int elem;
   fscanf(ran,"%d",&elem);
   fprintf(pu,"%d\n",elem);
   fprintf(oper,"%d is pushed\n",elem);
    stack[top++]=elem;
}
void pop()
{
    printf("%d is poped\n",stack[top-1]);
    fprintf(po,"%d\n",stack[top-1]);
    fprintf(oper,"%d is poped\n",stack[top-1]);
    top--;
}
void display()
{
    for (int i=0;i<top;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
void push_b()
{
    for(int i=top;i>=0;i--)
    {
        fprintf(stac,"%d\n",stack[top]);
    }
}
int main()
{
pu=fopen("push.txt","a");
po = fopen( "pop.txt" ,"a");
oper=fopen("operation.txt","a");
stac=fopen("stack.txt","r+");
ran=fopen("random.txt","r+");
  srand(time(NULL));
  for(int i=0;i<NUM;i++)
  {
      fprintf(ran,"%d\n",rand()%SIZE);
  }
  rewind(ran);
    printf("THESE ARE STACK BASIC OPERATIONS\n");
    int oper;


while(1)
{
        printf("ENTER YOUR CHOICE\n1:PUSH\n2:POP\n3:DISPLAY\n");
        scanf("%d",&oper);
        switch(oper)
        {

        case 1 :
            push();
            break;
        case 2 :
            pop();
            break;

        case 3 :
            display();
            break;
        case 4 :
            push_b();
            exit(0);
            break;

        default:
            printf("ENTER THE VALID CHOICE\n");
        }
}
}
