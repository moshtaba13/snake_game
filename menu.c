
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "menu.h"
#include "map.h"

char current_user[30];


void enter()
{
    char username[30], password[30];
    char u[30], p[30];
    int score;
    int found = 0;

    FILE *fp = fopen("users.txt", "r");

    printf("please enter your username: ");
    scanf("%s", username);
    system("cls");


    if (fp)
    {
        while (fscanf(fp, "%s %s %d", u, p, &score) == 3)
        {
            if (strcmp(u, username) == 0)
            {
                found = 1;
                break;
            }
        }
        fclose(fp);
    }

    if (found)
    {
        printf("this account already exist. please log in.\npassword: ");
        scanf("%s", password);
        system("cls");

        if (strcmp(password, p) == 0) {
            printf("Login successfully!\n");
            strcpy(current_user, username);
            system("cls");
        }

        else {
            printf("Wrong password!!\nplease try again.\n");
            enter();
        }
    }

    else
    {
        printf("please sign up.\nset password: ");
        scanf("%s", password);
        system("cls");

        printf("confirm your password:");
        scanf("%s", p);
        
        if (strcmp(password, p) == 0) {
            
            fp = fopen("users.txt", "a");
            if (fp) {
                fprintf(fp, "%s %s %d\n", username, password, 0);
                fclose(fp);
            }

            printf("Sign up successfully!\n");
            strcpy(current_user, username);
            system("cls");
        }

        else {
            printf("password doesn't match.\n");
            enter();
        }

    }
}


void menu_game(){
    int option;
    printf("=====MENU GAME====\n1.map1\n2.map2\n3.log out\n==================\n(Please enter from 1 to 3):");
    scanf("%d",&option);

    system("cls");

    switch (option)
    {
    case 1:
        map1();
        break;
    
    case 2:
        map2();
        break;

    case 3:
        enter();
        menu_game();
        break;
    
    default:
        menu_game();
        break;
    }
}

void menu_maps() {
    int option;
    printf("====lets play!====\n1.start game(press the x button to exit.)\n2.scors menu\n3.return\n===================\n");
    printf("(Please enter from 1 to 3):");
    scanf("%d",&option);

    system("cls");

    switch (option)
    {
    case 1:
        break;
    
    case 2:
        menu_score();
        break;

    case 3:
        menu_game();
        break;
    
    default:
        menu_maps();
        break;
    }

}


void menu_score() {
    FILE *fp = fopen("users.txt", "r");

    char u[30], p[30];
    int score;

    int record_score = 0;
    int user_best = 0;

    while (fscanf(fp, "%s %s %d", u, p, &score) == 3) {
        if (score > record_score)
            record_score = score;

        if (strcmp(u, current_user) == 0) {
            if (score > user_best)
                user_best = score;
        }
    }

    fclose(fp);

    system("cls");
    printf("===== SCORE MENU =====\n");
    printf("Record Score : %d\n", record_score);
    printf("Best score : %d\n", user_best);
    printf("======================\n");
    printf("Press Enter to return...");

    getchar();
    getchar();
    system("cls");
    menu_maps();
}


void update_score(int score) {
    FILE *fp = fopen("users.txt", "r");

    FILE *temp = fopen("temp_users.txt", "w");

    char u[30], p[30];
    int old_score;

    while (fscanf(fp, "%s %s %d", u, p, &old_score) == 3) {
        if (strcmp(u, current_user) == 0) {

            if (score > old_score)
                fprintf(temp, "%s %s %d\n", u, p, score);
            else
                fprintf(temp, "%s %s %d\n", u, p, old_score);
        } 

        else {
            fprintf(temp, "%s %s %d\n", u, p, old_score);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("users.txt");
    rename("temp_users.txt", "users.txt");

}

