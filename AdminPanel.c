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
	ADMIN PANEL*/
	printf("\tADMIN PANEL\n\tLOGIN\n\n");
	char username[10];// Here is username array for user entered
	char passwd[8];// Here is password array for user eneterd
	char fileUsername[10];// username from the file
	char filePasswd[8];// Passowrd from the file
	char fullName[50];//stored name from the file
	int found=0;
	int choice;
	FILE *adacc = fopen("Data/adminacc.txt", "r");
	printf("\033[7;34mUsername:\033[0m");
	scanf("%s", username);//take username from user
	printf("\033[7;34mPassword:\033[0m");
	scanf("%s", passwd);// input pw from user
	while (fscanf(adacc, "%s %s %s", fileUsername, filePasswd, fullName) != EOF) {//reads contents of file until it reachers End Of File marker
        if (strcmp(username, fileUsername) == 0 && strcmp(passwd, filePasswd) == 0) 
		{
        	found = 1;
            break;
        }
    }
	fclose(adacc);
	if (found) 
		{
        	printf("\033[1;32mLogin successful! Welcome, %s.\n\033[0m", fullName);//User has logged in successfully
        	printf("Please press any key to use your admin account.....");
        	getch();
        	start:
        	printf("\033[2J\033[H");//cleared screen again
        	printf("\033[7;36mLOGGED IN AS ADMIN\n");
        	printf("\033[1;33mFull Name : %s\n", fullName);
        	printf("Username  : %s\n", fileUsername);
        	printf("\033[7;35mEnter choice:\n1.Add new consumers\n2.Delete existing consumers\n3.Exit\n\033[0m");
        	scanf("%d", &choice);
        	if(choice == 1)
        	{
        		FILE *acc = fopen("Data/accounts.txt", "a");
        		char newuser[10];
        		char newpasswd[8];
        		char newname[50];
        		printf("Create the username of new user: ");
        		scanf("%s", newuser);
        		printf("Create a new password for new user: ");
        		scanf("%s", newpasswd);
        		printf("Enter the name of the new user: ");
        		scanf("%s", newname);
        		fprintf(acc, "%s %s %s 0.000000\n", newuser, newpasswd, newname);
        		fclose(acc);
        		printf("\033[1;32mNew user is successfully created!\n\033[0m");
        		printf("Press any key to return back to menu...");
        		getch();
        		goto start;
			}
			else if(choice == 2)
			{
    			char delUser[10];
    			printf("Enter username to delete: ");
    			scanf("%s", delUser);
				FILE *fin = fopen("Data/accounts.txt", "r");
    			FILE *temp = fopen("Data/tempaccounts.txt", "w");
				char u[10], p[8], name[50];
    			float b;
    			int deleted = 0;
				while (fscanf(fin, "%s %s %s %f", u, p, name, &b) == 4) {
        		if (strcmp(delUser, u) == 0) {
            	deleted = 1;
        		} else {
            	fprintf(temp, "%s %s %s %f\n", u, p, name, b);
        			}
    			}
				fclose(fin);
    			fclose(temp);
				remove("Data/accounts.txt");
    			rename("Data/tempaccounts.txt", "Data/accounts.txt");
				if(deleted)
        		printf("\033[1;32mUser '%s' deleted successfully.\n\033[0m", delUser);
    			else
        		printf("\033[1;31mUser '%s' not found.\n\033[0m", delUser);
        	}
			else if(choice == 3){
				return;
			}
			else
				printf("\033[1;31mInvalid choice!\033[0m");
			printf("Press any key to return to the main menu...");
			getch();
			goto start;
		}
	else
		printf("\033[1;31mInvalid user!\033[0m");
		getch();
}
        	
	
