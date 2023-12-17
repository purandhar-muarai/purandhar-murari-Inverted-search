#include "inverted_search.h"

int insert_at_last(Wlist **head, data_t *data,char *filename)
{
    //create node 
    Wlist *new = malloc(sizeof(Wlist));
    if(new == NULL)
    {
        return FAILURE;
    }

    //update 
    new->file_count = 1;
    strcpy(new->word,data);
    new->Tlink = NULL;
    new->link = NULL;

    //call fun to update the link table

    update_link_table(&new,filename);

    //check list is empty or not
    if(*head == NULL)
    {
        *head=new;
        return SUCCESS;
    }

    //list not empty

    Wlist *temp = *head;
    //traverse through the list

    while(temp->link)
    {
        temp=temp->link;
    }
    temp->link = new;
    return SUCCESS;

}

int update_link_table(Wlist **head, char *fname)
{
    //create node

    Ltable *new = malloc(sizeof(Ltable));
    if(new==NULL)
    {
        return FAILURE;
    }

    new->word_count = 1;
    strcpy(new->file_name,fname);
    new->table_link = NULL;

    Wlist *temp = *head;
    if(temp -> Tlink == NULL)
    {
        (*head)->Tlink = new;
        return SUCCESS;
    }
    Ltable *temp1 = temp -> Tlink;
    while(temp1 -> table_link != NULL)
    {
        temp1 = temp1 -> table_link;
    }
    temp1 -> table_link = new;
    return SUCCESS;
}







































