#include <complex>

#include "Line.h"

template struct Point<int>;
template struct Point<float>;
template struct Point<double>;
template struct Point<std::complex<float>>;
template struct Point<std::complex<double>>;

template<typename T>
Point<T>::Point(T key1, T key2)
{
	x = key1;
	y = key2;
}

template<typename T>
Point<T> Point<T>::operator=(const Point<T>& other) {
	x = other.x;
	y = other.y;

	return *this;
}

template class Line<int>;
template class Line<float>;
template class Line<double>;

template<typename T>
Line<T>::Line(const Line<T>& other)
{
	arr = new Point<T>[other.size_of];
	size_of = other.size_of;
	for (size_t i = 0; i < size_of; i++)
	{
		arr[i] = other.arr[i];
	}
}

template<typename T>
Line<T>::~Line()
{
	delete[] arr;
	size_of = 0;
}

template<typename T>
Line<T> Line<T>::operator=(const Line<T>& other) {
	if (this == &other) {
		return *this;
	}

	delete[] arr;
	size_of = other.size_of;
	arr = new Point<T>[size_of];

	for (size_t i = 0; i < size_of; i++)
		arr[i] = other.arr[i];

	return *this;
}

template<typename T>
Point<T>& Line<T>::operator[](size_t index) {
	checkIndex(index);
	return arr[index];
}

template<typename T>
Line<T> Line<T>::operator+=(const Point<T>& point) {
	Point<T> *helpArr = new Point<T>[size_of + 1];
	for (size_t i = 0; i < size_of; i++)
		helpArr[i] = arr[i];
	helpArr[size_of] = point;

	delete[] arr;
	size_of++;
	arr = new Point<T>[size_of];

	for (size_t i = 0; i < size_of; i++)
		arr[i] = helpArr[i];

	delete[] helpArr;
	return *this;
}

template<typename T>
Line<T> Line<T>::operator+=(const Line<T>& other) {
	Point<T>* helpArr = new Point<T>[size_of + other.size_of];

	for (size_t i = 0; i < size_of; i++)
		helpArr[i] = arr[i];
	for (size_t i = size_of; i < size_of + other.size_of; i++)
		helpArr[i] = arr[i - size_of];

	delete[] arr;
	size_of+= other.size_of;
	arr = new Point<T>[size_of];

	for (size_t i = 0; i < size_of; i++)
		arr[i] = helpArr[i];

	delete[] helpArr;
	return *this;
}

template<typename T>
Line<T> Line<T>::operator+(const Point<T>& point) {
	Line<T> NewLine(size_of+1);

	for (size_t i = 0; i < size_of; i++)
		NewLine.arr[i] = arr[i];
	NewLine.arr[size_of] = point;

	return NewLine;
}

template<typename T>
Line<T> Line<T>::operator+(const Line<T>& other) {
	Line<T> NewLine(size_of + other.size_of);

	for (size_t i = 0; i < size_of; i++)
		NewLine.arr[i] = arr[i];
	for (size_t i = size_of; i < size_of + other.size_of; i++)
		NewLine.arr[i] = other.arr[i - size_of];

	return NewLine;
}

template<typename T>
Line<T> operator+(const Point<T>& point, const Line<T>& other) {
	Line<T> NewLine(other.size_of + 1);

	NewLine.arr[0] = point;
	for (size_t i = 0; i < other.size_of; i++)
		NewLine.arr[i+1] = other.arr[i];
	

	return NewLine;
}

template<typename T>
size_t Line<T>::size() {
	return size_of;
}

template<typename T>
double Line<T>::lenght() {
	double len = 0;
	for (size_t i = 0; i < size_of - 1; i++) {
		len += distance(arr[i], arr[i + 1]);
	}
	return len;
}

template<typename T>
double Line<T>::distance(const Point<T>& point1, const Point<T>& point2) {
	double x = point2.x - point1.x;
	double y = point2.y - point1.y;

	return sqrt(x * x + y * y);
}

template<typename T>
void Line<T>::checkIndex(size_t index) {
	if (index >= size_of) {
		throw std::out_of_range("Index is greater than the number of points");
	}
}

template class Line<std::complex<float>>;
template class Line<std::complex<double>>;

