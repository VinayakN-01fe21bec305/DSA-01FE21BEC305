#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    fp=fopen("transpos.txt","r");

    if(fp==NULL)
        printf("file not found\n");

    int ar[10][10];

    for(int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            fscanf(fp,"%d",&ar[i][j]);
        }
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
           fprintf(fp,"%d",&ar[j][i]);
        }
    }
}
