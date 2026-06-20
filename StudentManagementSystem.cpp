#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Student class - represents a single student record (OOP: Encapsulation)
class Student {
public:
    int rollNumber;
    string name;
    float marks;

    Student(int roll, string n, float m) {
        rollNumber = roll;
        name = n;
        marks = m;
    }
};

// StudentManagementSystem class - manages all student records
class StudentManagementSystem {
private:
    vector<Student> students;

public:
    // Add a new student
    void addStudent(int roll, string name, float marks) {
        // Check if roll number already exists
        for (auto &s : students) {
            if (s.rollNumber == roll) {
                cout << "Error: Roll number already exists!\n";
                return;
            }
        }
        students.push_back(Student(roll, name, marks));
        cout << "Student added successfully!\n";
    }

    // Search for a student by roll number
    void searchStudent(int roll) {
        for (auto &s : students) {
            if (s.rollNumber == roll) {
                cout << "\nStudent Found!\n";
                cout << "Roll No: " << s.rollNumber << " | Name: " << s.name
                     << " | Marks: " << s.marks << endl;
                return;
            }
        }
        cout << "Student with this roll number not found!\n";
    }

    // Update a student's marks
    void updateMarks(int roll, float newMarks) {
        for (auto &s : students) {
            if (s.rollNumber == roll) {
                s.marks = newMarks;
                cout << "Marks updated successfully!\n";
                return;
            }
        }
        cout << "Student with this roll number not found!\n";
    }

    // Delete a student record
    void deleteStudent(int roll) {
        for (int i = 0; i < (int)students.size(); i++) {
            if (students[i].rollNumber == roll) {
                students.erase(students.begin() + i);
                cout << "Student record deleted successfully!\n";
                return;
            }
        }
        cout << "Student with this roll number not found!\n";
    }

    // Display all students
    void displayAllStudents() {
        if (students.empty()) {
            cout << "\nNo student records found!\n";
            return;
        }

        cout << "\n----- STUDENT RECORDS -----\n";
        for (auto &s : students) {
            cout << "Roll No: " << s.rollNumber << " | Name: " << s.name
                 << " | Marks: " << s.marks << endl;
        }
        cout << "----------------------------\n";
    }

    // Calculate and display class average
    void displayClassAverage() {
        if (students.empty()) {
            cout << "No students to calculate average!\n";
            return;
        }

        float total = 0;
        for (auto &s : students) {
            total += s.marks;
        }
        float average = total / students.size();
        cout << "Class Average Marks: " << average << endl;
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Update Marks\n";
        cout << "4. Delete Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Display Class Average\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int roll;
                string name;
                float marks;
                cout << "Enter roll number: ";
                cin >> roll;
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter marks: ";
                cin >> marks;
                sms.addStudent(roll, name, marks);
                break;
            }
            case 2: {
                int roll;
                cout << "Enter roll number to search: ";
                cin >> roll;
                sms.searchStudent(roll);
                break;
            }
            case 3: {
                int roll;
                float marks;
                cout << "Enter roll number: ";
                cin >> roll;
                cout << "Enter new marks: ";
                cin >> marks;
                sms.updateMarks(roll, marks);
                break;
            }
            case 4: {
                int roll;
                cout << "Enter roll number to delete: ";
                cin >> roll;
                sms.deleteStudent(roll);
                break;
            }
            case 5:
                sms.displayAllStudents();
                break;
            case 6:
                sms.displayClassAverage();
                break;
            case 7:
                cout << "Thank you for using the Student Management System!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
