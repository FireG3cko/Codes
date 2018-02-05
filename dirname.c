//Basic 'script' I once wrote to fix my music directory.
//I downloaded my songs from my Google Drive backups, and all the apostrophes became underscores.
//I'm sure this could be condensed to three lines of bash,
//But I partly wrote this to learn more practical C.

#include <stdio.h>
#include <dirent.h>

typedef struct dirent lol;

int main()
{
	printf("Char to replace: "); fflush(stdout);
	char old = getchar();
	char c; while ((c = getchar()) != '\n' && c != EOF);
	printf("Char to insert: "); fflush(stdout);
	char new = getchar();
	
	DIR *dirname = opendir(".");
	lol *dirEntry = readdir(dirname);

	char name[75];
	while (dirEntry != NULL)
	{
		if (dirEntry->d_name[0] == '.') 
		{
			dirEntry = readdir(dirname);
			continue;
		}

		for (int i = 0; dirEntry->d_name[i]; ++i)
		{
			name[i] = dirEntry->d_name[i];
			name[i+1] = 0;
			if (dirEntry->d_name[i] == old) name[i] = new;
		}
		rename(dirEntry->d_name, name);
		dirEntry = readdir(dirname);
	}

	return 0;
}
