# include <stdlib.h>
# include <stdio.h>
# pragma warning(disable:4996)

int main()
{
	char fname1[1000]; char fname2[1000]; char c;
	FILE* f = fopen("Archive.txt", "w");

	printf("Type the name of file1: ");
	scanf("%s", &fname1);
	printf("\n");

	printf("Type the name of file2: ");
	scanf("%s", &fname2);
	printf("\n");

	FILE* f1 = fopen(fname1, "r");
	FILE* f2 = fopen(fname2, "r");

	int size1 = 0;
	while (!feof(f1)) {
		c = fgetc(f1);
		size1++;
	}

	int size2 = 0;
	while (!feof(f2)) {
		c = fgetc(f2);
		size2++;
	}

	fprintf(f, "1. %s (%d B) \n", fname1, size1);
	fprintf(f, "2. %s (%d B) \n", fname2, size2);

	fclose(f1); fclose(f2);
	f1 = fopen(fname1, "r");
	f2 = fopen(fname2, "r");

	while (!feof(f1)) {
		c = fgetc(f1);
		if (c != EOF) fputc(c, f);
	}
	fprintf(f, "\n----------------------\n");

	while (!feof(f2)) {
		c = fgetc(f2);
		if (c != EOF) fputc(c, f);
	}
	fprintf(f, "\n----------------------\n");

	fclose(f);

	system("pause");
}