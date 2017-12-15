//Салыкина Дария, группа 108, семинар 7, задача 22
//Создание архива: название файлов, в него включенных, размеры, содержимое
# include <stdlib.h>
# include <stdio.h>

int main()
{
	char fname1[1000]; char fname2[1000]; char c;
	FILE* f = fopen("Archive.txt", "w");

	//Выбор пользователем файлов
	printf("Type the name of file1: ");
	scanf("%s", &fname1);
	printf("\n");

	printf("Type the name of file2: ");
	scanf("%s", &fname2);
	printf("\n");

	//Открытие файлов на чтение
	FILE* f1 = fopen(fname1, "r");
	FILE* f2 = fopen(fname2, "r");

	//Вычисление размеров файлов
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
	
        //Вывод информации о названии файлов и их размерах
	fprintf(f, "1. %s (%d B) \n", fname1, size1);
	fprintf(f, "2. %s (%d B) \n", fname2, size2);

	fclose(f1); fclose(f2);
	f1 = fopen(fname1, "r");
	f2 = fopen(fname2, "r");

	//Перенесение информации из файлов в один
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
