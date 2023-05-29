#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct stack
{
    int data[100];
    int top;
};
void push(struct stack* s1,int num)
{
    if(s1->top==100-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        s1->top++;
        s1->data[s1->top]=num;
    }
}
int pop(struct stack* s)
{
    int a;
    if(s->top==-1)
    {
       printf("Stack underflow\n");
    }
    else
    {
       a=s->data[s->top];
       s->top--;
    }
    return a;
}
int main()
{
    struct stack s1_var,s2_var,*s1,*s2;
    s1=&s1_var;
    s2=&s2_var;
    s1->top=-1;
    s2->top=-1;
    FILE *fp=NULL;
    fp=fopen("okdone.txt","w+");
    if(fp==NULL)
    {
        printf("Error in creating a file\n");
        exit(0);
    }
    srand(time(0));
    int n,num,u=40,l=1;
    printf("Enter the random number size\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
          num=rand()%(u-l+1)+l;
          printf("%d ",num);
          push(s1,num);
    }
    for(int i=0;i<n;i++)
    {
        num=pop(s1);
        push(s2,num*2);
    }
    for(int i=0;i<n;i++)
    {
        num=pop(s2);
        push(s1,num);
    }
    rewind(fp);
    for(int i=0;i<n;i++)
    {
        num=pop(s1);
        fprintf(fp,"%d ",num);
    }
    fclose(fp);
}
