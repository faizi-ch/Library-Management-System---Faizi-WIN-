#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <dos.h>
#include <time.h>

void TimeandDate();
void SetColor();
void ClearConsoleToColors();
void SetColorAndBackground();
void HeaderandBorders();
void HeaderandBordersPassword();
void clearWindow();
void Password();
void mainmenu();
void addbooks();
void deletebooks();
void searchbooks();
void issuebooks();
void issueabook();
void viewissued();
void searchissued();
void removeissued();
void viewbooks();
void editbooks();

int s;
FILE *fb, *ft, *fi;
char categories[][15] = { "Computer","Electronics","Electrical","Civil","Mechanical","Architecture" };
char password[10] = "faizi";

struct books
{
	int id;
	char name[30];
	char Author[30];
	int quantity;
	float Price;
	int rackno;
	char *cat;
	char stname[30];
};
struct books a;

void main()
{
	//mainmenu();
	Password();

	getchar();
}



void SetColor(int ForgC)
{
	WORD wColor;
	///We will need this handle to get the current background attribute
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	///We use csbi for the wAttributes word.
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		///Mask out all but the background attribute, and add in the forgournd color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}

void ClearConsoleToColors(int ForgC, int BackC)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	///Get the handle to the current output buffer...
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	///This is used to reset the carat/cursor to the top left.
	COORD coord = { 0, 0 };
	///A return value... indicating how many chars were written
	///   not used but we need to capture this since it will be
	///   written anyway (passing NULL causes an access violation).
	DWORD count;
	///This is a structure containing all of the console info
	/// it is used here to find the size of the console.
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	///Here we will set the current color
	SetConsoleTextAttribute(hStdOut, wColor);
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		///This fills the buffer with a given character (in this case 32=space).
		FillConsoleOutputCharacter(hStdOut, (TCHAR)32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		///This will set our cursor position for the next print statement.
		SetConsoleCursorPosition(hStdOut, coord);
	}
	return;
}

void SetColorAndBackground(int ForgC, int BackC)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
	return;
}

COORD coord = { 0, 0 }; // sets coordinates to 0,0
						//COORD max_buffer_size = GetLargestConsoleWindowSize(hOut);
