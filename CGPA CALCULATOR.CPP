#include <iostream>
#include <map>
#include <string>

using namespace std;

// Function to calculate SGPA
float calculateSGPA(map<string, int> subjectCredits, map<string, float> subjectGrades) {
    float totalCredits = 0;
    float totalGradePoints = 0;

    for (auto const& subject : subjectCredits) {
        totalCredits += subject.second;
        totalGradePoints += subjectGrades[subject.first] * subject.second;
    }

    return totalGradePoints / totalCredits;
}

int main() {
    map<string, int> subjectCredits = {{"Maths", 4}, {"Physics", 4}, {"Graphics", 2}, {"CS", 2}, {"EEE", 2}, {"Phyl", 1}, {"Grapl", 2}, {"CSL", 1}, {"SEM", 1}};
    map<string, float> subjectGrades;

    // Input grades from the user
    for (const auto& subject : subjectCredits) {
        string grade;
        cout << "Enter grade for " << subject.first << ": ";
        cin >> grade;
        if (grade == "ex") subjectGrades[subject.first] = 10;
        else if (grade == "aa") subjectGrades[subject.first] = 9;
        else if (grade == "ab") subjectGrades[subject.first] = 8.5;
        else if (grade == "bb") subjectGrades[subject.first] = 8;
        else if (grade == "bc") subjectGrades[subject.first] = 7.5;
        else if (grade == "cc") subjectGrades[subject.first] = 7;
        else if (grade == "cd") subjectGrades[subject.first] = 6.5;
        else if (grade == "dd") subjectGrades[subject.first] = 6;
        else if (grade == "de") subjectGrades[subject.first] = 5.5;
        else if (grade == "ee") subjectGrades[subject.first] = 5;
        else if (grade == "ff") subjectGrades[subject.first] = 0;
    }

    float sgpa = calculateSGPA(subjectCredits, subjectGrades);

    cout << "SGPA: " << sgpa << endl;

    return 0;
}