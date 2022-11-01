#include"inverted_index.h"
/*
   function search database declared
   init variable index and user passes the word to be searched in the file present in the database
   so in order to do that we have to check the index of the word 
   init the temp variable with main head of index
   then traverese and compare till you find the word
 */
int search_DB(main_node_t **main_head, char *word)
{
    int ind;
    if(islower(word[0]))
    {
	ind = word[0] - 'a';
    }
    else if(isupper(word[0]))
    {
	ind = word[0] - 'A';
    }
    else
	ind = 26;
    main_node_t *temp = main_head[ind];
    
    while(temp != NULL)
    {
	if(strcmp(temp->word, word)==0)
	{
	    printf(RED"Word "GREEN"%s "RED"found in database and it is present in "BLUE"%d "RED"file(s)\n",temp->word, temp->f_count);
	    sub_node_t *sub_temp = temp->sub_link;
	    while(sub_temp != NULL)
	    {
		printf(RED"In file "GREEN"%s "BLUE"%d "RED"times\n", sub_temp->f_name, sub_temp->w_count);
		sub_temp = sub_temp->link;
	    }
	    return SUCCESS;
	}
	temp = temp->link;
    }
    return FAILURE;
}
