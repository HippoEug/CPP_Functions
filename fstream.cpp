#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void aboutProgram();
void newStudent();
void lineCount(int &numberOfLines);
void viewFile(int numberOfLines);

int main()
{
    int choice;
    int numberOfLines;
    
    aboutProgram();
    cout << "Choice: ";
    cin >> choice;
    
    while (choice != 3)
    {
        switch (choice)
        {
            case 1:
            {
                newStudent();
                break;
            }
            case 2:
            {
                lineCount(numberOfLines);
                viewFile(numberOfLines);
                break;
            }
            case 3:
            {
                cout << "Bye!" << endl;
                break;
            }
            default:
                cout << "Invalid Choice!" << endl;
                break;
        }
        aboutProgram();
        cout << "Choice: ";
        cin >> choice;
    }
}

void aboutProgram()
{
    cout << "Program stores Grades for Students" << endl;
    cout << "===================================" << endl;
    cout << "1. Add a New Student" << endl;
    cout << "2. View File Content" << endl;
    cout << "3. End the program" << endl << endl;
}

void newStudent()
{
    ofstream outFile;
    outFile.open("ES6x", std::ios_base::app);
    
    double sub1, sub2, sub3, sub4, sub5;
    double average;
    
    string firstName;
    string lastName;
    
    cout << "\nEnter First name: ";
    cin >> firstName;
    cout << "Enter Last name: ";
    cin >> lastName;
    outFile << "\nStudent Name: " << firstName << " " << lastName << endl;
    
    cout << "\nEnter Results for 5 subjects, leaving a space between each subject: ";
    cin >> sub1 >> sub2 >> sub3 >> sub4 >> sub5;
    
    outFile << "Test scores: " << setw(6) << sub1 << setw(6) << sub2 << setw(6) << sub3 << setw(6) << sub4 << setw(7) << sub5 << endl;
    
    average = (sub1 + sub2 + sub3 + sub4 + sub5)/5.0;
    cout << "Average = " << average << endl << endl;
    outFile << "Average Test Score: " << setw(6) << average << endl << endl;
    
    outFile.close();
}

void lineCount(int& numberOfLines)
{
    ifstream inFile;
    inFile.open("ES6x");
    
    string line;
    
    numberOfLines = 0; //important to reset back to 0 each time you count the number of lines
    while (getline(inFile, line))
        ++numberOfLines;
}

void viewFile(int numberOfLines)
{
    ifstream inFile;
    inFile.open("ES6x");
    
    double sub1, sub2, sub3, sub4, sub5, average;
    int i, repeat;
    
    string student, name, firstName, lastName;
    string test, scores;
    string average2, test2, score2;
    
    repeat = (numberOfLines/5.0);
    
    for (i = 0; i < repeat; i++)
    {
        inFile >> student >> name >> firstName >> lastName;
        inFile >> test >> scores >> sub1 >> sub2 >> sub3 >> sub4 >> sub5;
        inFile >> average2 >> test2 >> score2 >> average;
        
        cout << "Student Name: " << firstName << " " << lastName << endl;
        cout << "Test scores: " << setw(6) << sub1 << setw(6) << sub2 << setw(6) << sub3 << setw(6) << sub4 << setw(7) << sub5 << endl;
        cout << "Average = " << average << endl << endl;
    }
    inFile.close();
}
