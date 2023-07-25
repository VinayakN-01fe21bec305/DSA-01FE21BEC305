#include<stdio.h>
#define max 10
int Q[max];
int f,r;
int main()
{
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
                        scanf("%d",&ele);
                        Insert(ele);
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
void Insert(int ele)
{
    if(f==-1&&r==-1)
    {
        f=(f+1)%max;
        r=(r+1)%max;
        Q[r]=ele;

    }
    else
    {
        r=(r+1)%max;
        Q[r]=ele;

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
            printf("Element deleted = %d \n",Q[f]);
            f=-1;
            r=-1;
        }
        else
        {
            printf("Element deleted = %d \n",Q[f]);
            f=(f+1)%max;

        }
    }
}

void display()
{
    int i;
    for(i=f;i!=r;i=(i+1)%max)
    {
         printf("%d ",Q[i]);
    }
    printf("%d ",Q[r]);
    printf("\n");
}

