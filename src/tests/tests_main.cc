#include <gtest/gtest.h>
#include "../s21_cpp_matrix.h"

TEST(MatrixTest, EqMatrix) {
	S21Matrix matrix1;
	S21Matrix matrix2;
	EXPECT_TRUE(matrix1.EqMatrix(matrix2));
}

TEST(MatrixTest, SumMatrix) {
	S21Matrix matrix1;
	S21Matrix matrix2;
	S21Matrix expected_matrix;

	expected_matrix.setRows(3);
	expected_matrix.setCols(3);

	for (int i = 0; i < expected_matrix.getRows(); ++i) {
		for (int j = 0; j < expected_matrix.getCols(); ++j) {
			double value = 2 * matrix1.getElement(i, j);
			expected_matrix.setElement(i, j, value);
		}
	}

	matrix1.SumMatrix(matrix2);

	EXPECT_TRUE(matrix1.EqMatrix(expected_matrix));
}

TEST(MatrixTest, SumOperatorMatrix) {
	S21Matrix matrix1;
	S21Matrix matrix2;
	S21Matrix expected_matrix;

	expected_matrix.setRows(3);
	expected_matrix.setCols(3);

	for (int i = 0; i < expected_matrix.getRows(); ++i) {
		for (int j = 0; j < expected_matrix.getCols(); ++j) {
			double value = 2 * matrix1.getElement(i, j);
			expected_matrix.setElement(i, j, value);
		}
	}

	matrix1 + matrix2;

	EXPECT_TRUE(matrix1.EqMatrix(expected_matrix));
}

TEST(MatrixTest, AdditionAssignmentOperatorMatrix) {
	S21Matrix matrix1;
	S21Matrix matrix2;
	S21Matrix expected_matrix;

	expected_matrix.setRows(3);
	expected_matrix.setCols(3);

	for (int i = 0; i < expected_matrix.getRows(); ++i) {
		for (int j = 0; j < expected_matrix.getCols(); ++j) {
			double value = 2 * matrix1.getElement(i, j);
			expected_matrix.setElement(i, j, value);
		}
	}

	matrix1 += matrix2;

	EXPECT_TRUE(matrix1.EqMatrix(expected_matrix));
}

TEST(MatrixTest, SubMatrix) {
	S21Matrix matrix1;
	S21Matrix matrix2;
	S21Matrix expected_matrix;

	expected_matrix.setRows(3);
	expected_matrix.setCols(3);

	for (int i = 0; i < expected_matrix.getRows(); ++i) {
		for (int j = 0; j < expected_matrix.getCols(); ++j) {
			expected_matrix.setElement(i, j, 0.0);
		}
	}

	matrix1.SubMatrix(matrix2);

	EXPECT_TRUE(matrix1.EqMatrix(expected_matrix));
}

TEST(MatrixTest, SubOperatorMatrix) {
	S21Matrix matrix1;
	S21Matrix matrix2;
	S21Matrix expected_matrix;

	expected_matrix.setRows(3);
	expected_matrix.setCols(3);

	for (int i = 0; i < expected_matrix.getRows(); ++i) {
		for (int j = 0; j < expected_matrix.getCols(); ++j) {
			expected_matrix.setElement(i, j, 0.0);
		}
	}

	matrix1 - matrix2;

	EXPECT_TRUE(matrix1.EqMatrix(expected_matrix));
}

TEST(MatrixTest, DifferenceAssignmentOperatorMatrix) {
	S21Matrix matrix1;
	S21Matrix matrix2;
	S21Matrix expected_matrix;

	expected_matrix.setRows(3);
	expected_matrix.setCols(3);

	for (int i = 0; i < expected_matrix.getRows(); ++i) {
		for (int j = 0; j < expected_matrix.getCols(); ++j) {
			expected_matrix.setElement(i, j, 0.0);
		}
	}

	matrix1 -= matrix2;

	EXPECT_TRUE(matrix1.EqMatrix(expected_matrix));
}

TEST(MatrixTest, MultByNumber) {
	S21Matrix matrix1;
	S21Matrix expected_matrix;

	expected_matrix.setRows(3);
	expected_matrix.setCols(3);

	for (int i = 0; i < expected_matrix.getRows(); ++i) {
		for (int j = 0; j < expected_matrix.getCols(); ++j) {
			expected_matrix.setElement(i, j, matrix1.getElement(i, j) * 3.0);
		}
	}

	matrix1.MultNumber(3.0);

	EXPECT_TRUE(matrix1.EqMatrix(expected_matrix));
}

