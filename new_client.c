#include <stdio.h>
#include <string.h>

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
  
  /* Gather information about client and store in respective variables. */
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
  printf("%s", client_balance_file_name);
  printf("%s", client_history_file_name);
  printf("%s", client_personal_file_name);
 
}
