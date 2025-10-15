#include <gtest/gtest.h>
#include <sstream>
#include <array>
#include "Figures.h"

TEST(PointStructTests, DefaultConstructor) {
    Point point;
    EXPECT_DOUBLE_EQ(point.x, 0.0);
    EXPECT_DOUBLE_EQ(point.y, 0.0);
}

TEST(PointStructTests, ValuesConstructor) {
    Point point(5, 2);
    EXPECT_DOUBLE_EQ(point.x, 5.0);
    EXPECT_DOUBLE_EQ(point.y, 2.0);
}

TEST(PointStructTests, ComparisonOperators) {
    Point firstPoint(5, 2);
    Point secondPoint(5, 2);
    Point thirdPoint(52, 52);

    EXPECT_TRUE(firstPoint == secondPoint);
    EXPECT_FALSE(firstPoint == thirdPoint);

    EXPECT_TRUE(firstPoint != thirdPoint);
    EXPECT_FALSE(firstPoint != secondPoint);

    EXPECT_TRUE(firstPoint < thirdPoint);
    EXPECT_FALSE(thirdPoint < firstPoint);

    EXPECT_TRUE(thirdPoint > firstPoint);
    EXPECT_FALSE(firstPoint > thirdPoint);
}

TEST(PointStructTests, IOTests) {
    Point point;

    std::istringstream is("5.2 6.66");
    is >> point;
    EXPECT_DOUBLE_EQ(point.x, 5.2);
    EXPECT_DOUBLE_EQ(point.y, 6.66);

    std::istringstream isInvalid("52 abc");
    EXPECT_THROW(isInvalid >> point, std::invalid_argument);

    std::ostringstream os;
    os << Point(5, 2);
    EXPECT_EQ(os.str(), "(5 2)");
}

TEST(RhombusTests, DefaultConstructor) {
    Rhombus rhombus;
    Point center = rhombus.GetGeometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 0.0);
    EXPECT_DOUBLE_EQ(center.y, 0.0);
}

TEST(RhombusTests, CopyConstructor) {
    Rhombus original;
    std::istringstream is("0 1 1 0 0 -1 -1 0");
    is >> original;
    Rhombus copy(original);
    EXPECT_TRUE(copy == original);
}

TEST(RhombusTests, MoveConstructor) {
    Rhombus original;
    std::istringstream is1("0 1 1 0 0 -1 -1 0");
    is1 >> original;
    Rhombus expected;
    std::istringstream is2("0 1 1 0 0 -1 -1 0");
    is2 >> expected;
    Rhombus moved(std::move(original));
    EXPECT_TRUE(moved == expected);
}

TEST(RhombusTests, CopyAssignmentOperator) {
    Rhombus original;
    std::istringstream is("0 1 1 0 0 -1 -1 0");
    is >> original;
    Rhombus copy;
    copy = original;
    EXPECT_TRUE(copy == original);
}

TEST(RhombusTests, MoveAssignmentOperator) {
    Rhombus original;
    std::istringstream is1("0 1 1 0 0 -1 -1 0");
    is1 >> original;
    Rhombus expected;
    std::istringstream is2("0 1 1 0 0 -1 -1 0");
    is2 >> expected;
    Rhombus moved;
    moved = std::move(original);
    EXPECT_TRUE(moved == expected);
}

TEST(RhombusTests, SelfCopyAssignment) {
    Rhombus rhombus;
    std::istringstream is1("0 1 1 0 0 -1 -1 0");
    is1 >> rhombus;
    Rhombus expected;
    std::istringstream is2("0 1 1 0 0 -1 -1 0");
    is2 >> expected;
    rhombus = rhombus;
    EXPECT_TRUE(rhombus == expected);
}

TEST(RhombusTests, SelfMoveAssignment) {
    Rhombus rhombus;
    std::istringstream is1("0 1 1 0 0 -1 -1 0");
    is1 >> rhombus;
    Rhombus expected;
    std::istringstream is2("0 1 1 0 0 -1 -1 0");
    is2 >> expected;
    rhombus = std::move(rhombus);
    EXPECT_TRUE(rhombus == expected);
}

