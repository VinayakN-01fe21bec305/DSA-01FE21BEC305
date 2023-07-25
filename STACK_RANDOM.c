#include<stdio.h>
#define max 100
int stack[max];
int top;
FILE* fp3,*fp4,*fp5,*fp6 ;
int ch,ele,num,val;
void push(int ele);
void pop(int );
int is_empty(int);
int is_full(int);
int peek(int);

int main()
{

     fp3=fopen("raksha.txt","w");
     fp4=fopen("hello.txt","w");
     fp5=fopen("om.txt","w");
     fp6=fopen("vastrad.txt","w");
    top=-1;
    time_t t;
    int n,i;
    fprintf(fp4,"PUSHED ELEMENTS\n");
    fprintf(fp5,"POPED ELEMENTS\n");
    srand((unsigned) time(&t));
    printf("Enter the element\n");
        scanf("%d",&n);
        int p=n;
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
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.DISPLAY\n");
        printf("4--isempty?\n");
        printf("5--isfull?\n");
        printf("6--peek\n");
        printf("7--exit\n");



        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : if(top==max-1)
                   {

                       printf("STACK IS FULL\n");
                   }
                    else
                   {
                       if(n!=0)
                       {
                            fscanf(fp3,"%d",&ele);
                            push(ele);
                       fprintf(fp4,"%d\n",ele);
                       fprintf(fp6,"PUSH\n");
                       n--;
                       }
                       else
                       {
                           printf("ALL THE ELEMENTS HAS BEEN PUSHED\n");
                           fprintf(fp6,"ALL THE ELEMENTS HAS BEEN PUSHED\n");

                       }


                   }
                   break;
            case 2 :
                if(n!=0)
                       {

                     fscanf(fp3,"%d",&ele);
                      pop(ele);
                       n--;
                       }
                        else
                       {
                           printf(" THE ELEMENTS HAS BEEN POPED\n");
                           fprintf(fp6," THE ELEMENTS HAS BEEN POPED\n");

                       }




                   break;
            case 3 : display();
                    break;
           case 4: val=is_empty(top);

                          if(val==1)
                            printf("stack is emtpy\n");
                          else
                            printf("stack is not empty\n");
                          break;
        case 5: val=is_full(top);

                          if(val==1)
                            printf("stack is full\n");
                          else
                            printf("stack is not full\n");
                          break;
        case 6: val=peek(top);
                          if(val!=-999)
                          printf("the peek value=%d\n",val);
                          else
                            printf("stack is emtpy\n");
                          break;
        case 7: exit(0);break;
        default: printf("invalid choice\n");
                        break;


        }
    }
      fclose(fp4);
        fclose(fp5);
          fclose(fp6);

}


void push(int ele)
{
    top++;
    stack[top]=ele;
}



void pop(int ele)
{
    if(top==-1)
    {
        printf("STACK IS EMPTY\n");
    }
    else
    {

        fprintf(fp5,"%d\n",ele);
        top--;
        fprintf(fp6,"POP\n");
    }
}



void display()
{
    int i;
    if(top==-1)
    {
         printf("STACK IS EMPTY\n");
    }
    else
    {
        printf("********************************\n");
        for(i=top;i>=0;i--)
        {

            printf("%d\n",stack[i]);
        }
         printf("********************************\n");
    }
}
int is_empty(int top)
{
    if(top==-1)
        return(1);
    else
        return(0);
}

int is_full(int top)
{
    if(top==max-1)
        return(1);
    else
        return(0);
}

int peek(int top)
{
    if(top!=-1)
    return(stack[top]);
    else
        return(-999);
}

