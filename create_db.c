#include"inverted_index.h"
/*function to create a database is written here
 first go through all the files in the list and run a loop till the list reaches null
 Then copy the file name of the list to the variable and pass it to the function reading data file from the list
 after succesfully reading the data file traverse to the next node*/
int create_DB(file_node_t *file_head, main_node_t **main_head)
{
    char f_name[100];
    while(file_head != NULL)
    {
	strcpy(f_name, file_head->f_name);
	read_datafile(file_head, main_head, f_name);
	file_head = file_head->link;
    }
    return SUCCESS;
}
/*
   from function create database and update database the function read data file is called with arguments file head and main head and file name
   in this function first we need to open the file in read mode and read each word from the file and store it in a variable str using fscanf
   after reading each word we need to check each character for eg: suppose you have the letter Hi or hi present in the variable take the first character and subtract it by with respective if it is upper case then subtract it by 'A' if it is lower case then subtract it with lower case 'a' so that you'll get a value which lies between 0-25 and one more for special character and numbers which will be stored in the 26th node. In order to determine this we use builtin function isupper/ islower and store that value in that ind variable
   after storing it the index then declare new node with main and sub node with sub and init temp as main of index

   if the index which you want to insert suppose you have john in as the word and the first character is j which is in lower case so if you subtract with 'a' you'll get a value of 10 in integer format so if the 10th index in the main node is empty/null thencopy the word to the node -> word and init file count as 1 and the link also as null then you will call the function sub which will init the values of sub node
   and update the sub link value with sub node

   if there is already a node present in that partiacular value you should traverse to the end of the node and compare if the the word is already present in the list it is present then check if the file is matching or not if trtue then increment the word count but if its in the different file then increment the file count and create a new sub node with the new file and word count present in the different file
 */
void read_datafile(file_node_t *file_head, main_node_t **main_head, char *f_name)
{
    FILE *fptr;
    char str[100];
    int ind;
    int flag=0;
    int flag2=0;

    fptr = fopen(f_name, "r");
    while(fscanf(fptr, "%s", str))
    {
	if(feof(fptr))
	    break;
	if(isupper(str[0]))
	{
	    ind = str[0] - 'A';
	}
	else if(islower(str[0]))
	{
	    ind = str[0] - 'a';
	}
	else
	{
	    ind = 26;
	}
	main_node_t *new = malloc(sizeof(main_node_t));
	sub_node_t *sub_node = malloc(sizeof(sub_node_t));
	main_node_t *temp = main_head[ind];

	if(temp == NULL)
	{
	    strcpy(new->word,str);
	    new->f_count = 1;
	    new->link = NULL;
	    main_head[ind] = new;
	    sub(&sub_node, f_name);
	    new->sub_link = sub_node;
	}
	else
	{
	    while(temp != NULL && flag==0)
	    {
		if(strcmp(str, temp->word)==0)
		{
		    sub_node_t *sub_temp = temp->sub_link;
		    while(sub_temp != NULL)
		    {
			if(strcmp(sub_temp->f_name, f_name)==0)
			{
			    sub_temp->w_count++;
			    printf(GREEN"Successful: Creation of database for file %s\n",f_name);
			    flag=1;
			    break;
			}
			else if(sub_temp->link == NULL)
			{
			    sub(&sub_node,f_name);
			    temp->f_count++;
			    sub_temp->link = sub_node;
			    flag=1;
			    break;
			}
			sub_temp = sub_temp->link;
		    }
		}
		else if(temp->link == NULL)
		{
		    strcpy(new->word,str);
		    new->f_count = 1;
		    new->link = NULL;
		    temp->link = new;

		    sub(&sub_node, f_name);
		    new->sub_link =sub_node;
		    break;
		}
		temp=temp->link;
	    }
	    flag=0;
	}
    }
}
/*function sub for init sub node */
int sub(sub_node_t **sub_node, char *f_name)
{
    *sub_node = malloc(sizeof(sub_node_t));
    (*sub_node)->w_count = 1;
    strcpy((*sub_node)->f_name,f_name);
    (*sub_node)->link = NULL;
}