TEST(RhombusTests, ComparisonOperators) {
    Rhombus a, b, c;
    std::istringstream is1("0 1 1 0 0 -1 -1 0");
    std::istringstream is2("0 1 1 0 0 -1 -1 0");
    std::istringstream is3("0 2 2 0 0 -2 -2 0");
    is1 >> a;
    is2 >> b;
    is3 >> c;

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);

    EXPECT_TRUE(a != c);
    EXPECT_FALSE(a != b);

    EXPECT_TRUE(a < c);
    EXPECT_FALSE(c < a);

    EXPECT_TRUE(c > a);
    EXPECT_FALSE(a > c);
}

TEST(RhombusTests, GetGeometricCenter) {
    Rhombus rhombus;
    std::istringstream is("0 1 1 0 0 -1 -1 0");
    is >> rhombus;
    Point center = rhombus.GetGeometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 0.0);
    EXPECT_DOUBLE_EQ(center.y, 0.0);
}

TEST(RhombusTests, GetGeometricCenterNonCentered) {
    Rhombus rhombus;
    std::istringstream is("1 2 2 1 1 0 0 1");
    is >> rhombus;
    Point center = rhombus.GetGeometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 1.0);
}

TEST(RhombusTests, AreaCalculation) {
    Rhombus rhombus;
    std::istringstream is("0 1 1 0 0 -1 -1 0");
    is >> rhombus;
    double area = static_cast<double>(rhombus);
    EXPECT_NEAR(area, 2.0, 0.01);
}

TEST(RhombusTests, AreaCalculationZero) {
    Rhombus rhombus;
    std::istringstream is("0 0 0 0 0 0 0 0");
    is >> rhombus;
    double area = static_cast<double>(rhombus);
    EXPECT_DOUBLE_EQ(area, 0.0);
}

TEST(RhombusTests, InputStreamInvalidInput) {
    Rhombus rhombus;
    std::istringstream is("a b c d e f g h");
    EXPECT_THROW(is >> rhombus, std::invalid_argument);
}

TEST(RhombusTests, OutputStreamOperator) {
    Rhombus rhombus;
    std::istringstream is("0 1 1 0 0 -1 -1 0");
    is >> rhombus;
    std::ostringstream os;
    os << rhombus;
    EXPECT_FALSE(os.str().empty());
    EXPECT_NE(os.str().find('('), std::string::npos);
}

TEST(RhombusTests, SwapFunction) {
    Rhombus first, second;
    std::istringstream is1("0 1 1 0 0 -1 -1 0");
    std::istringstream is2("0 2 2 0 0 -2 -2 0");
    is1 >> first;
    is2 >> second;
    Rhombus firstCopy = first;
    Rhombus secondCopy = second;
    swap(first, second);
    EXPECT_TRUE(first == secondCopy);
    EXPECT_TRUE(second == firstCopy);
}

TEST(PentagonTests, DefaultConstructor) {
    Pentagon pentagon;
    Point center = pentagon.GetGeometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 0.0);
    EXPECT_DOUBLE_EQ(center.y, 0.0);
}

