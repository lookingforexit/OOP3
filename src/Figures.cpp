#include "Figures.h"
#include <cmath>
#include <algorithm>

constexpr double eps = 1e-6;

Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) : x(x), y(y) {}

bool Point::operator==(const Point& other) const {
	return (fabs(x - other.x) < eps && fabs(y - other.y) < eps);
}

bool Point::operator!=(const Point& other) const {
	return (fabs(x - other.x) >= eps || fabs(y - other.y) >= eps);
}

bool Point::operator<(const Point& other) const {
	if (fabs(x - other.x) >= eps) {
		return x - other.x < -eps;
	}
	return y - other.y < -eps;
}

bool Point::operator>(const Point& other) const {
	if (fabs(x - other.x) >= eps) {
		return x - other.x > eps;
	}
	return y - other.y > eps;
}

std::istream& operator>>(std::istream& istream, Point& point) {
	if (!(istream >> point.x) || !(istream >> point.y)) {
		throw std::invalid_argument("Incorrect type provided");
	} 

	return istream;
}

std::ostream& operator<<(std::ostream& ostream, const Point& point) {
	return ostream << '(' << point.x << ' ' << point.y << ')';
}

Rhombus::Rhombus() : _points({Point(), Point(), Point(), Point()}) {}

Rhombus::Rhombus(const Rhombus& other) : _points({other._points[0], other._points[1], other._points[2], other._points[3]}) {}

Rhombus::Rhombus(Rhombus&& moved) noexcept : _points(moved._points) {}

Point Rhombus::GetGeometricCenter() const {
	double xCenterCoord = 0;
	double yCenterCoord = 0;

	for (uint64_t i = 0; i < _amountOfPoints; ++i) {
		xCenterCoord += _points[i].x;
		yCenterCoord += _points[i].y;
	}

	return {xCenterCoord / static_cast<double>(_amountOfPoints), yCenterCoord / static_cast<double>(_amountOfPoints)};
}

void swap(Rhombus& firstRhombus, Rhombus& secondRhombus) noexcept {
	std::swap(firstRhombus._points, secondRhombus._points);
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
	if (this != &other) {
		Rhombus copy(other);
		swap(*this, copy);
	}

	return *this;
}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
	if (this != &other) {
		Rhombus moved(std::move(other));
		swap(*this, moved);
	}

	return *this;
}

bool Rhombus::operator==(const Rhombus& other) const {
	std::array<Point, _amountOfPoints> lhsCopy = _points;
	std::array<Point, _amountOfPoints> rhsCopy = other._points;

	std::sort(lhsCopy.begin(), lhsCopy.end());
	std::sort(rhsCopy.begin(), rhsCopy.end());

	return lhsCopy == rhsCopy;
}

std::istream& operator>>(std::istream& istream, Rhombus& rhombus) {
	for (uint64_t i = 0; i < Rhombus::_amountOfPoints; ++i) {
		if (!(istream >> rhombus._points[i])) {
			throw std::invalid_argument("Incorrect type provided");
		}
	}

	return istream;
}
std::ostream& operator<<(std::ostream& ostream, const Rhombus& rhombus) {
	for (uint64_t i = 0; i < Rhombus::_amountOfPoints - 1; ++i) {
		ostream << rhombus._points[i] << ' ';
	}
	ostream << rhombus._points[Rhombus::_amountOfPoints - 1];

	return ostream;
}

Rhombus::operator double() const {
	double firstSide = sqrt((_points[0].x - _points[1].x) * (_points[0].x - _points[1].x) +
							(_points[0].y - _points[1].y) * (_points[0].y - _points[1].y));
	double secondSide = sqrt((_points[0].x - _points[2].x) * (_points[0].x - _points[2].x) +
							 (_points[0].y - _points[2].y) * (_points[0].y - _points[2].y));
	double thirdSide = sqrt((_points[2].x - _points[1].x) * (_points[2].x - _points[1].x) +
							(_points[2].y - _points[1].y) * (_points[2].y - _points[1].y));

	double halfOfPerimeter = (firstSide + secondSide + thirdSide) / 2.0;

	return 2.0 * sqrt(halfOfPerimeter * (halfOfPerimeter - firstSide) * 
					 (halfOfPerimeter - secondSide) * (halfOfPerimeter - thirdSide));
}

Pentagon::Pentagon() : _points({Point(), Point(), Point(), Point(), Point()}) {}

Pentagon::Pentagon(const Pentagon& other) : _points({other._points[0], other._points[1], other._points[2], other._points[3], other._points[4]}) {}

Pentagon::Pentagon(Pentagon&& moved) noexcept : _points(moved._points) {}

Point Pentagon::GetGeometricCenter() const {
	double xCenterCoord = 0;
	double yCenterCoord = 0;

	for (uint64_t i = 0; i < _amountOfPoints; ++i) {
		xCenterCoord += _points[i].x;
		yCenterCoord += _points[i].y;
	}

	return {xCenterCoord / static_cast<double>(_amountOfPoints), yCenterCoord / static_cast<double>(_amountOfPoints)};
}

void swap(Pentagon& firstPentagon, Pentagon& secondPentagon) noexcept {
	std::swap(firstPentagon._points, secondPentagon._points);
}

Pentagon& Pentagon::operator=(const Pentagon& other) {
	if (this != &other) {
		Pentagon copy(other);
		swap(*this, copy);
	}

	return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
	if (this != &other) {
		Pentagon moved(std::move(other));
		swap(*this, moved);
	}

	return *this;
}

