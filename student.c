#include <stdio.h>
#include <string.h>
#define MAX 100

struct Student {
    char name[50];
    float marks[5];
    float total;
    float average;
    char grade;
};

void inputDetails(struct Student *s, int n);
void calculateResults(struct Student *s, int n);
void displayResults(struct Student *s, int n);
char findGrade(float avg);

int main() {
    struct Student s[MAX];
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    inputDetails(s, n);
    calculateResults(s, n);
    displayResults(s, n);

    return 0;
}

void inputDetails(struct Student *s, int n) {
    for(int i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        s[i].total = 0;
        for(int j = 0; j < 5; j++) {
            printf("Enter marks in subject %d: ", j + 1);
            scanf("%f", &s[i].marks[j]);
        }
    }
}

void calculateResults(struct Student *s, int n) {
    for(int i = 0; i < n; i++) {
        s[i].total = 0;
        for(int j = 0; j < 5; j++)
            s[i].total += s[i].marks[j];
        s[i].average = s[i].total / 5;
        s[i].grade = findGrade(s[i].average);
    }
}

char findGrade(float avg) {
    if (avg >= 90)
        return 'A';
    else if (avg >= 75)
        return 'B';
    else if (avg >= 60)
        return 'C';
    else if (avg >= 45)
        return 'D';
    else
        return 'F';
}

void displayResults(struct Student *s, int n) {
    printf("\n\n=== STUDENT REPORT CARD ===\n");
    printf("Name\t\tTotal\tAverage\tGrade\n");
    printf("--------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%s\t\t%.2f\t%.2f\t%c\n", s[i].name, s[i].total, s[i].average, s[i].grade);
    }
}

