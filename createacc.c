#include<stdio.h>
#include "createacc.h"
#include "savetofile.h"

account_t *head = NULL;

int genarete_accno()
{

    int num;
    num=rand()%9000000;
    return num;
}

void createacc()
{
    account_t *new_acc = malloc(sizeof(account_t));

    new_acc->accno = genarete_accno();

    printf("Enter account holder name:\n");
    scanf("%s", new_acc->name);

    do {
        printf("Enter mobile no : ");
        scanf("%s", new_acc->contact);

        if (strlen(new_acc->contact) != 10)
            printf("Invalid! Must be 10 digits.\n");

    } while (strlen(new_acc->contact) != 10);

    printf("Enter minimum balance:\n");
    scanf("%f", &new_acc->balance);

    new_acc->next = NULL;
    new_acc->txn_head = NULL;

    if (head == NULL)
        head = new_acc;
    else {
        account_t *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_acc;
    }

    save_to_file(); 

    printf("Account created successfully!\n");
    printf("Account Number: %d\n", new_acc->accno);
}




       


	




