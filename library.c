#include<stdio.h>
#include<time.h>
#include<string.h>

#define MAX_YEAR 9999
#define MIN_YEAR 1900

#define Max_size_username 30
#define Max_Size_pasword 20
#define File_Name  "kiranlib.bin"

#define Max_BookName 50
#define Max_AuthorName 50
#define Max_StudentName 50
#define Max_Student_Address 300

#define FILE_Header_Size sizeof(sFileHeader)

typedef struct {
    int yyy;
    int mm;
    int dd;
} Date;

typedef struct {
    char username[Max_size_username];
    char password[Max_Size_pasword];
}; sFileHeader;

typedef struct
{
    unsigned int books_id;
    char bookName[Max_BookName];
    char authorName[Max_AuthorName];
    char studentName[Max_StudentName];
    char studentAddr[Max_Student_Address];
    Date bookIssueDate;
};
s_BooksInfo;

void printMessageCenter(const char* message){
    int len = 0;
    int pos = 0;
    len = (strlen(message)) / 2;
    printf("\t\t\t");
    for (pos = 0; pos < len; pos++){
        printf(" ");
    }
    printf("%s", message);
}
 
 
void headMessage(const char *message)
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}

void welcomeMessage()
{
     
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   To                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
}

int isNameValid(const char *name){
    int validName = 1;
    int len = 0;
    int index = 0;

    len = strlen(name);
    for ( index = 0; index < len; index++){
        if (!(isalpha(name[index])) && (name[index] != '\n') && (name[index]!=" "))
        {
            validName = 0;
            break;
        }
    }
    return validName;
    
}

int IsLeapYear(int year){
    return (((year % 4 == 0) &&
             (year % 100)) ||
            (year % 400 == 0));
}
int isValidDate(Date *validDate){
    if (validDate ->yyy > MAX_YEAR||validDate -> yyy < MIN_YEAR) 
       return 0;
    if (validDate ->mm <1|| validDate ->mm >12)
        return 0;
    if (validDate->dd<1 || validDate->dd >31)
        return 0;
    if (validDate->mm==2)
    {
        if (isLeapYear(validDate->yyy))
            return (validDate->dd <= 29);
        else
            return (validDate->dd <= 28);
    }
     if (validDate->mm == 4 || validDate->mm == 6 ||
            validDate->mm == 9 || validDate->mm == 11)
         return (validDate->dd <= 30);
         if (validDate->mm == 2 || validDate -> mm == 6 || validDate->mm == 9
         || validDate-> mm == 11)
             return (validDate->dd <= 30);

         return 1;
}

void addBookInDataBase()
{
    int days;
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(File_Name,"ab+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    headMessage("ADD NEW BOOKS");
    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tBook ID NO  = ");
    fflush(stdin);
    scanf("%u",&addBookInfoInDataBase.books_id);
    do
    {
        printf("\n\t\t\tBook Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.bookName,MAX_BOOK_NAME,stdin);
        status = isNameValid(addBookInfoInDataBase.bookName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tAuthor Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.authorName,Max_AuthorName,stdin);
        status = isNameValid(addBookInfoInDataBase.authorName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tStudent Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.studentName,Max_StudentName,stdin);
        status = isNameValid(addBookInfoInDataBase.studentName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        //get date year,month and day from user
        printf("\n\t\t\tEnter date in format (day/month/year): ");
        scanf("%d/%d/%d",&addBookInfoInDataBase.bookIssueDate.dd,&addBookInfoInDataBase.bookIssueDate.mm,&addBookInfoInDataBase.bookIssueDate.yyyy);
        //check date validity
        status = isValidDate(&addBookInfoInDataBase.bookIssueDate);
        if (!status)
        {
            printf("\n\t\t\tPlease enter a valid date.\n");
        }
    }
    while(!status);
    fwrite(&addBookInfoInDataBase,sizeof(addBookInfoInDataBase), 1, fp);
    fclose(fp);
}
void searchBooks()
{
    int found = 0;
    char bookName[Max_BookName] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(File_Name,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    headMessage("SEARCH BOOKS");
    //put the control on books detail
    if (fseek(fp,FILE_Header_Size,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while reading file\n");
        exit(1);
    }
    printf("\n\n\t\t\tEnter Book Name to search:");
    fflush(stdin);
    fgets(bookName,Max_BookName,stdin);
    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        if(!strcmp(addBookInfoInDataBase.bookName, bookName))
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf("\n\t\t\tBook id = %u\n",addBookInfoInDataBase.books_id);
        printf("\t\t\tBook name = %s",addBookInfoInDataBase.bookName);
        printf("\t\t\tBook authorName = %s",addBookInfoInDataBase.authorName);
        printf("\t\t\tBook issue date(day/month/year) =  (%d/%d/%d)",addBookInfoInDataBase.bookIssueDate.dd,
               addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    getchar();
}
