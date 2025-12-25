//deposit.c
#include<stdio.h>
#include "createacc.h"
#include "save_transactions.h"
#include "savetofile.h"

account_t* find_account(int accno)
{
    account_t *temp = head;

    while (temp != NULL)
    {
        if (temp->accno == accno)
            return temp;

        temp = temp->next;
    }

    return NULL;
}


void add_transaction(account_t *acc, const char *type, long amount)
{
    transaction_t *t = (transaction_t *)malloc(sizeof(transaction_t));

    t->txn_id = rand();
    strcpy(t->type, type);
    t->amount = amount;
   // t->balance_after = acc->balance;

    t->next = acc->txn_head;
    acc->txn_head = t;

    save_transaction_to_file(acc->accno, t);
}




void deposit()
{
    int accno;
    float amount; 


    account_t *t = head;
    printf("Listing accounts...\n");
    while (t != NULL)
    {
        printf("ACCNO=%d NAME=%s\n", t->accno, t->name);
        t = t->next;
    }

    printf("Enter account number: ");
    scanf("%d", &accno);

    account_t *acc = find_account(accno);

    if (acc == NULL)
    {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("Invalid amount!\n");
        return;
    }

    acc->balance += amount;
    add_transaction(acc, "DEPOSIT", amount);
    save_to_file();

    printf("Deposit successful!\n");
    printf("New balance: %.2f\n", acc->balance);
}




