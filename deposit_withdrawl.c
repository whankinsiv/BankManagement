#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void deposit_withdrawl(){
  char client_first_name[30];
  char client_last_inital[30];
  char repeat_function[10];
  int x;
  int nsf;
  int repeat_function_num;
  float balance;
  float transaction_amount;
  FILE* client_file;
  
  while (repeat_function_num != 1){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Enter client first name: ");
    scanf("%s", client_first_name);
    printf("Enter client last inital: ");
    scanf("%s", client_last_inital);
    strcat(strcat(client_first_name, "_"),strcat(client_last_inital,".txt"));
    x = strlen(client_first_name) - 3;
    for (;x>=0; x--){
        client_first_name[x] = tolower(client_first_name[x]);
    }
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
      strcat(strcat(client_first_name, "_"),strcat(client_last_inital,".txt"));
      x = strlen(client_first_name) - 3;
      for (;x>=0; x--){
        client_first_name[x] = tolower(client_first_name[x]);
      }
      client_file = fopen(client_first_name, "r");
    }
    fscanf(client_file, "%f", &balance);
    fclose(client_file);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Client successfully located.\n");
    printf("Current Balance: $%.2f\n", balance);
    printf("Please enter transaction amount (Use - for withdrawl): ");
    scanf("%f", &transaction_amount);
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
    balance = balance + transaction_amount;
    printf("Updated balance after transaction: $%.2f\n\n", balance);
    client_file = fopen(client_first_name, "w");
    fprintf(client_file, "%.2f", balance);
    printf("Please select from the following Options:\n");
    printf("1. Return to main menu\n");
    printf("2. Record tranaction for another client\n");
    scanf("%s", repeat_function);
    repeat_function_num = atoi(repeat_function);
    while ((repeat_function_num < 1) || (repeat_function_num > 2)){
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("Invalid input. Please try again.\n");
      printf("Please select from the following Options:\n");
      printf("1. Return to main menu\n");
      printf("2. Record tranaction for another client\n");
      scanf("%s", repeat_function);
      repeat_function_num = atoi(repeat_function);
    }
  }
}
