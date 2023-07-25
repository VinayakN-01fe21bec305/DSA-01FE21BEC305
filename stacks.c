#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int top=0;
int STACK[MAX];
FILE* fp;
void push()
{
    if(top==MAX-1)
    {
        printf("Stack is Full\n");
        return;
    }
    int element;
    fscanf(fp,"%d",&elem);
    stack[top++]=elem;

}
void pop()
{
    if(top==0)
    {
        printf("Stack is empty\n");
        return;
    }
        top--;
    printf("%d is poped\n",stack[top]);

}
void peak()
{
    printf("%d is peak element\n",stack[top-1]);
}
void display()
{
    if(top==0)
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i=0;i<top;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main()
{
    fp=fopen("mystack.txt","r");
    printf("THESE ARE STACK BASIC OPERATIONS\n");
    rewind(fp);
    int oper;
    while(1)

    {
        printf("ENTER YOUR CHOICE\n1:PUSH\n2:POP\n3:PEAK\n4:DISPLAY\n5:Exit\n");

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
            peak();
            break;
        case 4 :
            display();
            break;
        case 5 :
            exit(0);
        default:
            printf("ENTER THE VALID CHOICE\n");
        }
    }

}
