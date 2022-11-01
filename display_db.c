#include"inverted_index.h"
/*
   function int display to display the words present in the files
   in order to display traverse to all the 27 nodes so if the main node is equal to null i.e in the 0th index there is no word present then traverse to the next node and check 
   if it is not null then take a temp variable with the particular index and traverse to if there is other words in the same index is present and print the values required to the user such as word file name file count word count etc
 */
int display_DB(main_node_t **main_head)
{
    int i=0;
    while(i < 27)
    {
	if(main_head[i] != NULL)
	{
	    main_node_t *temp = main_head[i];
	    while(temp != NULL)
	    {
		printf(BLUE"[%d]\t",i);
		printf(GREEN"[%s]\t",temp->word);
		printf(RED"[%d]\t",temp->f_count);
		sub_node_t *sub_temp = temp->sub_link;
		while(sub_temp != NULL)
		{
		    printf(WHITE"file(s): File "GREEN"%s\t",sub_temp->f_name);
		    printf(RED"\t%d "WHITE"time(s):\t",sub_temp->w_count);
		    sub_temp = sub_temp->link;
		}
		temp = temp->link;

		printf("\n");
	    }
	}
	i++;
    }
}
