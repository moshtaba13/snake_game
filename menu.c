
#include <stdio.h>
#include <string.h>

#include "menu.h"

void enter() {
    char username[30], password[30];
    char u[30], p[30];
    int found = 0;

    FILE *fp = fopen("users.txt", "r");

   printf("please enter your username:");
    scanf("%s", username);

  
    if (fp) {
        while (fscanf(fp, "%s %s", u, p) != EOF) {
            if (strcmp(u, username) == 0) {
                found = 1;
                break;
            }
        }
        fclose(fp);
    }

    if (found) {
        printf("this account already exist. please log in.\npassword:");
        scanf("%s", password);

        if (strcmp(password, p) == 0) {
            printf("Login successfully! \n");
        } else {
            printf("Wrong password!!\nplease try again.\n");
            enter();
        }
    }

    else {
        printf("please sign up.\nset password:");
        scanf("%s", password);

        fp = fopen("users.txt", "a");
        fprintf(fp, "%s %s\n", username, password);
        fclose(fp);

        printf("Sign up successfully! \n");
    }
}

