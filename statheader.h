//Purpose: provide some useful functions that make working with stats easier
//(C) 2018, FireG3cko
#include <sys/stat.h>

short ftypeInt(struct stat *statstr) //Returns modetype as int value
{
	int arr[6];
	arr[0] = S_ISBLK(statstr->st_mode);
	arr[1] = S_ISCHR(statstr->st_mode);
	arr[2] = S_ISDIR(statstr->st_mode);
	arr[3] = S_ISFIFO(statstr->st_mode);
	arr[4] = S_ISREG(statstr->st_mode);
	arr[5] = S_ISLNK(statstr->st_mode);

	for (int i = 0; i < 8; ++i)
	{
		if (i == 7) return -1;
		if (arr[i] != 0) return i;
	}
}

char *ftypeStr(struct stat *statstr) //Returns modetype as string 
{
	short intType = ftypeInt(statstr);
	
	switch (intType)
	{	
		case 0: return "block";
		case 1: return "char";
		case 2: return "dir";
		case 3: return "fifo";
		case 4: return "reg";
		case 5: return "link";
		case -1: return NULL;

	}
}
