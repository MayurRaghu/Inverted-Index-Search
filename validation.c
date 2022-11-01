#include"inverted_index.h"
/*function validation and storing file names
 here you should take argument and and store it in a string and call the function to check if the file is valid or not
 after the file is valid then call the function to store the file in the list
 and run a loop for all the arguments passed in the command line*/
int validate_n_store_filenames(file_node_t **head, char *argv[])
{
    char f_name[100] = {'\0'};
    *head = NULL;
    int i = 1;
    int flag = 0;
    while(argv[i] != NULL)
    {
	strcpy(f_name,argv[i]);
	if(IsFileValid(f_name)==SUCCESS)
	{
	    if(store_filenames_to_list(f_name, head)== SUCCESS)
	    {
		printf(GREEN);
		printf("Successful: %s added to the list\n",f_name);
		flag = 1;
	    }
	  		
	}
	else
	{
	    printf("There are no valid files\nPlease enter valid files\n");
	}

	i++;
    }
    if(flag == 1)
    {
	return SUCCESS;
    }
    else
	return FAILURE;
}
/*function is the file valid
  open the file passed from read and validate
  if the file is not present then return not present
  this basically rules out all the possibility to check if the file is valid or not
 */
int IsFileValid(char *file_name)
{
    FILE *fptr_argv;
    if(fopen(file_name, "r") == NULL)
    {
	printf(RED"ERROR: %s not present\n",file_name);
	return NOT_PRESENT;
    }
    else
    {
	fptr_argv = fopen(file_name, "r");
	fseek(fptr_argv,0,SEEK_END);
	if(ftell(fptr_argv) == 0)
	{
	    printf(RED"ERROR: %s empty\n",file_name);
	    return FILE_EMPTY;
	}
    }
    fclose(fptr_argv);
    return SUCCESS;
}
/*
   this is used to store all the valid files in the list in order to carry out further operation
   it also checks if the file is repeating or not
 */
int store_filenames_to_list(char *f_name, file_node_t **head)
{
    file_node_t *new = malloc(sizeof(file_node_t));
    strcpy(new->f_name, f_name);
    new->link = NULL;
    file_node_t *temp = *head;
    if(*head == NULL)
    {
	*head = new;
	return SUCCESS;
    }
    while(temp != NULL)
    {
	if(strcmp(temp->f_name, new->f_name) == 0)
	{
	    printf(RED"ERROR: File %s already present\n", new->f_name);
	    return REPEATED;
	}
	if(temp->link == NULL)
	{
	    temp->link = new;
	    return SUCCESS;
	}
	temp = temp->link;
    }
    return SUCCESS;
}
