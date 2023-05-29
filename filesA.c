#include<stdio.h>
#include<string.h>

int main()
{
    int i,temp,a[20],n;
    FILE*fp;

    fp=fopen("mytext.txt","r");
    fscanf(fp,"%d",&n);

    for(i=0;i<n;i++)
    {
        fscanf(fp,"%d",&a[i]);

    }
    for(i=0;i<n;i++)
    {
        if(a[i]>a[i+1])
        {
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=a[i];
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    fclose(fp);

}
void replace(char a[10],int x,char str[100])
{
    int n;
    FILE*fp=fopen("text2.txt","w");
    while(n!=0)
    {
        str[x]=a[x];
        x++;
        n--;
    }
    for(int i=0;i<=a(i);i++)
    {
        fprintf(fp,"%c",str[i]);
    }

}
