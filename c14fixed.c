#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "bcrypt.h" // bcrypt password hashing library

#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 100
#define MAX_USERS 1000
#define USERNAME_DB "usernames2.dat"
#define BCRYPT_COST 12 // cost factor for bcrypt algorithm

struct User {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    int uid;
};

struct User usersDb[MAX_USERS];
int numUsers = 0;

const char *secret = "Rivest-Shamir-Adleman"; // secret key for encryption/decryption

char *encrypt(char *toEncrypt, int size) {
    for (int i = 0; i < size; i++)
        toEncrypt[i] ^= secret[i % strlen(secret)];
    return toEncrypt;
}

char *decrypt(char *toDecrypt, int size) {
    for (int i = 0; i < size; i++)
        toDecrypt[i] ^= secret[i % strlen(secret)];
    return toDecrypt;
}

int checkValidUserName(char *username) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, usersDb[i].username) == 0) {
            return 1;
        }
    }
    return 0;
}

int checkValidPassword(char *username, char *password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, usersDb[i].username) == 0 &&
            bcrypt_checkpw(password, usersDb[i].password) == 0) {
            return 1;
        }
    }
    return 0;
}

int checkCredentials(char *username, char *password) {
    if (!checkValidUserName(username)) {
        printf("Username is invalid\n");
        return 0;
    }

    if (!checkValidPassword(username, password)) {
        printf("Password is invalid\n");
        return 0;
    }

    return 1;
}

int addNewUser(char *username, char *password) {
    if (checkValidUserName(username)) {
        printf("Username already exists\n");
        return 0;
    }

    // generate a random UID
    srand(time(NULL) ^ getpid());
    int uid = rand() % 100000;

    // hash the password using bcrypt algorithm
    char hashedPassword[MAX_PASSWORD_LEN];
    if (bcrypt_hashpw(password, bcrypt_gensalt(BCRYPT_COST), hashedPassword) != 0) {
        printf("Failed to hash password\n");
        return 0;
    }

    // add the new user to the database
    struct User newUser;
    strncpy(newUser.username, username, MAX_USERNAME_LEN);
    strncpy(newUser.password, hashedPassword, MAX_PASSWORD_LEN);
    newUser.uid = uid;

    if (numUsers == MAX_USERS) {
        printf("Database is full\n");
        return 0;
    }

    usersDb[numUsers++] = newUser;

    // save the updated database to file
    FILE *fp = fopen(USERNAME_DB, "w");
    if (fp == NULL) {
        printf("Failed to open database file\n");
        return 0;
    }

    for (int i = 0; i < numUsers; i++) {
        char encryptedPassword[MAX_PASSWORD_LEN];
        strncpy(encryptedPassword, usersDb[i].password, MAX_PASSWORD_LEN);
        encrypt(encryptedPassword, strlen(encryptedPassword));
        fprintf(fp, "%s %s %d\n", usersDb[i].username, encryptedPassword
