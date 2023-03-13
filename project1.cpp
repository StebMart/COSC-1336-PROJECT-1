#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Employee {
    string name;
    int nKeysPossessed;
    string keys[5];
};

// read and 
bool reader(string input_filename, Employee employees[], int& nEmployees){
    ifstream inStream(input_filename);
    if (!inStream.is_open()){
        cout << "File not found, exiting the program...";
        return false;
    }
    string line;
    int numKeys;
    getline(inStream, line);
    nEmployees = stoi(line);
    for (int i = 0; i < nEmployees; i++){
        getline(inStream, line);
        employees[i].name = line;
        getline(inStream, line,' ');
        numKeys = stoi(line);
        employees[i].nKeysPossessed = numKeys;
        for (int j = 0; j < (numKeys-1); j++) {
            getline(inStream, line,' ');
            employees[i].keys[j] = line;
        }
        getline(inStream, line,'\n');
        employees[i].keys[numKeys-1] = line;
    }
    inStream.close();
    return true;
}

// this writer function will output current employees data in the same format as input file
void writer(string output_filename, Employee employees[], int nEmployees){
    ofstream outStream(output_filename);
    outStream << nEmployees << endl;
    for (int i = 0; i < nEmployees; i++) {
        outStream << employees[i].name << endl;
        outStream << employees[i].nKeysPossessed;
        for (int j = 0; j < employees[i].nKeysPossessed; j++) {
            outStream << " " << employees[i].keys[j];
        }
        outStream << endl;
    }
    outStream.close();
}

// this function will add a specified key to a specified employee, if employee does not exist, they already have 5 keys, or the specified key is already included. exit function and return false
bool addKeyForEmployee(Employee employees[], int nEmployees, string emp_name, string newKey){
    bool temp;
    int loc;
    temp = false;

    for (int i = 0; i < nEmployees; i++) {
        if (employees[i].name == emp_name){
            temp = true;
            loc = i;
        }
    }
    if (temp == false){
        cout << "Cannot find the specified employee!" << endl;
        return false;
    }

    if (employees[loc].nKeysPossessed == 5) {
        cout << "This employee already has 5 keys!" << endl;
        return false;
    }
    
    for (int i = 0; i < employees[loc].nKeysPossessed; i++){
        if (employees[loc].keys[i] == newKey){
            cout << "This employee already has this key!" << endl;
            return false;
        }
    }

    int last;
    last = employees[loc].nKeysPossessed;
    employees[loc].nKeysPossessed = last + 1;
    employees[loc].keys[last] = newKey;

    return true;
}

// this funciton will delete a specified key from specified employee, if employee does not exist, or key does not exist. exit function and return false
bool returnAKey(Employee employees[], int nEmployees, string emp_name, string returnKey){
    bool temp;
    int loc;
    temp = false;

    for (int i = 0; i < nEmployees; i++) {
        if (employees[i].name == emp_name){
            temp = true;
            loc = i;
        }
    }
    if (temp == false){
        cout << "Cannot find the specified employee!" << endl;
        return false;
    }
    for (int i = 0; i < employees[loc].nKeysPossessed; i++){
        if (employees[loc].keys[i] == returnKey){
            employees[loc].nKeysPossessed -= 1;
            employees[loc].keys[i] = employees[loc].keys[employees[loc].nKeysPossessed];
            return true;
        }
    }

    cout << "This employee does not have the specified key!" << endl;
    return false;

}

int main() {
    int nEmployees;
    bool fileOpen;
    string input_filename;
    cout << "Please enter key file name to start: ";
    cin >> input_filename;
    Employee employees[20];
    fileOpen = reader(input_filename, employees, nEmployees);
    if (fileOpen == false){
        return false;
    }
    
    // CREATE A DO WHILE LOOP TO ASK FOR INPUT IN MENU IF USER SELECTS INVALID OPTION PRINT "Not a valid option. Please try again.".
    // EACH OPTION IN THE MENU SHOULD CORRESPOND TO A FUNCTION
    int choice;
    


    do {
        cout << "Please select from the following options: " << endl;
        cout << "  1. show all employees and their keys" << endl;
        cout << "  2. show the keys an employee possesses" << endl;
        cout << "  3. show which employees possess a specific key" << endl;
        cout << "  4. add a key to an employee" << endl;
        cout << "  5. return a key by an employee" << endl;
        cout << "  6. save the current key status" << endl;
        cout << "  7. exit the program" << endl;
        cin >> choice;
        bool complete;
        string emp_name;
        string newKey;
        string returnKey;
        string outputName;
        if (choice == 1) {
            for (int i = 0; i < nEmployees; i++){
                cout << "Name: " << employees[i].name << endl;
                cout << "Keys possessed: ";
                for (int j = 0; j < employees[i].nKeysPossessed; j++){
                    cout << employees[i].keys[j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        else if (choice == 2) {
            cout << "Please enter employee's name: ";
            complete = false;
            string name;
            cin.ignore();
            getline(cin, name);
            for (int i = 0; i < nEmployees; i++){
                if (name == employees[i].name){
                    cout << employees[i].name << " possess the following keys: ";
                    for (int j = 0; j < employees[i].nKeysPossessed; j++){
                        cout << employees[i].keys[j] << " ";
                    }
                    cout << endl;
                    complete = true;
                }
            }
            if (complete == false) {
                cout << "Cannot find the specified employee!" << endl;
            }
            cout << endl;

        }
        else if (choice == 3) {
            cout << "Please enter a key: ";
            complete = false;
            string name;
            cin >> name;
            for (int i = 0; i < nEmployees; i++) {
                for (int j = 0; j < employees[i].nKeysPossessed; j++){
                    if (employees[i].keys[j] == name){
                        cout << employees[i].name << ", ";
                        complete = true;
                    }
                }
            }
            if (complete == false){
                cout << "No one possesses this key." << endl << endl;
            }
            else if (complete == true) {
                cout << "possess this key." << endl << endl;
            }
            

        }
        else if (choice == 4) {
            cout << "Please enter employee's name: ";
            cin.ignore();
            getline(cin, emp_name);
            cout << "Please enter a new key: ";
            cin >> newKey;
            complete = addKeyForEmployee(employees, nEmployees, emp_name, newKey);
            if (complete == true) {
                cout << "Key added successfully." << endl;
            }
            cout << endl;
        }
        else if (choice == 5) {
            cout << "Please enter employee's name: ";
            cin.ignore();
            getline(cin, emp_name);
            cout << "Please enter the returned key: ";
            cin >> returnKey;
            complete = returnAKey(employees, nEmployees, emp_name, returnKey);
            
            if (complete == true){
                cout << "Key returned successfully." << endl;
            }
            cout << endl;

        }
        else if (choice == 6) {
            cout << "Please enter output file name: ";
            cin >> outputName;
            writer(outputName, employees, nEmployees);
            cout << endl;
        }
        else if (choice == 7) {
            writer("keys_updated.txt", employees, nEmployees);
            cout << "Thank you for using the system! Goodbye!" << endl;
        }
        else {
            cout << "Not a valid option. Please try again." << endl << endl;
        }


    } while (choice != 7);   





    return 0;
}