COORD max_res, cursor_size;
void gotoxy(int x, int y)
{
	coord.X = x; coord.Y = y; // X and Y coordinates... "." is used as an access operator 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearWindow()
{
	int i, j;
	for (i = 56; i < 98; i++)
	{
		for (j = 9; j < 27; j++)
		{
			gotoxy(i, j);
			printf(" ");
		}
	}
	return;
}

void TimeandDate()
{
	time_t t;
	time(&t);
	printf(ctime(&t));
}
void HeaderandBorders()
{
	int i;
	ClearConsoleToColors(0, 15);
	gotoxy(20, 2);
	printf("%c", 201);
	for (i = 21; i < 98; i++) //length of upper line 
	{
		gotoxy(i, 2);
		printf("%c", 205);
	}
	gotoxy(98, 2);
	printf("%c", 187);
	for (i = 3; i < 27; i++) //length of right
	{ 
		gotoxy(98, i);
		if (i == 8)
		{
			printf("%c", 185);
		}
		else 
		{
			printf("%c", 186);
		}
	}
	gotoxy(98, 27);
	printf("%c", 188);
	for (i = 97; i > 20; i--) //length of below line
	{ 
		gotoxy(i, 27);
		if (i == 55) 
		{
			printf("%c", 202);
		}
		else 
		{
			printf("%c", 205);
		}
	}
	gotoxy(20, 27);
	printf("%c", 200);
	for (i = 26; i > 2; i--) //length of left
	{ 
		gotoxy(20, i);
		if (i == 8) 
		{
			printf("%c", 204);
		}
		else 
		{
			printf("%c", 186);
		}
	}

	for (i = 21; i < 98; i++) //length of mid horizontal
	{ 
		gotoxy(i, 8);
		if (i == 55) 
		{
			printf("%c", 203);
		}
		else 
		{
			printf("%c", 205);
		}
	}

	for (i = 9; i < 27; i++) 
	{
		gotoxy(55, i);
		printf("%c", 186);
	}
	gotoxy(46,4);
    SetColor(3);
    printf("LIBRARY MANAGEMENT SYSTEM");
    gotoxy(35,5);
    printf("COMSATS INSTITUTE OF INFORMATION TECHNOLOGY, WAH");
	gotoxy(47, 6);
	TimeandDate();
}
void HeaderandBordersPassword()
{
	ClearConsoleToColors(15, 0);
	int i;
	gotoxy(20, 2);
	printf("%c", 201);
	for (i = 21; i < 98; i++) //length of upper line
	{
		gotoxy(i, 2);
		printf("%c", 205);
	}
	gotoxy(98, 2);
	printf("%c", 187);
	for (i = 3; i < 27; i++) //length of right
	{
		gotoxy(98, i);
		if (i == 8)
		{
			printf("%c", 185);
		}
		else
		{
			printf("%c", 186);
		}
	}
	gotoxy(98, 27);
	printf("%c", 188);
	for (i = 97; i > 20; i--) //length of below line
	{
		gotoxy(i, 27);
		printf("%c", 205);
	}
	gotoxy(20, 27);
	printf("%c", 200);
	for (i = 26; i > 2; i--) //length of left
	{
		gotoxy(20, i);
		if (i == 8)
		{
			printf("%c", 204);
		}
		else
		{
			printf("%c", 186);
		}
	}

	for (i = 21; i < 98; i++) //length of mid horizontal
	{
		gotoxy(i, 8);
		printf("%c", 205);
	}
	gotoxy(46, 4);
	printf("LIBRARY MANAGEMENT SYSTEM");
	gotoxy(35, 5);
	printf("COMSATS INSTITUTE OF INFORMATION TECHNOLOGY, WAH");
	gotoxy(47, 6);
	TimeandDate();
}

void Password()
{
	HeaderandBordersPassword();
	char p[120] = "Password Protected";
	int i;
	int l = 0;
	char pass[10], ch = 0;
	gotoxy(50, 10);
	for (i = 0; p[i] != '\0'; i++)
	{
		Sleep(50);
		SetColorAndBackground(15, 9);
		printf("%c", p[i]);
	}
	gotoxy(50, 12);
	SetColorAndBackground(9, 0);
	printf("Enter Password: ");
	while (ch != 13)
	{
		ch = _getch();

		if (ch != 13 && ch != 8) {
			printf("*");
			pass[l] = ch;
			l++;
		}
	}
	pass[l] = '\0';
	char granted[15] = "ACCESS GRANTED";
	if (strcmp(pass, password) == 0)
	{
		gotoxy(50, 14);
		printf("Password Matched\n");
		gotoxy(52, 16);
		for (i = 0; granted[i] != '\0'; i++)
		{
			Sleep(50);
			SetColorAndBackground(15, 10);
			printf("%c", granted[i]);
		}
		SetColorAndBackground(14, 0);
		Sleep(100);
		gotoxy(50, 18);
		printf("Loading");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		mainmenu();
	}
	else
	{
		gotoxy(50, 14);
		printf("\aWarning!!! Incorrect Password");
		SetColorAndBackground(15, 12);
		gotoxy(52, 16);
		printf("ACCESS DENIED");
		SetColorAndBackground(15, 0);
		_getch();
			system("cls");
			Password();
	}

}

//mainmenu
void mainmenu()
{
	system("cls");
	HeaderandBorders();
	SetColor(4);
	gotoxy(22, 10);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Add Books");
	gotoxy(22, 12);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Delete Books");
	gotoxy(22, 14);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Search Books");
	gotoxy(22, 16);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Issue Books");
	gotoxy(22, 18);
	printf("\xDB\xDB\xDB\xDB\xB2 5. View Book List");
	gotoxy(22, 20);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Edit Books Record");
	gotoxy(22, 22);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Change Password");
	gotoxy(22, 24);
	printf("\xDB\xDB\xDB\xDB\xB2 8. Close Application");
	gotoxy(22, 26);
	printf("Enter your choice: ");
	switch (_getch())
	{
	case '1':
	{
		addbooks();
		break;
	}
	case '2':
	{
		deletebooks();
		break;
	}
	case '3':
	{
		searchbooks();
		break;
	}
	case '4':
	{
		issuebooks();
		break;
	}
	case '5':
	{
		viewbooks();
		break;
	}
	case '6':
	{
		editbooks();
		break;
	}
	case '7':
	{
		clearWindow();
		int i;
		gotoxy(68, 13);
		char st[20] = "Under Construction";
		for (i = 0; st[i] != '\0'; i++)
		{
			Sleep(50);
			SetColorAndBackground(15, 9);
			printf("%c", st[i]);
		}
		gotoxy(59, 15);
		SetColorAndBackground(1, 15);
		printf("Press any key to return to Main Menu");
		fflush(stdin);
		if (_getch())
			mainmenu();
		break;
	}
	case '8':
	{
		system("cls");
		HeaderandBordersPassword();
		gotoxy(30, 12);
		SetColorAndBackground(0, 15);
		printf("Programmers:");
		int i;
		char f[20] = "Faizan Ishfaq";
		char k[20] = "Kamal Shah";
		gotoxy(35, 14);
		for (i = 0; f[i] != '\0'; i++)
		{
				Sleep(100);
				SetColorAndBackground(15, 9);
				printf("%c", f[i]);
		}
		SetColorAndBackground(9, 0);
		gotoxy(35, 15);
		printf("CIIT/FA14-BCS-081/WAH");
		gotoxy(35, 16);
		printf("Cell: 0311-0222221		Email: faizi.ch@live.com");
		gotoxy(35, 18);
		for (i = 0; k[i] != '\0'; i++)
		{
			Sleep(100);
			SetColorAndBackground(15, 9);
			printf("%c", k[i]);
		}
		SetColorAndBackground(9, 0);
		gotoxy(35, 19);
		printf("CIIT/FA14-BCS-058/WAH");
		gotoxy(35, 20);
		printf("Cell: 0303-5693938		Email: kamalshah205@gmail.com");
		Sleep(500);
		gotoxy(50, 22);
		SetColor(10);
		printf("Exiting");
		Sleep(500);
		printf(".");
		Sleep(700);
		printf(".");
		Sleep(700);
		printf(".");
		Sleep(700);
		printf(".");
		Sleep(700);
		printf(".");
		Sleep(700);
		exit(0);
		break;
	}
	default:
	{
		gotoxy(37, 28);
		printf("\aWrong Entry!!Press any key to re-enter...");
		fflush(stdin);
		if (_getch())
			mainmenu();
	}
	}
}

void addbooks()				//ERROR: saving categories in a.cat
{
	clearWindow();
	gotoxy(68, 10);
	SetColorAndBackground(15, 3);
	printf("SELECT CATEGORIES");
	gotoxy(57, 12);
	SetColorAndBackground(0, 15);
	printf("1. Computer");
	gotoxy(57, 14);
	printf("2. Electronics");
	gotoxy(57, 16);
	printf("3. Electrical");
	gotoxy(57, 18);
	printf("4. Civil");
	gotoxy(57, 20);
	printf("5. Mechanical");
	gotoxy(57, 22);
	printf("6. Architecture");
	gotoxy(57, 24);
	printf("7. Back to Main Menu");
	gotoxy(57, 26);
	printf("Enter your choice:");
	scanf_s("%d", &s);
	if (s == 7)
		mainmenu();
	clearWindow();
	gotoxy(72, 10);
	SetColorAndBackground(1, 3);
	printf("ADD BOOKS");
	SetColorAndBackground(0, 15);
	fopen_s(&fb, "Books.dat", "ab+");
	gotoxy(63, 12); 
	printf("Enter the Information Below");
	gotoxy(63, 13); 
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(63, 14);
	printf("\xB2"); gotoxy(89, 14); printf("\xB2");
	gotoxy(63, 15);
	printf("\xB2"); gotoxy(89, 15); printf("\xB2");
	gotoxy(63, 16);
	printf("\xB2"); gotoxy(89, 16); printf("\xB2");
	gotoxy(63, 17);
	printf("\xB2"); gotoxy(89, 17); printf("\xB2");
	gotoxy(63, 18);
	printf("\xB2"); gotoxy(89, 18); printf("\xB2");
	gotoxy(63, 19);
	printf("\xB2"); gotoxy(89, 19); printf("\xB2");
	gotoxy(63, 20);
	printf("\xB2"); gotoxy(89, 20); printf("\xB2");
	gotoxy(63, 21);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(64, 14);
	printf("Category:");
	gotoxy(74, 14);
	printf("%s", categories[s - 1]);
	gotoxy(64, 15);
	int bookid;
	printf("Book ID:\t");
	gotoxy(73, 15);
	scanf_s("%d", &bookid);
	rewind(fb);
	while (fread(&a, sizeof(a), 1, fb) == 1)
		if (bookid == a.id)
		{
			gotoxy(63, 22);
			getchar();
			printf("\aThe book id already exists\a");
			getchar();
			fclose(fb);
			mainmenu();
		}
	a.id = bookid;
	gotoxy(64, 16);
	fflush(stdin);
	printf("Book Name:"); gotoxy(75, 16);
	gets_s(a.name);
	gotoxy(64, 17);
	printf("Author:"); gotoxy(72, 17);
	gets_s(a.Author);
	gotoxy(64, 18);
	printf("Quantity:"); gotoxy(74, 18);
	scanf_s("%d", &a.quantity);
	gotoxy(64, 19);
	printf("Price: Rs."); gotoxy(74, 19);
	scanf_s("%f", &a.Price);
	gotoxy(64, 20);
	printf("Rack No:"); gotoxy(73, 20);
	scanf_s("%d", &a.rackno);
	a.cat = categories[s - 1];
	//fputs(a.cat, fb);
	fseek(fb, 0, SEEK_END);
	fwrite(&a, sizeof(a), 1, fb);
	fclose(fb);
	gotoxy(59, 23);
	printf("The record is successfully saved");
	gotoxy(57, 25);
	printf("Save any more? (Y / N):");
	fflush(stdin);
	if (_getch() == 'n')
		mainmenu();
	else
		addbooks();
}
void deletebooks()
{
	clearWindow();
	int bookid;
	gotoxy(66, 10);
	SetColorAndBackground(15, 3);
	printf("DELETE BOOKS RECORD");
	gotoxy(57, 12);
	SetColorAndBackground(0, 15);
	printf("Enter the Book ID to delete: ");
	scanf_s("%d", &bookid);
	int flag = 0;
	fopen_s(&fb, "Books.dat", "rb+");
	rewind(fb);
	while (fread(&a, sizeof(a), 1, fb) == 1)
	{
		if (a.id == bookid)
		{
			gotoxy(10, 7);
			getchar();
			gotoxy(59, 14);
			printf("The Book is available");
			gotoxy(59, 15);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(59, 16);
			printf("\xB2 ID:%d", a.id); gotoxy(86, 16); printf("\xB2");
			gotoxy(59, 17);
			printf("\xB2 Name:%s", a.name); gotoxy(86, 17); printf("\xB2");
			gotoxy(59, 18);
			printf("\xB2 Author:%s ", a.Author); gotoxy(86, 18); printf("\xB2");
			gotoxy(59, 19);
			printf("\xB2 Quantity:%d ", a.quantity); gotoxy(86, 19); printf("\xB2");
			gotoxy(59, 20);
			printf("\xB2 Price:Rs.%.2f", a.Price); gotoxy(86, 20); printf("\xB2");
			gotoxy(59, 21);
			printf("\xB2 Rack No:%d ", a.rackno); gotoxy(86, 21); printf("\xB2");
			gotoxy(59, 22);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(59, 23);
			printf("Do you want to delete it? (Y/N)");
			fflush(stdin);
			if (_getch() == 'y')
			{
				fopen_s(&ft, "temp.dat", "wb+");//temporary file for delete
				rewind(fb);
				while (fread(&a, sizeof(a), 1, fb) == 1)
				{
					if (a.id != bookid)
					{
						fseek(ft, 0, SEEK_CUR);
						fwrite(&a, sizeof(a), 1, ft); //write all in temporary file except that
					}                              //we want to delete
				}
				fclose(ft);
				fclose(fb);
				remove("Books.dat");
				rename("temp.dat", "Books.dat"); //copy all item from temporary file to fb except that
				fopen_s(&fb, "Books.dat", "rb+"); //we want to delete
				fclose(fb);
				gotoxy(59, 25);
				printf("The record is successfully deleted");
				flag++;
			}
			else
			{
				fclose(fb);
				mainmenu();
			}
		}
	}
	if (flag == 0)
	{
		gotoxy(59, 14);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(59, 15); printf("\xB2");  gotoxy(77, 15); printf("\xB2");
		gotoxy(59, 16);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(61, 15); printf("\aNo Record Found");
	}
	gotoxy(57, 26);
	printf("Delete another Record? (Y/N)");
	fflush(stdin);
	if (_getch() == 'y')
	{
		fclose(fb);
		deletebooks();
	}
	else
	{
		fclose(fb);
		mainmenu();
	}
}
void searchbooks()
{
	clearWindow();
	int id;
	gotoxy(70, 10);
	SetColorAndBackground(15, 3);
	printf("SEARCH BOOKS");
	SetColorAndBackground(0, 15);
	gotoxy(57, 12);
	printf("1. Search by ID");
	gotoxy(57, 14);
	printf("2. Search by Name");
	gotoxy(57, 16);
	printf("3. Back to Main Menu");
	gotoxy(57, 18);
	printf("Enter your choice:");
	switch (_getch())
	{
	case '1':
	{
		clearWindow();
		SetColorAndBackground(15, 3);
		gotoxy(66, 10);
		printf("SEARCH BOOKS BY ID");
		SetColorAndBackground(0, 15);
		gotoxy(57, 12);
		printf("Enter the Book ID: ");
		scanf_s("%d", &id);
		int flag = 0;
		fopen_s(&fb, "Books.dat", "rb");
		rewind(fb);
		while (fread(&a, sizeof(a), 1, fb) == 1)
		{
			if (a.id == id)
			{
				gotoxy(59, 14);
				printf("The Book is available");
				gotoxy(59, 15);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(59, 16);
				printf("\xB2 ID:%d", a.id); gotoxy(86, 16); printf("\xB2");
				gotoxy(59, 17);
				printf("\xB2 Name:%s", a.name); gotoxy(86, 17); printf("\xB2");
				gotoxy(59, 18);
				printf("\xB2 Author:%s ", a.Author); gotoxy(86, 18); printf("\xB2");
				gotoxy(59, 19);
				printf("\xB2 Quantity:%d ", a.quantity); gotoxy(86, 19); printf("\xB2");
				gotoxy(59, 20);
				printf("\xB2 Price:Rs.%.2f", a.Price); gotoxy(86, 20); printf("\xB2");
				gotoxy(59, 21);
				printf("\xB2 Rack No:%d ", a.rackno); gotoxy(86, 21); printf("\xB2");
				gotoxy(59, 22);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				flag++;
			}
		}
		if (flag == 0)
		{
			gotoxy(59, 14);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(59, 15); printf("\xB2");  gotoxy(77, 15); printf("\xB2");
			gotoxy(59, 16);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(61, 15); printf("\aNo Record Found");
		}
		gotoxy(57, 24);
		printf("Try another search? (Y/N)");
		fflush(stdin);
		if (_getch() == 'y')
		{
			fclose(fb);
			searchbooks();
		}
		else
		{
			fclose(fb);
			mainmenu();
		}
		break;
	}
	case '2':
	{
		clearWindow();
		char n[25] = "\0";
		SetColorAndBackground(15, 3);
		gotoxy(66, 10);
		printf("SEARCH BOOKS BY NAME");
		SetColorAndBackground(0, 15);
		gotoxy(57, 12);
		printf("Enter Book Name: ");
		gets_s(n);
		int flag2 = 0;
		fopen_s(&fb, "Books.dat", "rb");
		rewind(fb);
		while (fread(&a, sizeof(a), 1, fb) == 1)
		{
			if (strcmp(a.name, (n)) == 0)
			{
				gotoxy(59, 14);
				printf("The Book is available");
				gotoxy(59, 15);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(59, 16);
				printf("\xB2 ID:%d", a.id); gotoxy(86, 16); printf("\xB2");
				gotoxy(59, 17);
				printf("\xB2 Name:%s", a.name); gotoxy(86, 17); printf("\xB2");
				gotoxy(59, 18);
				printf("\xB2 Author:%s ", a.Author); gotoxy(86, 18); printf("\xB2");
				gotoxy(59, 19);
				printf("\xB2 Quantity:%d ", a.quantity); gotoxy(86, 19); printf("\xB2");
				gotoxy(59, 20);
				printf("\xB2 Price:Rs.%.2f", a.Price); gotoxy(86, 20); printf("\xB2");
				gotoxy(59, 21);
				printf("\xB2 Rack No:%d ", a.rackno); gotoxy(86, 21); printf("\xB2");
				gotoxy(59, 22);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				flag2++;
			}
		}
		if (flag2 == 0)
		{
			gotoxy(59, 14);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(59, 15); printf("\xB2");  gotoxy(77, 15); printf("\xB2");
			gotoxy(59, 16);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(61, 15); printf("\aNo Record Found");
		}
		gotoxy(57, 24);
		printf("Try another search? (Y/N)");
		fflush(stdin);
		if (_getch() == 'y')
		{
			fclose(fb);
			searchbooks();
		}
		else
		{
			fclose(fb);
			mainmenu();
		}
		break;
	}
	case '3':
	{
		mainmenu();
		break;
	}
	default:
	{
		gotoxy(57, 20);
		printf("\aWrong Entry!!Press any key to re-enter...");
		if (_getch())
			searchbooks();
	}
	}
}
void issueabook()
{
	clearWindow();
	int id;
	SetColorAndBackground(15, 3);
	gotoxy(66, 10);
	printf("ISSUE BOOK SECTION");
	SetColorAndBackground(0, 15);
	gotoxy(57, 12);
	printf("Enter the Book Id:");
	scanf_s("%d", &id);
	int flag = 0;
	fopen_s(&fb, "Books.dat", "rb");
	fopen_s(&fi, "Issue.dat", "ab+");
	rewind(fb);
	while (fread(&a, sizeof(a), 1, fb) == 1)
	{
		if (a.id == id)
		{
			gotoxy(57, 14);
			printf("The book record is available");
			gotoxy(57, 15);
			printf("There are %d unissued books in library ", a.quantity);
			gotoxy(57, 16);
			printf("The name of book is %s", a.name);
			gotoxy(57, 17);
			fflush(stdin);
			printf("Enter student name:");
			gets_s(a.stname);
			char d[50];
			time_t current = time(NULL);
			struct tm* pLocal = localtime(&current);
			strftime(d, sizeof(d), "Issued Date: %a %d/%m/%Y", pLocal);
			gotoxy(57, 18);
			printf(d);
			gotoxy(57, 19);
			gotoxy(57, 20);
			printf("The BOOK of ID %d is issued", a.id);
			fseek(fi, sizeof(a), SEEK_END);
			fwrite(&a, sizeof(a), 1, fi);
			fclose(fi);
			flag++;
		}
	}
	if (flag == 0)
	{
		gotoxy(59, 14);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(59, 15); printf("\xB2");  gotoxy(77, 15); printf("\xB2");
		gotoxy(59, 16);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(61, 15); printf("\aNo Record Found");
	}
	gotoxy(57, 22);
	printf("Issue any more? (Y/N)");
	fflush(stdin);
	if (_getch() == 'y')
	{
		fclose(fi);
		fclose(fb);
		issueabook();
	}
	else
	{
		fclose(fi);
		fclose(fb);
		issuebooks();
	}
}
void viewissued()
{
	int total = 0, j = 6;
	system("cls");
	gotoxy(15, 3);
	SetColor(38);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BOOK LIST \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(14, 4);
	printf("  STUDENT NAME    |  CATEGORY   |   ID   |      BOOK NAME      |  ISSUE DATE  |  RETURN DATE  ");
	gotoxy(15, 5);
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	fopen_s(&fi, "Issue.dat", "rb");
	rewind(fi);
	while (fread(&a, sizeof(a), 1, fi) == 1)
	{
		fflush(stdin);
		gotoxy(14, j);
		printf("| %s", a.stname);
		gotoxy(35, j);
		//printf("%s", *a.cat);
		gotoxy(55, j);
		printf("| %s", a.name);
		gotoxy(46, j);
		printf("| %d", a.id);
		j++;
	}
	fclose(fi);
	gotoxy(70, j + 1);
	printf("Press ENTER to return to Main Menu");
	if (_getch())
		mainmenu();
}
void searchissued()
{
	clearWindow();
	int id;
	SetColorAndBackground(15, 3);
	gotoxy(66, 10);
	printf("SEARCH ISSUED BOOKS");
	SetColorAndBackground(0, 15);
	gotoxy(57, 12);
	printf("Enter the Book ID: ");
	scanf_s("%d", &id);
	int flag = 0;
	fopen_s(&fi, "Issue.dat", "rb");
	rewind(fi);
	while (fread(&a, sizeof(a), 1, fi) == 1)
	{
		if (a.id == id)
		{
			gotoxy(60, 14);
			printf("The Book is available");
			gotoxy(60, 15);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(60, 16);
			printf("\xB2 Issued to:%s", a.stname); gotoxy(87, 16); printf("\xB2");
			gotoxy(60, 17);
			printf("\xB2 Name:%s", a.name); gotoxy(87, 17); printf("\xB2");
			gotoxy(60, 18);
			printf("\xB2 Issue Date:%s ", a.Author); gotoxy(87, 18); printf("\xB2");
			gotoxy(60, 19);
			printf("\xB2 Return Date:%d ", a.quantity); gotoxy(87, 19); printf("\xB2");
			gotoxy(60, 20);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			flag++;
		}
	}
	if (flag == 0)
	{
		gotoxy(59, 14);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(59, 15); printf("\xB2");  gotoxy(77, 15); printf("\xB2");
		gotoxy(59, 16);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(61, 15); printf("\aNo Record Found");
	}
	gotoxy(57, 22);
	printf("Try another search? (Y/N)");
	fflush(stdin);
	if (_getch() == 'y')
	{
		fclose(fi);
		searchissued();
	}
	else
	{
		fclose(fi);
		issuebooks();
	}
}
void removeissued()
{
	clearWindow();
	int bookid;
	FILE *fti;
	SetColorAndBackground(15, 3);
	gotoxy(66, 10);
	printf("REMOVE ISSUED BOOKS");
	SetColorAndBackground(0, 15);
	gotoxy(57, 12);
	printf("Enter the Book ID to remove: ");
	scanf_s("%d", &bookid);
	int flag = 0;
	fopen_s(&fi, "Issue.dat", "rb+");
	rewind(fi);
	while (fread(&a, sizeof(a), 1, fi) == 1)
	{
		if (a.id == bookid)
		{
			gotoxy(10, 7);
			getchar();
			gotoxy(60, 14);
			printf("The Book is available");
			gotoxy(60, 15);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(60, 16);
			printf("\xB2 Issued to:%s", a.stname); gotoxy(87, 16); printf("\xB2");
			gotoxy(60, 17);
			printf("\xB2 Name:%s", a.name); gotoxy(87, 17); printf("\xB2");
			gotoxy(60, 18);
			printf("\xB2 Issue Date:%s ", a.Author); gotoxy(87, 18); printf("\xB2");
			gotoxy(60, 19);
			printf("\xB2 Return Date:%d ", a.quantity); gotoxy(87, 19); printf("\xB2");
			gotoxy(60, 20);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(60, 21);
			printf("Do you want to delete it? (Y/N)");
			fflush(stdin);
			if (_getch() == 'y')
			{
				fopen_s(&fti, "tempissue.dat", "wb+");//temporary file for delete
				rewind(fi);
				while (fread(&a, sizeof(a), 1, fi) == 1)
				{
					if (a.id != bookid)
					{
						fseek(fti, 0, SEEK_CUR);
						fwrite(&a, sizeof(a), 1, fti); //write all in temporary file except that
					}                              //we want to delete
				}
				fclose(fti);
				fclose(fi);
				remove("Issue.dat");
				rename("tempissue.dat", "Issue.dat"); //copy all item from temporary file to fb except that
				fopen_s(&fi, "Issue.dat", "rb+"); //we want to delete
				fclose(fi);
				gotoxy(60, 22);
				printf("The record is successfully deleted");
				flag++;
			}
			else
			{
				fclose(fi);
				issuebooks();
			}
		}
	}
	if (flag == 0)
	{
		gotoxy(59, 14);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(59, 15); printf("\xB2");  gotoxy(77, 15); printf("\xB2");
		gotoxy(59, 16);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(61, 15); printf("\aNo Record Found");
	}
	gotoxy(57, 24);
	printf("Delete another Record? (Y/N)");
	fflush(stdin);
	if (_getch() == 'y')
	{
		fclose(fi);
		removeissued();
	}
	else
	{
		fclose(fi);
		issuebooks();
	}
}
void issuebooks()
{
	clearWindow();
	SetColorAndBackground(15, 3);
	gotoxy(70, 10);
	printf("ISSUE SECTION");
	SetColorAndBackground(0, 15);
	gotoxy(57, 12);
	printf("1. Issue a Book");
	gotoxy(57, 14);
	printf("2. View Issued Books");
	gotoxy(57, 16);
	printf("3. Search Issued Book");
	gotoxy(57, 18);
	printf("4. Remove Issued Book");
	gotoxy(57, 20);
	printf("5. Back to Main Menu");
	gotoxy(57, 22);
	printf("Enter your choice:");
	switch (_getch())
	{
	case '1':
	{
		issueabook();
		break;
	}
	case '2':
	{
		viewissued();
		break;
	}
	case '3':
	{
		searchissued();
		break;
	}
	case '4':
	{
		removeissued();
		break;
	}
	case '5':
		mainmenu();
	default:
	{
		gotoxy(57, 24);
		printf("\aWrong Entry!!Press any key to re-enter...");
		if (_getch())
			issuebooks();
	}
	}
}
void viewbooks()
{
	int total = 0, j = 6;
	system("cls");
	gotoxy(15, 3);
	SetColor(38);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BOOK LIST \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(14, 4);
	printf("  CATEGORY   |   ID   |      BOOK NAME      |      AUTHOR      |  QTY  |   PRICE  |  RackNo ");
	gotoxy(15, 5);
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	fopen_s(&fb, "Books.dat", "rb");
	//rewind(fb);
	while (fread(&a, sizeof(a), 1, fb) == 1)
	{
		gotoxy(15, j);
		fflush(stdin);
		//printf("%s", *a.cat);
		gotoxy(36, j);
		printf("| %s", a.name);
		gotoxy(58, j);
		printf("| %s", a.Author);
		gotoxy(27, j);
		printf("| %d", a.id);
		gotoxy(77, j);
		printf("| %d", a.quantity);
		gotoxy(85, j);
		printf("| %.2f", a.Price);
		gotoxy(96, j);
		printf("| %d", a.rackno);
		j++;
		total += a.quantity;
	}
	gotoxy(15, j + 1);
	printf("Total Books: %d", total);
	fclose(fb);
	gotoxy(70, j + 1);
	printf("Press ENTER to return to Main Menu");
	fflush(stdin);
	if (_getch())
		mainmenu();
}
void editbooks()
{
	clearWindow();
	int id;
	SetColorAndBackground(15, 3);
	gotoxy(66, 10);
	printf("EDIT BOOKS RECORD");
	SetColorAndBackground(0, 15);
	gotoxy(57, 12);
	printf("Enter the Book ID to be edited: ");
	scanf_s("%d", &id);
	int flag = 0;
	fopen_s(&fb, "Books.dat", "rb+");
	rewind(fb);
	while (fread(&a, sizeof(a), 1, fb) == 1)
	{
		if (a.id == id)
		{
			clearWindow();
			gotoxy(60, 9);
			printf("The Book is available");
			gotoxy(60, 10);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(60, 11);
			printf("\xB2 ID:%d", a.id); gotoxy(87, 11); printf("\xB2");
			gotoxy(60, 12);
			printf("\xB2 Name:%s", a.name); gotoxy(87, 12); printf("\xB2");
			gotoxy(60, 13);
			printf("\xB2 Author:%s ", a.Author); gotoxy(87, 13); printf("\xB2");
			gotoxy(60, 14);
			printf("\xB2 Quantity:%d ", a.quantity); gotoxy(87, 14); printf("\xB2");
			gotoxy(60, 15);
			printf("\xB2 Price:Rs.%.2f", a.Price); gotoxy(87, 15); printf("\xB2");
			gotoxy(60, 16);
			printf("\xB2 Rack No:%d ", a.rackno); gotoxy(87, 16); printf("\xB2");
			gotoxy(60, 17);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(60, 18);
			printf("Enter new record:");
			gotoxy(60, 19);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(60, 20);
			printf("\xB2 ID:%d", a.id); gotoxy(87, 20); printf("\xB2");
			gotoxy(60, 21);
			printf("\xB2 Name:"); gotoxy(87, 21); printf("\xB2");
			gotoxy(60, 22);
			printf("\xB2 Author:"); gotoxy(87, 22); printf("\xB2");
			gotoxy(60, 23);
			printf("\xB2 Quantity:"); gotoxy(87, 23); printf("\xB2"); gotoxy(87, 11); printf("\xB2");
			gotoxy(60, 24);
			printf("\xB2 Price:Rs."); gotoxy(87, 24); printf("\xB2");
			gotoxy(60, 25);
			printf("\xB2 Rack No:"); gotoxy(87, 25); printf("\xB2");
			gotoxy(60, 26);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			fflush(stdin);
			gotoxy(67, 21);
			gets_s(a.name);
			gotoxy(69, 22);
			gets_s(a.Author);
			gotoxy(71, 23);
			scanf_s("%d", &a.quantity);
			gotoxy(71, 24);
			scanf_s("%f", &a.Price);
			gotoxy(70, 25);
			scanf_s("%d", &a.rackno);
			gotoxy(60, 27);
			printf("The record is modified");
			fseek(fb, ftell(fb) - sizeof(a), 0);
			fwrite(&a, sizeof(a), 1, fb);
			fclose(fb);
			flag++;
		}
	}
	if (flag == 0)
	{
		gotoxy(59, 14);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(59, 15); printf("\xB2");  gotoxy(77, 15); printf("\xB2");
		gotoxy(59, 16);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(61, 15); printf("\aNo Record Found");
	}
	gotoxy(60, 28);
	printf("Modify another Record? (Y/N)");
	fflush(stdin);
	if (_getch() == 'y')
	{
		fclose(fb);
		editbooks();
	}
	else
	{
		fclose(fb);
		mainmenu();
	}
}