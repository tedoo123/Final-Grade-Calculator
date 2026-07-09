/*
    Htet Htoo lwin
    Program: Final Grade calculator
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

void function1(), function2(), function3(int);

struct Container{
    double grade;
    double weight;
    string name;
};

int main() {
    int func;
    cout << "Function 1 or 2?\n";
    cin >> func;

    switch (func) {
        case 1:
            function1();
            break;
        case 2:
            function2();
            break;
    }




    return 0;
}


// Ask for percentage and grade to calculate the final grade
void function1() {
    vector<Container> container;
    cout << "Send the name(no spaces), grade and weight of each category " <<
            "in the format: (name grade weight), weight in decimal\nEnter -1 when done\n";
    double tempGrade, tempWeight, finalGrade = 0;

    while (cin >> tempGrade && tempGrade != -1) {
        cin >> tempWeight;
        container.push_back({tempGrade, tempWeight});
    }

    for (const auto& grade : container) {
        finalGrade += (grade.grade * grade.weight);
    }

    cout << finalGrade;
    
}


//Find minimum final exam grade to get a certain percentage
void function2() {
    double target, tempGrade, tempWeight, finalGrade = 0, goal;
    char YN;
    vector<Container> container;
    cout << "Send the grade and weight of each category in the format: (grade weight), weight in decimal\nEnter -1 when done\n";

    while (cin >> tempGrade && tempGrade != -1) {
        cin >> tempWeight;
        container.push_back({tempGrade, tempWeight});
    }

    cout << "What percentage is your goal?\n";
    cin >> target;
    cout << "What weight is the final grade?\n";
    cin >> tempWeight;

    for (const auto& grade : container) {
        finalGrade += (grade.grade * grade.weight);
    }

    goal = (target - finalGrade) / tempWeight;
    cout << fixed << setprecision(2) << goal << endl;

    cout << "Implement curves? (Y/N)\n";
    cin >> YN;

    if (YN == 'Y' || YN == 'y') {
        function3(finalGrade);
    } else {
        cout << "Final grade: " << finalGrade << endl;
    }

}

void function3(int finalGrade) {
    int curve;
    cout << "Select type of curve:\n"
         << "1. Root Curve\n"
         << "2. Drop lowest quiz\n" 
         << "3. Replace midterm with final\n" 
         << "4. Average of lowest midterm and final is new lowest midterm\n";

    cin >> curve;
    switch (curve) {
        case 1:
            finalGrade = sqrt(finalGrade) * 10;
            break;
        case 2:

            break;

    }
}