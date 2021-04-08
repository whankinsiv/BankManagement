#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void transaction_history(){
  FILE* client_history_file;
  int repeat_script = 1;
  char client_first_name[30];
  char client_last_inital[30];
  char current_file_line[100];
  int x;
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("Enter client first name: ");
  scanf("%s", client_first_name);
  printf("Enter client last inital: ");
  scanf("%s", client_last_inital);
  strcat(strcat(client_first_name, "_"),client_last_inital);
  x = strlen(client_first_name);
  for (;x>=0; x--){
    client_first_name[x] = tolower(client_first_name[x]);
  }
  strcat(client_first_name, "_history.txt");
  client_history_file = fopen(client_first_name, "r");
  while (client_history_file == NULL){
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
      strcat(client_first_name, "_history.txt");
      
      client_history_file = fopen(client_first_name, "r");
  }
  while (fscanf(client_history_file, "%s" ,current_file_line) != EOF){
    printf("%s", current_file_line);
  }
  
}
