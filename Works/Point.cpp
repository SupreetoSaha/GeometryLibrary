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

void Point::set(const std::string vectorComponent,const float componentValue) {
	if(std::strstr(vectorComponent.c_str(),"x")) {
		set(1,componentValue);
	}
	if(std::strstr(vectorComponent.c_str(),"y")) {
		set(2,componentValue);
	}
	if(std::strstr(vectorComponent.c_str(),"z")) {
		set(3,componentValue);
	}
	if(std::strstr(vectorComponent.c_str(),"t")) {
		set(4,componentValue);
	}
}

float& Point::access(const size_t vectorComponent) {
	if(vectorComponent) {
		while(size()<vectorComponent) {
			_vector.emplace_back(0.f);
		}
		return _vector[vectorComponent-1];
	}
	throw std::out_of_range("Requires natural number.");
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
		result._vector.emplace_back(a.get(i)+b.get(i));
	}
	return result;
}

Point Point::add(const Point& a,const float n) {
	Point result {};
	for(const float componentValue : a._vector) {
		result._vector.emplace_back(componentValue+n);
	}
	return result;
}

float Point::_componentSummation(const std::vector<Point>& points,const size_t vectorComponent) {
	float result {0};
	for(Point point : points) {
		result += point.get(vectorComponent);
	}
	return result;
}

Point Point::add(const std::vector<Point>& points,size_t length) {
	Point result {};
	if(!length) {
		for(Point point : points) {
			length = std::max(length,point.size());
		}
	}
	std::vector<std::future<float>> futures;
	for(size_t i {1};i<=length;++i) {
		futures.emplace_back(std::async(_componentSummation,points,i));
	}
	for(std::future<float>& future : futures) {
		result._vector.emplace_back(future.get());
	}
	return result;
}

Point Point::substract(Point& a,Point& b) {
	Point result {};
	size_t length {std::max(a.size(),b.size())};
	for(size_t i {1};i<=length;++i) {
		result._vector.emplace_back(b.get(i)-a.get(i));
	}
	return result;
}

Point Point::multiply(Point& a,Point& b) {
	Point result {};
	size_t length {std::max(a.size(),b.size())};
	for(size_t i {1};i<=length;++i) {
		result._vector.emplace_back(a.get(i)*b.get(i));
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
