#include "list.h"
#include<stdlib.h>
#include<stdio.h>
int main(int argc, char * argv[])
{
Node * head = NULL;
head = List_insert(head, 917);
head = List_insert(head, -504);
head = List_insert(head, 326);
List_print(head);
head = List_delete(head, -504);
List_print(head);
head = List_insert(head, 138);
head = List_insert(head, -64);
head = List_insert(head, 263);
List_print(head);

if(List_search(head, 138) != NULL)
{
printf("138 is in the list/n");
}
else
{
printf("138 is not in the list/n");
}

if(List_search(head, 987) != NULL)
{
printf("987 is in the list\n");
}
else
{
printf("987 is not in the list\n");
}

/* delete the first node */
head = List_delete(head, 263);
List_print(head);

/* delete the last node */
head = List_delete(head, 917);
List_print(head);

/* delete all nodes */
List_destroy(head);
return EXIT_SUCCESS;
}
