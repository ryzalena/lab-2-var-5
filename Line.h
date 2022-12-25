#pragma once

template <typename T>
struct Point
{
	T x;
	T y;

	Point(T key1, T key2);
	Point() : x(0), y(0) {};
	Point<T> operator=(const Point<T>& other);
};

template<typename T>
class Line
{
	Point<T>* arr;
	size_t size_of;

public:
	Line():arr(nullptr), size_of(0){}
	Line(size_t count) : arr(new Point<T>[count]), size_of(count) {}
	Line(const Line<T>& p);
	~Line();
	Line<T> operator=(const Line<T>& other);
	Point<T>& operator[](size_t index);
	Line<T> operator+=(const Point<T>& point);
	Line<T> operator+=(const Line<T>& other);
	Line<T> operator+(const Point<T>& point);
	Line<T> operator+(const Line<T>& other);
	friend Line<T> operator+(const Point<T>& point, const Line<T>& other);
	size_t size();
	double lenght();

private:
	double distance(const Point<T>& point1, const Point<T>& point2);
	void checkIndex(size_t index);
};

template<typename C>
class Line<std::complex<C>> {
	Point<std::complex<C>>* arr;
	size_t size_of;

public:
	Line() :arr(nullptr), size_of(0) {}
	Line(size_t count) : arr(new Point<std::complex<C>>[count]), size_of(count) {}
	Line(const Line<std::complex<C>>& p);
	~Line();
	Line<std::complex<C>> operator=(const Line<std::complex<C>>& other);
	Point<std::complex<C>>& operator[](size_t index);
	Line<std::complex<C>> operator+=(const Point<std::complex<C>>& point);
	Line<std::complex<C>> operator+=(const Line<std::complex<C>>& other);
	Line<std::complex<C>> operator+(const Point<std::complex<C>>& point);
	Line<std::complex<C>> operator+(const Line<std::complex<C>>& other);
	friend Line<std::complex<C>> operator+(const Point<std::complex<C>>& point, const Line<std::complex<C>>& other);
	size_t size();
	double lenght();
private:
	double distance(const Point<std::complex<C>>& point1, const Point<std::complex<C>>& point2);
	void checkIndex(size_t index);
};