TEST(PentagonTests, CopyConstructor) {
    Pentagon original;
    std::istringstream is("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    is >> original;
    Pentagon copy(original);
    EXPECT_TRUE(copy == original);
}

TEST(PentagonTests, MoveConstructor) {
    Pentagon original;
    std::istringstream is1("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    is1 >> original;
    Pentagon expected;
    std::istringstream is2("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    is2 >> expected;
    Pentagon moved(std::move(original));
    EXPECT_TRUE(moved == expected);
}

TEST(PentagonTests, CopyAssignmentOperator) {
    Pentagon original;
    std::istringstream is("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    is >> original;
    Pentagon copy;
    copy = original;
    EXPECT_TRUE(copy == original);
}

TEST(PentagonTests, MoveAssignmentOperator) {
    Pentagon original;
    std::istringstream is1("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    is1 >> original;
    Pentagon expected;
    std::istringstream is2("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    is2 >> expected;
    Pentagon moved;
    moved = std::move(original);
    EXPECT_TRUE(moved == expected);
}

TEST(PentagonTests, SelfCopyAssignment) {
    Pentagon pentagon;
    std::istringstream is1("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    is1 >> pentagon;
    Pentagon expected;
    std::istringstream is2("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    is2 >> expected;
    pentagon = pentagon;
    EXPECT_TRUE(pentagon == expected);
}

TEST(PentagonTests, SelfMoveAssignment) {
    Pentagon pentagon;
    std::istringstream is1("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    is1 >> pentagon;
    Pentagon expected;
    std::istringstream is2("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    is2 >> expected;
    pentagon = std::move(pentagon);
    EXPECT_TRUE(pentagon == expected);
}

TEST(PentagonTests, ComparisonOperators) {
    Pentagon a, b, c;
    std::istringstream is1("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    std::istringstream is2("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    std::istringstream is3("0 2 1.902 0.618 1.176 -1.618 -1.176 -1.618 -1.902 0.618");
    is1 >> a;
    is2 >> b;
    is3 >> c;

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);

    EXPECT_TRUE(a != c);
    EXPECT_FALSE(a != b);

    EXPECT_TRUE(a < c);
    EXPECT_FALSE(c < a);

    EXPECT_TRUE(c > a);
    EXPECT_FALSE(a > c);
}

TEST(FigureArrayTests, CreateAndStoreInArray) {
    std::array<Figure*, 3> figures;
    Rhombus r;
    std::istringstream is1("0 1 1 0 0 -1 -1 0");
    is1 >> r;
    figures[0] = &r;
    Pentagon p;
    std::istringstream is2("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    is2 >> p;
    figures[1] = &p;
    Hexagon h;
    std::istringstream is3("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866");
    is3 >> h;
    figures[2] = &h;
    EXPECT_EQ(figures.size(), 3);
}

TEST(FigureArrayTests, CalculateGeometricCenters) {
    std::array<Figure*, 2> figures;
    Rhombus r;
    std::istringstream is1("0 1 1 0 0 -1 -1 0");
    is1 >> r;
    figures[0] = &r;
    Pentagon p;
    std::istringstream is2("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    is2 >> p;
    figures[1] = &p;
    for (size_t i = 0; i < figures.size(); ++i) {
        Point c = figures[i]->GetGeometricCenter();
        EXPECT_NO_THROW((void)c);
    }
}

TEST(FigureArrayTests, CalculateAreas) {
    std::array<Figure*, 2> figures;
    Rhombus r;
    std::istringstream is1("0 1 1 0 0 -1 -1 0");
    is1 >> r;
    figures[0] = &r;
    Pentagon p;
    std::istringstream is2("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    is2 >> p;
    figures[1] = &p;
    for (size_t i = 0; i < figures.size(); ++i) {
        double a = static_cast<double>(*figures[i]);
        EXPECT_GT(a, 0.0);
    }
}

TEST(FigureArrayTests, CalculateTotalArea) {
    std::array<Figure*, 3> figures;
    Rhombus r;
    std::istringstream is1("0 1 1 0 0 -1 -1 0");
    is1 >> r;
    figures[0] = &r;
    Pentagon p;
    std::istringstream is2("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    is2 >> p;
    figures[1] = &p;
    Hexagon h;
    std::istringstream is3("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866");
    is3 >> h;
    figures[2] = &h;
    double total = 0.0;
    for (size_t i = 0; i < figures.size(); ++i) {
        total += static_cast<double>(*figures[i]);
    }
    EXPECT_GT(total, 0.0);
}

TEST(FigureArrayTests, RemoveByIndex) {
    std::array<Figure*, 3> figures;
    Rhombus r;
    std::istringstream is1("0 1 1 0 0 -1 -1 0");
    is1 >> r;
    figures[0] = &r;
    Pentagon p;
    std::istringstream is2("0 1 0.951 0.309 0.588 -0.809 -0.588 -0.809 -0.951 0.309");
    is2 >> p;
    figures[1] = &p;
    figures[0] = figures[1];
    figures[1] = figures[2];
    EXPECT_EQ(figures[0]->GetGeometricCenter().x, p.GetGeometricCenter().x);
}

TEST(FigureArrayTests, EmptyArray) {
    std::array<Figure*, 0> figures;
    EXPECT_TRUE(figures.empty());
}

TEST(FigureArrayTests, AddMultipleFigures) {
    std::array<Rhombus, 5> arr;
    for (size_t i = 0; i < arr.size(); ++i) {
        std::istringstream is("0 1 1 0 0 -1 -1 0");
        is >> arr[i];
        Point c = arr[i].GetGeometricCenter();
        EXPECT_DOUBLE_EQ(c.x, 0.0);
    }
}