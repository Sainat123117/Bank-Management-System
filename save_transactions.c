#include "createacc.h"
void save_transaction_to_file(int accno, transaction_t *t)
{
    FILE *fp = fopen("transactions.txt", "a");  
    if (!fp)
    {
        printf("Error: Could not open transactions.txt!\n");
        return;
    }

    fprintf(fp, "Account no:%d  transaction ID:%d  Type:%s Amount:%ld\n",
            accno,
            t->txn_id,
            t->type,
            t->amount);

    fclose(fp);
}

