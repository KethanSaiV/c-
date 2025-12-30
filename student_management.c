#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.dat", "ab");

    printf("ID Name Marks:\n");
    scanf("%d %s %f", &s.id, s.name, &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}

void displayStudents() {
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("%d %s %.2f\n", s.id, s.name, s.marks);
    }
    fclose(fp);
}

int main() {
    int choice;
    do {
        printf("1.Add 2.View 3.Exit\n");
        scanf("%d", &choice);

        if (choice == 1) addStudent();
        else if (choice == 2) displayStudents();

    } while (choice != 3);

    return 0;
}
