#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createacc.h"
#include "deposit.h"   
#include "save_transactions.h" 
#include "savetofile.h"

void withdraw()
{
    int accno;
    float amount;

    account_t *t1 = head;
    printf("Listing accounts...\n");
    while (t1!= NULL)
    {
        printf("ACCNO=%d NAME=%s\n", t1->accno, t1->name);
        t1 = t1->next;
    }

    printf("Enter account number: ");
    scanf("%d", &accno);


    account_t *acc = find_account(accno);

    if (acc == NULL)
    {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    
    if (amount <= 0)
    {
        printf("Invalid amount!\n");
        return;
    }

    
    if (acc->balance < amount)
    {
        printf("Insufficient balance!\n");
        return;
    }

    
    acc->balance -= amount;

    
    transaction_t *t = (transaction_t *)malloc(sizeof(transaction_t));

    t->txn_id = rand();
    strcpy(t->type, "WITHDRAW");
    t->amount = amount;
    t->balance_after = acc->balance;

    
    t->next = acc->txn_head;
    acc->txn_head = t;

    
    save_transaction_to_file(acc->accno, t);
    save_to_file();

    printf("Withdrawal successful!\n");
    printf("Remaining Balance: %.2f\n", acc->balance);
}

