#include <stdio.h>
#include <string.h>

#define SUBJECTS 5  // You can change this number (e.g., 3 or 6)

struct Student {
    char name[50];
    float marks[SUBJECTS];
    float total;
    float percentage;
    char grade;
};

// Function to calculate grade
char calculateGrade(float percentage) {
    if (percentage >= 90) return 'A';
    else if (percentage >= 80) return 'B';
    else if (percentage >= 70) return 'C';
    else if (percentage >= 60) return 'D';
    else return 'F';
}

// Function to sort students by total marks (descending)
void sortStudents(struct Student s[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].total < s[j].total) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // Input details for each student
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        s[i].total = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            printf("Enter marks for Subject %d (out of 100): ", j + 1);
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / SUBJECTS;
        s[i].grade = calculateGrade(s[i].percentage);
    }

    // Sort students by total marks
    sortStudents(s, n);

    // Display all student records
    printf("\n---------------------------------------------------------\n");
    printf("All Students:\n");
    printf("%-20s %-10s %-15s %-10s\n", "Name", "Total", "Percentage", "Grade");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10.2f %-15.2f %-10c\n", s[i].name, s[i].total, s[i].percentage, s[i].grade);
    }

    // Display top 3 students
    printf("\n🏆 Top 3 Students 🏆\n");
    printf("%-10s %-20s %-10s %-15s %-10s\n", "Rank", "Name", "Total", "Percentage", "Grade");
    printf("---------------------------------------------------------\n");

    int top = (n < 3) ? n : 3;
    for (int i = 0; i < top; i++) {
        printf("%-10d %-20s %-10.2f %-15.2f %-10c\n", i + 1, s[i].name, s[i].total, s[i].percentage, s[i].grade);
    }

    return 0;
}
