#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define MAX 6
struct patient
{
    char name[30];
    int pr;
};
int r=-1;
int f=-1;
struct patient q[MAX];
struct patient p;
void display();
struct patient dequeue();
void sort();
void insert(struct patient p);

main()
{
    int ch;
    int ele,n;
    char name[30];
    while(1)
    {
        printf("1-Insert /Enqueue\n");
        printf("2-Delete / Dequeue\n");
        printf("3-Display\n");
        printf("4-Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:  if(f==(r+1)%MAX)
                          printf("Queue is full\n");
                    else
                    {
                        printf("Enter the name and priority\n");
                        scanf("%s%d",&p.name,&p.pr);
                        insert(p);
                    }
                    break;
            case 2: if(f==-1 && r==-1)
                    {
                        printf("Queue is empty\n");
                    }
                    else
                    {
                        p=dequeue();
                        printf("Deleted element is:%s\t%d\n",p.name,p.pr);
                    }
                    break;
            case 3:if(f==-1 && r==-1)
                    {
                        printf("Queue is empty\n");
                    }
                    else
                        display();
                   break;
            case 4:exit(0);break;
            default:printf("Invalid choice\n");
                    break;
        }
    }
}
void insert(struct patient p)
{
    if(r==-1 && f==-1)
    {
        f=(f+1)%MAX;
        r=(r+1)%MAX;
        q[r]=p;
    }
    else
    {
        r=(r+1)%MAX;
        q[r]=p;
        sort();
    }
}
struct patient dequeue()
{

    if(f==r)
    {
        p=q[f];
        f=-1;
        r=-1;
    }
    else
    {
        p=q[f];
        f=(f+1)%MAX;
    }
    return(p);
}
void display()
{
    int i;
    for(i=f;i<=r;i=(i+1)%MAX)
        printf("%s\t%d\n",q[i].name,q[i].pr);
}
void sort()
{
    int i,j;
    struct patient temp;
    for(i=f;i<=r-f+1;i=(i+1)%MAX)
    {
        for(j=f;j<=r-f;j++)
        {
            if(q[j].pr < q[j+1].pr)
            {
                temp=q[j];
                q[j]=q[j+1];
                q[j+1]=temp;
            }
        }
    }
}
