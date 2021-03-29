#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void new_client(){
  FILE* client_balance_file;
  FILE* client_history_file;
  FILE* client_personal_file;
  char client_first_name[30];
  char client_last_inital[30];
  char client_balance_file_name[30];
  char client_history_file_name[30];
  char client_personal_file_name[30];
  int client_phone_number;
  char client_email_address[30];
  int client_age;
  int x;
  char client_select[10];
  int client_select_num = 1;
  
  /* Gather information about client and store in respective variables. */
  while (client_select_num == 1) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Please answer the following questions regaurding the new client.\n");
    printf("Client first name: ");
    scanf("%s", client_first_name);
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
 
}
