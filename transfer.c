#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createacc.h"
#include "deposit.h"          
#include "save_transactions.h" 
#include "savetofile.h"

void transfer_money()
{
    int from_accno, to_accno;
    float amount;


    account_t *t = head;
    printf("Listing accounts...\n");
    while (t != NULL)
    {
        printf("ACCNO=%d NAME=%s BAL=%.2f\n", t->accno, t->name, t->balance);
        t = t->next;
    }

    printf("Enter sender account number: ");
    scanf("%d", &from_accno);

    account_t *from = find_account(from_accno);
    if (!from)
    {
        printf("Sender account not found!\n");
        return;
    }

    printf("Enter receiver account number: ");
    scanf("%d", &to_accno);

    account_t *to = find_account(to_accno);
    if (!to)
    {
        printf("Receiver account not found!\n");
        return;
    }

    if (from_accno == to_accno)
    {
        printf("Cannot transfer to same account!\n");
        return;
    }

    printf("Enter amount to transfer: ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("Invalid amount!\n");
        return;
    }

    if (from->balance < amount)
    {
        printf("Insufficient balance in sender account!\n");
        return;
    }

    from->balance -= amount;

    transaction_t *t1 = malloc(sizeof(transaction_t));
    t1->txn_id = rand();
    strcpy(t1->type, "DEBIT");
    t1->amount = amount;
    t1->balance_after = from->balance;
    t1->next = from->txn_head;
    from->txn_head = t1;

    save_transaction_to_file(from->accno, t1);

    to->balance += amount;

    transaction_t *t2 = malloc(sizeof(transaction_t));
    t2->txn_id = rand();
    strcpy(t2->type, "CREDIT");
    t2->amount = amount;
    t2->balance_after = to->balance;
    t2->next = to->txn_head;
    to->txn_head = t2;

    save_transaction_to_file(to->accno, t2);
    save_to_file();

    printf("Transfer Successful!\n");
    printf("Deducted from %d → Remaining Balance: %.2f\n", from->accno, from->balance);
    printf("Added to %d → New Balance: %.2f\n", to->accno, to->balance);
}