TEST(MatrixTest, MultByNumberOperator) {
	S21Matrix matrix1;
	S21Matrix expected_matrix;

	expected_matrix.setRows(3);
	expected_matrix.setCols(3);

	for (int i = 0; i < expected_matrix.getRows(); ++i) {
		for (int j = 0; j < expected_matrix.getCols(); ++j) {
			expected_matrix.setElement(i, j, matrix1.getElement(i, j) * 3.0);
		}
	}

	matrix1 * 3.0;

	EXPECT_TRUE(matrix1.EqMatrix(expected_matrix));
}

TEST(MatrixTest, MultiplicationAssignmentOperatorMultNumber) {
	S21Matrix matrix1;
	S21Matrix expected_matrix;

	expected_matrix.setRows(3);
	expected_matrix.setCols(3);

	for (int i = 0; i < expected_matrix.getRows(); ++i) {
		for (int j = 0; j < expected_matrix.getCols(); ++j) {
			expected_matrix.setElement(i, j, matrix1.getElement(i, j) * 3.0);
		}
	}

	matrix1 *= 3.0;

	EXPECT_TRUE(matrix1.EqMatrix(expected_matrix));
}

TEST(MatrixTest, MultMatrix) {
	
	S21Matrix matrix1(3, 2);
	matrix1.setElement(0, 0, 1.0);
	matrix1.setElement(0, 1, 2.0);
	matrix1.setElement(1, 0, 3.0);
	matrix1.setElement(1, 1, 1.0);
	matrix1.setElement(2, 0, 2.0);
	matrix1.setElement(2, 1, 3.0);

	S21Matrix matrix2(2, 3);
	matrix2.setElement(0, 0, 1.0);
	matrix2.setElement(0, 1, 2.0);
	matrix2.setElement(0, 2, 3.0);
	matrix2.setElement(1, 0, 1.0);
	matrix2.setElement(1, 1, 2.0);
	matrix2.setElement(1, 2, 3.0);

	S21Matrix expected_matrix(3, 3);

    expected_matrix.setElement(0, 0, 3.0);
    expected_matrix.setElement(0, 1, 6.0);
    expected_matrix.setElement(0, 2, 9.0);
	expected_matrix.setElement(1, 0, 4.0);
    expected_matrix.setElement(1, 1, 8.0);
    expected_matrix.setElement(1, 2, 12.0);
	expected_matrix.setElement(2, 0, 5.0);
    expected_matrix.setElement(2, 1, 10.0);
    expected_matrix.setElement(2, 2, 15.0);

	matrix1.MultMatrix(matrix2);

	EXPECT_TRUE(matrix1.EqMatrix(expected_matrix));
}

TEST(MatrixTest, MultMatrixOperator) {
	
	S21Matrix matrix1(3, 2);
	matrix1.setElement(0, 0, 1.0);
	matrix1.setElement(0, 1, 2.0);
	matrix1.setElement(1, 0, 3.0);
	matrix1.setElement(1, 1, 1.0);
	matrix1.setElement(2, 0, 2.0);
	matrix1.setElement(2, 1, 3.0);

	S21Matrix matrix2(2, 3);
	matrix2.setElement(0, 0, 1.0);
	matrix2.setElement(0, 1, 2.0);
	matrix2.setElement(0, 2, 3.0);
	matrix2.setElement(1, 0, 1.0);
	matrix2.setElement(1, 1, 2.0);
	matrix2.setElement(1, 2, 3.0);

	S21Matrix expected_matrix(3, 3);

    expected_matrix.setElement(0, 0, 3.0);
    expected_matrix.setElement(0, 1, 6.0);
    expected_matrix.setElement(0, 2, 9.0);
	expected_matrix.setElement(1, 0, 4.0);
    expected_matrix.setElement(1, 1, 8.0);
    expected_matrix.setElement(1, 2, 12.0);
	expected_matrix.setElement(2, 0, 5.0);
    expected_matrix.setElement(2, 1, 10.0);
    expected_matrix.setElement(2, 2, 15.0);

	matrix1 * matrix2;

	EXPECT_TRUE(matrix1.EqMatrix(expected_matrix));
}

