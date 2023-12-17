#include "inverted_search.h"

void search( Wlist *head, char *word)
{
    //check empty or not

    if(head == NULL)
    {
	printf("\e[31mSearch is not possible , list is empty\e[0m\n");
	return ;
    }


    //traverse
    while(head)
    {
	//compare the search word with the available words in the list 

	if(!strcmp(head->word , word))
	{
	    printf("\e[34m Word \e[0m %s \e[34m is present in \e[0m%d file/s \n " , word, head->file_count);

	    Ltable *Thead = head->Tlink;
	    while(Thead)
	    {
		printf("\e[34mIn file : \e[0m%s   %d time\n " , Thead->file_name , Thead->word_count);
		Thead = Thead->table_link;
	    }
	    printf("\n");
	    return ;
	}
	head = head->link;
    }

    printf("\e[31mSearch word not found \e[0m\n");
}








