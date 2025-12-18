#include <gtest/gtest.h>
#include <sstream>
#include "Matrix.h"
#include "RandomGenerate.h"
#include "IStreamGenerate.h"
#include "ConstantGenerate.h"
#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"

TEST(MatrixTest, DefaultConstructor) {
    Matrix matrix;
    EXPECT_EQ(matrix.get_size(), 0);
}

TEST(MatrixTest, SizeConstructor) {
    Matrix matrix(5);
    EXPECT_EQ(matrix.get_size(), 5);
}

TEST(MatrixTest, CopyConstructor) {
    Matrix original(3);
    original[0] = 1; original[1] = 2; original[2] = 3;
    
    Matrix copy(original);
    EXPECT_EQ(copy.get_size(), 3);
    EXPECT_EQ(copy[0], 1);
    EXPECT_EQ(copy[1], 2);
    EXPECT_EQ(copy[2], 3);
}

TEST(MatrixTest, AssignmentOperator) {
    Matrix original(3);
    original[0] = 1; original[1] = 2; original[2] = 3;
    
    Matrix assigned;
    assigned = original;
    EXPECT_EQ(assigned.get_size(), 3);
    EXPECT_EQ(assigned[0], 1);
    EXPECT_EQ(assigned[1], 2);
    EXPECT_EQ(assigned[2], 3);
}

TEST(MatrixTest, SelfAssignment) {
    Matrix matrix(2);
    matrix[0] = 5; matrix[1] = 10;
    
    matrix = matrix;
    EXPECT_EQ(matrix.get_size(), 2);
    EXPECT_EQ(matrix[0], 5);
    EXPECT_EQ(matrix[1], 10);
}

TEST(MatrixTest, IndexOperator) {
    Matrix matrix(3);
    matrix[0] = 1;
    matrix[1] = 2;
    matrix[2] = 3;
    
    EXPECT_EQ(matrix[0], 1);
    EXPECT_EQ(matrix[1], 2);
    EXPECT_EQ(matrix[2], 3);
}

TEST(MatrixTest, ConstIndexOperator) {
    const Matrix matrix(2);
    EXPECT_EQ(matrix[0], 0);
    EXPECT_EQ(matrix[1], 0);
}

TEST(MatrixTest, OutputOperator) {
    Matrix matrix(2);
    matrix[0] = 1;
    matrix[1] = 2;
    
    std::ostringstream oss;
    oss << matrix;
    
    EXPECT_EQ(oss.str(), "1 2 \n");
}

TEST(MatrixTest, InputOperator) {
    Matrix matrix(2);
    std::istringstream iss("3 4");
    iss >> matrix;
    
    EXPECT_EQ(matrix[0], 3);
    EXPECT_EQ(matrix[1], 4);
}

TEST(RandomGenerateTest, GenerateValues) {
    RandomGenerate generator(0, 10);
    Matrix matrix(5);
    
    generator(matrix);
    
    for (int i = 0; i < matrix.get_size(); ++i) {
        EXPECT_GE(matrix[i], 0);
        EXPECT_LE(matrix[i], 10);
    }
}

TEST(IStreamGenerateTest, GenerateValues) {
    std::istringstream iss("1 2 3 4 5");
    IStreamGenerate generator(iss);
    Matrix matrix(5);
    
    generator(matrix);
    
    EXPECT_EQ(matrix[0], 1);
    EXPECT_EQ(matrix[1], 2);
    EXPECT_EQ(matrix[2], 3);
    EXPECT_EQ(matrix[3], 4);
    EXPECT_EQ(matrix[4], 5);
}

TEST(ConstantGenerateTest, GenerateValues) {
    ConstantGenerate generator(7);
    Matrix matrix(4);
    
    generator(matrix);
    
    for (int i = 0; i < matrix.get_size(); ++i) {
        EXPECT_EQ(matrix[i], 7);
    }
}

TEST(Task1Test, CalculateSum) {
    Matrix matrix(3);
    matrix[0] = 1;
    matrix[1] = 2;
    matrix[2] = 3;
    
    Task_1 task;
    double result = task.calculate(matrix);
    
    EXPECT_DOUBLE_EQ(result, 6.0);
}

TEST(Task1Test, CalculateWithNegative) {
    Matrix matrix(3);
    matrix[0] = -1;
    matrix[1] = 2;
    matrix[2] = -3;
    
    Task_1 task;
    double result = task.calculate(matrix);
    
    EXPECT_DOUBLE_EQ(result, -2.0);
}

TEST(Task2Test, CalculateAverage) {
    Matrix matrix(4);
    matrix[0] = 1;
    matrix[1] = 2;
    matrix[2] = 3;
    matrix[3] = 4;
    
    Task_2 task;
    double result = task.calculate(matrix);
    
    EXPECT_DOUBLE_EQ(result, 2.5);
}

TEST(Task2Test, CalculateSingleElement) {
    Matrix matrix(1);
    matrix[0] = 5;
    
    Task_2 task;
    double result = task.calculate(matrix);
    
    EXPECT_DOUBLE_EQ(result, 5.0);
}

TEST(Task3Test, CalculateMax) {
    Matrix matrix(5);
    matrix[0] = 1;
    matrix[1] = 8;
    matrix[2] = 3;
    matrix[3] = 6;
    matrix[4] = 2;
    
    Task_3 task;
    double result = task.calculate(matrix);
    
    EXPECT_DOUBLE_EQ(result, 8.0);
}

TEST(Task3Test, CalculateWithNegative) {
    Matrix matrix(3);
    matrix[0] = -5;
    matrix[1] = -2;
    matrix[2] = -8;
    
    Task_3 task;
    double result = task.calculate(matrix);
    
    EXPECT_DOUBLE_EQ(result, -2.0);
}

TEST(MatrixIntegrationTest, CompleteWorkflow) {
    Matrix matrix(3);
    matrix[0] = 2;
    matrix[1] = 4;
    matrix[2] = 6;
    
    Task_1 task1;
    Task_2 task2;
    Task_3 task3;
    
    EXPECT_DOUBLE_EQ(task1.calculate(matrix), 12.0);
    EXPECT_DOUBLE_EQ(task2.calculate(matrix), 4.0);
    EXPECT_DOUBLE_EQ(task3.calculate(matrix), 6.0);
}

TEST(MatrixExceptionTest, InvalidSize) {
    EXPECT_THROW(Matrix(-1), std::invalid_argument);
    EXPECT_THROW(Matrix(0), std::invalid_argument);
}

TEST(MatrixExceptionTest, OutOfBoundsAccess) {
    Matrix matrix(2);
    
    EXPECT_THROW(matrix[2], std::out_of_range);
    EXPECT_THROW(matrix[-1], std::out_of_range);
}

TEST(MatrixExceptionTest, ConstOutOfBoundsAccess) {
    const Matrix matrix(2);
    
    EXPECT_THROW(matrix[2], std::out_of_range);
    EXPECT_THROW(matrix[-1], std::out_of_range);
}

TEST(IStreamGenerateTest, InsufficientData) {
    std::istringstream iss("1 2");
    IStreamGenerate generator(iss);
    Matrix matrix(5);
    
    EXPECT_THROW(generator(matrix), std::runtime_error);
}

TEST(TaskExceptionTest, EmptyMatrix) {
    Matrix matrix(0);
    Task_1 task1;
    Task_2 task2;
    Task_3 task3;
    
    EXPECT_THROW(task1.calculate(matrix), std::invalid_argument);
    EXPECT_THROW(task2.calculate(matrix), std::invalid_argument);
    EXPECT_THROW(task3.calculate(matrix), std::invalid_argument);
}
