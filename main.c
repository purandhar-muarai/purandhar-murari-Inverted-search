/*
    Name : Purandhar Murarisetty
    Project : Inverted Search
 */




#include "inverted_search.h"

int main(int argc , char *argv[])
{
    system("clear");
    Wlist *head[27];
    for(int i = 0; i<27; i++)
    {
        head[i] = NULL;
    }

    //validate the CLA 
    if(argc <= 1)
    {
        printf("\e[31m Enter the valid no. of arguments\e[0m\n");
        printf("\e[91m./Slist.exe  file1.txt  file2.txt....\e[0m\n");
        return 0;
    }
    //create file linked list 

    //declare head pointer

    Flist *f_head = NULL;

    //validate the file

    file_validation_n_file_list(&f_head , argv);

    if(f_head == NULL)
    {
        printf("\e[31m No files are available in the file Linked list\n");
        printf("Hence the process terminated\e[0m\n");
        return 1;
    }
    /*
       ......TODO..........
       Select your choice among following options:
       1. Create DATABASE
       2. Display Database
       3. Update DATABASE
       4. Search
       5. Save Database
       Enter your choice
     */
    char op = 'y';
    while(op == 'y' || op == 'Y')
    {
        int choice;
        printf("\e[34m Select your choice among following options: \e[0m\n");
        printf("1. Create DATABASE\n2. Display Database\n3. Update DATABASE\n4. Search\n5. Save Database\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        char word[WORD_SIZE];
        switch(choice)
        {
            case 1:
                //create database 
                create_database(f_head , head);
                printf("\e[32m SUCCESSFUL : create database for file %s[\e[0m\n", f_head -> file_name);
                break;
            case 2:
                //display database 
                display_database(head);
                break;
            case 3:  
                //update database
                update_database(head , &f_head);
                break;
            case 4:
                //search 
                // char word[WORD_SIZE];
                printf("Enter the word : ");
                scanf("%s" , word);
                search(head[tolower(word[0] % 97)],word);
                break;
            case 5:
                //save database 
                save_database(head);
                break;
            default :
                printf("\e[91m Enter valid input\e[0m\n");
                break;
        }
        printf("Do you want to continue(y/n) : ");
        getchar();
        scanf(" %c",&op);
    }
}























