#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node * head,* temp,* temp1,*temp2,* newnode;
struct node*Insert_node_beg(struct node * newnode);
struct node *Insert_node_end(struct node * newnode);
struct node * Delete_node_beg(struct node * head);
struct node * Delete_node_end(struct node * head);
void display(struct node * head);
int count_nodes(struct node * head);
struct node *Insert_node(struct node *head,int * pos);
void search_node(struct node *head,int * key);
struct node *delete_node(struct node * head,int * pos);
void sort(struct node * head);
int main()
{
    int ch,c,pos,p,key;

    head=NULL;
    while(1)
    {


    printf("1.Insert a node at beginning\n");
    printf("2.Insert a node at end\n");
    printf("3.Delete a nod from beginning\n");
    printf("4.Delete a node from end\n");
    printf("5.Display the nodes of linked list\n");
    printf("6.count the number of nodes\n");
    printf("7.search for a given node\n");
    printf("8.Insert a node at specified position\n");
    printf("9.Delete a node from specific location\n");
    printf("11.exit\n");
    printf("10.Sort of an array");


        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:newnode=(struct node *)malloc(sizeof(struct node));
                    printf("Enter the data\n");
                    scanf("%d",&newnode->data);
                    head=Insert_node_beg(newnode);
                    break;
            case 2:newnode=(struct node *)malloc(sizeof(struct node));
                    printf("Enter the data\n");
                    scanf("%d",&newnode->data);
                    head=Insert_node_end(newnode);
                    break;
            case 3:head=Delete_node_beg(head);
                    break;
            case 4:head=Delete_node_end(head);
                    break;
            case 5:display(head);
                    break;
            case 6:if(head==NULL)
                  {
                       printf("Doubly linked list is empty\n");
                  }
                  else
                  {
                      c=count_nodes(head);
            printf("Number of nodes =%d",c);
                  }

                   break;
            case 7:
                if(head==NULL)
                  {
                       printf("Doubly linked list is empty\n");
                  }
                    else
                    {
                         printf("enter the key\n");
                   scanf("%d",&key);
                   search_node(head,key);
                    }

                   break;
            case 8:printf("Enter the position\n");
                   scanf("%d",&pos);
                   head=Insert_node(head,pos);
                   break;
            case 9:
                if(head==NULL)
                  {
                       printf("Circular linked list is empty\n");
                  }
                    else
                    {printf("Enter the position\n");
                   scanf("%d",&pos);
                   head=delete_node(head,pos);
                    }
                   break;
            case 10:sort(head);
                    break;
            case 11:exit(0);
            default:printf("INvalid choice");
        }
    }
}
struct node*Insert_node_beg(struct node * newnode)
{
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;

    }
    else
    {
       temp=head;
       while(temp->next!=head)
       {
           temp=temp->next;

       }
       newnode->next=head;
       head=newnode;
       temp->next=head;
    }
    return(head);
}
void display(struct node * head)
{
    if(head==NULL)
    {
        printf("circular linked list is empty\n");
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {

            printf("%d->",temp->data);
            temp=temp->next;

        }
         printf("%d->",temp->data);

    }
}
struct node *Insert_node_end(struct node * newnode)
{
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
    return(head);
}
struct node * Delete_node_beg(struct node * head)
{
    if(head==NULL)
    {
        printf("circular linked list is empty\n");

    }
    else if(head->next==head)
    {
        printf("NODE DELETED=%d\n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp1=head;
        head=head->next;
        printf("NODE DELETED=%d\n",temp1->data);
        free(temp1);
        temp->next=head;

    }
    return(head);
}
struct node * Delete_node_end(struct node * head)
{
    if(head==NULL)
    {
        printf("Singly linked list is empty\n");

    }
    else if(head->next==head)
    {
         printf("NODE DELETED=%d\n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp1=temp;
            temp=temp->next;
        }
         printf("NODE DELETED=%d\n",temp->data);
         free(temp);
         temp1->next=head;

    }
    return(head);
}
int count_nodes(struct node * head)
{
    int count=0;

        temp=head;
        while(temp->next!=head)
        {
            count++;
            temp=temp->next;
        }
        count++;
        return(count);

}
struct node *Insert_node(struct node *head,int * pos)
{
    if(pos<1||pos>count_nodes(head))
    {
        printf("INVALID POSITION\n");

    }
   else if(pos==1)
                    {
                        newnode=(struct node *)malloc(sizeof(struct node));
                    printf("Enter the data\n");
                    scanf("%d",&newnode->data);
                    head=Insert_node_beg(newnode);
                    }
    else
    {
        newnode=(struct node *)malloc(sizeof(struct node));
                    printf("Enter the data\n");
                    scanf("%d",&newnode->data);


                        int p=1;
                        temp=head;
                        while(p!=pos)
                        {
                            temp1=temp;
                            temp=temp->next;
                            p++;
                        }
                        temp1->next=newnode;
                        newnode->next=temp;
                    }
                    return(head);

}
void search_node(struct node *head,int * key)
{

        temp=head;
        while(temp->next!=head)
        {
            if(key==temp->data)
            {
                printf("Searched key is=%d",temp->data);
                temp=temp->next;
            }

            else
                temp=temp->next;
        }

                    if(key==temp->data)
                    {
                        printf("Searched key is=%d",temp->data);
                    }


}
struct node *delete_node(struct node * head,int * pos)
{
    int n=count_nodes(head);
    if(pos<1||pos>count_nodes(head))
    {
        printf("INVALID POSITION\n");

    }
     else if(n==1)
    {
        head=Delete_node_beg(head);
    }

    else if(pos==1)
                    {

                            head=Delete_node_beg(head);
                    }

    else if(pos==count_nodes(head))
    {
        head=Delete_node_end(head);
    }
    else
    {




                        int p=1;
                        temp=head;
                        while(p!=pos)
                        {
                             temp1=temp;
                            temp=temp->next;
                            temp2=temp->next;

                            p++;
                        }
                        printf("NODE DELETED=%d\n",temp->data);
                       free(temp);
                       temp1->next=temp2;

                    }
                    return(head);

};
void sort(struct node * head)
{
   int n;

    int i,j;
    if(head==NULL)
    {
        printf("linked list is empty\n");

    }
    else
    {
        if(head->next==head)
        {
            return(head);
        }
        else
        {


            temp1=(struct node * )malloc(sizeof(struct node));
             n=count_nodes(head);
    for(i=0;i<n;i++)
    {
        temp =head;
        for(j=0;j<n-i;j++)
        {
            if(temp->data>temp->next->data)
            {
                temp1->data=temp->data;
                temp->data=temp->next->data;
                temp->next->data=temp1->data;

            }
            temp=temp->next;
        }
    }
    }
}
}

