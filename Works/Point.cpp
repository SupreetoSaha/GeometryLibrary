#include "Point.h"

Point::Point() : _vector() {
	//std::cout<<"Size:"<<_vector.size();
}

Point::Point(std::vector<float> vector) : _vector(vector) {
	//std::cout<<"Size:"<<_vector.size();
}

void Point::display() {
	if(_vector.size()) {
		std::printf("(");
		for(const float& component:_vector) {
			std::printf("%f,",component);
		}
		std::printf("\b)");
	}
	else {
		std::printf("()");
	}
}

float Point::get(const size_t vectorComponent) const {
	return 0<vectorComponent&&vectorComponent<=_vector.size() ? _vector[vectorComponent-1] : 0.f;
}

void Point::set(const size_t vectorComponent,const float componentValue) {
	if(vectorComponent) {
		while(size()<vectorComponent) {
			_vector.emplace_back(0.f);
		}
		_vector[vectorComponent-1] = componentValue;
	}
}

size_t Point::size() {
	auto i {_vector.cend()};
	do {
		--i;
	} while(i!=_vector.cbegin()&&!*i); 
	_vector.erase(++i,_vector.cend());
	return _vector.size();
}

Point Point::add(Point& a,Point& b) {
	Point result {};
	size_t length {std::max(a.size(),b.size())};
	for(size_t i {1};i<=length;++i) {
		result._vector.push_back(a.get(i)+b.get(i));
	}
	return result;
}

Point Point::substract(Point& a,Point& b) {
	Point result {};
	size_t length {std::max(a.size(),b.size())};
	for(size_t i {1};i<=length;++i) {
		result._vector.push_back(b.get(i)-a.get(i));
	}
	return result;
}

Point Point::multiply(Point& a,Point& b) {
	Point result {};
	size_t length {std::max(a.size(),b.size())};
	for(size_t i {1};i<=length;++i) {
		result._vector.push_back(a.get(i)*b.get(i));
	}
	return result;
}

Point Point::divide(Point& a,Point& b) {
	Point result {};
	size_t length {std::max(a.size(),b.size())};
	for(size_t i {1};i<=length;++i) {
		result._vector.emplace_back(a.get(i)+b.get(i));
	}
	return result;
}
