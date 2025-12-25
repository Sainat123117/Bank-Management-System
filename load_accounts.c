#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createacc.h"


void load_accounts()
{
    int accno;
    char name[50], contact[15];
    float balance;

    FILE *fp = fopen("accounts.txt", "r");
    if (!fp)
    {
        printf("No account file found. Starting fresh.\n");
        return;
    }

    while (fscanf(fp, "%d %s %s %f",
                  &accno, name, contact, &balance) ==4)  
    {
        account_t *acc = malloc(sizeof(account_t));

        acc->accno = accno;
        strcpy(acc->name, name);
        strcpy(acc->contact, contact);
        acc->balance = balance;
        acc->txn_head = NULL;

        acc->next = head;
        head = acc;
    }

    fclose(fp);
    

}


