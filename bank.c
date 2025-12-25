#include<stdio.h>
#include<time.h>
#include "createacc.h"
#include "deposit.h"
#include "savetofile.h"
#include "load_accounts.h"
#include "withdraw.h"
#include "transfer.h"

int main()
{
	char choice;
	srand(time(NULL));
	load_accounts();
	while(1)
	{
		printf("1.create account 2.deposit 3.withdraw 4.Transfer 5.exit\n");
		printf("enter the choice\n");
		scanf(" %c",&choice);
		switch(choice)
		{
			case '1':createacc();
				 break;
		        case '2':deposit();
				 break;
		        case '3':withdraw();
				 break;
		        case '4':transfer_money();
				 break;
		        case '5':exit(0);
		}
         }
}

