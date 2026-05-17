#include <stdio.h>
#include <string.h>

#define MAXD 5
#define MAXF 10

// File list
char files[MAXF][20];

int fcount = 0;

// Directory structure
struct Dir
{
    char name[20];

    int links[MAXF];

    int lc;
};

// Directories
struct Dir dirs[MAXD];

int dcount = 0;

// Add file
int addFile(char name[])
{
    strcpy(files[fcount], name);

    return fcount++;
}

// Add directory
int addDir(char name[])
{
    strcpy(dirs[dcount].name, name);

    dirs[dcount].lc = 0;

    return dcount++;
}

// Link file to directory
void linkFile(int d, int f)
{
    dirs[d].links[dirs[d].lc++] = f;
}

// Display DAG structure
void display()
{
    printf("\nDAG Directory Structure\n");

    for(int i = 0; i < dcount; i++)
    {
        printf("Directory: %s\n",
               dirs[i].name);

        for(int j = 0; j < dirs[i].lc; j++)
        {
            printf("   -> %s\n",
                   files[dirs[i].links[j]]);
        }
    }
}

int main()
{
    // Create directories
    int d1 = addDir("alice");

    int d2 = addDir("bob");

    // Create files
    int f1 = addFile("shared.pdf");

    int f2 = addFile("notes.txt");

    // Link files
    linkFile(d1, f1);

    linkFile(d2, f1);

    linkFile(d1, f2);

    // Display structure
    display();

    return 0;
}
