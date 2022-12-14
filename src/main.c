// ~~~~~ DOUBLE LINK LIBRARY ~~~~~
// Implemented as a STACK (i.e. remove function will pop off most recent item)

#include <dbl_lnk.h>
// #include "../include/dbl_lnk.h" /* Keep this here because valgrind 3.18 does not seem to work nicely with .d files */

int main(void)
{
    // Start Screen
    printf("\n\t\t~~~~ CREATE YOUR OWN LIST ~~~~~\n\n");
    printf("Type 'quit' anytime to QUIT or type 'remove' anytime to REMOVE last item.\n\n");

    // User input: Name List
    char *list_name = inf_buffer("Name of list: ");
    if (strcasecmp(list_name, "quit") == 0) {free_null(&list_name); return 0;}

    // Prepend "csv/" and append ".csv" to list name, to create file path
    char file_path[(strlen(list_name) + strlen("txt/.txt") + 1) * sizeof(char)];
    sprintf(file_path, "./txt/%s.txt", list_name);

    // Declare Main Pointers
    node *head = NULL;
    node *last = NULL;

    //  _____ BUILD DOUBLE LINKED LIST _____

    // Declare string pointers
    char *s = NULL, *choice = NULL;

    // Loop until user quits
    uint64_t node_count = 0;
    while (true)
    {
        bool append_item = false, quit_choice = false;

        // User Input
        s = inf_buffer("Enter item: ");

        // -- QUIT --
        if (strcasecmp(s, "quit") == 0) {
               // -- QUIT --
            while (true) {
                choice = inf_buffer("\n\t ~ QUIT ~\nDo you want to QUIT? (yes/no): ");

                if (strcasecmp(choice, "yes") == 0) {
                    quit_choice = true;
                    break;
                }
                else if (strcasecmp(choice, "no") == 0) {

                    printf("Do you want to ADD '%s' as an item to the list? (yes/no): ", s);
                    free(choice);
                    choice = inf_buffer("");

                    if (strcasecmp(choice, "yes") == 0) {
                        append_item = true;
                        free_null(&choice);
                        break;
                    }
                    else if (strcasecmp(choice, "no") == 0) {
                        free_null(&s);
                        free_null(&choice);
                        break;
                    }
                }
                printf("\n\n*** Enter 'yes' or 'no' only. ***\n");
                free_null(&choice);
            }
        }
        else if (strcasecmp(s, "remove") == 0) {
            // -- REMOVE --
            while (true) {
                choice = inf_buffer("\n\t ~ REMOVE ~\nDo you want to REMOVE the last item? (yes/no): ");

                if (strcasecmp(choice, "yes") == 0) {

                    // Attempt to Remove last item from Double Linked List
                    char *popped = list_remove_item(&head, &last, true);

                    if (popped == NULL) {
                        printf("\n\n* Nothing to remove. List empty.\n");
                    }
                    else {
                        csv_rewrite(file_path, head);
                        printf("\n* You just REMOVED: '%s'\n", popped);
                        node_count--;
                    }
                    free_null(&s);
                    free_null(&choice);
                    if (popped != NULL) {free_null(&popped);}
                    break;
                }
                else if (strcasecmp(choice, "no") == 0) {
                    free(choice);
                    printf("Do you want to ADD '%s' as an item to the list? (yes/no): ", s);

                    choice = inf_buffer("");
                    if (strcasecmp(choice, "yes") == 0) {
                        append_item = true;
                        free_null(&choice);
                        break;
                    }
                    else if (strcasecmp(choice, "no") == 0) {
                        free_null(&s);
                        free_null(&choice);
                        break;
                    }
                }
                printf("\n\n*** Enter 'yes' or 'no' only. ***\n");
                free_null(&choice);
            }
        }
        else append_item = true;

        if (quit_choice) break;

        if (append_item == true) {
            // Append Item to List
            build_dblink_list(&s, &head, &last);
            append_csv(file_path, last->s);
            node_count++;
        }

        // Print List
        printf("\n");
        print_list_and_listname(head, list_name);

        // I do not need to free(s) because the buffer that s points to has been taken over by node->s
    }


    //      _____ END _____

    // Print
    printf("\nLIST: '%s'\n----\n", list_name);
    print_list(head);

    // End Screen
    printf("\n\t\t~~ GOODBYE ~~\n");
    if (node_count > 0) {
        printf("\n** A file named '%s.txt' was made for you. **\n", list_name);
        printf("\nFile path: '%s'\n\n", file_path);
    }

    // Free Pointers
    free_null(&list_name);
    free_null(&s);
    free_null(&choice);
    free_list(head);
    head = last = NULL;

    return EXIT_SUCCESS;
}


