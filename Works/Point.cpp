#include "Point.h"

Point::Point() : _vector() {
	std::cout<<"Size:"<<_vector.size();
}

Point::Point(std::vector<float> vector) : _vector(vector) {
	std::cout<<"Size:"<<_vector.size();
}

void Point::display() {
	std::printf("\n(");
	for(const float& component:_vector) {
		std::printf("%f,",component);
	}
	std::printf("\b)");
}

Point Point::add(const Point& a,const Point& b) {
	Point result {};
	auto length {std::max(a._vector.size(),b._vector.size())};
	return Point({length*1.f});
}
