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
