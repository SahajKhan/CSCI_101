/* Program name: Area of a Circle
*  Author: Sahaj Khan
*  Date last updated: 12/01/2020
*  Purpose: Calculate the radius, area, and perimiter of a circle.
*  UPDATE - Use structs to store the values.
*/
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

/*These variables represent values on a cartesian plane*/
struct Circle {
	double x1, x2, y1, y2;
};

/*Functions that represent the required formulas*/
double calculateRadius(double x1, double y1, double x2, double y2) {return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));}

double calculateArea(double r) { return atan(1) * 4 * r * r;}	   //atan(1) * 4 is the formula for pi

double calculatePerimeter(double r) { return 2 * r * atan(1) * 4;} //atan(1) * 4 is the formula for pi


int main() {
	/*Use the Circle struct to store all the values represented in a cartesian plane*/
	Circle c;


	/*Output and Input*/
	cout << "Please enter the center point in the form x y: ";
	cin  >> c.x1 >> c.y1;
	cout << endl;

	/*Error checking*/
	while (!cin) {
		cout << "You entered something that is not a number. Please try again\n\n";
		cout << "Please enter the center point in the form x y: ";
		
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin  >> c.x1 >> c.y1;
		cout << endl;
	}

	/*Output and Input*/
	cout << "Please enter the point on the circle in the form x y: ";
	cin  >> c.x2 >> c.y2;
	cout << endl;

	/*Error Checking*/
	while (!cin) {
		cout << "You entered something that is not a number. Please try again\n\n";
		cout << "Please enter the point on the circle in the form x y: ";
		
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin  >> c.x2 >> c.y2;
		cout << endl;
	}

	double radius = calculateRadius(c.x1, c.y1, c.x2, c.y2);
	
	/*Print Statement*/
	cout << "Here is the information for the circle formed from (" << c.x1 << ","<< c.y1
		 << ") and (" << c.x2 << "," << c.y2 << ")" << endl;
	cout << "Radius: " << radius << endl;
	cout << "Area: " << calculateArea(radius) << endl;
	cout << "Perimeter: " << calculatePerimeter(radius) << endl;

	return 0;
}