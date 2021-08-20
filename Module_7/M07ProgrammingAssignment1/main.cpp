/* Program name: main.cpp
*  Author: Sahaj Khan
*  Date last updated: 11/28/2020
*  Purpose: Create a struct MovieData and store data from user input.  
*/
#include <iostream>
#include <string>
#include <climits>
using namespace std;

struct MovieData {
    string title, genre, director;
    int yearReleased, runningTime;
};

//These functions will take in data and error check.
void inputData(string &data, string dataType);
void inputData(int &data, string dataType);

//Print function
void print(MovieData, int);

int main () {
    MovieData movieData[2];

    //Ask the user for movie data and store into movieData via input function
    for (int i = 0; i < 2; i++) {
        cout << "Entering Data for movie #" << i+1 <<endl;
        inputData(movieData[i].title, "Enter the title of the movie: ");
        inputData(movieData[i].genre, "Enter the genre of the movie: ");
        inputData(movieData[i].director, "Enter the director's name: ");
        inputData(movieData[i].yearReleased, "Enter the year the movie was released: ");
        inputData(movieData[i].runningTime, "Enter the runtime in minutes: ");
        cout << endl << endl;
        cin.ignore(1); //ignore next line skip of next getline(string, string)
    }

    //Print
    for (int i = 0; i < 2; i++) {
        print(movieData[i], i);
    }
    return 0;
}

void inputData (string &data, string dataType) {
    cout << dataType;
    getline(cin, data);
    if (!cin) {
        cout << "\nThat is not a number! Please try again.\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        inputData(data, dataType);
    }
}

void inputData (int &data, string dataType) {
    cout << dataType;
    cin >> data;
    if (!cin) {
        if (dataType.compare("Enter the year the movie was released: ") == 0)
            cout << "The year should be a number after 1887.\n";
        if (dataType.compare("Enter the runtime in minutes: ") == 0)
            cout << "The runtime should be a number greater than 0.\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        inputData(data, dataType);
    }
    //Check if data is a year and is less than 1887
    if (dataType.compare("Enter the year the movie was released: ") == 0 && data < 1887) {
        cout << "The year should be a number after 1887.\n";
        inputData(data, dataType);
    }
    //Check if data is minutes and checks if it is greater than zero
    if (dataType.compare("Enter the runtime in minutes: ") == 0 && data < 1) {
        cout << "The runtime should be a number greater than 0.\n";
        inputData(data, dataType);
    }
}

void print(MovieData md, int i) {
    cout << "Here is the information for movie #" << i+1 << endl;
    cout << "Title: " << md.title << endl;
    cout << "Genre: " << md.genre << endl;
    cout << "Director: " << md.director << endl;
    cout << "Year Released: " << md.yearReleased << endl;
    cout << "Running time (in minutes): " << md.runningTime << endl << endl;
}