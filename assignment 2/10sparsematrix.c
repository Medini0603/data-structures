// A university consists of 500 students and there are totally 40 courses for registration.
// Each  student can register maximum of 4 courses.
// Store the details of registration and generate  course wise registration
//  and student wise registration details with linked storage structure.

#include <stdio.h>
#include <stdlib.h>
struct details
{
    int srnum;
    int coursecode;
    struct details *llink;
    struct details *rlink;
};
typedef struct details *DET;

struct course
{
    int code;
    char name[10];
    struct course *rlink;
    DET llink;
};
typedef struct course *CRS;

struct student
{
    int srno;
    char name[10];
    struct student *llink;
    DET rlink;
};
typedef struct student *STD;

struct tab
{
    int totalstu;
    int totalcor;
    STD llink;
    CRS rlink;
};
typedef struct tab *TAB;

void insertstu(TAB);
void insertcour(TAB);
void dispcourse(TAB);
void dispstu(TAB);
void insertdetails(TAB);
void studetails(TAB);
void cordetails(TAB);

int main()
{
    TAB table = (TAB)malloc(sizeof(struct tab));
    table->totalstu = 0;
    table->llink = NULL;
    table->rlink = NULL;
    table->totalcor = 0;
    table->totalstu = 0;

    int choice;
    for (;;)
    {
        printf("Enter choice\n1->to add new course\n2->to add new student\n3->insert course details of students\n4->display student details\n5->display course details\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertcour(table);
            dispcourse(table);
            break;
        case 2:
            insertstu(table);
            dispstu(table);
            break;
        case 3:
            insertdetails(table);
            break;
        case 4:
            studetails(table);
            break;
        case 5:
            cordetails(table);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}

void insertcour(TAB t)
{
    CRS nn = (CRS)malloc(sizeof(struct course));
    t->totalcor++;
    printf("Enter course code\n");
    scanf("%d", &nn->code);
    printf("Enter course name\n");
    scanf("%s", nn->name);
    nn->rlink = NULL;
    nn->llink = NULL;

    if (t->rlink == NULL)
    {
        nn->rlink = nn;
    }
    else
    {
        nn->rlink = t->rlink->rlink;
        t->rlink->rlink = nn;
    }
    t->rlink = nn;
}

void dispcourse(TAB t)
{
    printf("Number of courses in list %d\n", t->totalcor);
    CRS fp = t->rlink->rlink;
    do
    {
        printf("%d %s", fp->code, fp->name);
        printf("\t");
        fp = fp->rlink;
    } while (fp != t->rlink->rlink);
    printf("\n");
}

void insertstu(TAB t)
{
    STD nn = (STD)malloc(sizeof(struct student));
    t->totalstu++;
    printf("Enter student name\n");
    scanf("%s", nn->name);
    printf("Enter reg no\n");
    scanf("%d", &nn->srno);
    nn->rlink = NULL;
    nn->llink = NULL;

    if (t->llink == NULL)
    {
        nn->llink = nn;
    }
    else
    {
        nn->llink = t->llink->llink;
        t->llink->llink = nn;
    }
    t->llink = nn;
}

void dispstu(TAB t)
{
    printf("Number of students in list %d\n", t->totalstu);
    STD fp = t->llink->llink;
    do
    {
        printf("%d %s", fp->srno, fp->name);
        printf("\n");
        fp = fp->llink;
    } while (fp != t->llink->llink);
    printf("\n");
}

void insertdetails(TAB t)
{
    DET nn = (DET)malloc(sizeof(struct details));
    printf("enter sr number of student registering for course\n");
    scanf("%d", &nn->srnum);
    printf("enter code number of course to be for registered\n");
    scanf("%d", &nn->coursecode);

    STD ts = t->llink;
    int cnts = 1;
    while (cnts <= t->totalstu && ts->srno != nn->srnum)
    {
        ts = ts->llink;
        cnts++;
    }
    if (cnts > t->totalstu)
    {
        printf("No student of given sr number is found please add the student\n");
        return;
    }

    CRS tc = t->rlink;
    int cntc = 1;

    while (cntc <= t->totalcor && tc->code != nn->coursecode)
    {
        tc = tc->rlink;
        cntc++;
    }
    if (cntc > t->totalcor)
    {
        printf("No course of given code is found please add the course\n");
        return;
    }
    // adding to row
    if (ts->rlink == NULL)
    {
        nn->rlink = nn;
    }
    else
    {
        nn->rlink = ts->rlink->rlink;
        ts->rlink->rlink = nn;
    }
    ts->rlink = nn;

    // adding to column
    if (tc->llink == NULL)
    {
        nn->llink = nn;
    }
    else
    {
        nn->llink = tc->llink->llink;
        tc->llink->llink = nn;
    }
    tc->llink = nn;
}

void studetails(TAB t)
{
    printf("Enter sr number of student to be displayed\n");
    int key;
    scanf("%d", &key);
    STD s = t->llink;
    int cnt = 1;

    while (cnt <= t->totalcor && s->srno != key)
    {
        s = s->llink;
        cnt++;
    }

    if (cnt > t->totalstu)
    {
        printf("Student not found\n");
        return;
    }

    printf("Name : %s\n", s->name);
    printf("Course code that %s of sr no %d has registered is\n", s->name, s->srno);
    DET temp = s->rlink;
    if(temp==NULL)return;
    do
    {
        printf("course code = %d\n", temp->coursecode);
        temp = temp->rlink;
    } while (temp != s->rlink);
}

void cordetails(TAB t)
{
    printf("Enter course code of course to be displayed\n");
    int key;
    scanf("%d", &key);
    CRS c = t->rlink;
    int cnt = 1;

    while (cnt <= t->totalcor && c->code != key)
    {
        c = c->rlink;
        cnt++;
    }

    if (cnt > t->totalcor)
    {
        printf("Course not found\n");
        return;
    }

    printf("Course name : %s\n", c->name);
    printf("Students registered for %s course of code %d are \n",c->name,c->code);
    DET temp = c->llink;
    if(temp==NULL)return;
    do
    {
        printf("sr number = %d\n", temp->srnum);
        temp = temp->llink;
    } while (temp != c->llink);
}