#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>

#define RETURNTIME 15

char categories[][15]={"Fantasy","Adventure","Romance","Mystery","Horror","Sci-Fi","History"};
void returnfunc(void);
void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void editbooks(void);
void searchbooks(void);
void viewbooks(void);
void closeapplication(void);
int getdata();
int checkid(int);
int t(void);
void Password();
void loaderanim();


FILE *fp *ft *fs;

COORD coord = {0, 0};

int s;
char findbook;
char pass[10]={"kelam"};

void gotoxy (int x, int y)
{
    coord.X = x; coord.Y =y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct meroDate
{
    int dd,mm,yyyy;
};
struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;
    struct meroDate duedate;
};

struct books a;
int main()
{
    Password();
    getch();
    return 0;
}

void mainmenu();
{
    system("cls");

    int i;
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5)
    printf("\xDB\xDB\xDB\xDB\xB2 1. Add Books   ");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Delete books");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Search Books");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. View Book list");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Edit Book's Record");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Close Application");
    gotoxy(20,17);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(20,20);
    t();
    gotoxy(20,21);
    printf("Enter your choice:");

switch(getch())
{
case '1':
    addbooks();
    break;
case '2':
    deletebooks();
    break;
case '3':
    searchbooks();
    break;
case '4':
    viewbooks();
    break;
case '5':
    editbooks();
    break;
case '6':
    {
        system("cls");
        gotoxy(16,3);
        printf("\tLibrary Management System");
        gotoxy(16,4);
        printf("\taka Terminal Lib System");
        gotoxy(16,5);
        printf("***************************************");
        gotoxy(16,6);
        printf("***************************************");
        gotoxy(16,7);
        printf("***************************************");
        gotoxy(16,8);
        printf("Exiting in 3 second..............>");

        Sleep(3000);
        exit(0);
    }
default:
    {
        gotoxy(10,23);
        printf("\aWrong Entry! ! Please re-entered correct option");
        if(getch())
            mainmenu();
    }
  }
}
void addbooks(void)
{
    system("cls");

    int i;
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT CATEGORIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7)
    printf("\xDB\xDB\xDB\xDB\xB2 1. Fantasy   ");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Adventure");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Romance");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Mystery");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Horror");
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Sci-Fi");
    gotoxy(20,19);
    printf("\xDB\xDB\xDB\xDB\xB2 7. History");
    gotoxy(20,21);
    printf("\xDB\xDB\xDB\xDB\xB2 8. Back to main menu");
    gotoxy(20,23);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,25);
    printf("Enter your choice:");
    scanf("%d",&s);
    if(s==7)

    mainmenu();
    system("cls");
    fp=fopen("Bibek.dat","ab+");
    if(getdata()==1)
    {
        a.cat=categories[s-1];
        fseek(fp,0,SEEK_END);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        gotoxy(21,14);
        printf("The record is sucessfully saved");
        gotoxy(21,15);
        printf("Save any more?(Y / N):");
        if(getch()=='n')
            mainmenu();
        else
            system("cls");
        addbooks();
    }
}
void deletebooks()
{
    system("cls");
    int d;
    char another='y';
    while(another=='y')
    {
        system("cls");
        gotoxy(10,5);
        printf("Enter the Book ID to delete:");
        scanf("%d",&d);
        fp=fopen("Bibek.dat","rb+");
        rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id==d)
            {
                gotoxy(10,7);
                printf("The book record is avaible");
                gotoxy(10,8);
                printf("Book name is %s",a.name);
                gotoxy(10,9);
                printf("Rack No. is %d",a.rackno);
                findbook='t';
            }
        }
        if(findbook!='t')
        {
            gotoxy(10,10);
            printf("No record is found modify the search");
            if(getch())
                mainmenu();

        }
        if(findbook=='t')
        {
            gotoxy(10,9);
            printf("Do you want to delete it? (Y/N):");
            if(getch()=='y')
            {
                ft=fopen("test.dat","wb+");
                rewind(fp);
                while(fread(&a,sizeof(a),1,fp)==1)
                {
                    if(a.id!=d)
                    {
                        fseek(ft,0,SEEK_CUR);
                        fwrite(&a,sizeof(a),1,ft);
                    }
                }
                fclose(ft);
                fclose(fp);
                remove("Bibek.dat");
                rename("test.dat","Bibek.dat");
                fp=fopen("Bibek.dat","rb+");
                if(findbook=='t')
                {
                    gotoxy(10,10);
                    printf("The record is succesfully deleted.");
                    gotoxy(10,11);
                    printf("Delete another record?(Y/N)");

                }
            }
            else mainmenu();
            fflush(stdin);
            another=getch();
        }
    }
    gotoxy(10,15);
    mainmenu();
}

void searchbooks()
{
    system("cls");
    int d;
    printf("*****************************Search Books*********************************");
    gotoxy(20,10);
    printf("\xDB\xDB\xDB\xB2 1. Search By ID");
    gotoxy(20,14);
    printf("\xDB\xDB\xDB\xB2 2. Search By Name");
    gotoxy( 15,20);
    printf("Enter Your Choice");
    fp=fopen("Bibek.dat","rb+");
    rewind(fp);
    switch(getch())
    {
    case '1':
        {
            system("cls");
            goto(25,4);
            printf("****Search Books By Id****");
            gotoxy(20,5);
            printf("Enter the book id:");
            scanf("%d",&d);
            gotoxy(20,7);
            printf("Searching........");
            while(fread(&a,sizeof(a),1,fp)==1)
            {
                if(a.id==d)
                {
                    Sleep(2);
                    gotoxy(20,7);
                    printf("The Book is available");
                    gotoxy(20,8);
                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    gotoxy(20,9);
                    printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
                    gotoxy(20,10);
                    printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
                    gotoxy(20,11);
                    printf("\xB2 Author:%s ",a.Author);gotoxy(47,11);printf("\xB2");
                    gotoxy(20,12);
                    printf("\xB2 Qantity:%d ",a.quantity);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
                    gotoxy(20,13);
                    printf("\xB2 Price:Rs.%.2f",a.Price);gotoxy(47,13);printf("\xB2");
                    gotoxy(20,14);
                    printf("\xB2 Rack No:%d ",a.rackno);gotoxy(47,14);printf("\xB2");
                    gotoxy(20,15);
                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    findbook='t';

                }
            }
            if(findbook!='t')
            {
                gotoxy(20,8);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
                gotoxy(20,10);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(22,9);
                printf("\aNo Record Found");
            }
            gotoxy(20,17);
            printf("Try another search?(Y/N)");
            if(getch()=='y')
                searchb
        }
    }
}
