/* Program name: main.cpp
*  Author: Sahaj Khan
*  Date last updated: 12/01/2020
*  Purpose: Import data from school documents and store into an array, then print Highest GPA data
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//make sure you created the programType enum. It has the programs CSCI, DBMS, INFM, SDEV
enum programType {CSCI, DBMS, INFM, SDEV};

 // create the nameType struct.  It has first_name, last_name, and middle_initial.
struct nameType {
	string first_name,  last_name, middle_initial;
};

//create the studentType struct. It has name, id, email, program (should be a programType), and GPA.
struct studentType {
	nameType name;
	string email;
	int id;
	double GPA;
	programType program;
};

//function prototypes
void readClassRoster(ifstream&, studentType[], int&); //reads in the classroster.txt Parameters are an input file handle, array of studentType variables, and the number of students
void readProgramGPA(ifstream&, studentType[], int); //reads in the studentlist.txt and for the students in the roster adds their program and GPA. Parameters are an input file handle, array of studentType variables, and the number of students
int findStudentByID(int, const studentType[], int); //finds the position in the array of the student that has the id provided. returns -1 if not found. Parameters are the studentId to search for, array of studentType variables set to be constant, and the number of students;
double findHighestGPA(const studentType[], int); //finds the highest GPA of all students in the list.  Parameters are the array of studentType variables and the number of students
void printHighestGPA(double, const studentType[], int); //prints the names of the students with the highest GPA Parameters are the highestGPA, array of studentType variables, and number of students
int getSize(string); //returns the size of the number of students in the file



int main() {	
	ifstream input;
	int numOfStudents;

	numOfStudents = getSize("classroster.txt");
	studentType * students;
	students = new studentType[numOfStudents]; //create variable array on heap

	//call the functions to save data into array and output results
	readClassRoster(input, students, numOfStudents);
	readProgramGPA(input, students, numOfStudents);
	printHighestGPA(findHighestGPA(students, numOfStudents), students, numOfStudents);

	delete []students; //free heap memory
	return 0;
}

//reads in the classroster.txt Parameters are an input file handle, array of studentType variables, and the number of students
void readClassRoster(ifstream& input, studentType * students, int& numOfStudents) {
	input.open("classroster.txt");
	input >> numOfStudents;

	for (int i = 0; i < numOfStudents; i++) {
		input >> students[i].name.first_name;
		input >> students[i].name.middle_initial;
		input >> students[i].name.last_name;
		input >> students[i].id;
		input >> students[i].email;
	}
	input.close();
}

//reads in the studentlist.txt and for the students in the roster adds their program and GPA. Parameters are an input file handle, array of studentType variables, and the number of students
void readProgramGPA(ifstream& input, studentType * students, int numOfStudents) {
	string **studentListInfo; //array to store the data from studentlist.txt
	int sizeOfStudentList = 0;//store the number of lines in studentlist.txt
	
	//retrieve number of students from studentlist.txt for proper memory allocations for array
	input.open("studentlist.txt");
	while (!input.eof()) {
		string temp; //temp variable used for cin
		getline(input, temp);
		sizeOfStudentList++;
	}
	input.close();

	//Create a 2D array on heap memory for variablility and retrieve data from studentlist.txt
	input.open("studentlist.txt");
	studentListInfo = new string *[sizeOfStudentList];
	for (int i = 0; i < sizeOfStudentList; i++) {
		studentListInfo[i] = new string [3]; //allocate 3 elements in for every i element initializing 2d array
		for (int j = 0; j < 3; j++) {
			input >> studentListInfo[i][j];
		}
	}
	input.close();

	//Match the IDs and import the correct ProgramType and GPA
	for (int i = 0; i < numOfStudents; i++) {
		for (int j = 0; j < sizeOfStudentList; j++) {
			if (students[i].id == stoi(studentListInfo[j][0])) {
				switch (studentListInfo[j][1].c_str()[0]) {
				case 'S':
					students[i].program = SDEV;
					break;
				case 'C':
					students[i].program = CSCI;
					break;
				case 'I':
					students[i].program = INFM;
					break;
				case 'D':
					students[i].program = DBMS;
					break;
				default:
					break;
				}

				students[i].GPA = stod(studentListInfo[j][2]);
			}
		}
	}
	delete studentListInfo; //deallocate memory from heap
}

//finds the position in the array of the student that has the id provided. returns -1 if not found. Parameters are the studentId to search for, array of studentType variables set to be constant, and the number of students;
int findStudentByID(int ID, const studentType students[], int numOfStudents) {
	for (int i = 0; i < numOfStudents; i++) {
		if (ID == students[i].id)
			return i;
	}
	return -1;
}

//finds the highest GPA of all students in the list.  Parameters are the array of studentType variables and the number of students
double findHighestGPA(const studentType students[], int numOfStudents) {
	double highestGPA = 0;
	for (int i = 0; i < numOfStudents; i++) {
		if (highestGPA < students[i].GPA)
			highestGPA = students[i].GPA;
	}
	return highestGPA;
}

//prints the names of the students with the highest GPA Parameters are the highestGPA, array of studentType variables, and number of students
void printHighestGPA(double highestGPA, const studentType students[], int numOfStudents) {
	cout << "The students with the highest GPA of " << highestGPA << " are:\n";

	for (int i = 0; i < numOfStudents; i++) {
		if (students[i].GPA == highestGPA) {
			cout << students[i].id << " - " << students[i].name.last_name << ", " << students[i].name.first_name << endl;		
		}
	}
}

//returns the size of the number of students in the file
int getSize(string s) {
	ifstream input;
	input.open(s);
	int size;
	input >> size;
	input.close();
	return size;
}