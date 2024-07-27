#include <iostream>
#include <queue>
#include <string>
#include <vector>

// Structure to hold student details
struct Student {
    std::string name;
    int rollNumber;
    std::string department;
    int year;
    float marks;
};

// Function to print student details
void printStudentDetails(const Student& student) {
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "Roll Number: " << student.rollNumber << std::endl;
    std::cout << "Department: " << student.department << std::endl;
    std::cout << "Year: " << student.year << std::endl;
    std::cout << "Marks: " << student.marks << std::endl;
}

void addStudent(std::queue<Student>& studentQueue) {
    Student student;
    std::cin.ignore(); // To ignore the newline character left by previous input
    std::cout << "Enter Name: ";
    std::getline(std::cin, student.name);
    std::cout << "Enter Roll Number: ";
    std::cin >> student.rollNumber;
    std::cin.ignore(); // To ignore the newline character left by previous input
    std::cout << "Enter Department: ";
    std::getline(std::cin, student.department);
    std::cout << "Enter Year: ";
    std::cin >> student.year;
    std::cout << "Enter Marks: ";
    std::cin >> student.marks;

    studentQueue.push(student);
}

void displayStudents(std::queue<Student> studentQueue) {
    if (studentQueue.empty()) {
        std::cout << "No student details available.\n";
        return;
    }

    std::cout << "\nStudent Details in Queue:\n";
    while (!studentQueue.empty()) {
        Student student = studentQueue.front();
        printStudentDetails(student);
        studentQueue.pop();
        std::cout << std::endl;
    }
}

void editStudent(std::queue<Student>& studentQueue) {
    if (studentQueue.empty()) {
        std::cout << "No student details available to edit.\n";
        return;
    }

    std::vector<Student> temp;
    int rollNumber;
    bool found = false;

    std::cout << "Enter Roll Number of student to edit: ";
    std::cin >> rollNumber;

    while (!studentQueue.empty()) {
        Student student = studentQueue.front();
        studentQueue.pop();

        if (student.rollNumber == rollNumber) {
            found = true;
            std::cin.ignore(); // To ignore the newline character left by previous input
            std::cout << "Enter New Name: ";
            std::getline(std::cin, student.name);
            std::cout << "Enter New Department: ";
            std::getline(std::cin, student.department);
            std::cout << "Enter New Year: ";
            std::cin >> student.year;
            std::cout << "Enter New Marks: ";
            std::cin >> student.marks;
        }
        temp.push_back(student);
    }

    for (const auto& student : temp) {
        studentQueue.push(student);
    }

    if (!found) {
        std::cout << "Student with Roll Number " << rollNumber << " not found.\n";
    }
}

int main() {
    std::queue<Student> studentQueue;
    int choice;

    while (true) {
        std::cout << "\nOptions:\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display All Students\n";
        std::cout << "3. Edit Student Details\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(studentQueue);
                break;
            case 2:
                displayStudents(studentQueue);
                break;
            case 3:
                editStudent(studentQueue);
                break;
            case 4:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
