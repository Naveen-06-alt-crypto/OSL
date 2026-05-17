#include <stdio.h>
#include <string.h>

#define MAXU 5
#define MAXF 10

// File structure
struct File
{
    char name[20];
    char type[10];
};

// User structure
struct User
{
    char uname[20];

    struct File files[MAXF];

    int fc;
};

// Master directory
struct User master[MAXU];

int uc = 0;

// Find user function
int findUser(char u[])
{
    for(int i = 0; i < uc; i++)
    {
        if(strcmp(master[i].uname, u) == 0)
        {
            return i;
        }
    }

    return -1;
}

// Add new user
void addUser(char u[])
{
    strcpy(master[uc].uname, u);

    master[uc].fc = 0;

    uc++;

    printf("User '%s' created.\n", u);
}

// Add file to user
void addFile(char u[], char fname[], char ftype[])
{
    int idx = findUser(u);

    if(idx == -1)
    {
        printf("User not found\n");
        return;
    }

    struct File *f =
        &master[idx].files[master[idx].fc];

    strcpy(f->name, fname);

    strcpy(f->type, ftype);

    master[idx].fc++;

    printf("File '%s' added to user '%s'\n",
           fname, u);
}

// Display all users and files
void listAll()
{
    printf("\nUser\tFiles\n");

    for(int i = 0; i < uc; i++)
    {
        printf("%s:\t", master[i].uname);

        for(int j = 0; j < master[i].fc; j++)
        {
            printf("%s.%s ",
                   master[i].files[j].name,
                   master[i].files[j].type);
        }

        printf("\n");
    }
}

int main()
{
    addUser("alice");

    addUser("bob");

    addFile("alice", "resume", "pdf");

    addFile("alice", "notes", "txt");

    addFile("bob", "photo", "jpg");

    listAll();

    return 0;
}