template<typename C>
Line<std::complex<C>>::Line(const Line<std::complex<C>>& other)
{
	arr = new Point<std::complex<C>>[other.size_of];
	size_of = other.size_of;
	for (size_t i = 0; i < size_of; i++)
	{
		arr[i] = other.arr[i];
	}
}

template<typename C>
Line<std::complex<C>>::~Line()
{
	delete[] arr;
	size_of = 0;
}

template<typename C>
Line<std::complex<C>> Line<std::complex<C>>::operator=(const Line<std::complex<C>>& other) {
	if (this == &other) {
		return *this;
	}

	delete[] arr;
	size_of = other.size_of;
	arr = new Point<std::complex<C>>[size_of];

	for (size_t i = 0; i < size_of; i++)
		arr[i] = other.arr[i];

	return *this;
}

template<typename C>
Point<std::complex<C>>& Line<std::complex<C>>::operator[](size_t index) {
	checkIndex(index);
	return arr[index];
}

template<typename C>
Line<std::complex<C>> Line<std::complex<C>>::operator+=(const Point<std::complex<C>>& point) {
	Point<std::complex<C>>* helpArr = new Point<std::complex<C>>[size_of + 1];
	for (size_t i = 0; i < size_of; i++)
		helpArr[i] = arr[i];
	helpArr[size_of] = point;

	delete[] arr;
	size_of++;
	arr = new Point<std::complex<C>>[size_of];

	for (size_t i = 0; i < size_of; i++)
		arr[i] = helpArr[i];

	delete[] helpArr;
	return *this;
}

template<typename C>
Line<std::complex<C>> Line<std::complex<C>>::operator+=(const Line<std::complex<C>>& other) {
	Point<std::complex<C>>* helpArr = new Point<std::complex<C>>[size_of + other.size_of];

	for (size_t i = 0; i < size_of; i++)
		helpArr[i] = arr[i];
	for (size_t i = size_of; i < size_of + other.size_of; i++)
		helpArr[i] = arr[i - size_of];

	delete[] arr;
	size_of += other.size_of;
	arr = new Point<std::complex<C>>[size_of];

	for (size_t i = 0; i < size_of; i++)
		arr[i] = helpArr[i];

	delete[] helpArr;
	return *this;
}

template<typename C>
Line<std::complex<C>> Line<std::complex<C>>::operator+(const Point<std::complex<C>>& point) {
	Line<std::complex<C>> NewLine(size_of + 1);

	for (size_t i = 0; i < size_of; i++)
		NewLine.arr[i] = arr[i];
	NewLine.arr[size_of] = point;

	return NewLine;
}

template<typename C>
Line<std::complex<C>> Line<std::complex<C>>::operator+(const Line<std::complex<C>>& other) {
	Line<std::complex<C>> NewLine(size_of + other.size_of);

	for (size_t i = 0; i < size_of; i++)
		NewLine.arr[i] = arr[i];
	for (size_t i = size_of; i < size_of + other.size_of; i++)
		NewLine.arr[i] = other.arr[i - size_of];

	return NewLine;
}

template<typename C>
Line<std::complex<C>> operator+(const Point<std::complex<C>>& point, const Line<std::complex<C>>& other) {
	Line<std::complex<C>> NewLine(other.size_of + 1);

	NewLine.arr[0] = point;
	for (size_t i = 0; i < other.size_of; i++)
		NewLine.arr[i + 1] = other.arr[i];


	return NewLine;
}

template<typename C>
size_t Line<std::complex<C>>::size() {
	return size_of;
}

template<typename C>
double Line<std::complex<C>>::lenght() {
	double len = 0;
	for (size_t i = 0; i < size_of - 1; i++) {
		len += distance(arr[i], arr[i + 1]);
	}
	return len;
}

template<typename C>
double Line<std::complex<C>>::distance(const Point<std::complex<C>>& point1, const Point<std::complex<C>>& point2) {
	std::complex<C> x = point2.x - point1.x;
	std::complex<C> y = point2.y - point1.y;

	std::complex<C> res = sqrt(x * x + y * y);
	return sqrt(res.imag() * res.imag() + res.real() * res.real());
}

template<typename C>
void Line<std::complex<C>>::checkIndex(size_t index) {
	if (index >= size_of) {
		throw std::out_of_range("Index is greater than the number of points");
	}
}