TEST(MatrixTest, MultiplicationAssignmentOperatorMultMatrix) {
	
	S21Matrix matrix1(3, 2);
	matrix1.setElement(0, 0, 1.0);
	matrix1.setElement(0, 1, 2.0);
	matrix1.setElement(1, 0, 3.0);
	matrix1.setElement(1, 1, 1.0);
	matrix1.setElement(2, 0, 2.0);
	matrix1.setElement(2, 1, 3.0);

	S21Matrix matrix2(2, 3);
	matrix2.setElement(0, 0, 1.0);
	matrix2.setElement(0, 1, 2.0);
	matrix2.setElement(0, 2, 3.0);
	matrix2.setElement(1, 0, 1.0);
	matrix2.setElement(1, 1, 2.0);
	matrix2.setElement(1, 2, 3.0);

	S21Matrix expected_matrix(3, 3);

    expected_matrix.setElement(0, 0, 3.0);
    expected_matrix.setElement(0, 1, 6.0);
    expected_matrix.setElement(0, 2, 9.0);
	expected_matrix.setElement(1, 0, 4.0);
    expected_matrix.setElement(1, 1, 8.0);
    expected_matrix.setElement(1, 2, 12.0);
	expected_matrix.setElement(2, 0, 5.0);
    expected_matrix.setElement(2, 1, 10.0);
    expected_matrix.setElement(2, 2, 15.0);

	matrix1 *= matrix2;

	EXPECT_TRUE(matrix1.EqMatrix(expected_matrix));
}

TEST(MatrixTest, EqMatrixOperator) {
	
	S21Matrix matrix1(3, 2);
	matrix1.setElement(0, 0, 1.0);
	matrix1.setElement(0, 1, 2.0);
	matrix1.setElement(1, 0, 3.0);
	matrix1.setElement(1, 1, 1.0);
	matrix1.setElement(2, 0, 2.0);
	matrix1.setElement(2, 1, 3.0);

	S21Matrix matrix2(3, 2);
	matrix2.setElement(0, 0, 1.0);
	matrix2.setElement(0, 1, 2.0);
	matrix2.setElement(1, 0, 3.0);
	matrix2.setElement(1, 1, 1.0);
	matrix2.setElement(2, 0, 2.0);
	matrix2.setElement(2, 1, 3.0);

	EXPECT_TRUE(matrix1 == matrix2);
}

TEST(MatrixTest, TransposeMatrix) {
	
	S21Matrix matrix1(3, 2);
	matrix1.setElement(0, 0, 1.0);
	matrix1.setElement(0, 1, 2.0);
	matrix1.setElement(1, 0, 3.0);
	matrix1.setElement(1, 1, 1.0);
	matrix1.setElement(2, 0, 2.0);
	matrix1.setElement(2, 1, 3.0);

	S21Matrix expected_matrix(2, 3);

    expected_matrix.setElement(0, 0, 1.0);
    expected_matrix.setElement(0, 1, 3.0);
    expected_matrix.setElement(0, 2, 2.0);
	expected_matrix.setElement(1, 0, 2.0);
    expected_matrix.setElement(1, 1, 1.0);
    expected_matrix.setElement(1, 2, 3.0);

	S21Matrix transposed_matrix = matrix1.Transpose();

	EXPECT_TRUE(transposed_matrix.EqMatrix(expected_matrix));
}

TEST(MatrixTest, CalcComplementsMatrix_1) {
	S21Matrix input_matrix(1, 1);
	input_matrix.setElement(0, 0, 21.0);

	S21Matrix expected_result(1, 1);
	expected_result.setElement(0, 0, 21.0);

	S21Matrix actual_result = input_matrix.CalcComplements();

	EXPECT_TRUE(actual_result.EqMatrix(expected_result));
}

TEST(MatrixTest, CalcComplementsMatrix_2) {
	S21Matrix input_matrix(2, 2);
	input_matrix.setElement(0, 0, 21.0);
	input_matrix.setElement(0, 1, 42.0);
	input_matrix.setElement(1, 0, 13.0);
	input_matrix.setElement(1, 1, 420.0);

	S21Matrix expected_result(2, 2);
	expected_result.setElement(0, 0, 420.0);
	expected_result.setElement(0, 1, 13.0);
	expected_result.setElement(1, 0, 42.0);
	expected_result.setElement(1, 1, 21.0);

	S21Matrix actual_result = input_matrix.CalcComplements();
	
//	std::cout << "Input:" << std::endl;
//	input_matrix.print_out_matrix();
//	std::cout << "Actual result:" << std::endl;
//	actual_result.print_out_matrix();
//	std::cout << "Expected result:" << std::endl;
//	expected_result.print_out_matrix();	

	EXPECT_TRUE(actual_result.EqMatrix(expected_result));
}

