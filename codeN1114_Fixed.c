#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LEN 9
#define USERNAME_DB "usernames2.dat"

struct User {
    char username[50];
    char password[MAX_PASSWORD_LEN];
    int uid;
};

struct User usersDb[3] = {
        {.username = "admin", .password = "jrAz+"},
        {.username = "userA", .password = "ocAr6"},
        {.username = "userB", .password = "idMf("},
};


const char secret[8] = {11, 22, 44, 19, 69, 30, 90, 14};

char *encrypt(char *toEncrypt, int size) {
    int i;
    for (i = 0; i < size; i++)
        toEncrypt[i] ^= secret[i];

    return toEncrypt;
}

char *decrypt(char *toDecrypt, int size) {
    int i;
    for (i = 0; i < size; i++)
        toDecrypt[i] ^= secret[i];
    return toDecrypt;

}

int checkValidUserName(char *username) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(username, usersDb[i].username) == 0) {
            return 1;
        }
    }
    return 0;
}

int checkValidPassword(char *username, char *password) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(username, usersDb[i].username) == 0 &&
            strcmp(password, decrypt(usersDb[i].password, strlen(usersDb[i].password))) == 0) {
            return 1;
        }
    }
    return 0;
}


int checkCredentials(char *username, char *password) {
    if (checkValidUserName(username)) {
        if (checkValidPassword(username, password)) {
            return 1;
        } else {
            printf("%s", "Password is invalid\n");
            return 0;
        }
    } else {
        printf("%s", "Username is invalid\n");
        return 0;
    }
}

int main(int argc, char **argv) {
    printf("What would you like to do? \n");
    printf("[1]. Add user to file \n");
    printf("[2]. Drop DB \n");
    printf("[3]. exit \n");

    int menu;
    scanf("%d", &menu);

    char username[20];
    char newUsername[20];
    char password[20];
    if (menu == 1 || menu == 2) {
        printf("Enter username: ");
        scanf("%19s", username);
        printf("Enter password: ");
        scanf("%19s", password);
    }

    // Fixed code to check for input buffer overflow
    if (strlen(username) >= 20 || strlen(password) >= 20) {
        printf("Input buffer overflow detected.\n");
        return 1;
    }
    
    FILE *fp;

switch (menu) {
case 1:
    if (checkCredentials(username, password) != 0) {
        printf("Only admin can access!\n");
        break;
    }
    FILE *fp = fopen(USERNAME_DB, "a");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        break;
    }
    printf("Enter username to be added (max 19 characters): ");
    char newUsername[20];
    if (scanf("%19s", newUsername) != 1) {
        printf("Error: invalid input\n");
        fclose(fp);
        break;
    }
    fprintf(fp, "%s\n", newUsername);
    printf("%s\n", "username added to file");
    fclose(fp);
    break;


   case 2:
    	if (!checkCredentials(username, password)) {
        printf("Only admin can access!");
        break;
    }
    fp = fopen(USERNAME_DB, "w");
    if (fp) {
        fprintf(fp, "%s\n", "");
        printf("%s\n", "users DB wiped!");
    } else {
        printf("%s\n", "failed to open file");
    }
    break;

    case 3:
        return (0);
        break;
}

}
