#include <stdio.h>
#include <string.h>

#define MAX 10

// Structure for file details
struct File
{
    char name[20];
    char type[10];
    int size;
};

// Directory array
struct File dir[MAX];

int count = 0;

// Create file function
void createFile(char name[], char type[], int size)
{
    if(count >= MAX)
    {
        printf("Directory Full!\n");
        return;
    }

    strcpy(dir[count].name, name);
    strcpy(dir[count].type, type);
    dir[count].size = size;

    count++;

    printf("File '%s' created.\n", name);
}

// Display files
void listFiles()
{
    printf("\nFile Name\tType\tSize\n");

    for(int i = 0; i < count; i++)
    {
        printf("%s\t\t%s\t%dKB\n",
               dir[i].name,
               dir[i].type,
               dir[i].size);
    }
}

// Delete file
void deleteFile(char name[])
{
    for(int i = 0; i < count; i++)
    {
        if(strcmp(dir[i].name, name) == 0)
        {
            // Shift files
            for(int j = i; j < count - 1; j++)
            {
                dir[j] = dir[j + 1];
            }

            count--;

            printf("File '%s' deleted.\n", name);

            return;
        }
    }

    printf("File not found.\n");
}

int main()
{
    createFile("notes", "txt", 12);

    createFile("photo", "jpg", 340);

    createFile("program", "c", 5);

    listFiles();

    deleteFile("photo");

    listFiles();

    return 0;
}