TEST(MatrixTest, CalcComplementsMatrix) {
	
	S21Matrix input_matrix(3, 3);
	input_matrix.setElement(0, 0, 1.0);
	input_matrix.setElement(0, 1, 2.0);
	input_matrix.setElement(0, 2, 3.0);
	input_matrix.setElement(1, 0, 1.0);
	input_matrix.setElement(1, 1, 3.0);
	input_matrix.setElement(1, 2, 2.0);
	input_matrix.setElement(2, 0, 5.0);
	input_matrix.setElement(2, 1, 2.0);
	input_matrix.setElement(2, 2, 1.0);

	S21Matrix expected_matrix(3, 3);

    expected_matrix.setElement(0, 0, -1.0);
    expected_matrix.setElement(0, 1, 9.0);
    expected_matrix.setElement(0, 2, -13.0);
	expected_matrix.setElement(1, 0, 4.0);
    expected_matrix.setElement(1, 1, -14.0);
    expected_matrix.setElement(1, 2, 8.0);
    expected_matrix.setElement(2, 0, -5.0);
    expected_matrix.setElement(2, 1, 1.0);
    expected_matrix.setElement(2, 2, 1.0);

	S21Matrix actual_result = input_matrix.CalcComplements();

	EXPECT_TRUE(actual_result.EqMatrix(expected_matrix));
}

TEST(MatrixTest, DeterminantMatrix00) {
	
	S21Matrix input_matrix(3, 3);
	input_matrix.setElement(0, 0, 21.0);
	input_matrix.setElement(0, 1, 42.0);
	input_matrix.setElement(0, 2, 13.0);
	input_matrix.setElement(1, 0, 21.0);
	input_matrix.setElement(1, 1, 42.0);
	input_matrix.setElement(1, 2, 13.0);
	input_matrix.setElement(2, 0, 21.0);
	input_matrix.setElement(2, 1, 42.0);
	input_matrix.setElement(2, 2, 13.0);

	double expected_result = 0.0;

	double actual_result = input_matrix.Determinant();

	ASSERT_DOUBLE_EQ(expected_result, actual_result);
}

TEST(MatrixTest, DeterminantMatrix01) {
	
	S21Matrix input_matrix(3, 3);
	input_matrix.setElement(0, 0, 2.0);
	input_matrix.setElement(0, 1, 5.0);
	input_matrix.setElement(0, 2, 7.0);
	input_matrix.setElement(1, 0, 6.0);
	input_matrix.setElement(1, 1, 3.0);
	input_matrix.setElement(1, 2, 4.0);
	input_matrix.setElement(2, 0, 5.0);
	input_matrix.setElement(2, 1, -2.0);
	input_matrix.setElement(2, 2, -3.0);

	double expected_result = -1.0;

	double actual_result = input_matrix.Determinant();

	ASSERT_DOUBLE_EQ(expected_result, actual_result);
}

TEST(MatrixTest, InverseMatrix00) {
	
	S21Matrix input(3, 3);
	input.setElement(0, 0, 2.0);
	input.setElement(0, 1, 5.0);
	input.setElement(0, 2, 7.0);
	input.setElement(1, 0, 6.0);
	input.setElement(1, 1, 3.0);
	input.setElement(1, 2, 4.0);
	input.setElement(2, 0, 5.0);
	input.setElement(2, 1, -2.0);
	input.setElement(2, 2, -3.0);

	S21Matrix expected(3, 3);

    expected.setElement(0, 0, 1.0);
    expected.setElement(0, 1, -1.0);
    expected.setElement(0, 2, 1.0);
	expected.setElement(1, 0, -38.0);
    expected.setElement(1, 1, 41.0);
    expected.setElement(1, 2, -34.0);
    expected.setElement(2, 0, 27.0);
    expected.setElement(2, 1, -29.0);
    expected.setElement(2, 2, 24.0);

	S21Matrix actual = input.InverseMatrix();

	EXPECT_TRUE(actual.EqMatrix(expected));
}

TEST(MatrixTest, InverseMatrixZeroException) {
	
	S21Matrix input(3, 3);
	input.setElement(0, 0, 1.0);
	input.setElement(0, 1, 2.0);
	input.setElement(0, 2, 3.0);
	input.setElement(1, 0, 4.0);
	input.setElement(1, 1, 5.0);
	input.setElement(1, 2, 6.0);
	input.setElement(2, 0, 7.0);
	input.setElement(2, 1, 8.0);
	input.setElement(2, 2, 9.0);

	EXPECT_THROW(input.InverseMatrix(), ZeroDeterminantException);
	// TODO: Check if the initial matrix is null;
}

