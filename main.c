#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "deposit_withdrawl.h"
#include "new_client.h"
#include "transaction_history.h"
#include "personal_info.h"

int main()
{
    FILE *check_username;
    FILE *username;
    FILE *check_password;
    FILE *password;
    
    int username_attempts=3;
    int password_attempts=3;
    int user_select_num;
    char user_select[10];
    char input_username[30];
    char real_username[30];
    char input_password[30];
    char real_password[30];
    
    /* Check if the username file exists. */
    check_username = fopen("username.txt", "r");
    if (check_username != NULL)
    {
        fclose(check_username);
    }
    /* If the username file does not exist, create the .txt file and input the
       standard username "admin". */
    if (check_username == NULL){
        username = fopen("username.txt", "w");
        fprintf(username, "%s", "admin");
        fclose(username);
    }
    /* Check if password file exists. */
    check_password = fopen("password.txt", "r");
    if (check_password != NULL)
    {
        fclose(check_password);
    }
    /* If the password file does not exist, create the .txt file  and input the
       standard password "password". */
    if (check_password == NULL){
        password = fopen("password.txt", "w");
        fprintf(password, "%s", "password");
        fclose(password);
    }
   
    /* Welcome user to the program and prompt for username */
    printf("Welcome to Embry Bank Employee Portal\n");
    printf("Please enter your user name: ");
    fgets(input_username, 30, stdin);
    /* Check if username matches data in file */
    username = fopen("username.txt", "r");
    fgets(real_username, 30, username);
    /* Give user 3 attempts to input correct username, if they fail 3 times, terminate the program. */
    if (strncmp(input_username, real_username, 5) != 0){
        for(;username_attempts>0;username_attempts--){
            if (username_attempts > 1){
                printf("Incorrect username, Please try again. %d attempts remaining: ", username_attempts);
            }
            else{
                printf("Incorrect username, Please try again. %d attempt remaining: ", username_attempts);
            }
            fgets(input_username, 30, stdin);
            if (strncmp(input_username, real_username, 5) == 0){
                break;
            }
        }
        if (strncmp(input_username, real_username, 5) != 0){
            exit(0);
        }
    }
    /* Prompt user for password and check if it matches data in file */
    printf("Please enter your password: ");
    fgets(input_password, 30, stdin);
    password = fopen("password.txt", "r");
    fgets(real_password, 30, password);
    /* Give user 3 attempts to input correct password, if they fail 3 times, terminate program. */
    if (strncmp(input_password, real_password, 8) != 0){
        for(;password_attempts>0;password_attempts--){
            if (password_attempts > 1){
                printf("Incorrect password, Please try again. %d attempts remaining: ", password_attempts);
            }
            else{
                printf("Incorrect password, Please try again. %d attempt remaining: ", password_attempts);
            }
            fgets(input_password, 30, stdin);
            if (strncmp(input_password, real_password, 8) == 0){
                break;
            }
        }
        if (strncmp(input_password, real_password, 8) != 0){
            exit(0);
        }
    }
    /* Continue running the rest of the program until the user inputs "5" when asked to make a selection at the home menu. */
    while (user_select_num != 5){
        /* Display home screen and prompt user to make a selection. */
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("Embry Bank Employee Portal\n");
        printf("1. Record Deposit or Withdrawl\n");
        printf("2. Add New Client\n");
        printf("3. View Client Transaction History\n");
        printf("4. View Client Personal Information\n");
        printf("5. Sign Out\n");
        printf("Please select one of the above options: ");
        (scanf("%s", user_select));
        user_select_num = atoi(user_select);
        /* If the user makes an invalid choice, reprompt user. */
        while ((user_select_num > 5) || (user_select_num < 1)){
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("Embry Bank Employee Portal\n");
            printf("1. Record Deposit or Withdrawl\n");
            printf("2. Add New Client\n");
            printf("3. View Client Transaction History\n");
            printf("4. View Client Personal Information\n");
            printf("5. Sign Out\n");
            printf("Invalid selection. Please try again: ");
            (scanf("%s", user_select));
            user_select_num = atoi(user_select);
        }
        /* Use a switch statement to pick which file to execute. */
        switch(user_select_num){
            /* Call the record deposit or withdrawl file. */
            case 1:
                printf("Case 1");
                deposit_withdrawl();
                break;

            /* Call the add new client file. */
            case 2:
                printf("Case 2");
                new_client();
                break;

            /* Call the view client transaction history file. */
            case 3:
                printf("Case 3");
                transaction_history();
                break;

            /* Call the view client personal information file. */
            case 4:
                printf("Case 4");
                personal_info();
                break;
        }
    }
    return 0;
}
