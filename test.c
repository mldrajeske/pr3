#include "list.h"
#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node *next;
};

void printMenu()
{
   printf("\n");
   printf("1 ---> Insert at head\n");
   printf("2 ---> Insert at tail\n");
   printf("3 ---> Delete a node\n");
   printf("4 ---> Delete all\n");
   printf("5 ---> Display\n");
   printf("6 ---> Search for a node\n");
   printf("7 ---> Exit\n");
   printf("\n");
}

/* function that prints the list */
void printList(struct Node *node)       
{
   if(!node)
   {
       printf("Empty List\n");
       return;
   }
   while(node)
   {
       printf("%d ",node->data);
       node=node->next;
   }
   printf("\n");
}

/* function that adds a new node at head */
struct Node * insertAtHead(struct Node *head,int value) 
{
   struct Node *node=(struct Node *)malloc(sizeof(struct Node));
   node->data=value;
   node->next=head;
   return node;
}

/* function that adds a new node at tail */
struct Node * insertAtTail(struct Node *head,struct Node *tail,int value)
{
   struct Node *node=(struct Node *)malloc(sizeof(struct Node));
   node->data=value;
   if(tail==NULL)
       return node;
   tail->next=node;
   return node;
}

/* function that deletes a node */
struct Node * deleteNode(struct Node *head,int value)
{
   if(head==NULL)
       return NULL;
   struct Node *node=head,*prev=NULL;
   while(node)
   {
       if(node->data==value)
           break;
       prev=node;
       node=node->next;
   }
   if(prev==NULL)
       return head->next;
   prev->next=node->next;
   return head;
}

/* function that deletes the list */
struct Node * deleteList(struct Node *node)           
{
   if(!node)
       return NULL;
   deleteList(node->next);
   free(node);
   return NULL;
}

/* function that deletes the list */
void searchElement(struct Node *node,int value)       
{
   while(node)
   {
       if(node->data==value)
       {
           printf("%d is present in list\n",value);
           return;
       }
       node=node->next;
   }
   printf("%d is not present in list\n",value);
}

/* testing main method */
int main()
{
   struct Node *head=NULL,*tail=NULL;
   int choice,value;
   while(1)
   {
       printMenu();
       printf("Enter your option: ");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
               printf("Enter a value: ");
               scanf("%d",&value);
               head=insertAtHead(head,value);
               if(tail==NULL)
                   tail=head;
               break;
           case 2:
               printf("Enter a value: ");
               scanf("%d",&value);
               tail=insertAtTail(head,tail,value);
               if(head==NULL)
                   head=tail;
               break;
           case 3:
               printf("Enter a value: ");
               scanf("%d",&value);
               head=deleteNode(head,value);
               break;
           case 4:
               head=deleteList(head);
               break;
           case 5:
               printList(head);
               break;
           case 6:
               printf("Enter a value: ");
               scanf("%d",&value);
               searchElement(head,value);
               break;
           case 7:
               return 0;
           default:
               printf("Invalid option\n");
               break;
       }
   }
   return 0;
}
