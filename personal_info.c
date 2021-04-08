#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void personal_info(){
  FILE* client_file;
  int x;
  char client_first_name[30];
  char client_last_inital[30];
  char first_name_from_file[30];
  char last_inital_from_file[30];
  int age_from_file;
  char number_from_file[30];
  char email_from_file[50];
  char quit_search_lower[20];
  char client_select[10];
  int client_select_num = 1;
  int repeat_script = 1;
  while (repeat_script == 1){
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
      quit_search_lower = tolower(client_first_name);
      if (quit_search_lower == 'q'){
        return;
      }
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
    fscanf(client_file, "%s\n%s\n%d\n%s\n%s", first_name_from_file, last_inital_from_file, &age_from_file, number_from_file, email_from_file);
    fclose(client_file);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Personal Information is displayed below.\n");
    printf("Client first name: %s\n", first_name_from_file);
    printf("Client last inital: %s\n", last_inital_from_file);
    printf("Client age: %d\n", age_from_file);
    printf("Client phone number: %s\n", number_from_file);
    printf("Client email: %s\n\n", email_from_file);
    printf("1. Look up another client\n");
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
