#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void delay() 
{
    volatile long long i;
    for (i = 0; i < 1000000000; i++) {
        // used this loop for loading bars used in this programming according to my C knowledge
    }
}
void main()
{
	volatile long long i;
	printf("\033[1;32m******\t*****\t**\t**\t*****\t******\t**\t**\t**\t** ©\n**  **\t*\t**\t**\t**   *\t**  **\t***\t**\t**    **\n******\t*****\t**********\t******\t******\t** *\t**\t******\n**  **\t    *\t**\t**\t**   *\t**  **\t**  *\t**\t**    **\n**  **\t*****\t**\t**\t*****\t**  **\t**    *\t**\t**\t**\n################################################**######**######**#######**\n###########################################################################\n\033[7;35mCreated by Muhammad Ashir Malik\n\n");//BANK LOGO
	printf("\033[1;36mPress any key to continue....\033[0m");
	getch();
	printf("\033[2J\033[H"); //Cleared screen
	printf("[");
	for (i = 0; i < 20; i++) //This is for loading bar
	{
        printf("#");
        fflush(stdout);
        delay();
    }
    printf("]\n");
    printf("\033[2J\033[H"); //Cleared screen
	/* BELOW IS THE MAIN 
	LOGIN PAGE*/
	printf("\tLOGIN\n\n");
	char username[10];// Here is username array for user entered
	char passwd[8];// Here is password array for user eneterd
	char fileUsername[10];// username from the file
	char filePasswd[8];// Passowrd from the file
	char fullName[50];//stored name from the file
	float balance; //User balance
	int found=0;// variable found is declared to see wether things match with data in txt file
	int choice;
	char msguser[10];
	char msg[3000];
	float money; //money to withdraw or deposit
	FILE *acc;// file pointer
	if((acc=fopen("Data/accounts.txt", "r"))== NULL){//checks if file exist
		printf("\033[1;31mERROR 404: FILE NOT FOUND\nContact support\n\033[0m");}
 	else{
		//here starts the real deal
		printf("\033[7;34mUsername:\033[0m");
		scanf("%s", username);//take username from user
		printf("\033[7;34mPassword:\033[0m");
		scanf("%s", passwd);// input pw from user
		 while (fscanf(acc, "%s %s %s %f", fileUsername, filePasswd, fullName, &balance) != EOF) {//reads contents of file until it reachers End Of File marker
        	if (strcmp(username, fileUsername) == 0 && strcmp(passwd, filePasswd) == 0) 
			{
            found = 1;
            break;
        	}
    	}
		fclose(acc);
		if (found) 
		{
        	printf("\033[1;32mLogin successful! Welcome, %s.\n\033[0m", fullName);//User has logged in successfully
        	printf("Please press any key to use your bank account now.....");
        	getch();
        	start:
        	printf("\033[2J\033[H");//cleared screen again
        	printf("\033[1;33mFull Name : %s\n", fullName);
        	printf("Username  : %s\n", fileUsername);
        	printf("Balance   : $%.2f\n\033[0m", balance);
        	printf("\033[7;35mEnter choice:\n1.Deposit\n2.Withdraw\n3.Exit\n\033[0m");
        	scanf("%d", &choice);
        	if(choice == 1)
        	{
    			printf("Enter money to deposit:");
    			scanf("%f", &money);
    			balance += money;
    			FILE *fin = fopen("Data/accounts.txt", "r");
    			FILE *temp = fopen("Data/tempaccounts.txt", "w");
    			char tempUsername[10], tempPasswd[8], tempFullName[50];
    			float tempBalance;
    			while(fscanf(fin, "%s %s %s %f", tempUsername, tempPasswd, tempFullName, &tempBalance) == 4) 
    			{
        			if(strcmp(username, tempUsername) == 0)
        			{
            			tempBalance = balance; // update balance for logged in user
        			}
        			fprintf(temp, "%s %s %s %f\n", tempUsername, tempPasswd, tempFullName, tempBalance);
    			}
    			fclose(fin);
    			fclose(temp);
    			remove("Data/accounts.txt");
    			rename("Data/tempaccounts.txt", "Data/accounts.txt");
    			printf("Deposit successful! New balance: $%.2f\n", balance);
    			printf("Press any key to return to menu...\n");
    			getch();
    			goto start;
    		}
    		else if(choice== 2)
    		{
			printf("Enter money to withdraw:");
        		scanf("%f", &money);
        		if(money>balance){
        			printf("Insufficient funds!\n");
				}
				else{
        		balance -= money;
        		FILE *fin = fopen("Data/accounts.txt", "r");
    			FILE *temp = fopen("Data/tempaccounts.txt", "w");
    			char tempUsername[10], tempPasswd[8], tempFullName[50];
				float tempBalance;
				while(fscanf(fin, "%s %s %s %f", tempUsername, tempPasswd, tempFullName, &tempBalance) == 4) 
				{
    				if(strcmp(username, tempUsername) == 0)
    				{
        				tempBalance = balance; // update balance for logged in user
    				}
    				fprintf(temp, "%s %s %s %f\n", tempUsername, tempPasswd, tempFullName, tempBalance);
				}
            	fclose(fin);
            	fclose(temp);
            	remove("Data/accounts.txt");
				rename("Data/tempaccounts.txt", "Data/accounts.txt");
    			printf("Withdrawl successful! New balance: $%.2f\n", balance);
    			printf("Press any key to return to menu...\n");
    			getch();
    			goto start;
    			}
    		}
    		else if(choice== 3)
    		return;
			else
			{
			printf("\nInvalid Choice!");
			}
		}
		else 
		{
        	printf("\033[1;31mIncorrect username or password.\n\033[0m");//Sorry ur acc details are invalid.
    	}
            getch();
	}
}
	
	
