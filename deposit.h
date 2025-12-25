//deposit.h
account_t* find_account(int accno);
void add_transaction(account_t *acc, const char *type, long amount);
void deposit();


