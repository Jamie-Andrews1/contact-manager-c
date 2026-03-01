#ifndef CONTACTS_H
#define CONTACTS_H

#define RED   "\033[0;31m"
#define GRN   "\033[0;32m"
#define YEL   "\033[0;33m"
#define BLU   "\033[0;34m"
#define RESET "\033[0m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STORESIZE 50
#define MAXCONTACTS 100

typedef struct Contact
{
    char name[STORESIZE];
    char phone[20];
    char email[STORESIZE];
} Contact;

#endif