#include<stdio.h>
#define max 5
struct random
{
    int data;
    int pri;
};
struct random Q[max];
int f,r;
FILE* fp3,*fp4,*fp5,*fp6,*fp7 ;
  struct random Q1;
int main()
{

     f=-1;
     r=-1;
    int ch,n,i;
    int ele;
     fp3=fopen("raksha.txt","w");
     fp4=fopen("hello.txt","w");
     fp5=fopen("positive.txt","w");
     fp6=fopen("bcd.txt","w");
     fp7=fopen("abc.txt","w");
      time_t t;
      srand((unsigned) time(&t));
    printf("Enter the element\n");
        scanf("%d",&n);
        int ar2[n];

    for(i=0;i<n;i++)
    {
        ar2[i]=rand()%1000;
        fprintf(fp3,"%d\n",ar2[i]);

    }
   fclose(fp3);
      fp3=fopen("raksha.txt","r");
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
        case 1 : if(r==max-1)
                {
                        printf("priority  Queue is Full\n");

                }
                else
                {
                       fscanf(fp3,"%d", &Q1.data);
                       printf("ENTER THE PRIORITY\n");
                       scanf("%d",&Q1.pri);
                        Insert(Q1);
                        fprintf(fp4,"INSERTED ELEMENT %d %d \n",Q1.data,Q1.pri);
                 fprintf(fp6,"INSERT\n");
                }
                break;

        case 2 : delete();
                 fprintf(fp6,"DELETE\n");
                 break;

        case 3 : if(f==-1&&r==-1)
                   {
                       printf("Priority Queue is empty\n");
                   }
                else
                    display();
                    break;
        case 4 : exit(0);
        default : printf("Invalid Choice\n");
    }
    }
}
void Insert(struct random Q1)
{
    if(f==-1&&r==-1)
    {
        f++;
        r++;
        Q[r]=Q1;

    }
     else if (r == max - 1)
    {
        printf("Priority Queue is Full\n");
    }
     else {
        int i;
        for (i = r; i >= f; i--)
            {
            if (Q1.pri > Q[i].pri)
            {
                Q[i + 1] = Q[i];
            }
        else
            {
                break;
            }
        }
        Q[i + 1] = Q1;
        r++;
    }
}

void delete()
{
    if(f==-1&&r==-1)
    {
        printf(" Priority Queue is empty\n");

    }

    else
    {
        if(f==r)
        {
            printf("random checked = %d  %d \n",Q[f].data,Q[f].pri);
            fprintf(fp4,"DELETED ELEMENT %d %d \n",Q[f].data,Q[f].pri);
            f=-1;
            r=-1;
        }
        else
        {
             printf("random checked = %d  %d \n",Q[f].data,Q[f].pri);
             fprintf(fp4,"DELETED ELEMENT %d %d \n",Q[f].data,Q[f].pri);
             f++;

        }
    }
}

void display()
{
    int i;
    for(i=f;i<=r;i++)
    {
        printf("%d %d \n",Q[i].data,Q[i].pri);
        fprintf(fp4,"%d %d\n",Q[i].data,Q[i].pri);
    }



}

