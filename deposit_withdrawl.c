#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
void deposit_withdrawl(){
  /* Initialize variables & declare structures */
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char current_time[64];
  char client_first_name[30];
  char client_last_inital[30];
  char repeat_function[10];
  char client_transaction_history_name[30];
  int x;
  int nsf;
  int repeat_function_num;
  float balance;
  float transaction_amount;
  FILE* client_file;
  FILE* client_history_file;
  
  /* This first while loop will be used to determine when to go back to the main menu */
  while (repeat_function_num != 1){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    /* Prompt user to enter their first name and last initial. */
    printf("Enter client first name: ");
    scanf("%s", client_first_name);
    printf("Enter client last inital: ");
    scanf("%s", client_last_inital);
    /* Use strcat to combine first name / last inital with and underscore in the middle */
    strcat(strcat(client_first_name, "_"),client_last_inital);
    /* Use the tolower function to get the string in lower case. */
    x = strlen(client_first_name);
    for (;x>=0; x--){
        client_first_name[x] = tolower(client_first_name[x]);
    }
    /* Copy string into transaction history variable, will be used to post transaction to transaction history later in file. */
    strcpy(client_transaction_history_name, client_first_name);
    strcat(client_transaction_history_name, "_history.txt");
    /* add _balance.txt to end of string to get correct name for the balance file for the client. */
    strcat(client_first_name, "_balance.txt");
    
    /* Try to open the balance file and if it cannot be found, prompt user to try again. */
    client_file = fopen(client_first_name, "r");
    while (client_file == NULL){
      printf("Unable to locate client, please try again.\n");
      printf("Enter Q to quit search\n");
      printf("Enter client first name: ");
      scanf("%s", client_first_name);
      if ((client_first_name[0] == 'q') || (client_first_name[0] == 'Q')){
          return;
      }
      printf("Enter client last inital: ");
      scanf("%s", client_last_inital);
      strcat(strcat(client_first_name, "_"),client_last_inital);
      x = strlen(client_first_name);
      for (;x>=0; x--){
        client_first_name[x] = tolower(client_first_name[x]);
      }
      strcpy(client_transaction_history_name, client_first_name);
      strcat(client_transaction_history_name, "_history.txt");
      strcat(client_first_name, "_balance.txt");
      
      client_file = fopen(client_first_name, "r");
    }
    
    /* Scan the contents of the file into the variable "balance", then close the file. */
    fscanf(client_file, "%f", &balance);
    fclose(client_file);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    
    /* Display the current balance and prompt user to enter the transaction amount. */
    printf("Client successfully located.\n");
    printf("Current Balance: $%.2f\n", balance);
    printf("Please enter transaction amount (Use - for withdrawl): ");
    scanf("%f", &transaction_amount);
    
    /* If the transaction amount will bring the balance below 0, notify user and request a new transaction amount. */
    if (balance + transaction_amount < 0){
        nsf = 1;
    }
    else{
        nsf = 0;
    }
    while (nsf == 1){
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("Client Does Not Have sufficent funds to make this withdrawl.\n");
      printf("Current Balance: $%.2f\n", balance);
      printf("Please enter transaction amount (Use - for withdrawl): ");
      scanf("%f", &transaction_amount);
      if (balance + transaction_amount < 0){
          nsf = 1;
      }
      else{
          nsf = 0;
      }
    }
    
    /* Update balance by adding it to the transaction amount. */
    balance = balance + transaction_amount;
    /* Print updated balance to screen and store in the balance file. */
    printf("Updated balance after transaction: $%.2f\n\n", balance);
    client_file = fopen(client_first_name, "w");
    fprintf(client_file, "%.2f", balance);
    fclose(client_file);
    
    /* Get the current date and time in string format */
    /* Method to format time found on stack exchange */
    assert(strftime(current_time, sizeof(current_time), "%c", tm));
    
    /* Open transaction history file and write the date, transaction amount, and balance into one line. */
    client_history_file = fopen(client_transaction_history_name, "a");
    fprintf(client_history_file, "%s | Transaction Amount: %.2f | Balance: %.2f\n", current_time, transaction_amount, balance);
    fclose(client_transaction_history_name);
     
    /* Prompt user to select to either record another transaction or return to the main menu. */
    printf("1. Return to main menu\n");
    printf("2. Record tranaction for another client\n");
    printf("Please select from one of the above options: ");
    scanf("%s", repeat_function);
    repeat_function_num = atoi(repeat_function);
    while ((repeat_function_num < 1) || (repeat_function_num > 2)){
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("Invalid input. Please try again.\n");
      printf("1. Return to main menu\n");
      printf("2. Record tranaction for another client\n");
      printf("Please select from one of the above options: ");
      scanf("%s", repeat_function);
      repeat_function_num = atoi(repeat_function);
    }
  }
}
