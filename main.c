#include"inverted_index.h"
int main(int argc, char *argv[])
{
    char op;
    /*check if the argument variable is greater than 1 if it is less than 1 then return error
      if it ie greater then init both head of main and file nodes as NULL
      then call the function validate and store filenames in order to store it into list
      if it returns success then the file has been added to the list
     */
    if(argc > 1)
    {
	file_node_t *file_head = NULL;
	main_node_t *main_head[27] = {NULL};
	if(validate_n_store_filenames(&file_head, argv) == SUCCESS)
	{
	    printf("SUcCESSFUL: File added to the list\n");
	}
	else
	    return 0;
	/*based on the choice given by the user giving the choice the following actions will be taken
	 */
	int choice;
	int flag = 0;
	int case_flag = 0;
	printf(BLUE);
	printf("1. Create Database\n2. Display Database\n3. Search Database\n4. Update Databse\n5. Save Database\n6. Exit\n");
	printf(RED"Enter your choice: ");
	do
	{
	    printf(WHITE);
	    scanf("%d",&choice);
	    switch(choice)
	    {
		case 1:
		    /*case 1 is for creating database
		      if it returns success then make flag as 1 for error handling so if you call the create database once again with the same file it will return an error*/
		    if(flag == 0 && create_DB(file_head, main_head) == SUCCESS)
		    {
			flag = 1;
		    }
		    else if(flag == 1)
		    {
			printf(RED"Files passed through commandline already added into the Database\n");
			flag = 0;
		    }
		    case_flag = 1;
		    break;
		case 2:
		    /*case 2 is for displaying the database*/
		    if(case_flag == 1)
			display_DB(main_head);
		    else
			printf(RED"ERROR: Database has not been created in order to display\n");
		    break;
		case 3:
		    /*case 3 is for searching the given word in the database if it is not found then return error
		      searching the keyword is by taking the keyword from the user and searching it throughout the database*/

		    if(case_flag == 1)
		    {
			char word[100];
			printf(CYAN"Enter the word to be searched in Database : "WHITE);
			scanf("%s",word);
			if(search_DB(main_head, word)!=SUCCESS)
			    printf(RED"Word %s is not found in the Database\n",word);
		    }
		    else
			printf(RED"ERROR: Database has not been created in order to search the element\n");
		    break;
		case 4:
		    /*for updating database with a new file which exists in the directory*/
		    char file[100];
		    if(case_flag == 1)
		    {
			printf(CYAN"Enter the filename "WHITE);
			scanf("%s",file);
			update_DB(&file_head, main_head, file);
		    }
		    else
			printf(RED"ERROR: Database has not been created in order to update\n");
		    break;
		case 5:
		    /*for creating the backup with a backup file*/
		    char backup[100];
		    if(case_flag == 1)
		    {
			printf(CYAN"Enter the backup file to be created : "WHITE);
			scanf("%s",backup);
			save_DB(main_head, backup);
		    }
		    else
			printf(RED"ERROR: Database has not been created in order to save\n");
		    break;
		case 6:
		    return 0;
		default:
		    printf("Invalid input\n");
		    break;
	    }
	    /*run a while loop until user exit the loop*/
	    printf(WHITE"Do you want to continue (y/n) ");
	    scanf("\n%c", &op);
	    if(op == 'y' || op == 'Y')
	    {
		printf(RED"Please enter your choice: ");
	    }

	}
	while (op == 'y' || op == 'Y');

    }
    /*for argument which is == 1*/
    else
    {
	printf(RED);
	printf("Error : Invalid no.of arguments\nUsage ./inverted_index <file.txt> <file1.txt> ...\n");
    }
}
