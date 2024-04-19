//
// Created by Hp on 17/04/2024.
//

#ifndef UNTITLED_LOGIN_H
#define UNTITLED_LOGIN_H

void getLoginCommand(char *buffer,short *x,char *name, char *surname);

int validateName (char *name);

int validateLogin (char *input);

int verifAcc(const char *name);

void getCommand(char *buffer);

void getInput(char *buffer);

void loadUsers();

bool validateUser(char *name, char *surname);

void saveUser(char *name, char *surname);

#endif //UNTITLED_LOGIN_H
