#include"inverted_index.h"
/*
   function update database
   calling function is file is valid
   if true then store filenames to list function is called
   if it is also successful then read the data from the file for display purpose
 */
int update_DB(file_node_t **file_head, main_node_t **main_head, char *file)
{
    if(IsFileValid(file)==SUCCESS)
    {
	file_node_t *temp = *file_head;
	if(store_filenames_to_list(file, file_head)==SUCCESS)
	{
	    read_datafile(temp, main_head,file);
	    printf(GREEN"Successful: %s added to the list\n",file);
	    printf(GREEN"Successful: Creation for database for file %s\n",file);
	}
    }
}

