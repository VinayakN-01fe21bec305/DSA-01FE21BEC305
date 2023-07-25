#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
FILE* fp3,*fp4,*fp5,*fp6,*fp7 ;
int main()
{
    struct node* head = NULL;
    int ch,data,n,i;
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



    while (1)
  {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch (ch)
         {
            case 1:  if(n!=0)
                       {
                fscanf(fp3,"%d", &data);
                printf("Push element %d into the stack",data);
                push(&head, data);
                fprintf(fp4,"PUSHED ELEMENT %d \n",data);
                n--;
                       }
                       else
                        printf("STACK IS FULL\n");

                break;

            case 2:

                if (isEmpty(head))
                    {
                    printf("Stack is empty\n");
                } else
                {
                  int ele= pop(&head);
                    printf("POPPED ELEMENTS ARE %d\n",ele);
                    fprintf(fp4,"POPPED ELEMENT %d \n",ele);
                }


                break;

            case 3:  display(head);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }

        printf("\n");
    }

    return 0;
}




struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
        {
        printf("linked list is empty\n");

       }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}


int isEmpty(struct node* head)
{
    return (head == NULL);
}

void push(struct node** head, int data)
{
    struct node* newnode = createnode(data);
    newnode->next = *head;
    *head = newnode;


}

int pop(struct node** head)
{
    if (isEmpty(*head))
        {
        printf("Stack is empty\n");

        }
    struct node* temp = *head;
    *head = (*head)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}


void display(struct node* head)
{
    if (isEmpty(head))
        {
        printf("Stack is empty\n");
        fprintf(fp4,"STACK IS EMPTY\n");
        return;
        }
    struct node* temp = head;
    printf("Stack elements ");
    while (temp != NULL)
     {
        printf("%d ", temp->data);
        fprintf(fp4,"%d\n",temp->data);
        temp = temp->next;
     }
    printf("\n");
}


