#include <stdio.h>
#include <string.h>

// simple program to find out pupil student

struct student
{ // this time the database file has a single line format, so basically a csv type format
    // which is the industry standard
    char name[100];
    char classname[100]; // 10th A, 10th B and so on
    float percentage;
};

void view_students()
{
    FILE *fp;
    fp = fopen("records.txt", "r");
    char lines[1000];
    while (fgets(lines, 1000, fp))
    {
        printf("%s\n", lines);
    }
}
void view_pupil()
{
    printf("\n\n\n");
    FILE *fp;
    fp = fopen("records.txt", "r");

    struct student pupil;
    // to find the student with highest percentage
    int student_count = 0;

    while (fscanf(fp, " %99[^,],%[^,],%f", pupil.name, pupil.classname, &pupil.percentage) == 3)
    { // we used %[^,] because this time we are reading a text piece until comma is discovered
        student_count++;
    }

    rewind(fp);

    float marks_arr[student_count];
    int i = 0;
    while (fscanf(fp, " %99[^,],%[^,],%f", pupil.name, pupil.classname, &pupil.percentage) == 3)
    {
        marks_arr[i] = pupil.percentage;
        i++;
    }

    // printing the marks array
    for (int i = 0; i < student_count; i++)
    {
        printf("%.2f,", marks_arr[i]);
    }

    // now getting the highest %

    float highest_perc;
    highest_perc = marks_arr[0];
    for (int i = 0; i < student_count; i++)
    {

        if (marks_arr[i] > highest_perc)
        {
            highest_perc = marks_arr[i];
        }
    }
    printf("\n\n\n Highest percentage obtained: %.2f", highest_perc);
    rewind(fp);

    // printing the name of the student who obtained highest %;
    rewind(fp);
    printf("\n");
    while (fscanf(fp, " %[^,],%[^,],%f", pupil.name, pupil.classname, &pupil.percentage) == 3)
    {
        if (pupil.percentage == highest_perc)
        {
            printf("%s\n", pupil.name);
            printf("%s\n", pupil.classname);
            printf("%.2f", pupil.percentage);
        }
    }

    fclose(fp);
}

void avg_perc()
{
    printf("\n\n");
    FILE *fp;
    fp = fopen("records.txt", "r");

    struct student average;

    float total = 0.00;
    int student_count = 0;

    while (fscanf(fp, "%[^,],%[^,],%f", average.name, average.classname, &average.percentage) == 3)
    {
        total = total + average.percentage;
        student_count++;
    }
    printf("\n\n Total number of record entries: %d", student_count);
    float school_avg_percentage = total / student_count;
    printf("\nAverage percentage of school: %.2f", school_avg_percentage);
}

void section()
{
    printf("\n");

    // to see section wise student names and percentages

    printf("\n Enter section name: (use format 10th A, 10th B etc): ");
    char sec_name[100];
    scanf(" %99[^\n]", sec_name);

    printf("\n \n");

    FILE *fp;
    fp = fopen("records.txt", "r");

    struct student sectional_division;

    while (fscanf(fp, " %[^,],%[^,],%f", sectional_division.name, sectional_division.classname, &sectional_division.percentage) == 3)
    {

        if (strcmp(sec_name, sectional_division.classname) == 0)
        {
            printf("%s\n", sectional_division.name);
            printf("%s\n", sectional_division.classname);
            printf("%.2f\n", sectional_division.percentage);
            printf("\n");
        }
    }
}

