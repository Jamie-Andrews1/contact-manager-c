
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "contacts.h"
#define CSV_NAME "contacts.csv"
#define TEMP "temp.csv"

Contact addContact(char *nameInput, char *phoneInput, char *emailInput);
void remove_contact(Contact *list, char *name_to_delete, int count);
void save_to_csv(Contact *list, int count);
void StrCpy(char *first, char *second, int size);
int is_file_empty(const char *filename);
void getPath(char *buffer, size_t size, char *name);

void print_usage(char *msg); 
void print_missing(char *msg);
void print_error(char *msg);
void print_success(char *msg); 
void print_contacts(Contact *list, int count);
void find_contact (Contact *list, char *name_to_find, int count);

#endif