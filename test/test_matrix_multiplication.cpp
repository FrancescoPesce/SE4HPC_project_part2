#include "matrix_multiplication.h"
#include "matrix_multiplication_without_errors.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

/*
We copied the tests that are present in the repository for part 1, with the exception of those 
that had ill-formed inputs and "TestMultiplySameObject", which causes a SEGFAULT error.
Interestingly, "TestMultiplyEmptyMatrices" does not cause a SEGFAULT error with this implementation.
*/

TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplicationTest, TestMultiplyEmptyMatrices) {
    const std::vector<std::vector<int>> A(0, std::vector<int>(0, 0));
    const std::vector<std::vector<int>> B(0, std::vector<int>(0, 0));
    
    std::vector<std::vector<int>> C(0, std::vector<int>(0, 0));
    std::vector<std::vector<int>> expected(0, std::vector<int>(0, 0));

    multiplyMatrices(A, B, C, 0, 0, 0);

    ASSERT_EQ(C, expected) << "Result incorrect.";
}

TEST(MatrixMultiplicationTest, TestMultiplyScalars) {
    const std::vector<std::vector<int>> A(1, std::vector<int>(1, 6));
    const std::vector<std::vector<int>> B(1, std::vector<int>(1, 7));
    
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));
    std::vector<std::vector<int>> expected(1, std::vector<int>(1, 42));

    multiplyMatrices(A, B, C, 1, 1, 1);

    ASSERT_EQ(C, expected) << "Result incorrect.";
}

TEST(MatrixMultiplicationTest, TestMultiplyVectors) {
    const std::vector<std::vector<int>> A = {
        {1, 2, 3}
    };
    const std::vector<std::vector<int>> B = {
        {7},
        {8},
        {9}
    };
    
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));
    std::vector<std::vector<int>> expected(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 3, 1);
    multiplyMatricesWithoutErrors(A, B, expected, 1, 3, 1);

    ASSERT_EQ(C, expected) << "Result incorrect.";
}

TEST(MatrixMultiplicationTest, TestMultiplyVectorsTransposed) {
    const std::vector<std::vector<int>> A = {
        {5},
        {6},
        {7}
    };
    const std::vector<std::vector<int>> B = {
        {2, 3, 4}
    };
    
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));
    std::vector<std::vector<int>> expected(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 1, 3);
    multiplyMatricesWithoutErrors(A, B, expected, 3, 1, 3);

    ASSERT_EQ(C, expected) << "Result incorrect.";
}

TEST(MatrixMultiplicationTest, TestMultiplySquareMatrices) {
    // 100x100 matrix with ordered numbers from 1 to 10000.
    std::vector<std::vector<int>> A(100, std::vector<int>(100, 0));
    int count = 1;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            A[i][j] = count++;
        }
    }

    // Copy of A.
    std::vector<std::vector<int>> B(A);

    std::vector<std::vector<int>> C(100, std::vector<int>(100, 0));
    std::vector<std::vector<int>> expected(100, std::vector<int>(100, 0));
    
    multiplyMatrices(A, B, C, 100, 100, 100);
    multiplyMatricesWithoutErrors(A, B, expected, 100, 100, 100);

    ASSERT_EQ(C, expected) << "Result incorrect.";
}

TEST(MatrixMultiplicationTest, TestMultiplyIdentity) {
    // 10x10 matrix with entries ordered by row.
    std::vector<std::vector<int>> A(10, std::vector<int>(10, 0));
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            A[i][j] = count++;
        }
    }

    // 10x10 identity matrix.
    std::vector<std::vector<int>> B(10, std::vector<int>(10, 0));
    for (int i = 0; i < 10; ++i) {
        B[i][i] = 1;
    }

    std::vector<std::vector<int>> C(10, std::vector<int>(10, 0));
    std::vector<std::vector<int>> expected(10, std::vector<int>(10, 0));
    
    multiplyMatrices(A, B, C, 10, 10, 10);
    multiplyMatricesWithoutErrors(A, B, expected, 10, 10, 10);

    ASSERT_EQ(C, expected) << "Result incorrect.";
}

TEST(MatrixMultiplicationTest, TestMultiplyMatricesWithNegativeNumbers) {
    const std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, -6}
    };
    const std::vector<std::vector<int>> B = {
        {-7, 8},
        {9, -10},
        {11, -12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);
    multiplyMatricesWithoutErrors(A, B, expected, 2, 3, 2);

    ASSERT_EQ(C, expected) << "Result incorrect.";
}

TEST(MatrixMultiplicationTest, TestMultiplyStripedMatrices) {
    // 10x10 matrix with the value i in the i-th column.
    std::vector<std::vector<int>> A(10, std::vector<int>(10, 0));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            A[j][i] = i;
        }
    }

    // 10x10 matrix with the value i in the i-th row.
    std::vector<std::vector<int>> B(10, std::vector<int>(10, 0));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            B[i][j] = i;
        }
    }

    std::vector<std::vector<int>> C(10, std::vector<int>(10, 0));
    std::vector<std::vector<int>> expected(10, std::vector<int>(10, 0));
    
    multiplyMatrices(A, B, C, 10, 10, 10);
    multiplyMatricesWithoutErrors(A, B, expected, 10, 10, 10);

    ASSERT_EQ(C, expected) << "Result incorrect.";
}

TEST(MatrixMultiplicationTest, TestMultiplyStripedMatricesTranspose) {
    // a 10x10 matrix with the value i in the i-th row.
    std::vector<std::vector<int>> A(10, std::vector<int>(10, 0));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            A[i][j] = i;
        }
    }

    // a 10x10 matrix with the value i in the i-th column.
    std::vector<std::vector<int>> B(10, std::vector<int>(10, 0));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            B[j][i] = i;
        }
    }

    std::vector<std::vector<int>> C(10, std::vector<int>(10, 0));
    std::vector<std::vector<int>> expected(10, std::vector<int>(10, 0));
    
    multiplyMatrices(A, B, C, 10, 10, 10);
    multiplyMatricesWithoutErrors(A, B, expected, 10, 10, 10);

    ASSERT_EQ(C, expected) << "Result incorrect.";
}

TEST(MatrixMultiplicationTest, TestNoErrors1) {
    std::vector<std::vector<int>> A = {
        {3, 2}
    };
    std::vector<std::vector<int>> B = {
        {1, 0},
        {2, 2}
    };
    
    std::vector<std::vector<int>> C(1, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected(1, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 1, 2, 1);
    multiplyMatricesWithoutErrors(A, B, expected, 1, 2, 1);

    ASSERT_EQ(C, expected) << "Result incorrect.";
}

TEST(MatrixMultiplicationTest, TestNoErrors2) {
    std::vector<std::vector<int>> A = {
        {2, 2, 2, 2},
        {2, 2, 2, 2},
        {2, 2, 2, 2}
    };
    std::vector<std::vector<int>> B = {
        {1, 0, 0, 2},
        {2, 2, 2, 2},
        {0, 0, 0, 0},
        {2, 0, 2, 0}
    };
    
    std::vector<std::vector<int>> C(3, std::vector<int>(4, 0));
    std::vector<std::vector<int>> expected(3, std::vector<int>(4, 0));

    multiplyMatrices(A, B, C, 3, 4, 3);
    multiplyMatricesWithoutErrors(A, B, expected, 3, 4, 3);

    ASSERT_EQ(C, expected) << "Result incorrect.";
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
