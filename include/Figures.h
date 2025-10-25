#ifndef FIGURES_H
#define FIGURES_H

#include <iostream>
#include <array>
#include <cinttypes>

struct Point {
	double x;
	double y;

	Point();
	Point(double x, double y);

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;
	bool operator<(const Point& other) const;
	bool operator>(const Point& other) const;

	friend std::istream& operator>>(std::istream& istream, Point& point);
	friend std::ostream& operator<<(std::ostream& ostream, const Point& point);
};

std::istream& operator>>(std::istream& istream, Point& point);
std::ostream& operator<<(std::ostream& ostream, const Point& point);

class Figure {
public:
	virtual ~Figure() noexcept = default;
public:
	virtual Point GetGeometricCenter() const = 0;
public:
	virtual explicit operator double() const = 0;
};

class Rhombus: public Figure {
public:
	Rhombus();
	Rhombus(const Rhombus& other);
	Rhombus(Rhombus&& moved) noexcept;
public:
	Point GetGeometricCenter() const override;
public:
	friend void swap(Rhombus& firstRhombus, Rhombus& secondRhombus) noexcept;
public:
	Rhombus& operator=(const Rhombus& other);
	Rhombus& operator=(Rhombus&& other) noexcept;

	bool operator==(const Rhombus& other) const;

	friend std::istream& operator>>(std::istream& istream, Rhombus& rhombus);
	friend std::ostream& operator<<(std::ostream& ostream, const Rhombus& rhombus);

	explicit operator double() const override;
private:
	static constexpr uint64_t _amountOfPoints = 4;
	std::array<Point, _amountOfPoints> _points;
};

void swap(Rhombus& firstRhombus, Rhombus& secondRhombus) noexcept;

std::istream& operator>>(std::istream& istream, Rhombus& rhombus);
std::ostream& operator<<(std::ostream& ostream, const Rhombus& rhombus);

class Pentagon: public Figure {
	public:
		Pentagon();
		Pentagon(const Pentagon& other);
		Pentagon(Pentagon&& moved) noexcept;
	public:
		Point GetGeometricCenter() const override;
	public:
		friend void swap(Pentagon& firstPentagon, Pentagon& secondPentagon) noexcept;
	public:
		Pentagon& operator=(const Pentagon& other);
		Pentagon& operator=(Pentagon&& other) noexcept;
	
		bool operator==(const Pentagon& other) const;
	
		friend std::istream& operator>>(std::istream& istream, Pentagon& pentagon);
		friend std::ostream& operator<<(std::ostream& ostream, const Pentagon& pentagon);
	
		explicit operator double() const override;
	private:
		static constexpr uint64_t _amountOfPoints = 5;
		std::array<Point, _amountOfPoints> _points;
	};
	
void swap(Pentagon& firstPentagon, Pentagon& secondPentagon) noexcept;

std::istream& operator>>(std::istream& istream, Pentagon& pentagon);
std::ostream& operator<<(std::ostream& ostream, const Pentagon& pentagon);

class Hexagon: public Figure {
	public:
		Hexagon();
		Hexagon(const Hexagon& other);
		Hexagon(Hexagon&& moved) noexcept;
	public:
		Point GetGeometricCenter() const override;
	public:
		friend void swap(Hexagon& firstHexagon, Hexagon& secondHexagon) noexcept;
	public:
		Hexagon& operator=(const Hexagon& other);
		Hexagon& operator=(Hexagon&& other) noexcept;
	
		bool operator==(const Hexagon& other) const;
	
		friend std::istream& operator>>(std::istream& istream, Hexagon& hexagon);
		friend std::ostream& operator<<(std::ostream& ostream, const Hexagon& hexagon);
	
		explicit operator double() const override;
	private:
		static constexpr uint64_t _amountOfPoints = 6;
		std::array<Point, _amountOfPoints> _points;
	};
	
void swap(Hexagon& firstHexagon, Hexagon& secondHexagon) noexcept;

std::istream& operator>>(std::istream& istream, Hexagon& hexagon);
std::ostream& operator<<(std::ostream& ostream, const Hexagon& hexagon);

#endif