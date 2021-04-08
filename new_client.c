#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>

void new_client(){
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char current_time[64];
  FILE* client_balance_file;
  FILE* client_history_file;
  FILE* client_personal_file;
  char client_first_name[30];
  char client_first_name_real[30];
  char client_last_inital[30];
  char client_balance_file_name[30];
  char client_history_file_name[30];
  char client_personal_file_name[30];
  int client_phone_number;
  char client_email_address[30];
  int client_age;
  int repeat_script = 1;
  int x;
  char client_select[10];
  int client_select_num = 1;
  
  /* Gather information about client and store in respective variables. */
  while (repeat_script == 1){
    while (client_select_num == 1) {
      client_select_num = 0;
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("Please answer the following questions regaurding the new client.\n");
      printf("Client first name: ");
      scanf("%s", client_first_name);
      strcpy(client_first_name_real, client_first_name);
      printf("Client last initial: ");
      scanf("%s", client_last_inital);
      printf("Client phone number: ");
      scanf("%d", &client_phone_number);
      printf("Client email address: ");
      scanf("%s", client_email_address);
      printf("Client age: ");
      scanf("%d", &client_age);

      /* Get correct file names to be generated for the client */
      strcat(strcat(client_first_name, "_"),client_last_inital);
      x = strlen(client_first_name);
      for (;x>=0; x--){
        client_first_name[x] = tolower(client_first_name[x]);
      }
      strcpy(client_balance_file_name, client_first_name);
      strcpy(client_history_file_name, client_first_name);
      strcpy(client_personal_file_name, client_first_name);
      strcat(client_balance_file_name, "_balance.txt");
      strcat(client_history_file_name, "_history.txt");
      strcat(client_personal_file_name, "_info.txt");

      /* Check if a balance file already exists under this name to see if the client already has an account. */
      client_balance_file = fopen(client_balance_file_name, "r");
      if (client_balance_file != NULL){
        fclose(client_balance_file);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("Error. Client with this name already exists.\n");
        printf("1. Input different client information\n");
        printf("2. Return to main menu\n");
        printf("Please select from the above options: ");
        scanf("%s", client_select);
        client_select_num = atoi(client_select);
        while ((client_select_num < 1) || (client_select_num > 2)){
          printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
          printf("Invalid input. Please try again.\n");
          printf("1. Input different client information\n");
          printf("2. Return to main menu\n");
          printf("Please select from the above options: ");
          scanf("%s", client_select);
          client_select_num = atoi(client_select);
        }
        if (client_select_num == 2){
          return;
        }
        client_select_num = 1;
      }
    }
    /* Create files for the new client */
    /* Client balance file. Initialize balance to 0.00 */
    client_balance_file = fopen(client_balance_file_name, "w");
    fprintf(client_balance_file, "%.2f", 0.00);
    fclose(client_balance_file);

    /* Client transaction history file. Initalize with current date and balance of 0. */
    client_history_file = fopen(client_history_file_name, "w");
    /* Get the current date and time in string format */
    /* Method to format time found on stack exchange */
    assert(strftime(current_time, sizeof(current_time), "%c", tm));
    fprintf(client_history_file, "%s | Transaction Amount: $0.00 | Balance: $0.00\n", current_time);
    fclose(client_history_file);

    /* Client personal info file. */
    client_personal_file = fopen(client_personal_file_name, "w");
    fprintf(client_personal_file, "%s\n", client_first_name_real);
    fprintf(client_personal_file, "%s\n", client_last_inital);
    fprintf(client_personal_file, "%d\n", client_age);
    fprintf(client_personal_file, "%d\n", client_phone_number);
    fprintf(client_personal_file, "%s\n", client_email_address);
    fclose(client_personal_file);

    /* Alert user that client account has successfully been created. */
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("%s %s's account has successfully been created!\n", client_first_name_real, client_last_inital);
    printf("1. Add another new client\n");
    printf("2. Return to main menu\n");
    printf("Please select from the above options: ");
    scanf("%s", client_select);
    client_select_num = atoi(client_select);
    while ((client_select_num < 1) || (client_select_num > 2)){
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("Invalid input. Please try again.\n");
      printf("1. Add another new client\n");
      printf("2. Return to main menu\n");
      printf("Please select from the above options: ");
      scanf("%s", client_select);
      client_select_num = atoi(client_select);
    }
    if (client_select_num == 2){
      return;
    }
    repeat_script = 1;
  }
}
