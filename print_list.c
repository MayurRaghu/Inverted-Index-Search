#include "inverted_index.h"

int print_list(file_node_t *head)									
{
    if (head == NULL)												//checking if head is null or not
    {
	printf("INFO : List is empty\n");									//print list is empty
	return FAILURE;												//return failure
    }
  
    else
    {
	printf("head -> ");
	while (head)												//while head is true then print the list	
	{
	    printf("%s -> ", head ->f_name);	
	    head = head -> link;										//update head with head->link
	}

	printf("NULL\n");
    }
}
