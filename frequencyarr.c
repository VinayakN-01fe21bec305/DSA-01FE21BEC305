#include<stdio.h>

int main()
{
  int arr[20],arr1[20];

  printf("Enter the array elements\n");
  FILE* fpr=fopen("hello.txt","r");
  for(int i=0;i<20;i++)
  {
      fscanf(fpr,"%d",&arr[i]);
  }
  int j=0,f=0;
for(int m=0;m<20;m++)
{
    if(arr[j]==999)
        continue;

  for(int i=j;i<20;i++)
  {
      if(arr[j]==arr[i+1])
      {
      arr[i+1]=999;
      arr1[i]=-1;
      }
  }
  for( int i=0;i<20 ;i++ )
  {
      if(arr1[i]==-1)
      {
          f++;
      }
  }
  printf("%d is occured %d times\n",arr[j],f+1);
  j++;
  f=0;
for( int i=0;i<20 ;i++ )
{
    arr1[i]=0;
}

}
 return 0;
}
