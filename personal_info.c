#include <stdio.h>
#include <string.h>
#include <ctype.h>
void personal_info(){
  FILE* client_file;
  int x;
  char client_first_name[30];
  char client_last_inital[30];
  
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("Personal Info Search:\n");
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
  strcat(client_first_name, "_info.txt");
  client_file = fopen(client_first_name, "r");
  
  while (client_file == NULL){
    printf("Unable to locate client, please try again.\n");
    printf("Enter Q to quit search\n");
    printf("Enter client first name: ");
    scanf("%s", client_first_name);
    printf("Enter client last inital: ");
    scanf("%s", client_last_inital);
    strcat(strcat(client_first_name, "_"),client_last_inital);
    /* Use the tolower function to get the string in lower case. */
    x = strlen(client_first_name);
    for (;x>=0; x--){
      client_first_name[x] = tolower(client_first_name[x]);
    }
    strcat(client_first_name, "_info.txt");
    client_file = fopen(client_first_name, "r");
  }
  
}
