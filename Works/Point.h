#pragma once

#include <cstdio>
#include <iostream>
#include <vector>

class Point {
	std::vector<float> _vector {};
public:
	Point();
	Point(std::vector<float> vector);
	void display();
	Point add(const Point& a,const Point& b);
	Point substract(const Point& a,const Point& b);
	Point multiply(const Point& a,const Point& b);
	Point divide(const Point& a,const Point& b);
};
