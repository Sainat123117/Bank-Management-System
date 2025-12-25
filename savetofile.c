#include <stdio.h>
#include <stdlib.h>
#include "createacc.h" 
#include "savetofile.h"

void save_to_file()
{
    FILE *fp = fopen("accounts.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file for writing!\n");
        return;
    }

    account_t *temp = head;

    while (temp != NULL)
    {
        fprintf(fp, "%d %s %s %.2f\n", temp->accno,temp->name,temp->contact,temp->balance);

        temp = temp->next;
    }
    printf("\n");

    fclose(fp);

    printf("Accounts saved to file successfully\n");
}

