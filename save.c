#include "inverted_search.h"

void save_database( Wlist *head[])
{
    //prompt the user 

    char file_name[FNAME_SIZE];

    printf("Enter the filename : ");
    scanf("%s" , file_name);

    //open file 

    FILE *fptr = fopen(file_name , "w");

    for(int i = 0; i<27 ; i++)
    {
        if(head[i] != NULL)
        {
            write_databasefile(head[i] , fptr);
        }
    }
    printf("\e[32m Database saved\e[0m\n");
}
void write_databasefile(Wlist *head, FILE* databasefile)
{
    fprintf(databasefile, "#[%d]\nword is [%s] : file count is [%d] : ", tolower(head->word[0]) % 97, head->word, head->file_count);

    Ltable *temp = head->Tlink;

    while (temp) {
        fprintf(databasefile, "file is %s : word count is  %d\n", temp->file_name, temp->word_count);
        temp = temp->table_link;
    }

    fprintf(databasefile, "\n");
}

