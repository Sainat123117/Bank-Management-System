#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct transaction
{
    unsigned int txn_id;
    char type[16];
    long amount;
    long balance_after;
    struct transaction *next;

} transaction_t;

typedef struct account
{
    int accno;
    char name[50];
    float balance;
    char contact[10];

    transaction_t *txn_head;   

    struct account *next;

} account_t;

extern account_t *head;     

int genarete_accno();
void createacc();







