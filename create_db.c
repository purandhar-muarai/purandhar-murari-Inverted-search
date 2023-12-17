#include "inverted_search.h"

void create_database(Flist *f_head, Wlist *head[])
{
    //trverse through flist
    while(f_head)
    {
        read_datafile(f_head,head,f_head->file_name);
        f_head=f_head->link;
    }
}
//read contents of file 
Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
    //fname = filename;

    int flag = 1;
    //open the file
    FILE *fptr=fopen(filename , "r");

    //declare an array
    char word[WORD_SIZE];

    while(fscanf(fptr , "%s" , word) != EOF)
    {
        //index 
        int index = tolower(word[0])%97;

        //other that alphabets
        if(!(index >= 0 && index <= 25))
            index = 26;

        if(head[index] != NULL)
        {
            Wlist *temp = head[index];
            //compare the words at each node with new word
            while(temp)
            {
                if(!strcmp(temp->word , word))
                {
                    update_word_count(&temp , filename);
                    flag = 0;
                    break;
                }
                temp = temp -> link;
            }
        }
        if(flag == 1)

            //if words are not same
            insert_at_last(&head[index],word,filename);
    }
}
int update_word_count(Wlist **head , char *file_name)
{
    //...............TODO..........
    //check whether files names are same or different
    //if file names are same  , word_count incremented
    //if file names are diff , increment file_count , create Ltable node

    Wlist *temp = *head;

    if(!strcmp(temp->Tlink->file_name, file_name))
    {
        (temp->Tlink->word_count)++;
    }
    else
    {
        (temp -> file_count)++;
        //fname = file_name;
        update_link_table(&temp,file_name);
    }

}

