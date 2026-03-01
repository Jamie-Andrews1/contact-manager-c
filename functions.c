#include "functions.h"

void print_contacts(Contact *list, int count) {
    if (count == 0) {
        printf("\n\033[0;31m[!] No contacts found.\033[0m\n");
        return;
    }

    printf("\n%-4s | %-20s | %-15s | %-25s\n", "ID", "NAME", "PHONE", "EMAIL");
    printf("------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-4d | %-20s | %-15s | %-25s\n", 
               i + 1, 
               list[i].name, 
               list[i].phone, 
               list[i].email);
    }
    printf("------------------------------------------------------------------------------\n");
    printf("Total: %d contacts\n\n", count);
}

void print_usage(char *msg) {
    printf("%sUsage: %s%s\n", YEL, msg, RESET);
}
void print_missing(char *msg) {
    printf("%sMISSING: %s%s\n", BLU, msg, RESET);
}
void print_success(char *msg) {
    printf("%sSUCCESS: %s%s\n", GRN, msg, RESET);
}
void print_error(char *msg) {
    printf("%sERROR: %s%s\n", RED, msg, RESET);
}

void getPath(char *buffer, size_t size, char *name){
    char *home = getenv("HOME");
    
    if (home == NULL) {
        fprintf(stderr, "Error: Could not find HOME directory\n");
        return;
    }

    snprintf(buffer, size, "%s/Documents/%s", home, name);
}

int is_file_empty(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) return 1;

    int c = fgetc(fp);
    if (c == EOF) {
        fclose(fp);
        return 1;
    } else {
        ungetc(c, fp);

        fclose(fp);
        return 0; 
    }
}

void remove_contact(Contact *list, char *name_to_delete, int count)
{
    char tempPath[100];
    getPath(tempPath, sizeof(tempPath), TEMP);
    FILE *temp = fopen(tempPath, "w");

    int found = 0;
    char *toDel = name_to_delete; 
    
    if (!temp)
    {
        print_error("Error opening files.\n");
        return;
    }

    
    for (int i = 0; i < count; i++)
    {
        char *name = list[i].name;
          for ( ; *name == *toDel && *name != '\0'; name++, toDel++){
          ;
        }
        if (*name == '\0' && *toDel == '\0')
        {
            found = 1;
        }
        else
        {
            fprintf(temp, "%s,%s,%s\n", list[i].name, list[i].phone, list[i].email);
        }
    }

    fclose(temp);

    if (found)
    {
        char myPath[256];
        getPath(myPath, sizeof(myPath), CSV_NAME);
        remove(myPath);                  
        rename(tempPath, myPath);
        print_success("Contact deleted successfully.\n");
    }
    else
    {
        remove(tempPath);
        print_error("Contact not found.\n");
    }
}
void save_to_csv(Contact *list, int count)
{
    char myPath[256];
    getPath(myPath, sizeof(myPath), CSV_NAME);
    FILE *file = fopen(myPath, "a+");
    if (file == NULL)
        return;

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s,%s,%s\n", list[i].name, list[i].phone, list[i].email);
    }

    fclose(file);
}


Contact addContact(char *nameInput, char *phoneInput, char *emailInput)
{

    Contact Result;

    StrCpy(Result.name, nameInput, STORESIZE);
    StrCpy(Result.phone, phoneInput, 20);
    StrCpy(Result.email, emailInput, STORESIZE);

    return Result;
}

void StrCpy(char *first, char *second, int size)
{

    int i = 0;
    while (second[i] != '\0' && i < size - 1)
    {
        first[i] = second[i];
        i++;
    }
    first[i] = '\0';
}