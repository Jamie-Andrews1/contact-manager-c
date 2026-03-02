#include "contacts.h"
#include "functions.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        print_usage("contacts [add|list|delete]\n");
        return 1;
    }

    int i = 0;
    char add[] = "add";
    char list[] = "list";
    char del[] = "delete";

    char *input = argv[1];

    switch (**(argv + 1))
    {
    case 'a':
        i++;
        if (!argv[2] || !argv[3] || !argv[4])
        {
            print_missing("Opps! missing args, adding requires Name | Number | Email");
            return (0);
        }
        while (input[i] == add[i])
        {
            if (input[i] == '\0')
            {
                Contact *ContactList = malloc(sizeof(Contact) * MAXCONTACTS);

                if(ContactList == NULL){
                    print_error("Couldn't create contactList");
                    return (0);
                }

                int current = 0;
                ContactList[current] = addContact(argv[2], argv[3], argv[4]);
                current++;

                save_to_csv(ContactList, current);

                print_success("Contact Added!");
                free(ContactList);
                return (0);
            }
            i++;
        }
        break;
    case 'l':
        i++;
        while (input[i] == list[i])
        {
            if (input[i] == '\0')
            {

                char myPath[256];
                getPath(myPath, sizeof(myPath), CSV_NAME);

                if (is_file_empty(myPath))
                {
                    print_missing("No existing contacts found. Starting fresh!\n");
                    return (0);
                }
                FILE *fp = fopen(myPath, "r");
              
                int lines = 0;
                char buf[150];
                Contact *ContactList = malloc(sizeof(Contact) * MAXCONTACTS);
                if (ContactList == NULL)
                    return 1;
                while (lines < MAXCONTACTS && fgets(buf, sizeof buf, fp) != NULL)
                {
                    Contact temp;
                    int assigned = sscanf(buf, "%49[^,],%19[^,],%49s",
                                          temp.name,
                                          temp.phone,
                                          temp.email);

                    if (assigned == 3)
                    {
                        ContactList[lines] = addContact(temp.name, temp.phone, temp.email);
                        lines++;
                    }
                }

                print_contacts(ContactList, lines); 
                
                fclose(fp);
                free(ContactList);
                return (0);
            }
            i++;
        }
        break;
    case 'd':
        i++;
        if (!argv[2])
        {
            print_missing("oops!, parameter missed, must have delete and a name.\n");
            return (0);
        }
        while (input[i] == del[i])
        {
            if (input[i] == '\0')
            {
                char myPath[256];
                getPath(myPath, sizeof(myPath), CSV_NAME);

                FILE *fp = fopen(myPath, "r");
                if (fp == NULL)
                {
                    print_missing("Nothing saved to the list");
                    return (0);
                }

                int lines = 0;
                char buf[150];
                Contact *ContactList = malloc(sizeof(Contact) * MAXCONTACTS);
                if (ContactList == NULL)
                    return 1;
                while (lines < MAXCONTACTS && fgets(buf, sizeof buf, fp) != NULL)
                {
                    Contact temp;
                    int assigned = sscanf(buf, "%49[^,],%19[^,],%49s",
                                          temp.name,
                                          temp.phone,
                                          temp.email);

                    if (assigned == 3)
                    {
                        ContactList[lines] = addContact(temp.name, temp.phone, temp.email);
                        lines++;
                    }
                }
                fclose(fp);
                remove_contact(ContactList, argv[2], lines);

                free(ContactList);
                return (0);
            }
            i++;
        }
        break;
    case 's':
        i++;
        char search[] = "search";
        if (!argv[2])
        {
            print_missing("oops!, parameter missed, must have search and a name.\n");
            return (0);
        }
        while (input[i] == search[i])
        {
            if (input[i] == '\0')
            {
                char myPath[256];
                getPath(myPath, sizeof(myPath), CSV_NAME);

                FILE *fp = fopen(myPath, "r");
                if (fp == NULL)
                {
                    print_missing("Nothing saved to the list");
                    return (0);
                }

                int lines = 0;
                char buf[150];
                Contact *ContactList = malloc(sizeof(Contact) * MAXCONTACTS);
                if (ContactList == NULL)
                    return 1;
                while (lines < MAXCONTACTS && fgets(buf, sizeof buf, fp) != NULL)
                {
                    Contact temp;
                    int assigned = sscanf(buf, "%49[^,],%19[^,],%49s",
                                          temp.name,
                                          temp.phone,
                                          temp.email);

                    if (assigned == 3)
                    {
                        ContactList[lines] = addContact(temp.name, temp.phone, temp.email);
                        lines++;
                    }
                }
                fclose(fp);
                find_contact(ContactList, argv[2], lines);

                free(ContactList);
                return (0);
            }
            i++;
        }
        break;
    default:
        print_error("Command Not Found, must be add, list or delete.");
        return (0);
        break;
    }

    printf("Command not found, must be add | list | delete.");
}