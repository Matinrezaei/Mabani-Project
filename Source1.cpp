#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
time_t t = time(NULL);
struct tm* tm = localtime(&t);
typedef struct date {
	int year, day, month, code, tedad, kol, u, salamat
		, rahgiri, strlencode, strlenname, strlenlast;
	char codemelli[30], name[10], last[10], rooz[15];
}date;
typedef struct karbaranaddi {
	char pass[15], email[30], user[30], blood[5], codemeli[30], name[20], lastname[20], rooz[15], vaziat[10];
	int salamat, code, rahgiri, age, tedad, number, day, month, year, kol, shomare;
	float weight, size;
	date molaqat[100], places[100], tests[100];
}normal;
typedef struct mashaqel {
	char codemeli[30], user[30], email[30], pass2[15], pass[15], city[10], shname[30], name[20], vaziat[10];
	int code, rahgiri, area, tedad, kol;
	date moraje[100];
}mashaqel;
typedef struct hospital {
	int mantaghe;
	char name[30], city[15], addres[40];
}bimaresta;
bimaresta bimarestan[100];
normal addi[100];
mashaqel job[100];
FILE* matin, * hospital;
int welcome(), forgot(), logup(int, int), login(), menu(), menu2(), menu3();
int count, j, i, number = 1, shomare = 1, vorood, b, num = 1, h;
char name[6] = "Matin", lastname[7] = "Rezaee", x, macan[10], pass[15];
char userad[8] = "123", passad[20] = "123";
inline void setFontSize(int a, int b) {

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();

	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);

	GetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);

	lpConsoleCurrentFontEx->dwFontSize.X = a;

	lpConsoleCurrentFontEx->dwFontSize.Y = b;

	SetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);

}
void bimar() {
	system("cls");
	setFontSize(25, 25);
	char city[20];
	printf("\n\n          inter your city: ");
	gets_s(city);
	for (i = 1; i < num; i++) {
		if (strcmp(city, bimarestan[i].city) == 0) {
			printf("  name                              addres          Region\n\n");
			printf("  %s              %s               %d\n", bimarestan[i].name, bimarestan[i].addres, bimarestan[i].mantaghe);
		}
	}
	printf("\n\n    1.menu\n");
	x = getch();
	if (x == '1')
		menu();
}
void vaziat(int type, int vared) {
	if (type == 1) {
		if (addi[vared].code == 0)
			strcpy(addi[vared].vaziat, "Death");
		if (addi[vared].code == 1)
			strcpy(addi[vared].vaziat, "Healthy");
		if (addi[vared].code == 2)
			strcpy(addi[vared].vaziat, "Suspicuos");
		if (addi[vared].code == 3)
			strcpy(addi[vared].vaziat, "Dangarous");
		if (addi[vared].code == 4)
			strcpy(addi[vared].vaziat, "Sick");
	}
	else {
		if (job[vared].code == 1)
			strcpy(job[vared].vaziat, "White");
		if (job[vared].code == 2)
			strcpy(job[vared].vaziat, "RED");
	}
}
void findday(int d, int m, int y) {
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i;
	if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
		month[1] = 29;
	if (y < 1900 || m < 1 || m > 12 || d < 1 || d > month[m - 1])
		printf("This is an invalid date.\n");
	for (i = 1900; i < y; i++)
		if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
			d += 366;
		else
			d += 365;
	for (i = 0; i < m - 1; i++)
		d += month[i];
	count = d;
	b = d % 7;
	return;
}
void taghircode() {
	findday(tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
	for (i = 1; i < shomare; i++) {
		if (count - addi[i].kol == 7) {
			if (addi[i].code == 3) {
				addi[i].code = 2;
				vaziat(1, i);
				addi[i].kol = count;
			}
			if (addi[i].code == 2) {
				addi[i].code = 1;
				vaziat(1, i);
				addi[i].kol = count;
			}
		}
	}
	for (i = 1; i < number; i++) {
		if (count - job[i].kol == 14 && job[i].code != 1) {
			job[i].code = 1;
			vaziat(2, i);
			job[i].kol = count;
		}
	}
}
void see(int vared) {
	int a = 1;
	system("cls");
	setFontSize(25, 25);
	printf("                                                                  Afrad Mobtala\n\n");
	printf(" 1.Suspicuos\n");
	printf(" 2.Dangarous\n");
	printf(" 3.Sick\n");
	x = getch();
	for (i = 0; i < 3; i++) {
		fputs("\033[A\033[2K", stdout);
		rewind(stdout);
	}
	printf("   Row          Codemelli                First name       Last name              Date\n\n\n");
	for (i = 1; i < job[vared].tedad; i++) {
		if (job[vared].moraje[i].code == x - 48 + 1) {
			printf("   %d            %s               %s             %s               %d-%d-%d\n\n"
				, a, job[vared].moraje[i].codemelli, job[vared].moraje[i].name, job[vared].moraje[i].last,
				job[vared].moraje[i].day, job[vared].moraje[i].month, job[vared].moraje[i].year);
			a++;
		}
	}
	printf("\n\n    1.menu\n");
	x = getch();
	if (x == '1')
		menu2();
}
void ofooni(int vared) {
	system("cls");
	setFontSize(30, 30);
	findday(tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
	if (job[vared].code == 2) {
		job[vared].code = 1;
		vaziat(2, vared);
		job[vared].kol = count;
	}
	printf("\n\n\n\n\n\n\n\n\n");
	printf("                                   While disinfecting, please wait\n");
	Sleep(6000);
	menu2();
}
void record(int vared) {
	findday(tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
	char codemeli[20];
	fputs("\033[A\033[2K", stdout);
	rewind(stdout);
	fputs("\033[A\033[2K", stdout);
	rewind(stdout);
	fputs("\033[A\033[2K", stdout);
	rewind(stdout);
	fputs("\033[A\033[2K", stdout);
	rewind(stdout);
	printf("\n\n");
	if (vared == 1) {
		printf("          Please inter the Nation code:  ");
		scanf("%s", codemeli);
		x = getchar();
		for (i = 1; i < number; i++) {
			if (strcmp(addi[i].codemeli, codemeli) == 0) {
				addi[i].code = 0;
				vaziat(1, i);
				addi[i].kol = count;
				printf("\n            Death record is complete\n\n");
				i = 0;
				break;
			}
		}
		if (i != 0)
			printf("            Nation code not founded\n\n");
	}
	else if (vared == 2) {
		printf("          Please inter the Nation code:  ");
		scanf("%s", codemeli);
		x = getchar();
		for (i = 1; i < number; i++) {
			if (strcmp(addi[i].codemeli, codemeli) == 0 && addi[i].code == 4) {
				addi[i].code = 2;
				vaziat(1, i);
				addi[i].kol = count;
				printf("\n\n           Recovery record is complete\n\n");
				i = 0;
				break;
			}
		}
		if (i != 0)
			printf("           Nation code not founded\n\n");
	}
}
void deads() {
	system("cls");
	setFontSize(18, 18);
	int a = 1;
	printf("                                                          Deads\n\n");
	printf("   Row          Codemelli                First name       Last name              Date\n\n\n");
	for (i = 1; i < shomare; i++) {
		if (addi[i].code == 0) {
			printf("   %d            %s                      %s               %s                  %d-%d-%d\n\n"
				, a, addi[i].codemeli, addi[i].name, addi[i].lastname, addi[i].day, addi[i].month, addi[i].year);
			a++;
		}
	}
	printf("\n\n    1.menu\n");
	x = getch();
	if (x == '1')
		menu3();
}
void hamemashaqel() {
	system("cls");
	setFontSize(25, 25);
	int a = 1;
	printf("                                                          All Mashaqel\n\n");
	printf("   Row          Codemelli               name            city                code       condition\n\n\n");
	for (i = 1; i < number; i++) {
		printf("   %d            %s                 %s             %s                 %d          %s\n\n"
			, a, job[i].codemeli, job[i].name, job[i].city, job[i].code, job[i].vaziat);
		a++;
	}
	printf("\n\n    1.menu\n");
	x = getch();
	if (x == '1')
		menu3();
}
void all() {
	system("cls");
	setFontSize(25, 25);
	int a = 1;
	printf("                                                           Karbaran\n\n");
	printf("   Row          Codemelli                First name       Last name              code      condition\n\n\n");
	for (i = 1; i < shomare; i++) {
		if (addi[i].code != 0) {
			printf("   %d            %s               %s              %s               %d       %s\n\n"
				, a, addi[i].codemeli, addi[i].name, addi[i].lastname, addi[i].code, addi[i].vaziat);
			a++;
		}
	}
	printf("\n\n    1.menu\n");
	x = getch();
	if (x == '1')
		menu3();
}
void marizan() {
	system("cls");
	setFontSize(25, 25);
	int a = 1;
	printf("                                                                     Mobtalayan\n\n");
	printf("   Row          Codemelli                First name       Last name              Date\n\n\n");
	for (i = 1; i < shomare; i++) {
		if (addi[i].code == 4) {
			printf("   %d            %s               %s               %s                %d-%d-%d\n\n"
				, a, addi[i].codemeli, addi[i].name, addi[i].lastname, addi[i].day, addi[i].month, addi[i].year);
			a++;
		}
	}
	while (1) {
		printf("  1.Death record                2.Recovery record\n\n");
		printf("                    3.menu\n\n");
		x = getch();
		if (x == '1')
			record(1);
		else if (x == '2')
			record(2);
		else if (x == '3')
			menu3();
	}
}
void showhospitals() {
	system("cls");
	setFontSize(25, 25);
	int a = 1;
	printf("                                                          Hospitals\n\n");
	printf("   Row          city                     name               mantaqe                       Adress\n\n\n");
	for (i = 1; i < num; i++) {
		printf("   %d            %s                %s               %d                %s\n\n"
			, a, bimarestan[i].city, bimarestan[i].name, bimarestan[i].mantaghe, bimarestan[i].addres);
		a++;
	}
	printf(" 1.menu\n");
	x = getch();
	if (x == '1')
		menu3();
}
void rooz(int nam, int vared, int test, int k) {
	if (k == 1) {
		if (nam == 0)
			strcpy(addi[vared].tests[test].rooz, "Sunday");
		if (nam == 1)
			strcpy(addi[vared].tests[test].rooz, "Monday");
		if (nam == 2)
			strcpy(addi[vared].tests[test].rooz, "Tuesday");
		if (nam == 3)
			strcpy(addi[vared].tests[test].rooz, "Wednesday");
		if (nam == 4)
			strcpy(addi[vared].tests[test].rooz, "Thursday");
		if (nam == 5)
			strcpy(addi[vared].tests[test].rooz, "Friday");
		if (nam == 6)
			strcpy(addi[vared].tests[test].rooz, "Saturday");
	}
	if (k == 2) {
		if (nam == 0)
			strcpy(addi[vared].molaqat[test].rooz, "Sunday");
		if (nam == 1)
			strcpy(addi[vared].molaqat[test].rooz, "Monday");
		if (nam == 2)
			strcpy(addi[vared].molaqat[test].rooz, "Tuesday");
		if (nam == 3)
			strcpy(addi[vared].molaqat[test].rooz, "Wednesday");
		if (nam == 4)
			strcpy(addi[vared].molaqat[test].rooz, "Thursday");
		if (nam == 5)
			strcpy(addi[vared].molaqat[test].rooz, "Friday");
		if (nam == 6)
			strcpy(addi[vared].molaqat[test].rooz, "Saturday");
	}
	if (k == 3) {
		if (nam == 0)
			strcpy(addi[vared].places[test].rooz, "Sunday");
		if (nam == 1)
			strcpy(addi[vared].places[test].rooz, "Monday");
		if (nam == 2)
			strcpy(addi[vared].places[test].rooz, "Tuesday");
		if (nam == 3)
			strcpy(addi[vared].places[test].rooz, "Wednesday");
		if (nam == 4)
			strcpy(addi[vared].places[test].rooz, "Thursday");
		if (nam == 5)
			strcpy(addi[vared].places[test].rooz, "Friday");
		if (nam == 6)
			strcpy(addi[vared].places[test].rooz, "Saturday");
	}
	if (k == 4) {
		if (nam == 0)
			strcpy(addi[vared].rooz, "Sunday");
		if (nam == 1)
			strcpy(addi[vared].rooz, "Monday");
		if (nam == 2)
			strcpy(addi[vared].rooz, "Tuesday");
		if (nam == 3)
			strcpy(addi[vared].rooz, "Wednesday");
		if (nam == 4)
			strcpy(addi[vared].rooz, "Thursday");
		if (nam == 5)
			strcpy(addi[vared].rooz, "Friday");
		if (nam == 6)
			strcpy(addi[vared].places[test].rooz, "Saturday");
	}
	if (k == 5) {
		if (nam == 0)
			strcpy(job[vared].moraje[test].rooz, "Sunday");
		if (nam == 1)
			strcpy(job[vared].moraje[test].rooz, "Monday");
		if (nam == 2)
			strcpy(job[vared].moraje[test].rooz, "Tuesday");
		if (nam == 3)
			strcpy(job[vared].moraje[test].rooz, "Wednesday");
		if (nam == 4)
			strcpy(job[vared].moraje[test].rooz, "Thursday");
		if (nam == 5)
			strcpy(job[vared].moraje[test].rooz, "Friday");
		if (nam == 6)
			strcpy(job[vared].moraje[test].rooz, "Saturday");
	}
}
void daryaft() {
	matin = fopen("matin.txt", "a+");
	hospital = fopen("Hospitals.txt", "a+");
	int m, q, n;
	fscanf(matin, "%d%d", &number, &shomare);
	fscanf(hospital, "%d%d", &num);
	for (m = 1; m < num; m++) {
		fread(&bimarestan[m], sizeof(bimaresta), 1, hospital);
	}
	fclose(hospital);
	for (m = 1; m < shomare; m++) {
		fread(&addi[m], sizeof(normal), 1, matin);
		addi[m].age /= 256;
		addi[m].shomare /= 256;
		addi[m].kol /= 256;
		addi[m].month /= 256;
		addi[m].day /= 256;
		addi[m].year /= 256;
		addi[m].number /= 256;
		addi[m].tedad /= 256;
		addi[m].rahgiri /= 256;
		addi[m].code /= 256;
		addi[m].salamat /= 256;
		for (q = 1; addi[m].name[q] != '\0'; addi[m].name[q - 1] = addi[m].name[q], q++);
		addi[m].name[q - 1] = '\0';
		for (q = 1; addi[m].lastname[q] != '\0'; addi[m].lastname[q - 1] = addi[m].lastname[q], q++);
		addi[m].lastname[q - 1] = '\0';
		for (q = 1; addi[m].codemeli[q] != '\0'; addi[m].codemeli[q - 1] = addi[m].codemeli[q], q++);
		addi[m].codemeli[q - 1] = '\0';
		for (q = 1; addi[m].email[q] != '\0'; addi[m].email[q - 1] = addi[m].email[q], q++);
		addi[m].email[q - 1] = '\0';
		for (q = 1; addi[m].user[q] != '\0'; addi[m].user[q - 1] = addi[m].user[q], q++);
		addi[m].user[q - 1] = '\0';
		for (q = 1; addi[m].pass[q] != '\0'; addi[m].pass[q - 1] = addi[m].pass[q], q++);
		addi[m].pass[q - 1] = '\0';
		for (q = 1; addi[m].blood[q] != '\0'; addi[m].blood[q - 1] = addi[m].blood[q], q++);
		addi[m].blood[q - 1] = '\0';
		for (q = 1; addi[m].rooz[q] != '\0'; addi[m].rooz[q - 1] = addi[m].rooz[q], q++);
		addi[m].rooz[q - 1] = '\0';
		vaziat(1, m);
		for (n = 1; n < addi[m].tedad; n++) {
			addi[m].molaqat[n].kol /= 256;
			addi[m].molaqat[n].year /= 256;
			addi[m].molaqat[n].code /= 256;
			addi[m].molaqat[n].day /= 256;
			addi[m].molaqat[n].month /= 256;
			addi[m].molaqat[n].tedad /= 256;
			addi[m].molaqat[n].rahgiri /= 256;
			addi[m].molaqat[n].u /= 256;
			addi[m].molaqat[n].strlencode /= 256;
			addi[m].molaqat[n].strlenlast /= 256;
			addi[m].molaqat[n].strlenname /= 256;
		}
		for (n = 1; n < addi[m].tedad; n++) {
			for (q = 1; addi[m].molaqat[n].codemelli[q] != '\0'; addi[m].molaqat[n].codemelli[q - 1] = addi[m].molaqat[n].codemelli[q], q++);
			addi[m].molaqat[n].codemelli[addi[m].molaqat[n].strlencode] = '\0';
		}
		for (n = 1; n < addi[m].tedad; n++) {
			for (q = 1; addi[m].molaqat[n].name[q] != '\0'; addi[m].molaqat[n].name[q - 1] = addi[m].molaqat[n].name[q], q++);
			addi[m].molaqat[n].name[addi[m].molaqat[n].strlenname] = '\0';
		}
		for (n = 1; n < addi[m].tedad; n++) {
			for (q = 1; addi[m].molaqat[n].last[q] != '\0'; addi[m].molaqat[n].last[q - 1] = addi[m].molaqat[n].last[q], q++);
			addi[m].molaqat[n].last[addi[m].molaqat[n].strlenlast] = '\0';
		}
		for (n = 1; n < addi[m].tedad; rooz(addi[m].molaqat[n].u, m, n, 2), n++);
		for (n = 1; n < addi[m].number; n++) {
			addi[m].places[n].kol /= 256;
			addi[m].places[n].year /= 256;
			addi[m].places[n].code /= 256;
			addi[m].places[n].day /= 256;
			addi[m].places[n].month /= 256;
			addi[m].places[n].tedad /= 256;
			addi[m].places[n].rahgiri /= 256;
			addi[m].places[n].u /= 256;
			addi[m].places[n].strlenname /= 256;
			addi[m].places[n].strlenlast /= 256;
			addi[m].places[n].strlencode /= 256;
		}
		for (n = 1; n < addi[m].number; n++) {
			for (q = 1; addi[m].places[n].codemelli[q] != '\0'; addi[m].places[n].codemelli[q - 1] = addi[m].places[n].codemelli[q], q++);
			addi[m].places[n].codemelli[addi[m].places[n].strlencode] = '\0';
		}
		for (n = 1; n < addi[m].number; n++) {
			for (q = 1; addi[m].places[n].name[q] != '\0'; addi[m].places[n].name[q - 1] = addi[m].places[n].name[q], q++);
			addi[m].places[n].name[addi[m].places[n].strlenname] = '\0';
		}
		for (n = 1; n < addi[m].number; n++) {
			for (q = 1; addi[m].places[n].last[q] != '\0'; addi[m].places[n].last[q - 1] = addi[m].places[n].last[q], q++);
			addi[m].places[n].last[addi[m].places[n].strlenlast] = '\0';
		}
		for (n = 1; n < addi[m].number; rooz(addi[m].places[n].u, m, n, 3), n++);
		for (n = 1; n < addi[m].shomare; n++) {
			addi[m].tests[n].kol /= 256;
			addi[m].tests[n].year /= 256;
			addi[m].tests[n].code /= 256;
			addi[m].tests[n].day /= 256;
			addi[m].tests[n].month /= 256;
			addi[m].tests[n].tedad /= 256;
			addi[m].tests[n].u /= 256;
			addi[m].tests[n].salamat /= 256;
			addi[m].tests[n].rahgiri /= 256;
		}
		for (n = 1; n < addi[m].shomare; rooz(addi[m].tests[n].u, m, n, 1), n++);
	}
	for (m = 1; m < number; m++) {
		fread(&job[m], sizeof(mashaqel), 1, matin);
		int code, rahgiri, area, tedad;
		job[m].code /= 256;
		job[m].rahgiri /= 256;
		job[m].area /= 256;
		job[m].tedad /= 256;
		for (q = 1; job[m].name[q] != '\0'; job[m].name[q - 1] = job[m].name[q], q++);
		job[m].name[q - 1] = '\0';
		for (q = 1; job[m].user[q] != '\0'; job[m].user[q - 1] = job[m].user[q], q++);
		job[m].user[q - 1] = '\0';
		for (q = 1; job[m].codemeli[q] != '\0'; job[m].codemeli[q - 1] = job[m].codemeli[q], q++);
		job[m].codemeli[q - 1] = '\0';
		for (q = 1; job[m].email[q] != '\0'; job[m].email[q - 1] = job[m].email[q], q++);
		job[m].email[q - 1] = '\0';
		for (q = 1; job[m].pass[q] != '\0'; job[m].pass[q - 1] = job[m].pass[q], q++);
		job[m].pass[q - 1] = '\0';
		for (q = 1; job[m].pass2[q] != '\0'; job[m].pass2[q - 1] = job[m].pass2[q], q++);
		job[m].pass2[q - 1] = '\0';
		for (q = 1; job[m].shname[q] != '\0'; job[m].shname[q - 1] = job[m].shname[q], q++);
		job[m].shname[q - 1] = '\0';
		for (q = 1; job[m].city[q] != '\0'; job[m].city[q - 1] = job[m].city[q], q++);
		job[m].city[q - 1] = '\0';
		vaziat(2, m);
		for (n = 1; n < job[m].tedad; n++) {
			job[m].moraje[n].kol /= 256;
			job[m].moraje[n].year /= 256;
			job[m].moraje[n].code /= 256;
			job[m].moraje[n].day /= 256;
			job[m].moraje[n].month /= 256;
			job[m].moraje[n].tedad /= 256;
			job[m].moraje[n].u /= 256;
			job[m].moraje[n].strlenname /= 256;
			job[m].moraje[n].strlenlast /= 256;
			job[m].moraje[n].strlencode /= 256;
		}
		for (n = 1; n < job[m].tedad; n++) {
			for (q = 1; job[m].moraje[n].codemelli[q] != '\0'; job[m].moraje[n].codemelli[q - 1] = job[m].moraje[n].codemelli[q], q++);
			job[m].moraje[n].codemelli[job[m].moraje[n].strlencode] = '\0';
		}
		for (n = 1; n < job[m].tedad; n++) {
			for (q = 1; job[m].moraje[n].last[q] != '\0'; job[m].moraje[n].last[q - 1] = job[m].moraje[n].last[q], q++);
			job[m].moraje[n].last[job[m].moraje[n].strlenlast] = '\0';
		}
		for (n = 1; n < job[m].tedad; n++) {
			for (q = 1; job[m].moraje[n].name[q] != '\0'; job[m].moraje[n].name[q - 1] = job[m].moraje[n].name[q], q++);
			job[m].moraje[n].name[job[m].moraje[n].strlenname] = '\0';
		}
	}
	fclose(matin);
	return;
}
void Exit() {
	int m;
	matin = fopen("matin.txt", "w");
	hospital = fopen("Hospitals.txt", "w");
	fprintf(hospital, "%d\n", num);
	fprintf(matin, "%d\n%d\n", number, shomare);
	for (m = 1; m < shomare; m++) {
		fwrite(&bimarestan[m], sizeof(bimaresta), 1, hospital);
	}
	for (m = 1; m < shomare; m++) {
		fwrite(&addi[m], sizeof(normal), 1, matin);
	}
	for (m = 1; m < number; m++) {
		fwrite(&job[m], sizeof(mashaqel), 1, matin);
	}
	fclose(matin);
	fclose(hospital);
	exit(0);
}
void tcode(int vared, int code) {
	findday(tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
	for (i = 0; i < addi[vared].tedad; i++) {
		if (count - addi[vared].molaqat[i].kol < 7) {
			if (code == 4) {
				if (addi[addi[vared].molaqat[i].rahgiri].code < 3) {
					addi[addi[vared].molaqat[i].rahgiri].code = 3;
					vaziat(1, addi[vared].molaqat[i].rahgiri);
					addi[addi[vared].molaqat[i].rahgiri].kol = count;
					tcode(addi[vared].molaqat[i].rahgiri, 3);
				}
			}
			if (code == 3) {
				if (addi[addi[vared].molaqat[i].rahgiri].code == 1) {
					addi[addi[vared].molaqat[i].rahgiri].code = 2;
					vaziat(1, addi[vared].molaqat[i].rahgiri);
					addi[addi[vared].molaqat[i].rahgiri].kol = count;
				}
			}
		}
	}
}
void alltest(int vared) {
	system("cls");
	setFontSize(20, 20);
	puts("                                                                                 History of Tests\n\n\n");
	int a = 1, c = 0;
	printf("   Row    National code            first name    last name              Date            Day              health condition        salamat      code\n\n");
	findday(tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
	if (addi[vared].shomare > 10) {
		for (; a < 10; c++) {
			for (i = addi[vared].shomare - 10; i < addi[vared].shomare && a < 10; i++) {
				if (count - addi[vared].tests[i].kol == c) {
					printf("   %d.     %s                   %s       %s                %d-%d-%d         %s              %s              %d            %d\n\n",
						a, addi[vared].codemeli, addi[vared].name, addi[vared].lastname, addi[vared].tests[i].day, addi[vared].tests[i].month,
						addi[vared].tests[i].year, addi[vared].tests[i].rooz, addi[vared].vaziat, addi[vared].tests[i].salamat, addi[vared].tests[i].code);
					a++;
				}
			}
		}
	}
	else {
		for (; a < addi[vared].shomare; c++) {
			for (i = 1; i < addi[vared].shomare && a < addi[vared].shomare; i++) {
				if (count - addi[vared].tests[i].kol == c) {
					printf("   %d.     %s                   %s       %s                %d-%d-%d         %s              %s              %d            %d\n\n",
						a, addi[vared].codemeli, addi[vared].name, addi[vared].lastname, addi[vared].tests[i].day, addi[vared].tests[i].month,
						addi[vared].tests[i].year, addi[vared].tests[i].rooz, addi[vared].vaziat, addi[vared].tests[i].salamat, addi[vared].tests[i].code);
					a++;
				}
			}
		}
	}
	printf("  1.menu\n");
	scanf("%s", macan);
	x = getchar();
	if (strcmp(macan, "1") == 0 || strcmp(macan, "menu") == 0)
		menu();
}
void hismeet(int vared) {
	system("cls");
	setFontSize(18, 18);
	puts("                                                          History of Meeting\n\n\n");
	int a = 1, c = 0;
	printf("   Row    National code              first name    last name                  Date            Day              code\n\n");
	findday(tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
	if (addi[vared].tedad >= 10) {
		for (; a < 10; c++) {
			for (i = addi[vared].tedad - 10; i < addi[vared].tedad && a < 10; i++) {
				if (count - addi[vared].molaqat[i].kol == c) {
					printf("   %d.     %s              %s      %s                    %d-%d-%d            %s                %d\n\n",
						a, addi[vared].molaqat[i].codemelli, addi[vared].molaqat[i].name, addi[vared].molaqat[i].last, addi[vared].molaqat[i].day,
						addi[vared].molaqat[i].month, addi[vared].molaqat[i].year, addi[vared].molaqat[i].rooz, addi[vared].molaqat[i].code);
					a++;
				}
			}
		}
	}
	else {
		for (; a < addi[vared].tedad; c++) {
			for (i = 1; i < addi[vared].tedad && a < addi[vared].tedad; i++) {
				if (count - addi[vared].molaqat[i].kol == c) {
					printf("   %d.     %s              %s      %s                    %d-%d-%d            %s                %d\n\n",
						a, addi[vared].molaqat[i].codemelli, addi[vared].molaqat[i].name, addi[vared].molaqat[i].last, addi[vared].molaqat[i].day,
						addi[vared].molaqat[i].month, addi[vared].molaqat[i].year, addi[vared].molaqat[i].rooz, addi[vared].molaqat[i].code);
					a++;
				}
			}
		}
	}
	printf("  1.menu\n");
	scanf("%s", macan);
	x = getchar();
	if (strcmp(macan, "1") == 0 || strcmp(macan, "menu") == 0)
		menu();
}
void amar() {
	system("cls");
	setFontSize(18, 18);
	int a = 1;
	puts("                                                          Infected statistics\n\n\n");
	printf("   1. today\n");
	printf("   2. last week\n\n");
	x = getch();
	for (i = 0; i < 5; i++) {
		fputs("\033[A\033[2K", stdout);
		rewind(stdout);
	}
	printf("   Row    National code              firt name  last name                  Date of infection            Day\n\n");
	findday(tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
	for (i = 1; i < shomare; i++) {
		if (x == '2') {
			if (count - addi[i].kol < 8 && addi[i].code == 4) {
				printf("   %d.     %s              %s   %s                   %d-%d-%d            %s\n\n",
					a, addi[i].codemeli, addi[i].name, addi[i].lastname, addi[i].day, addi[i].month, addi[i].year, addi[i].rooz);
				a++;
			}
		}
		else {
			if (count == addi[i].kol && addi[i].code == 4) {
				printf("   %d.     %s              %s   %s                   %d-%d-%d            %s\n\n",
					a, addi[i].codemeli, addi[i].name, addi[i].lastname, addi[i].day, addi[i].month, addi[i].year, addi[i].rooz);
				a++;
			}
		}
	}
	printf("  1.menu\n");
	scanf("%s", macan);
	x = getchar();
	if (strcmp(macan, "1") == 0 || strcmp(macan, "menu") == 0)
		menu();
}
void hisplace(int vared) {
	system("cls");
	setFontSize(18, 18);
	puts("                                                          History of places\n\n\n");
	int a = 1, b = 1, c = 0;
	printf("   Row    National code               name of place                  Date            Day                health condition\n\n");
	findday(tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
	b = count;
	if (addi[vared].number >= 10) {
		for (; a < 10; c++) {
			for (i = addi[vared].number - 10; i < addi[vared].number && a < 10; i++) {
				if (count - addi[vared].places[i].kol == c) {
					printf("   %d.     %s              %s                     %d-%d-%d            %s                 %s\n\n",
						a, addi[vared].places[i].codemelli, addi[vared].places[i].name, addi[vared].places[i].day,
						addi[vared].places[i].month, addi[vared].places[i].year, addi[vared].places[i].rooz, job[vared].vaziat);
					a++;
				}
			}
		}
	}
	else {
		for (; a < addi[vared].number; c++) {
			for (i = 1; i < addi[vared].number && a < addi[vared].number; i++) {
				if (count - addi[vared].places[i].kol == c) {
					printf("   %d.     %s              %s                     %d-%d-%d            %s                  %s\n\n",
						a, addi[vared].places[i].codemelli, addi[vared].places[i].name, addi[vared].places[i].day,
						addi[vared].places[i].month, addi[vared].places[i].year, addi[vared].places[i].rooz, job[vared].vaziat);
					a++;
				}
			}
		}
	}
	printf("  1.menu\n");
	scanf("%s", macan);
	x = getchar();
	if (strcmp(macan, "1") == 0 || strcmp(macan, "menu") == 0)
		menu();
}
void addplace(int vared) {
	system("cls");
	system("COLOR C0");
	char  name2[20];
	int d, m, y;
	printf("\n\n          please enter the name of place: ");
	gets_s(name2);
	printf("\n\n          Date: ");
	scanf("%d%d%d", &d, &m, &y);
	x = getchar();
	for (i = 1, h = 1; i < number; i++) {
		if (strcmp(name2, job[i].shname) == 0) {
			if (addi[vared].code > 1) {
				job[i].moraje[job[i].tedad].year = y;
				job[i].moraje[job[i].tedad].month = m;
				job[i].moraje[job[i].tedad].day = d;
				strcpy(job[i].moraje[job[i].tedad].codemelli, addi[vared].codemeli);
				job[i].moraje[job[i].tedad].strlencode = strlen(job[i].moraje[job[i].tedad].codemelli);
				strcpy(job[i].moraje[job[i].tedad].last, addi[vared].lastname);
				job[i].moraje[job[i].tedad].strlenlast = strlen(job[i].moraje[job[i].tedad].last);
				strcpy(job[i].moraje[job[i].tedad].name, addi[vared].name);
				job[i].moraje[job[i].tedad].strlenname = strlen(job[i].moraje[job[i].tedad].name);
				findday(d, m, y);
				rooz(b, vared, job[vared].tedad, 5);
				job[vared].moraje[job[vared].tedad].u = b;
				job[i].moraje[job[i].tedad].code = addi[vared].code;
				job[i].moraje[job[i].tedad].tedad = job[i].tedad;
				job[i].moraje[job[i].tedad].rahgiri = vared;
				job[i].moraje[job[i].tedad].kol = count;
				job[i].tedad++;
			}
			addi[vared].places[addi[vared].number].year = y;
			addi[vared].places[addi[vared].number].month = m;
			addi[vared].places[addi[vared].number].day = d;
			strcpy(addi[vared].places[addi[vared].number].codemelli, job[i].codemeli);
			addi[vared].places[addi[vared].number].strlencode = strlen(addi[vared].places[addi[vared].number].codemelli);
			strcpy(addi[vared].places[addi[vared].number].name, job[i].name);
			addi[vared].places[addi[vared].number].strlenname = strlen(addi[vared].places[addi[vared].number].name);
			strcpy(addi[vared].places[addi[vared].number].last, job[i].shname);
			addi[vared].places[addi[vared].number].strlenlast = strlen(addi[vared].places[addi[vared].number].last);
			rooz(b, vared, addi[vared].number, 3);
			addi[vared].places[addi[vared].number].u = b;
			addi[vared].places[addi[vared].number].code = job[i].code;
			addi[vared].places[addi[vared].number].tedad = addi[vared].number;
			addi[vared].places[addi[vared].number].rahgiri = i;
			addi[vared].places[addi[vared].number].kol = count;
			addi[vared].number++;
			h = 0;
			break;
		}
	}
	j = count;
	findday(tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
	if (h == 0) {
		printf(ANSI_COLOR_GREEN"\n\n            Location added successfully\n\n\n");
		if (count - j < 8 && addi[vared].code == 4 && job[i].code == 1 && count>job[i].kol) {
			job[i].code = 2;
			job[i].kol = count;
			vaziat(2, i);
		}
	}
	else
		printf(ANSI_COLOR_RED"\n\n             Sorry, this location could not be found\n\n\n");
	printf(ANSI_COLOR_MAGENTA"  1.menu\n");
	scanf("%s", macan);
	x = getchar();
	if (strcmp(macan, "1") == 0 || strcmp(macan, "menu") == 0)
		menu();
}
void molaqat(int vared) {
	system("cls");
	system("COLOR C0");
	setFontSize(30, 30);
	char codemeli2[30];
	int d, m, y;
	printf("                                          Meeting log page\n\n");
	printf("\n\n       Please enter the national code of the person you met: ");
	scanf("%s", codemeli2);
	printf("\n\n       Date: ");
	scanf("%d%d%d", &d, &m, &y);
	x = getchar();
	for (i = 1, b = 1; i < shomare; i++) {
		if (i == vared)
			continue;
		if (strcmp(codemeli2, addi[i].codemeli) == 0) {
			addi[i].molaqat[addi[i].tedad].year = y;
			addi[i].molaqat[addi[i].tedad].month = m;
			addi[i].molaqat[addi[i].tedad].day = d;
			strcpy(addi[i].molaqat[addi[i].tedad].codemelli, addi[vared].codemeli);
			addi[i].molaqat[addi[i].tedad].strlencode = strlen(addi[i].molaqat[addi[i].tedad].codemelli);
			strcpy(addi[i].molaqat[addi[i].tedad].last, addi[vared].lastname);
			addi[i].molaqat[addi[i].tedad].strlenlast = strlen(addi[i].molaqat[addi[i].tedad].last);
			strcpy(addi[i].molaqat[addi[i].tedad].name, addi[vared].name);
			addi[i].molaqat[addi[i].tedad].strlenname = strlen(addi[i].molaqat[addi[i].tedad].name);
			findday(d, m, y);
			addi[i].molaqat[addi[i].tedad].u = b;
			rooz(b, vared, addi[vared].tedad, 2);
			addi[i].molaqat[addi[i].tedad].code = addi[vared].code;
			addi[i].molaqat[addi[i].tedad].tedad = addi[i].tedad;
			addi[i].molaqat[addi[i].tedad].kol = count;
			addi[i].molaqat[addi[i].tedad].rahgiri = vared;
			addi[i].tedad++;
			addi[vared].molaqat[addi[vared].tedad].year = y;
			addi[vared].molaqat[addi[vared].tedad].month = m;
			addi[vared].molaqat[addi[vared].tedad].day = d;
			strcpy(addi[vared].molaqat[addi[vared].tedad].codemelli, addi[i].codemeli);
			addi[vared].molaqat[addi[vared].tedad].strlencode = strlen(addi[vared].molaqat[addi[vared].tedad].codemelli);
			strcpy(addi[vared].molaqat[addi[vared].tedad].last, addi[i].lastname);
			addi[vared].molaqat[addi[vared].tedad].strlenlast = strlen(addi[vared].molaqat[addi[vared].tedad].last);
			strcpy(addi[vared].molaqat[addi[vared].tedad].name, addi[i].name);
			addi[vared].molaqat[addi[vared].tedad].strlenname = strlen(addi[vared].molaqat[addi[vared].tedad].name);
			addi[vared].molaqat[addi[vared].tedad].u = b;
			rooz(b, vared, addi[vared].tedad, 2);
			addi[vared].molaqat[addi[vared].tedad].code = addi[i].code;
			addi[vared].molaqat[addi[vared].tedad].tedad = addi[vared].tedad;
			addi[vared].molaqat[addi[vared].tedad].kol = count;
			addi[vared].molaqat[addi[vared].tedad].rahgiri = i;
			addi[vared].tedad++;
			b = 0;
			break;
		}
	}
	if (b != 0)
		puts(ANSI_COLOR_RED"\n\n             Unfortunately, there is no user with the code entered in the system.\n\n");
	else {
		puts(ANSI_COLOR_GREEN"\n\n             Your appointment has been successfully registered.\n\n");
		j = count;
		findday(tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
		if (count - j < 8) {
			if (addi[i].code < 3 && addi[vared].code == 4) {
				addi[i].code = 3;
				addi[i].kol = count;
				h = i;
				tcode(h, 3);
				vaziat(1, h);
			}
			else if (addi[vared].code < 3 && addi[i].code == 4) {
				addi[vared].code = 3;
				addi[vared].kol = count;
				h = vared;
				tcode(h, 3);
				vaziat(1, h);
			}
			else if (addi[i].code == 3 && addi[vared].code == 1) {
				addi[vared].code = 2;
				addi[vared].kol = count;
				vaziat(1, vared);
			}
			else if (addi[vared].code == 3 && addi[i].code == 1) {
				addi[i].code = 2;
				addi[i].kol = count;
				vaziat(1, i);
			}
		}
	}
	printf(ANSI_COLOR_MAGENTA"  1.menu\n");
	scanf("%s", macan);
	x = getchar();
	if (strcmp(macan, "1") == 0 || strcmp(macan, "menu") == 0)
		menu();
}
void hospitals() {
	system("cls");
	setFontSize(25, 25);
	printf("     inter the hospital name:  ");
	gets_s(bimarestan[num].name);
	printf("\n\n");
	printf("     inter the hospital city:  ");
	gets_s(bimarestan[num].city);
	printf("\n\n");
	printf("     inter the hospital mantaqe:  ");
	scanf("%d", &bimarestan[num].mantaghe);
	x = getchar();
	printf("\n\n");
	printf("     inter the hospital Adress:  ");
	gets_s(bimarestan[num].addres);
	num++;
	printf("\n\n");
	printf("                                               the hospitall added succesfully\n\n\n");
	printf("  1.menu             2.Add hospital\n");
	scanf("%s", macan);
	x = getchar();
	if (strcmp(macan, "1") == 0 || strcmp(macan, "menu") == 0)
		menu3();
	else
		hospitals();
}
void pas(int type, int rahgiri) {
	setFontSize(20, 20);
	if (type == 1) {
		printf("                                                      Password: ");
		for (i = 0, x = 0; x != 10; i++) {
			addi[rahgiri].pass[i] = getch();
			if (addi[rahgiri].pass[i] == '\r') {
				printf(" \b\n");
				break;
			}
			if (addi[rahgiri].pass[i] != 8)
				printf(" \b*");
			else {
				printf("\b \b");
				addi[rahgiri].pass[i - 1] = '\0';
				i -= 2;
			}
		}
		addi[rahgiri].pass[i] = '\0';
		while (i < 3) {
			printf("     each field must have at least 3 characters\n");
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			printf("                                                      Password: ");
			for (i = 0, x = 0; x != 10; i++) {
				addi[rahgiri].pass[i] = getch();
				if (addi[rahgiri].pass[i] == '\r') {
					printf(" \b\n");
					break;
				}
				if (addi[rahgiri].pass[i] != 8)
					printf(" \b*");
				else {
					printf("\b \b");
					addi[rahgiri].pass[i - 1] = '\0';
					i -= 2;
				}
			}
			addi[rahgiri].pass[i] = '\0';
		}
		printf("\n");
		printf("                                                      Password(repeat): ");
		for (i = 0, x = 0; x != 10; i++) {
			pass[i] = getch();
			if (pass[i] == '\r') {
				printf(" \b\n");
				break;
			}
			if (pass[i] != 8)
				printf(" \b*");
			else {
				printf("\b \b");
				pass[i - 1] = '\0';
				i -= 2;
			}
		}
		pass[i] = '\0';
		while (i < 3) {
			printf("     each field must have at least 3 characters\n");
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			printf("                                                      Password(repeat): ");
			for (i = 0, x = 0; x != 10; i++) {
				pass[i] = getch();
				if (pass[i] == '\r') {
					printf(" \b\n");
					break;
				}
				if (pass[i] != 8)
					printf(" \b*");
				else {
					printf("\b \b");
					pass[i - 1] = '\0';
					i -= 2;
				}
			}
			pass[i] = '\0';
		}
		printf("\n");
	}
	else {
		printf("                                            Password: ");
		for (i = 0, x = 0; x != 10; i++) {
			job[rahgiri].pass[i] = getch();
			if (job[rahgiri].pass[i] == '\r') {
				printf(" \b\n");
				break;
			}
			if (job[rahgiri].pass[i] != 8)
				printf(" \b*");
			else {
				printf("\b \b");
				job[rahgiri].pass[i - 1] = '\0';
				i -= 2;
			}
		}
		job[rahgiri].pass[i] = '\0';
		while (i < 3) {
			printf("     each field must have at least 3 characters\n");
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			printf("                                            Password: ");
			for (i = 0, x = 0; x != 10; i++) {
				job[rahgiri].pass[i] = getch();
				if (job[rahgiri].pass[i] == '\r') {
					printf(" \b\n");
					break;
				}
				if (job[rahgiri].pass[i] != 8)
					printf(" \b*");
				else {
					printf("\b \b");
					job[rahgiri].pass[i - 1] = '\0';
					i -= 2;
				}
			}
			job[rahgiri].pass[i] = '\0';
		}
		printf("\n");
		printf("                                            Password(repeat): ");
		for (i = 0, x = 0; x != 10; i++) {
			job[rahgiri].pass2[i] = getch();
			if (job[rahgiri].pass2[i] == '\r') {
				printf(" \b\n");
				break;
			}
			if (job[rahgiri].pass2[i] != 8)
				printf(" \b*");
			else {
				printf("\b \b");
				job[rahgiri].pass2[i - 1] = '\0';
				i -= 2;
			}
		}
		job[rahgiri].pass2[i] = '\0';
		while (i < 3) {
			printf("     each field must have at least 3 characters\n");
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			printf("                                            Password(repeat): ");
			for (i = 0, x = 0; x != 10; i++) {
				job[rahgiri].pass2[i] = getch();
				if (job[rahgiri].pass2[i] == '\r') {
					printf(" \b\n");
					break;
				}
				if (job[rahgiri].pass2[i] != 8)
					printf(" \b*");
				else {
					printf("\b \b");
					job[rahgiri].pass2[i - 1] = '\0';
					i -= 2;
				}
			}
			job[rahgiri].pass2[i] = '\0';
		}
		printf("\n");
	}
	if (type == 1) {
		while (strcmp(addi[rahgiri].pass, pass) != 0) {
			printf("    ERROR:Repetition is not equal to the principle. \n");
			Sleep(2000);
			for (i = 5; i > 0; i--) {
				fputs("\033[A\033[2K", stdout);
				rewind(stdout);
			}
			pas(type, rahgiri);
		}
	}
	else {
		while (strcmp(job[rahgiri].pass, job[rahgiri].pass2) != 0) {
			printf("     ERROR:Repetition is not equal to the principle. \n");
			Sleep(2000);
			for (i = 5; i > 0; i--) {
				fputs("\033[A\033[2K", stdout);
				rewind(stdout);
			}
			pas(type, rahgiri);
		}
	}
}
void tips() {
	system("cls");
	setFontSize(25, 25);
	printf("      1.Wash your hands regularly\n\n\n");
	printf("      2.Keep a (safe) distance in communities\n\n\n");
	printf("      3.Do not touch your eyes, nose or mouth\n\n\n");
	printf("      4.Maintain respiratory hygiene\n\n\n");
	printf("      5.Seek medical attention as soon as possible if you have a fever, cough, or shortness of breath\n\n\n");
	printf("      6.Be aware of the situation and follow the recommendations of health care providers\n\n\n");
	printf("      7.Precautions are taken for people who live in the area where Covid-19 is being distributed or who have recently\n");
	printf("        (in the last 14 days) traveled to these areas\n\n\n");
	printf("      8.If you feel sick, even at home with mild symptoms such as headaches and runny nose, stay home until you recover\n\n");
	printf("  1.menu\n");
	scanf("%s", macan);
	x = getchar();
	if (strcmp(macan, "1") == 0 || strcmp(macan, "menu") == 0)
		menu();
}
void contact() {
	system("cls");
	setFontSize(25, 25);
	printf("\n\n");
	printf("                                           Phone number: 09215546251 -  09133635723\n\n\n");
	printf("                                                 Email: m.matin.r.81@gmail.com\n\n\n");
	printf("                                                    Telegram ID: M_MATIN_R\n\n\n");
	printf("                                                    GitHub ID: Matinrezaei\n\n\n");
	printf("                                             any copyof the program is prosecuted\n\n");
	printf("  1.menu\n");
	scanf("%s", macan);
	x = getchar();
	if (strcmp(macan, "1") == 0 || strcmp(macan, "menu") == 0)
		menu();
}
void test(int vared) {
	system("cls");
	setFontSize(25, 25);
	addi[vared].salamat = 0;
	printf("                          Answer the questions with 1.yes or 2.no\n\n");
	printf("  Dry cough in large numbers?(30 percent):  \n\n");
	x = getch();
	if (x == '1')
		addi[vared].salamat += 30;
	printf("  Fever above 37 degrees?(20 percent)  \n\n");
	x = getch();
	if (x == '1')
		addi[vared].salamat += 20;
	printf("  Shortness of breath?(20 percent)  \n\n");
	x = getch();
	if (x == '1')
		addi[vared].salamat += 20;
	printf("  pain and bruising?(15 percent)  \n\n");
	x = getch();
	if (x == '1')
		addi[vared].salamat += 15;
	printf("  Sore throat?(15 percent)  \n\n");
	x = getch();
	if (x == '1')
		addi[vared].salamat += 15;
	if (addi[vared].salamat <= 15) {
		printf("              Congratulations, Your are Healthy                    you should keep taking care of yourself\n\n");
		i = 1;
	}
	if (addi[vared].salamat > 15 && addi[vared].salamat <= 50) {
		printf("              be careful, you are suspicious                    Stay at Home and wear Mask\n\n");
		i = 2;
	}
	if (addi[vared].salamat > 50 && addi[vared].salamat <= 75) {
		printf("              you are dangerous                    you shold see a doctor\n\n");
		i = 3;
	}
	if (addi[vared].salamat > 75) {
		printf("              Unfortunatelly, you have the corona virus                   you have to see a doctor immediately.\n\n");
		i = 4;
	}
	printf("                                       disease %d percent\n\n\n", addi[vared].salamat);
	printf("                                       1.menu        2.test again\n\n");
	scanf("%s", macan);
	x = getchar();
	count = i;
	if (strcmp(macan, "1") == 0 || strcmp(macan, "menu") == 0) {
		if (i > addi[vared].code) {
			addi[vared].code = i;
			vaziat(1, vared);
			addi[vared].year = tm->tm_year + 1900;
			addi[vared].month = tm->tm_mon + 1;
			addi[vared].day = tm->tm_mday;
			findday(addi[vared].day, addi[vared].month, addi[vared].year);
			rooz(b, vared, 0, 4);
			addi[vared].tests[addi[vared].shomare].u = b;
			addi[vared].kol = count;
			if (i > 2)
				tcode(vared, i);
			if (i == 4) {
				for (i = 1; i < addi[vared].number; i++) {
					if (job[addi[vared].places[i].rahgiri].code == 1) {
						job[addi[vared].places[i].rahgiri].code == 2;
						job[addi[vared].places[i].rahgiri].kol = count;
						vaziat(2, 2);
					}
				}
			}
		}
		addi[vared].tests[addi[vared].shomare].code = count;
		addi[vared].tests[addi[vared].shomare].year = tm->tm_year + 1900;
		addi[vared].tests[addi[vared].shomare].month = tm->tm_mon + 1;
		addi[vared].tests[addi[vared].shomare].day = tm->tm_mday;
		findday(addi[vared].tests[addi[vared].shomare].day,
			addi[vared].tests[addi[vared].shomare].month, addi[vared].tests[addi[vared].shomare].year);
		addi[vared].tests[addi[vared].shomare].u = b;
		rooz(b, vared, addi[vared].shomare, 1);
		addi[vared].tests[addi[vared].shomare].salamat = addi[vared].salamat;
		addi[vared].tests[addi[vared].shomare].code = i;
		addi[vared].tests[addi[vared].shomare].kol = count;
		addi[vared].shomare++;
		menu();
	}
	else
		test(vared);
}
int welcome() {
	system("cls");
	setFontSize(22, 22);
	system("COLOR F0");
	printf("                                                    Hi welcome to Matin anti virus\n\n\n");
	printf("                                                         YOU NEVER WALK ALONE\n\n\n\n");
	printf("                              *  *                                 *                                  *  *\n");
	printf("                             *     *                              * *                               *      *\n");
	printf("                            *       ******************************   *******************************        *\n");
	printf("                            *        ***************************************************************        *\n");
	printf("                             *        *************************************************************        *\n");
	printf("                              *       *************************************************************       *\n");
	printf("                                *    ***************************************************************    *\n");
	printf("                                 *  *****************************************************************  *\n\n\n");
	printf("                             Matin anti virus: a specialized and comprehensive program that guids coronary patients.\n\n\n\n\n");
	printf("                                                        developer: Matin Rezaei\n\n");
	//Sleep(6000);
	printf("                                                        1.Sign in        2.Sign up\n\n");
	printf("                                                            3.Forgot password?\n\n");
	printf("                                                                 0.exit\n");
	x = getch();
	if (x == '1')
		return login();
	if (x == '2')
		return logup(0, 0);
	if (x == '3')
		return forgot();
	if (x == '0')
		Exit();
}
int forgot() {
	system("cls");
	system("COLOR F0");
	setFontSize(20, 20);
	char email2[30], codemeli2[30], name2[10], username[15];
	system("COLOR F0");
	printf("                                            Email(optional): ");
	fgets(email2, sizeof(email2), stdin);
	printf("\n\n");
	printf("                                            Username: ");
	fgets(username, sizeof(username), stdin);
	printf("\n\n");
	printf("The national code must have 10 digits.      Natinal code: ");
	fgets(codemeli2, sizeof(codemeli2), stdin);
	printf("\n\n");
	for (i = 1; i < number; i++) {
		if (strcmp(email2, job[i].email) == 0 && strcmp(username, job[i].user) == 0 && strcmp(codemeli2, job[i].codemeli) == 0) {
			pas(2, i);
			Sleep(3000);
			return login();
		}
	}
	for (i = 1; i < shomare; i++) {
		if (strcmp(email2, addi[i].email) == 0 && strcmp(username, addi[i].user) == 0 && strcmp(codemeli2, addi[i].codemeli) == 0) {
			pas(1, i);
			Sleep(3000);
			return login();
		}
	}
	printf("                               national cod , username and email do not match\n\n");
	printf("   1.Try again\n\n");
	printf("   2.login\n\n");
	printf("   0.exit\n\n");
	scanf("%d", &i);
	x = getchar();
	if (i == 1)
		return forgot();
	if (i == 0)
		Exit();
	if (i == 2)
		return login();
}
int logup(int type, int kind) {
	system("cls");
	system("COLOR F0");
	setFontSize(20, 20);
	if (type == 0) {
		printf(" 1.normal user\n");
		printf(" 2.business owner\n");
		x = getch();
		fputs("\033[A\033[2K", stdout);
		rewind(stdout);
		fputs("\033[A\033[2K", stdout);
		rewind(stdout);
		if (x == '1')
			type = shomare;
		else
			type = number;
	}
	else
		x = kind + 48;
	if (x == '2') {
		printf("                                                  please fill in the fields below carefully\n\n");
		printf("                                                  each field must have at least 3 characters\n\n");
		printf("                                                      name: ");
		gets_s(job[type].name);
		while (strlen(job[type].name) < 3) {
			printf("    each field must have at least 3 characters\n");
			Sleep(2000);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			printf("                                                      name: ");
			gets_s(job[number].name);
		}
		printf("\n");
		printf("The national code must have 10 digits.                Natinal code: ");
		gets_s(job[type].codemeli);
		for (i = 0, count = 0; i < strlen(job[type].codemeli) - 1; i++) {
			if (job[number].codemeli[i] < 48 || job[number].codemeli[i]>57) {
				count++;
				break;
			}
		}
		while (strlen(job[type].codemeli) != 10 || count == 1) {
			printf("        ERROR: your national code is either not 10 digits or not all characters are numbers.\n");
			Sleep(2000);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			printf("The national code must have 10 digits.                Natinal code: ");
			gets_s(job[number].codemeli);
			for (i = 0, count = 0; i < strlen(job[number].codemeli) - 1; i++) {
				if (job[number].codemeli[i] < 48 || job[number].codemeli[i]>57) {
					count++;
					break;
				}
			}
		}
		printf("\n");
		printf("                                                      Username: ");
		gets_s(job[type].user);
		while (strlen(job[type].user) < 3) {
			printf("    each field must have at least 3 characters\n");
			Sleep(2000);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			printf("                                                      Username: ");
			gets_s(job[number].user);
		}
		printf("\n");
		pas(2, type);
		printf("                                                      Email(optional): ");
		gets_s(job[type].email);
		while (strlen(job[type].email) < 3) {
			printf("    each field must have at least 3 characters\n");
			Sleep(2000);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			printf("                                            Email(optional): ");
			gets_s(job[type].email);
		}
		printf("\n");
		printf("                                                      city: ");
		gets_s(job[type].city);
		printf("\n");
		printf("                                                      shop name: ");
		gets_s(job[type].shname);
		printf("\n");
		printf("                                                      area in city: ");
		scanf("%d", &job[type].area);
		x = getchar();
		if (type == number) {
			job[number].code = 1;
			vaziat(2, type);
			job[number].tedad = 1;
			job[number].rahgiri = number;
			number++;
		}
	}
	if (x == '1') {
		printf("                                                  please fill in the fields below carefully\n");
		printf("                                                  each field must have at least 3 characters\n\n");
		printf("                                                      Firs name: ");
		gets_s(addi[type].name);
		while (strlen(addi[type].name) < 3) {
			printf("    each field must have at least 3 characters\n");
			Sleep(2000);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			printf("                                                      Firs name: ");
			fgets(addi[type].name, 20, stdin);
		}
		printf("\n");
		printf("                                                      Last name: ");
		gets_s(addi[type].lastname);
		while (strlen(addi[type].lastname) < 3) {
			printf("    each field must have at least 3 characters\n");
			Sleep(2000);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			printf("                                                      Last name: ");
			gets_s(addi[type].lastname);
		}
		count = strlen(addi[type].lastname);
		printf("\n");
		printf("The national code must have 10 digits.                Natinal code: ");
		gets_s(addi[type].codemeli);
		for (i = 0, count = 0; i < strlen(addi[type].codemeli) - 1; i++) {
			if (addi[type].codemeli[i] < 48 || addi[type].codemeli[i]>57) {
				count++;
				break;
			}
		}
		while (strlen(addi[type].codemeli) != 10 || count == 1) {
			printf("          ERROR: your national code is either not 10 digits or not all characters are numbers.\n");
			Sleep(2000);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			printf("The national code must have 10 digits.                Natinal code: ");
			gets_s(addi[type].codemeli);
			for (i = 0, count = 0; i < strlen(addi[type].codemeli) - 1; i++) {
				if (addi[type].codemeli[i] < 48 || addi[type].codemeli[i]>57) {
					count++;
					break;
				}
			}
		}
		printf("\n");
		printf("                                                      Username: ");
		gets_s(addi[type].user);
		while (strlen(addi[type].user) < 3) {
			printf("    each field must have at least 3 characters\n");
			Sleep(2000);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			printf("                                                      Username: ");
			gets_s(addi[type].user);
		}
		printf("\n");
		pas(1, type);
		printf("                                                      Email(optional): ");
		gets_s(addi[type].email);
		while (strlen(addi[type].email) < 3) {
			printf("    each field must have at least 3 characters\n");
			Sleep(2000);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			fputs("\033[A\033[2K", stdout);
			rewind(stdout);
			printf("                                                      Email(optional): ");
			gets_s(addi[type].email);
		}
		printf("\n");
		printf("                                                      Blood type(optional): ");
		gets_s(addi[type].blood);
		printf("\n");
		printf("                                                      Age(optional): ");
		scanf("%d", &addi[type].age);
		x = getchar();
		printf("\n");
		printf("                                                      Height(meter)(optional): ");
		scanf("%f", &addi[type].size);
		x = getchar();
		printf("\n");
		printf("                                                      weight(optional): ");
		scanf("%f", &addi[type].weight);
		x = getchar();
		if (type == shomare) {
			addi[type].code = 1;
			vaziat(1, type);
			addi[type].salamat = 0;
			addi[type].number = 1;
			addi[type].shomare = 1;
			addi[type].rahgiri = shomare;
			addi[type].tedad = 1;
			shomare++;
		}
	}
	if (kind == 1) {
		printf("                     The change was saved successfully");
		Sleep(3000);
		menu();
	}
	else if (kind == 2) {
		printf("                     The change was saved successfully");
		Sleep(3000);
		menu2();
	}
	else {
		printf("  1.sign in\n");
		printf("  0.exit\n");
		x = getch();
		if (x == '0')
			Exit();
		if (x == '1')
			return login();
	}
}
int login() {
	system("cls");
	setFontSize(30, 30);
	char username[30], password[30];
	printf("\n\n");
	printf("                                       Username: ");
	gets_s(username);
	printf("\n\n");
	printf("                                       Password: ");
	for (i = 0, x = 0; x != 10; i++) {
		password[i] = getch();
		if (password[i] == '\r') {
			printf(" \b\n");
			break;
		}
		if (password[i] != 8)
			printf(" \b*");
		else {
			printf("\b \b");
			password[i - 1] = '\0';
			i -= 2;
		}
	}
	password[i] = '\0';
	if (strcmp(passad, password) == 0 && strcmp(username, userad) == 0) {
		vorood = -1;
		printf("\n\n\n\n\n                                   You are signing as Admin\n");
		Sleep(3000);
		return menu3();
	}
	for (i = 1; i < shomare; i++) {
		if (strcmp(addi[i].pass, password) == 0 && strcmp(username, addi[i].user) == 0) {
			vorood = i;
			printf("\n\n\n\n\n                               You are signing as Normal user\n");
			Sleep(3000);
			return menu();
		}
	}
	for (i = 0; i < number; i++) {
		if (strcmp(job[i].pass, password) == 0 && strcmp(username, job[i].user) == 0) {
			vorood = i;
			printf("\n\n\n\n\n                                     You are signing as Business owner\n");
			Sleep(3000);
			return menu2();
		}
	}
	printf("\n\n\n\n\n                             username or password is incorrect\n\n");
	printf("  3.Lock\n\n");
	printf("  4.Try again\n\n");
	printf("  5.forget password\n\n");
	printf("  0.exit\n\n");
	x = getch();
	if (x == '3')
		return welcome();
	if (x == '4')
		return login();
	if (x == '0')
		Exit();
	if (x == '5')
		return forgot();
}
int menu() {
	system("cls");
	system("COLOR C0");
	setFontSize(25, 25);
	printf("                                                  Matin anti virus\n\n");
	printf("  %s %s    code: %d         %s       disease: %d percent \n\n\n", addi[vorood].name,
		addi[vorood].lastname, addi[vorood].code, addi[vorood].vaziat, addi[vorood].salamat);
	printf("  1.health condition(corona test)                   2.Health Tips\n\n\n");
	printf("  3.Contact us                                      4.Edit information\n\n\n");
	printf("  5.Meeting appointment                             6.History of Meeting\n\n\n");
	printf("  7.Register places                                 8.History of places\n\n\n");
	printf("  9.Infected statistics                             10.Last 10 test\n\n\n");
	printf("                                11.Hospitals \n\n\n");
	printf("  12.lock                                           0.exit\n\n\n");
	scanf("%d", &i);
	x = getchar();
	if (i == 1)
		test(vorood);
	if (i == 2)
		tips();
	if (i == 3)
		contact();
	if (i == 4)
		logup(vorood, 1);
	if (i == 5)
		molaqat(vorood);
	if (i == 6)
		hismeet(vorood);
	if (i == 7)
		addplace(vorood);
	if (i == 8)
		hisplace(vorood);
	if (i == 9)
		amar();
	if (i == 10)
		alltest(vorood);
	if (i == 11)
		bimar();
	if (i == 12)
		return welcome();
	if (i == 0)
		Exit();
}
int menu2() {
	system("cls");
	system("COLOR 60");
	setFontSize(25, 25);
	printf("                   business page                       Matin anti virus\n\n\n");
	printf("  %s    %s    code: %d         %s         %s \n\n\n", job[vorood].name,
		job[vorood].shname, job[vorood].code, job[vorood].vaziat, job[vorood].city);
	printf("  1.See infected people                     2.Notice for disinfection\n\n\n");
	printf("  3.Edit information                        4.lock\n\n\n");
	printf("                           0.exit\n\n\n");
	x = getch();
	if (x == '1')
		see(vorood);
	if (x == '2')
		ofooni(vorood);
	if (x == '3')
		return logup(vorood, 2);
	if (x == '4')
		return welcome();
	if (x == '0')
		Exit();
}
int menu3() {
	system("cls");
	system("COLOR D7");
	setFontSize(25, 25);
	printf("                   Management page                     Matin anti virus\n\n\n");
	printf("  1.Add Hospitals                                    2.Show Hospitals\n\n\n");
	printf("  3.namayesh mobtalayan                              4.Deads\n\n\n");
	printf("  5.All Users Addi                                   6.All Users Mashaqel\n\n\n");
	printf("  7.lock                                             0.exit\n\n\n");
	x = getch();
	if (x == '1')
		hospitals();
	if (x == '2')
		showhospitals();
	if (x == '3')
		marizan();
	if (x == '4')
		deads();
	if (x == '5')
		all();
	if (x == '6')
		hamemashaqel();
	if (x == '7')
		return welcome();
	if (x == '0')
		Exit();
}
int main() {
	daryaft();
	taghircode();
	welcome();
}