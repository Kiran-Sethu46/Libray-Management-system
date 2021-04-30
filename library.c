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
    if (validDate ->yyy > MAX_YEAR)||
       (validDate -> yyy < MIN_YEAR) 
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
           return(validDate->dd)
        
    }
    
}
