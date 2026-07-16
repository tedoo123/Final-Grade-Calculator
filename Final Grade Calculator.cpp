/*
    Htet Htoo lwin
    Program: Final Grade calculator
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

void function1(), function2(), function3(double, double, double);

struct Container{
    vector<double> grades;
    double weight;
    string name;
};

int main() {
    int func;
    cout << "Function 1 or 2?\n";
    cin >> func;
    cin.ignore();

    switch (func) {
        case 1:
            //function1();
            break;
        case 2:
            function2();
            break;
    }




    return 0;
}

/*
// Ask for percentage and grade to calculate the final grade
void function1() {
    string name;
    vector<Container> container;
    double tempGrade, tempWeight, finalGrade = 0;
    
    while (true) {
        Container category;
        cout << "\nWhat is the name of the category?: \n";
        cout << "Enter -1 when done\n";
        getline(cin, name);
        if (name == "-1") {
            break;
        }
        category.name = name;

        cout << "\nWhat is the weight in decimal:\n";
        while (true) {
            cin >> category.weight;

            if (category.weight >= 0 && category.weight <= 1)
                break;

            cout << "Weight must be between 0 and 1.\n";
        }

        cout << "\nWhat is the grades:\nType -1 when done\n";
        while (cin >> tempGrade && tempGrade != -1) {
            if (tempGrade < 0 || tempGrade > 100) {
                cout << "Invalid grade. Enter 0-100. Please try again:\n";
                continue;
            }
            category.grades.push_back(tempGrade);
        }


        cin.ignore();

        container.push_back(category);
    }

    for (const auto& category : container) {
        double sum = 0;

        for (double grade : category.grades) {
            sum += grade;
        }

        double average = sum / category.grades.size();

        finalGrade += average * category.weight;
    }

    cout << "Final grade:" << fixed << setprecision(2) << finalGrade << endl;
    
}
*/


//Find minimum final exam grade to get a certain percentage
void function2() {
    string name;
    vector<Container> container;
    double target, goal, tempGrade, tempWeight, finalGrade = 0;
    
    while (true) {
        Container category;
        cout << "\nWhat is the name of the category?: \n";
        cout << "Enter -1 when done\n";
        getline(cin, name);
        if (name == "-1") {
            break;
        }
        category.name = name;

        cout << "\nWhat is the weight in decimal:\n";
        while (true) {
            cin >> category.weight;

            if (category.weight >= 0 && category.weight <= 1)
                break;

            cout << "Weight must be between 0 and 1.\n";
        }

        cout << "\nWhat is the grades:\nType -1 when done\n";
        while (cin >> tempGrade && tempGrade != -1) {
            if (tempGrade < 0 || tempGrade > 100) {
                cout << "Invalid grade. Enter 0-100. Please try again:\n";
                continue;
            }
            category.grades.push_back(tempGrade);
        }


        cin.ignore();

        container.push_back(category);
    }

    cout << "\nWhat percentage is your goal?\n";
    cin >> target;

    cout << "\nWhat weight is the final grade in decimals?\n";
    cin >> tempWeight;

    for (const auto& category : container) {
        double sum = 0;

        for (double grade : category.grades) {
            sum += grade;
        }

        double average = sum / category.grades.size();

        finalGrade += average * category.weight;
    }

    goal = (target - finalGrade) / tempWeight;

    char YN;
    
    cout << "Implement curves? (Y/N)\n";
    
    while (cin >> YN) {
        if (toupper(static_cast<unsigned char>(YN)) == 'Y') {
            cout << "You said yes to curve!";
            //function3(finalGrade, target, tempWeight);
            break;
        } else if (toupper(static_cast<unsigned char>(YN)) == 'N') {
            cout << "Min final score: " << fixed << setprecision(2) <<  goal << endl;
            break;
        } else {
            cout << "You didn't press a Y or N, please try again\n";
        }
    }   

}

/*
void function3(double finalGrade, double target, double tempWeight) {
    double goal;
    int curve;
    cout << "Select type of curve:\n"
         << "1. Root Curve\n"
         << "2. Drop lowest quiz\n" 
         << "3. Replace midterm with final\n" 
         << "4. Average of lowest midterm and final is new lowest midterm\n";

    cin >> curve;
    switch (curve) {
        case 1:
            cout << "Square root curve is when square rooting your final grade in decimal and then turning it back into percentage. (e.g. 81% to 90%)\n"; 
            goal = (pow((target / 10), 2) - finalGrade) / tempWeight;
            break;
        case 2:

            break;

    }

    cout << "Min final score: " << fixed << setprecision(2) << goal << endl;
}
*/

