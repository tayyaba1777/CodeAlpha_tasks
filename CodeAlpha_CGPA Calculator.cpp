#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to convert letter grade to GPA points
double letterToGPA(string grade) {
    if (grade == "A+" || grade == "A") return 4.0;
    else if (grade == "A-") return 3.7;
    else if (grade == "B+") return 3.3;
    else if (grade == "B") return 3.0;
    else if (grade == "B-") return 2.7;
    else if (grade == "C+") return 2.3;
    else if (grade == "C") return 2.0;
    else if (grade == "C-") return 1.7;
    else if (grade == "D") return 1.0;
    else if (grade == "F") return 0.0;
    else return -1; // invalid grade
}

int main() {
    const int totalCourses = 5;
    string subjects[totalCourses] = {
        "Programming Fundamentals",
        "Application of ICT",
        "Functional English",
        "Calculus",
        "Applied Physics"
    };

    // Predefined credits
    int theoryCredits[totalCourses] = {3, 3, 2, 3, 3};
    int labCredits[totalCourses]    = {1, 1, 0, 0, 1};

    string gradesLetters[totalCourses], labGradesLetters[totalCourses];
    double grades[totalCourses], labGrades[totalCourses];
    double totalGradePoints = 0;
    int totalCredits = 0;
    double courseGPA[totalCourses];

    // Input grades
    for (int i = 0; i < totalCourses; i++) {
        // Theory grade
        while (true) {
            cout << "Enter letter grade for " << subjects[i] << " (A+, A, A-, B+, ... F): ";
            cin >> gradesLetters[i];
            grades[i] = letterToGPA(gradesLetters[i]);
            if (grades[i] != -1) break;
            cout << "Invalid letter grade. Try again.\n";
        }

        // Lab grade if exists
        if (labCredits[i] > 0) {
            while (true) {
                cout << "Enter lab letter grade for " << subjects[i] << ": ";
                cin >> labGradesLetters[i];
                labGrades[i] = letterToGPA(labGradesLetters[i]);
                if (labGrades[i] != -1) break;
                cout << "Invalid letter grade. Try again.\n";
            }
        } else {
            labGrades[i] = -1;
            labGradesLetters[i] = "-";
        }

        // Calculate totals for GPA
        totalGradePoints += grades[i] * theoryCredits[i];
        totalCredits += theoryCredits[i];

        if (labCredits[i] > 0) {
            totalGradePoints += labGrades[i] * labCredits[i];
            totalCredits += labCredits[i];
        }

        // Course GPA = total points / total credits for that course
        int courseTotalCredits = theoryCredits[i] + labCredits[i];
        double courseTotalPoints = grades[i] * theoryCredits[i];
        if (labCredits[i] > 0) courseTotalPoints += labGrades[i] * labCredits[i];
        courseGPA[i] = courseTotalPoints / courseTotalCredits;
    }

    double gpa = totalGradePoints / totalCredits;

    // Print transcript
    cout << "\n================= GPA TRANSCRIPT =================\n";
    cout << left << setw(30) << "Course Name"
         << setw(8) << "Grade"
         << setw(8) << "Credit"
         << setw(10) << "Lab Grade"
         << setw(10) << "Lab Credit"
         << setw(8) << "Course GPA" << endl;
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < totalCourses; i++) {
        cout << left << setw(30) << subjects[i]
             << setw(8) << gradesLetters[i]
             << setw(8) << theoryCredits[i]
             << setw(10) << labGradesLetters[i]
             << setw(10) << labCredits[i]
             << fixed << setprecision(2) << setw(8) << courseGPA[i]
             << endl;
    }

    cout << "------------------------------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "TOTAL GPA (including labs) : " << gpa << endl;
    cout << "============================================================\n";

    return 0;
}
