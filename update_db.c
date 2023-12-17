#include "inverted_search.h"

void update_database( Wlist *head[], Flist **f_head)
{
    // prompt the user

    char file_name[FNAME_SIZE];
    printf("Enter the file name : ");
    scanf("%s" , file_name);

    //validate 
    //....TODO.....
    int empty;
    empty = isFileEmpty(file_name);

    if(empty == FILE_NOTAVAILABLE)
    {
        printf("\e[31mFile : %s is not available\n" , file_name);
        printf("Hence we are not adding that file into file linked list\e[0m\n");
    }
    else if(empty == FILE_EMPTY)
    {
        printf("\e[31mFile : %s is empty\n" , file_name);
        printf("Hence we are not adding that file into file linked list\e[0m\n");
    }
    else
    {
        int ret_val = to_create_list_of_files(f_head,file_name);

        if(ret_val == SUCCESS)
        {
            printf("\e[32mSuccessfull: inserting file name : %s into file linked list\e[0m\n" , file_name);
        }
        else if(ret_val == REPEATATION)
        {
            printf("\e[34mThis file name : %s is repeated. Do not add that into file linked list\e[0m\n" , file_name);
        }
        else
        {
            printf("Failure\n");
        }
    }

    while(*f_head)
    {
        if(strcmp((*f_head)->file_name , file_name) != 0)
        {
            create_database(*f_head,head);
            break;
        }

        *f_head = (*f_head)->link;

    }
}