TEST(MatrixTest, BasicConstructorTest) {
	
	S21Matrix actual;

	S21Matrix expected(3, 3);
	expected.setElement(0, 0, 0.0);
	expected.setElement(0, 1, 1.0);
	expected.setElement(0, 2, 2.0);
	expected.setElement(1, 0, 3.0);
	expected.setElement(1, 1, 4.0);
	expected.setElement(1, 2, 5.0);
	expected.setElement(2, 0, 6.0);
	expected.setElement(2, 1, 7.0);
	expected.setElement(2, 2, 8.0);

	EXPECT_TRUE(actual.EqMatrix(expected));
}

TEST(MatrixTest, ParametrizedConstructorTest) {
	
	S21Matrix actual(3, 3);

	S21Matrix expected(3, 3);
	expected.setElement(0, 0, 0.0);
	expected.setElement(0, 1, 0.0);
	expected.setElement(0, 2, 0.0);
	expected.setElement(1, 0, 0.0);
	expected.setElement(1, 1, 0.0);
	expected.setElement(1, 2, 0.0);
	expected.setElement(2, 0, 0.0);
	expected.setElement(2, 1, 0.0);
	expected.setElement(2, 2, 0.0);

	EXPECT_TRUE(actual.EqMatrix(expected));
}

TEST(MatrixTest, CopyConstructorTest) {
	
	S21Matrix input(3, 3);
	input.setElement(0, 0, 1.0);
	input.setElement(0, 1, 2.0);
	input.setElement(0, 2, 3.0);
	input.setElement(1, 0, 4.0);
	input.setElement(1, 1, 5.0);
	input.setElement(1, 2, 6.0);
	input.setElement(2, 0, 7.0);
	input.setElement(2, 1, 8.0);
	input.setElement(2, 2, 9.0);

	S21Matrix expected(3, 3);
	expected.setElement(0, 0, 1.0);
	expected.setElement(0, 1, 2.0);
	expected.setElement(0, 2, 3.0);
	expected.setElement(1, 0, 4.0);
	expected.setElement(1, 1, 5.0);
	expected.setElement(1, 2, 6.0);
	expected.setElement(2, 0, 7.0);
	expected.setElement(2, 1, 8.0);
	expected.setElement(2, 2, 9.0);

	S21Matrix actual(input);

	EXPECT_TRUE(actual.EqMatrix(expected));
}

TEST(MatrixTest, MovementConstructorTest) {
	
	S21Matrix input(3, 3);
	input.setElement(0, 0, 1.0);
	input.setElement(0, 1, 2.0);
	input.setElement(0, 2, 3.0);
	input.setElement(1, 0, 4.0);
	input.setElement(1, 1, 5.0);
	input.setElement(1, 2, 6.0);
	input.setElement(2, 0, 7.0);
	input.setElement(2, 1, 8.0);
	input.setElement(2, 2, 9.0);

	S21Matrix expected(3, 3);
	expected.setElement(0, 0, 1.0);
	expected.setElement(0, 1, 2.0);
	expected.setElement(0, 2, 3.0);
	expected.setElement(1, 0, 4.0);
	expected.setElement(1, 1, 5.0);
	expected.setElement(1, 2, 6.0);
	expected.setElement(2, 0, 7.0);
	expected.setElement(2, 1, 8.0);
	expected.setElement(2, 2, 9.0);

	S21Matrix actual(std::move(input));

	EXPECT_TRUE(actual.EqMatrix(expected));
}

TEST(MatrixTest, DestructorTest) {
	
	S21Matrix input(3, 3);
	input.setElement(0, 0, 1.0);
	input.setElement(0, 1, 2.0);
	input.setElement(0, 2, 3.0);
	input.setElement(1, 0, 4.0);
	input.setElement(1, 1, 5.0);
	input.setElement(1, 2, 6.0);
	input.setElement(2, 0, 7.0);
	input.setElement(2, 1, 8.0);
	input.setElement(2, 2, 9.0);

	input.~S21Matrix();

	int rows = input.getRows();
	int cols = input.getCols();
	bool is_null = input.matrix_is_null();
	
	ASSERT_EQ(rows, 0);
	ASSERT_EQ(cols, 0);
	EXPECT_TRUE(is_null);
}

TEST(MatrixTest, IndexationByMatrixElements) {
	
	S21Matrix input(3, 3);
	input.setElement(0, 0, 1.0);
	input.setElement(0, 1, 2.0);
	input.setElement(0, 2, 3.0);
	input.setElement(1, 0, 4.0);
	input.setElement(1, 1, 5.0);
	input.setElement(1, 2, 6.0);
	input.setElement(2, 0, 7.0);
	input.setElement(2, 1, 8.0);
	input.setElement(2, 2, 9.0);

	double actual = input(1, 1);
	double expected = 5.0;

	ASSERT_DOUBLE_EQ(expected, actual);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
