# dblink_create_list
More modular version of double_link_list_pystyle

    // Written in C
    
    // * Prints in style of Python list[]: ['item1', 'item2', ...]
    // * Appends list item by item to new csv file as you type them in

    // - Quit any time by typing "quit" or "q"
        // - Allows user to add the string "quit" or "q" as an item in the list with prompts that follow
    // - Remove last item (node) any time by typing "remove" or "r"
        // - Allows user to add the string "remove" or "r" as an item in the list with prompts that follow
        
    // - If any errors occur during null checks etc:
        // - Will append to error_log.csv:
            // - a positive non-zero error # in column A, an error message in column B, and the timestamp in column C before returning that number from main.
                // - If any errors while trying to append to error_log.csv, will return negative values. (All other error numbers will be positive)
                
        // List of error codes/error messages:
            Error code 1: "Failure while scanning command line for name of new list."
            Error code 2: "Failure while allocating memory for node."
            Error code 3: "Failure while allocating memory for string.
            Error code 4: "Failure while scanning from command line."
            Error code 5: "Failure while re-allocating memory for string."
            Error code 6: "Failure while appending last item in list to <filename.csv>"
            Error code 7: "Failure while writing list to <filename.csv>"
