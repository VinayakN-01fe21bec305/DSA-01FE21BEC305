#include<stdio.h>
#define max 5
struct student
{
    char name[100];
    int rno;
};
struct student Q[max];
int f,r;
int main()
{
    struct student Q1;
     f=-1;
     r=-1;
    int ch;
    int ele;
    while(1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");

    printf("enter the choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : if((r+1)%max==f)
                {
                        printf("Circular Queue is Full\n");

                }
                else
                {
                        printf("enter the data\n");
                        scanf("%s %d",&Q1.name,&Q1.rno);
                        Insert(Q1);
                }
                break;

        case 2 : delete();
                 break;

        case 3 : if(f==-1&&r==-1)
                   {
                       printf("Circular Queue is empty\n");
                   }
                else
                    display();
                    break;
        case 4 : exit(0);
        default : printf("Invalid Choice\n");
    }
    }
}
void Insert(struct student Q1)
{
    if(f==-1&&r==-1)
    {
        f=(f+1)%max;
        r=(r+1)%max;
        Q[r]=Q1;

    }
    else
    {
        r=(r+1)%max;
        Q[r]=Q1;

    }
}

void delete()
{
    if(f==-1&&r==-1)
    {
        printf(" Circular Queue is empty\n");

    }
    else
    {
        if(f==r)
        {
            printf("Element deleted = %s  %d \n",Q[f].name,Q[f].rno);
            f=-1;
            r=-1;
        }
        else
        {
            printf("Element deleted = %s  %d \n",Q[f].name,Q[f].rno);
            f=(f+1)%max;

        }
    }
}

void display()
{
    int i;
    for(i=f;i!=r;i=(i+1)%max)
    {
        printf("%s  %d \n",Q[i].name,Q[i].rno);
    }
     printf("%s  %d \n",Q[i].name,Q[i].rno);
    printf("\n");
}