bool Pentagon::operator==(const Pentagon& other) const {
	std::array<Point, _amountOfPoints> lhsCopy = _points;
	std::array<Point, _amountOfPoints> rhsCopy = other._points;

	std::sort(lhsCopy.begin(), lhsCopy.end());
	std::sort(rhsCopy.begin(), rhsCopy.end());

	return lhsCopy == rhsCopy;
}

std::istream& operator>>(std::istream& istream, Pentagon& pentagon) {
	for (uint64_t i = 0; i < Pentagon::_amountOfPoints; ++i) {
		if (!(istream >> pentagon._points[i])) {
			throw std::invalid_argument("Incorrect type provided");
		}
	}

	return istream;
}
std::ostream& operator<<(std::ostream& ostream, const Pentagon& pentagon) {
	for (uint64_t i = 0; i < Pentagon::_amountOfPoints - 1; ++i) {
		ostream << pentagon._points[i] << ' ';
	}
	ostream << pentagon._points[Pentagon::_amountOfPoints - 1];

	return ostream;
}

Pentagon::operator double() const {
	double minSide = sqrt((_points[0].x - _points[_amountOfPoints - 1].x) * 
						  (_points[0].x - _points[_amountOfPoints - 1].x) + 
						  (_points[0].y - _points[_amountOfPoints - 1].y) * 
						  (_points[0].y - _points[_amountOfPoints - 1].y));
	double temp = 0;
	for (uint64_t i = 0; i < _amountOfPoints - 1; ++i) {
		temp = sqrt((_points[i].x - _points[i + 1].x) * (_points[i].x - _points[i + 1].x) +
					(_points[i].y - _points[i + 1].y) * (_points[i].y - _points[i + 1].y));

		if (temp < minSide) {
			minSide = temp;
		}
	}

	if (minSide <= 0) {
		return 0;
	}

	return (_amountOfPoints * minSide * minSide / 4.0 * cos(acos(-1.0) / _amountOfPoints) / sin((acos(-1.0) / _amountOfPoints)));
}

Hexagon::Hexagon() : _points({Point(), Point(), Point(), Point(), Point(), Point()}) {}

Hexagon::Hexagon(const Hexagon& other) : _points({other._points[0], other._points[1], other._points[2], other._points[3], other._points[4], other._points[5]}) {}

Hexagon::Hexagon(Hexagon&& moved) noexcept : _points(moved._points) {}

Point Hexagon::GetGeometricCenter() const {
	double xCenterCoord = 0;
	double yCenterCoord = 0;

	for (uint64_t i = 0; i < _amountOfPoints; ++i) {
		xCenterCoord += _points[i].x;
		yCenterCoord += _points[i].y;
	}

	return {xCenterCoord / static_cast<double>(_amountOfPoints), yCenterCoord / static_cast<double>(_amountOfPoints)};
}

void swap(Hexagon& firstHexagon, Hexagon& secondHexagon) noexcept {
	std::swap(firstHexagon._points, secondHexagon._points);
}

Hexagon& Hexagon::operator=(const Hexagon& other) {
	if (this != &other) {
		Hexagon copy(other);
		swap(*this, copy);
	}

	return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
	if (this != &other) {
		Hexagon moved(std::move(other));
		swap(*this, moved);
	}

	return *this;
}

bool Hexagon::operator==(const Hexagon& other) const {
	std::array<Point, _amountOfPoints> lhsCopy = _points;
	std::array<Point, _amountOfPoints> rhsCopy = other._points;

	std::sort(lhsCopy.begin(), lhsCopy.end());
	std::sort(rhsCopy.begin(), rhsCopy.end());

	return lhsCopy == rhsCopy;
}

std::istream& operator>>(std::istream& istream, Hexagon& hexagon) {
	for (uint64_t i = 0; i < Hexagon::_amountOfPoints; ++i) {
		if (!(istream >> hexagon._points[i])) {
			throw std::invalid_argument("Incorrect type provided");
		}
	}

	return istream;
}
std::ostream& operator<<(std::ostream& ostream, const Hexagon& hexagon) {
	for (uint64_t i = 0; i < Hexagon::_amountOfPoints - 1; ++i) {
		ostream << hexagon._points[i] << ' ';
	}
	ostream << hexagon._points[Hexagon::_amountOfPoints - 1];

	return ostream;
}

Hexagon::operator double() const {
	double minSide = sqrt((_points[0].x - _points[_amountOfPoints - 1].x) * 
						  (_points[0].x - _points[_amountOfPoints - 1].x) + 
						  (_points[0].y - _points[_amountOfPoints - 1].y) * 
						  (_points[0].y - _points[_amountOfPoints - 1].y));
	double temp = 0;
	for (uint64_t i = 0; i < _amountOfPoints - 1; ++i) {
		temp = sqrt((_points[i].x - _points[i + 1].x) * (_points[i].x - _points[i + 1].x) +
					(_points[i].y - _points[i + 1].y) * (_points[i].y - _points[i + 1].y));

		if (temp < minSide) {
			minSide = temp;
		}
	}

	if (minSide <= 0) {
		return 0;
	}

	return (_amountOfPoints * minSide * minSide / 4.0 * cos(acos(-1.0) / _amountOfPoints) / sin((acos(-1.0) / _amountOfPoints)));
}