#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i=1 , empty;

    while(argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);

        if(empty == FILE_NOTAVAILABLE)
        {
            printf("\e[31m File : %s is not available\n" , argv[i]);
            printf("Hence we are not adding that file into file linked list\e[0m\n");
            i++;
            continue;
        }
        else if(empty == FILE_EMPTY)
        {
            printf("\e[31m File : %s is empty\n" , argv[i]);
            printf("Hence we are not adding that file into file linked list\e[0m\n");
            i++;
            continue;
        }
        else
        {
            int ret_val = to_create_list_of_files(f_head,argv[i]);

            if(ret_val == SUCCESS)
            {
                printf("\e[32mSuccessfull: inserting file name : %s into file linked list\e[0m\n" , argv[i]);
                i++;
            }
            else if(ret_val == REPEATATION)
            {
                printf("\e[34mThis file name : %s is repeated. Do not add that into file linked list\e[0m\n" , argv[i]);
                i++;
            }
            else
            {
                printf("Failure\n");
                i++;
            }
        }
    }
}
//fun is used to check file available or not
// to check if it is having contents or  not
int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename , "r");
    if(fptr == NULL)
    {
        if(errno == ENOENT)
        {
            return FILE_NOTAVAILABLE;
        }
    }

    fseek(fptr , 0 , SEEK_END);
    if(ftell(fptr) == 0)
    {
        return FILE_EMPTY;
    }
}

int to_create_list_of_files(Flist **f_head, char *name)
{
    //.......TODO.......
    //....check duplicate files 
    //create list of files

    Flist *node = malloc(sizeof(Flist));
    if(node == NULL)
    {
        return FAILURE;
    }
    strcpy(node -> file_name,name);
    node -> link = NULL;
    if(*f_head == NULL)
    {
        *f_head = node;
        return SUCCESS;
    }
    Flist *temp = *f_head;
    int count = 0;
    while(temp -> link != NULL)
    {
        if(strcmp(temp -> file_name,name) == 0)
        {
            count = 1;
            break;
        }
        else
        {
            temp = temp -> link;
        }
    }
    if(count == 0)
    {
        temp -> link = node;   
        return SUCCESS;
    }
    else
    {
        return REPEATATION;
    }
}
