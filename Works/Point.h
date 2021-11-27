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

	/**
	* \brief						Fetches the, 1-indexed, component-value, if available. Otherwise, 0 (zero).
	* \param[in] vectorComponent	1-indexed component.
	* \return						Value of the component, if present. Otherwise, 0 (zero).
	*/
	float get(const size_t vectorComponent) const;

	/**
	* \brief						Sets componentValue to specified vectorComponent.
	* \param[in] vectorComponent	1-indexed component.
	* \param[in] componentValue		Value of the component.
	*/
	void set(const size_t vectorComponent,const float componentValue);

	/**
	* \brief	Determines the actual dimension of Point.
	* \return	Dimension (non-trivial) of the Point vector.
	*/
	size_t size();

	/**
	* \brief		Adds a and b, component-wise.
	* \param[in] a	Instance of class Point.
	* \param[in] b	Instance of class Point.
	* \return		New instance of class Point containing the result.
	*/
	static Point add(Point& a,Point& b);

	/**
	* \brief		Substracts a from b, component-wise.
	* \param[in] a	Instance of class Point.
	* \param[in] b	Instance of class Point.
	* \return		New instance of class Point containing the result.
	*/
	static Point substract(Point& a,Point& b);

	/**
	* \brief		Multiplies a with b, component-wise.
	* \param[in] a	Instance of class Point.
	* \param[in] b	Instance of class Point.
	* \return		New instance of class Point containing the result.
	*/
	static Point multiply(Point& a,Point& b);

	/**
	* \brief		Divides a by b, component-wise.
	* \param[in] a	Instance of class Point.
	* \param[in] b	Instance of class Point.
	* \return		New instance of class Point containing the result.
	*/
	static Point divide(Point& a,Point& b);

};
