/******************************************************************************

File Name: transaction_history.c
Purpose: To allow users to view client transaction history in the CS 125 Bank Program.
Created By: William Hankins

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void transaction_history(){
  FILE* client_history_file;
  int repeat_script = 1;
  int client_select_num = 1;
  char client_select[10];
  char client_first_name[30];
  char client_last_inital[30];
  char current_file_line[100];
  int x;
  /* Continue running the script until the user requests to return to the main menu when prompted. */
  while (repeat_script == 1){
    /* Prompt user for the client's name and concatinate it with _history.txt to get the correct file name. */
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
    /* Open the client's history file with read access. */
    client_history_file = fopen(client_first_name, "r");
    /* If the client's history file does not exist, prompt user to try again with a different name. */
    while (client_history_file == NULL){
        printf("Unable to locate client, please try again.\n");
        printf("Enter Q to quit search\n");
        printf("Enter client first name: ");
        scanf("%s", client_first_name);
        /* If the user enters q for the first name, return to the main menu. */
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
    x=0;
    /* Once the client history file has been sucessfully opened, print the text file to the screen. */
    while (fscanf(client_history_file, "%s" ,current_file_line) != EOF){
      printf("%s ", current_file_line);
      x++;
      if (x==12){
        printf("\n");
        x=0;
      }
    }
    /* Close the text file. */
    fclose(client_history_file);
    /* Ask user if they would like to repeat the function or return to the main menu. */
    printf("\n1. Search another client's history\n");
    printf("2. Return to main menu\n");
    printf("Please select from the above options: ");
    scanf("%s", client_select);
    client_select_num = atoi(client_select);
    /* While the user reponse is invalid, continue to prompt for a valid input. */
    while ((client_select_num < 1) || (client_select_num > 2)){
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("Invalid input. Please try again.\n");
      printf("1. Search another client's history\n");
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
    /* If the user selects 1, repeat the function. */
  }
}
