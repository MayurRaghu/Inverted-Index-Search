#include"inverted_index.h"
/*
   function save database
   take the file name from te user and store it in variable then open the file in write mode
   then run the main node up until 0-26 in order to store each character word from the file to another file
 */
int save_DB(main_node_t **main_head, char *fname)
{
    FILE *fptr_backup;
    if(strstr(fname,".")==NULL)
    {
	strcat(fname,".txt");
    }
    fptr_backup = fopen(fname, "w");
    int i = 0;
    while(i < 27)
    {
	if(main_head[i] != NULL)
	{
	    main_node_t *temp = main_head[i];
	    while(temp != NULL)
	    {
		fprintf(fptr_backup, "#%d;\n%s;%d;",i,temp->word,temp->f_count);
		sub_node_t *sub_temp = temp->sub_link;
		while(sub_temp != NULL)
		{
		    fprintf(fptr_backup, "%s;%d\n",sub_temp->f_name,sub_temp->w_count);
		    sub_temp = sub_temp->link;
		}
		temp = temp->link;
	    }
	}
	i++;
    }
    printf(GREEN"Successful : Database saved in %s file\n",fname);
    fclose(fptr_backup);
}