void ninety_perecentage_or_more()
{

    printf("\n\n");
    printf("Students who scored 90 percent or more:");
    printf("\n");
    // fxn to view students who got more than 90%
    FILE *fp;
    fp = fopen("records.txt", "r");

    struct student high_scorers;

    int Section_A_points = 0;
    int Section_B_points = 0;
    int Section_C_points = 0;
    int Section_D_points = 0;
    int Section_E_points = 0;
    int Section_F_points = 0;

    while (fscanf(fp, "%99[^,],%[^,],%f", high_scorers.name, high_scorers.classname, &high_scorers.percentage) == 3)
    {
        // high-scorers from Section A
        if (high_scorers.percentage >= 90.00 && (strcmp(high_scorers.classname, "10th A") == 0))
        {
            printf("%s\n", high_scorers.name);
            printf("%s\n", high_scorers.classname);
            printf("%.2f", high_scorers.percentage);
            printf("\n");
            Section_A_points++;
        }

        // high-scorers from Section B
        if (high_scorers.percentage >= 90.00 && (strcmp(high_scorers.classname, "10th B") == 0))
        {
            printf("%s\n", high_scorers.name);
            printf("%s\n", high_scorers.classname);
            printf("%.2f", high_scorers.percentage);
            printf("\n");
            Section_B_points++;
        }

        // high-scorers from Section C
        if (high_scorers.percentage >= 90.00 && (strcmp(high_scorers.classname, "10th C") == 0))
        {
            printf("%s\n", high_scorers.name);
            printf("%s\n", high_scorers.classname);
            printf("%.2f", high_scorers.percentage);
            printf("\n");
            Section_C_points++;
        }
        // high-scorers from Section D
        if (high_scorers.percentage >= 90.00 && (strcmp(high_scorers.classname, "10th D") == 0))
        {
            printf("%s\n", high_scorers.name);
            printf("%s\n", high_scorers.classname);
            printf("%.2f", high_scorers.percentage);
            printf("\n");
            Section_D_points++;
        }

        // high-scorers from Section E
        if (high_scorers.percentage >= 90.00 && (strcmp(high_scorers.classname, "10th E") == 0))
        {
            printf("%s\n", high_scorers.name);
            printf("%s\n", high_scorers.classname);
            printf("%.2f", high_scorers.percentage);
            printf("\n");
            Section_E_points++;
        }

        // high-scorers from Section F
        if (high_scorers.percentage >= 90.00 && (strcmp(high_scorers.classname, "10th F") == 0))
        {
            printf("%s\n", high_scorers.name);
            printf("%s\n", high_scorers.classname);
            printf("%.2f", high_scorers.percentage);
            printf("\n");
            Section_F_points++;
        }
    }

    printf("Number of students who scored 90 Perecent or more from Section A: %d\n", Section_A_points);

    printf("Number of students who scored 90 Perecent or more from Section B: %d\n", Section_B_points);
    printf("Number of students who scored 90 Perecent or more from Section C: %d\n", Section_C_points);
    printf("Number of students who scored 90 Perecent or more from Section D: %d\n", Section_D_points);
    printf("Number of students who scored 90 Perecent or more from Section E: %d\n", Section_E_points);
    printf("Number of students who scored 90 Perecent or more from Section F: %d\n", Section_F_points);
}
int main()
{
    int operator_choice;
    while (1)
    {
        printf("See all students list: 1\n");
        printf("See Higehst scorer: 2\n");
        printf("See school avg percentage: 3\n");
        printf("View section-wise breakdown: 4\n");
        printf("View students who scored 90 percent or above: 5\n");
        printf("Exit: 6\n");
        scanf("%d", &operator_choice);
        if (operator_choice == 1)
        {
            view_students();
        }
        else if (operator_choice == 2)
        {
            view_pupil();
            /* code */
        }
        else if (operator_choice == 3)
        {
            avg_perc();
            /* code */
        }
        else if (operator_choice == 4)
        {
            section();
        }
        else if (operator_choice == 5)
        {
            /* code */ ninety_perecentage_or_more();
        }
        else if (operator_choice == 6)
        {
            break;
            printf("\n\nThank you for using SMART(Student Management And Record Tracker).\n\n");
        }
        printf("\n\nThank you for using SMART(Student Management And Record Tracker).\n\n");
    }

    return 0;
}