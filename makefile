bank : bank.o savetofile.o createacc.o deposit.o load_accounts.o save_transactions.o withdraw.o transfer.o
	cc bank.o savetofile.o createacc.o deposit.o load_accounts.o  save_transactions.o  withdraw.o  transfer.o -o bank

bank.o : bank.c
	cc -c bank.c

savetofile.o : savetofile.c
	cc -c savetofile.c

createacc.o : createacc.c
	cc -c createacc.c

deposit.o : deposit.c
	cc -c deposit.c

load_accounts.o : load_accounts.c
	cc -c load_accounts.c

save_transactions.o : save_transactions.c
	cc -c save_transactions.c
withdraw.o : withdraw.c
	cc -c withdraw.c
transfer.o :transfer.c
	cc -c transfer.c

clean:
	rm -f *.o bank

