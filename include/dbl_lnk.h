#ifndef DBL_LNK_H
#define DBL_LNK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>
#include <time.h>
#include <ctype.h>

// Double Linked Node
typedef struct node
{
    char *s;
    struct node *prev;
    struct node *next;
}
node;

// Function Prototypes
void append_csv(char *file_name, char *s);
void csv_rewrite(char *file_path, node *head);
char *inf_buffer(char *prompt);
void build_dblink_list(char **s_ptr, node **head, node **last);
char *list_remove_item(node **head, node **last, bool pop_or_not);
void print_list(node *head);
void free_list(node *head);
void if_error(int16_t error_num);
void free_null(char **filename);
void fclose_null(FILE **file);
void underline(uint64_t n);
void print_list_and_listname(node *head, char *list_name);

#endif /* DBL_LNK_H */