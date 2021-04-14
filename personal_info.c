/******************************************************************************

File Name: personal_info.c
Purpose: To allow users to lookup client information in the CS125 Bank Program.
Created By: William Hankins

*******************************************************************************/
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
  /* Continue running function until the user types 1 when prompted to return to main menu. */
  while (repeat_script == 1){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    /* Get client's name and concatinate it with _info.txt to get the name of their personal info file. */
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
    /* Open the personal info text file with read access. */
    client_file = fopen(client_first_name, "r");
    /* If the client_file does not exist, prompt the user to try again with a different name. */
    while (client_file == NULL){
      printf("Unable to locate client, please try again.\n");
      printf("Enter Q to quit search\n");
      printf("Enter client first name: ");
      scanf("%s", client_first_name);
      x = strlen(client_first_name);
      for (;x>=0; x--){
        client_first_name[x] = tolower(client_first_name[x]);
      }
      strcpy(quit_search_lower, client_first_name);
      /* If the user types q when asked for the first name, exit the function and return to the main menu. */
      if (strcmp(quit_search_lower, "q") == 0){
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
    /* Once the client's file has been successfully opened with read access, read the information from the file to the screen. */
    fscanf(client_file, "%s\n%s\n%d\n%s\n%s", first_name_from_file, last_inital_from_file, &age_from_file, number_from_file, email_from_file);
    fclose(client_file);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Personal Information is displayed below.\n");
    printf("Client first name: %s\n", first_name_from_file);
    printf("Client last inital: %s\n", last_inital_from_file);
    printf("Client age: %d\n", age_from_file);
    printf("Client phone number: %s\n", number_from_file);
    printf("Client email: %s\n\n", email_from_file);
    /* Ask the user if they would like to look up another client or return to the main menu. */
    printf("1. Look up another client\n");
    printf("2. Return to main menu\n");
    printf("Please select from the above options: ");
    scanf("%s", client_select);
    client_select_num = atoi(client_select);
      /* If the user does not type a valid response, reprompt them to make a valid selection. */
      while ((client_select_num < 1) || (client_select_num > 2)){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("Invalid input. Please try again.\n");
        printf("1. Add another new client\n");
        printf("2. Return to main menu\n");
        printf("Please select from the above options: ");
        scanf("%s", client_select);
        client_select_num = atoi(client_select);
      }
      /* If the user selects 2, return to the main menu. */
      if (client_select_num == 2){
        return;
      }
      repeat_script = 1;
      /* If the user selects 1, return to the top of the function and run again. */
  }
}
