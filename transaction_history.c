#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void transaction_history(){
  int repeat_script = 1;
  char client_first_name[30];
  char client_last_inital[30];
  int x;
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
  printf("%s", client_first_name);
  
}
