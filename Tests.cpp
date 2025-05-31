#include "CppUnitTest.h"
#include "Point.h"
#include "Square.h"
#include "Polygon.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeometryTests
{
    TEST_CLASS(PointTests)
    {
    public:
        TEST_METHOD(DefaultConstructor_CreatesOriginPoint)
        {
            Point p;
            Assert::AreEqual(0.0, p.getX());
            Assert::AreEqual(0.0, p.getY());
        }

        TEST_METHOD(ParameterizedConstructor_SetsCoordinates)
        {
            Point p(3.5, -2.1);
            Assert::AreEqual(3.5, p.getX());
            Assert::AreEqual(-2.1, p.getY());
        }

        TEST_METHOD(EqualityOperator_ReturnsTrueForEqualPoints)
        {
            Point p1(1.0, 2.0);
            Point p2(1.0, 2.0);
            Assert::IsTrue(p1 == p2);
        }

        TEST_METHOD(StreamInsertionOperator_OutputsCorrectFormat)
        {
            Point p(1.5, 3.5);
            std::stringstream ss;
            ss << p;
            Assert::AreEqual(std::string("(1.5, 3.5)"), ss.str());
        }

        TEST_METHOD(StreamExtractionOperator_ReadsCoordinates)
        {
            Point p;
            std::stringstream ss("2.5 4.5");
            ss >> p;
            Assert::AreEqual(2.5, p.getX());
            Assert::AreEqual(4.5, p.getY());
        }
    };

    TEST_CLASS(SquareTests)
    {
    public:
        TEST_METHOD(DefaultConstructor_CreatesUnitSquare)
        {
            Square sq;
            Assert::AreEqual(1.0, sq.sideLength());
            Assert::AreEqual(1.0, sq.area());
            Assert::AreEqual(4.0, sq.perimeter());
        }

        TEST_METHOD(ConstructorWithPoints_CreatesValidSquare)
        {
            std::vector<Point> points = {Point(0,0), Point(2,0), Point(2,2), Point(0,2)};
            Square sq(points);
            Assert::AreEqual(2.0, sq.sideLength());
        }

        TEST_METHOD(ConstructorWithPoints_ThrowsForInvalidSquare)
        {
            auto func = []() {
                std::vector<Point> points = {Point(0,0), Point(1,1), Point(0,1), Point(1,0)};
                Square sq(points);
            };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(Area_ReturnsCorrectValue)
        {
            Square sq({Point(0,0), Point(3,0), Point(3,3), Point(0,3)});
            Assert::AreEqual(9.0, sq.area());
        }

        TEST_METHOD(Perimeter_ReturnsCorrectValue)
        {
            Square sq({Point(0,0), Point(5,0), Point(5,5), Point(0,5)});
            Assert::AreEqual(20.0, sq.perimeter());
        }

        TEST_METHOD(Circumradius_ReturnsCorrectValue)
        {
            Square sq({Point(0,0), Point(2,0), Point(2,2), Point(0,2)});
            double expected = sqrt(2);
            Assert::AreEqual(expected, sq.circumradius(), 0.0001);
        }

        TEST_METHOD(ReadFromStream_CreatesValidSquare)
        {
            std::stringstream ss("0 0 2 0 2 2 0 2");
            Square sq = Square::readFromStream(ss);
            Assert::AreEqual(2.0, sq.sideLength());
        }

        TEST_METHOD(ToString_ReturnsCorrectFormat)
        {
            Square sq({Point(0,0), Point(1,0), Point(1,1), Point(0,1)});
            std::string result = sq.ToString();
            Assert::IsTrue(result.find("Квадрат с вершинами") != std::string::npos);
            Assert::IsTrue(result.find("длина стороны: 1") != std::string::npos);
        }

        TEST_METHOD(EqualityOperator_ReturnsTrueForEqualSquares)
        {
            Square sq1({Point(0,0), Point(1,0), Point(1,1), Point(0,1)});
            Square sq2({Point(0,0), Point(1,0), Point(1,1), Point(0,1)});
            Assert::IsTrue(sq1 == sq2);
        }
    };

    TEST_CLASS(PolygonTests)
    {
    public:
        TEST_METHOD(StreamOperator_OutputsSquareCorrectly)
        {
            Square sq;
            std::stringstream ss;
            ss << sq;
            std::string result = ss.str();
            Assert::IsTrue(result.find("Квадрат с вершинами") != std::string::npos);
        }

        TEST_METHOD(StreamOperator_ReadsSquareCorrectly)
        {
            std::stringstream ss("0 0 1 0 1 1 0 1");
            Square sq;
            ss >> sq;
            Assert::AreEqual(1.0, sq.area());
        }
    };
}