// Geometry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>

// to header commences
struct Point {
	float _x;
	float _y;
public:
	Point(float x,float y);
};
// to header ends

int main()
{
	std::cout<<"Hello!\n";
	Point p {10,23};
}

// to cpp commences
Point::Point(float x,float y) : _x(x),_y(y) {
	std::printf("Initialied %f,%f\n",_x,_y);
}
// to cpp ends

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
