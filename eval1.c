#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,k,mul=0;
    int a[3][5],b[5][1],r[3][1];
    printf("enter the matrix 1\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<5;j++)
        {
            //printf("enter the %d %d matrix element\n");
            scanf("%d\n",&a[i][j]);

        }
        printf("%d\t");


    }
    printf("enter the matrix 2\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<1;j++)
        {
           // printf("enter the %d %d matrix element\n");
            scanf("%d\n",&b[i][j]);

        }
        printf("%d\t");
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
        {
            for(k=0;k<5;k++)
            {
                mul+=a[i][k]*b[k][i];

            }
            r[i][j]=mul;
            mul=0;
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
        {
            printf("%d\n",r[i][j]);
        }
    }
}


