#ifndef INVERTED_INDEX_H
#define INVERTED_INDEX_H 

#include"colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stddef.h>

#define SUCCESS 0
#define FAILURE -1
#define NOELEMENT -2
#define EMPTYLIST -3
#define REPEATED -4
#define FILE_EMPTY -5
#define NOT_PRESENT -6

#define SIZE 26
#define BUFF_SIZE 255
#define NAMELENGTH 50

//inverted table

typedef struct sub_node
{
	char f_name[NAMELENGTH];
	int w_count;
	struct sub_node *link;
}sub_node_t;

typedef struct node
{
	char word[NAMELENGTH];
	struct node *link;
	sub_node_t *sub_link;
	int f_count;
}main_node_t;

typedef struct file_node
{
    char f_name[NAMELENGTH];
    struct file_node *link;
}file_node_t;

/* File validation */
int validate_n_store_filenames(file_node_t **head, char *argv[]);
int IsFileValid(char *file_name);
int store_filenames_to_list(char *f_name, file_node_t **head);

/*Create DB*/
int create_DB(file_node_t *file_head, main_node_t **main_head);
void read_datafile(file_node_t *file_head, main_node_t **main_head, char *f_name);

int sub(sub_node_t **sub_node, char *f_name);
int print_list(file_node_t *head);
/*Display*/
int display_DB(main_node_t **head);

/*search */
int search_DB(main_node_t **main_head, char *word);

/*Save*/
int save_DB(main_node_t **main_head, char *fname);

/*Update */
int update_DB(file_node_t **, main_node_t **, char *);


#endif
