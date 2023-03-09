#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Employee {
    string name;
    int nKeysPossessed;
    string keys[5];
};

bool reader(string input_filename, Employee employees[], int& nEmployees){
    ifstream inStream(input_filename);
    if (!inStream.is_open()){
        return false;
    }
    string line;
    getline(inStream, line);
    nEmployees = stoi(line);
    for (int i = 0; i < nEmployees; i++){
        getline(inStream, line);
        cout << line;
    }
    return true;
}

void writer(string output_filename, Employee employees[], int nEmployees){
    cout << "code not finished" << endl;
}

bool addKeyForEmployee(Employee employees[], int nEmployees){
    cout << "code not finished" << endl;
}

bool returnAKey(Employee employees[], int nEmployees, string emp_name, string returnKey){
    cout << "code not finished" << endl;
}

int main() {
    int nEmployees;
    string input_filename;
    cout << "Please enter key file name to start: ";
    cin >> input_filename;
    reader(input_filename, );

    // CREATE A DO WHILE LOOP TO ASK FOR INPUT IN MENU IF USER SELECTS INVALID OPTION PRINT "Not a valid option. Please try again.".
    // EACH OPTION IN THE MENU SHOULD CORRESPOND TO A FUNCTION
    int choice;

    /*do {
        if (choice == 1) {

        }









    } while ((choice < 8) && (choice > 0));
    */





    return 0;
}
