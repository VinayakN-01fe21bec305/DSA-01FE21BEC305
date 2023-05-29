#include<stdio.h>

int main()
{
    int ar[200],r,c;
    printf("enter the row and column\n");
    scanf("%d %d",&r,&c);
    if(r!=c)
    {
        printf("as the row is not equal to column hence not symmetric\n");
        return 0;
    }
    int arr[r][c],s,u;
    printf("enter the elements in an array\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<r;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for( int i=0;i<r;i++)
    {
        for(int j=0;j<r;j++)
        {
            if(i!=j)
            {
                s++;
                if(arr[i][j]==arr[j][i])
                {
                    u++;
                }
            }
        }
    }
    if(s=u)
    {
        printf("the given matrix is symmetric \n");

    }
    else
        printf("the given matrix is unsymmetric\n");
}
