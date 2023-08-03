#include <stdio.h>
#include <string.h>

struct dob {
    int day;
    int month;
    int year;
};

struct student_info {
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

// Function to populate the structure using call-by-value
void populateStructByValue(struct student_info student) {
    printf("Populating structure using call-by-value...\n");
    printf("Enter Roll No: ");
    scanf("%d", &student.roll_no);

    printf("Enter Name: ");
    scanf("%s", student.name);

    printf("Enter CGPA: ");
    scanf("%f", &student.CGPA);

    printf("Enter Date of Birth (dd mm yyyy): ");
    scanf("%d %d %d", &student.age.day, &student.age.month, &student.age.year);

    printf("\n");
}

// Function to populate the structure using call-by-address
void populateStructByAddress(struct student_info *student) {
    printf("Populating structure using call-by-address...\n");
    printf("Enter Roll No: ");
    scanf("%d", &student->roll_no);

    printf("Enter Name: ");
    scanf("%s", student->name);

    printf("Enter CGPA: ");
    scanf("%f", &student->CGPA);

    printf("Enter Date of Birth (dd mm yyyy): ");
    scanf("%d %d %d", &student->age.day, &student->age.month, &student->age.year);

    printf("\n");
}

// Function to print the structure
void printStruct(struct student_info student) {
    printf("Roll No: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("CGPA: %.2f\n", student.CGPA);
    printf("Date of Birth: %02d/%02d/%d\n", student.age.day, student.age.month, student.age.year);
}

int main() {
    struct student_info student1 = {0}; // Initialize with all members set to 0
    struct student_info student2;

    // Using call-by-value function
    populateStructByValue(student1);
    printf("Printing student1 details:\n");
    printStruct(student1);
    printf("\n");

    // Using call-by-address function
    populateStructByAddress(&student2);
    printf("Printing student2 details:\n");
    printStruct(student2);

    return 0;
}
