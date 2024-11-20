# s21_matrix Library



## Introduction

This project implements a custom matrix library in C. Matrices are essential data structures in many computational tasks, including data analysis, computer graphics, and neural networks. This library provides a set of functions for creating, manipulating, and performing operations on matrices, such as addition, subtraction, multiplication, and more. It is structured to handle matrix operations efficiently and accurately, while also providing a foundation for further optimizations and enhancements.

---
# Chapter I

### The Background Story
The s21_matrix library has its origins in a project designed for efficient mathematical operations on matrices, with potential applications in areas like computer graphics, particularly for optimizations in rendering technologies. As the team worked to improve computational efficiency, the idea of creating a fast and versatile matrix manipulation library came to life.

- **Precision and Range:**  
  The `decimal` type supports values in the range from -79,228,162,514,264,337,593,543,950,335 to +79,228,162,514,264,337,593,543,950,335.
# Chapter II
### Matrix Operations Overview
A matrix is a two-dimensional array of numbers arranged in rows and columns. The library supports a range of matrix operations, including:

1. <b>Matrix Creation:</b> Allocates memory for matrices.
2. <b>Matrix Removal:</b> Frees memory for matrices.
3. <b>Matrix Comparison:</b> Compares two matrices for equality.
4. <b>Matrix Addition & Subtraction:</b> Adds or subtracts matrices of the same size.
5. <b>Matrix Multiplication:</b> Supports both scalar multiplication and matrix multiplication.
6. <b>Matrix Transpose:</b> Swaps the rows and columns of a matrix.
7. <b>Matrix Determinant:</b> Calculates the determinant of square matrices.
8. <b>Matrix Inverse:</b> Computes the inverse of a matrix, if possible.
9. <b>Minor & Algebraic Complements:</b> Computes the minor and algebraic complement of a matrix element.
Each function is designed to return an error code when an operation fails, or a success code when it completes successfully. The functions follow the C standard and ensure correct matrix dimensioning and element-wise operations.

---

# Chapter III

## Implementation Details

The library is implemented in the C programming language, using the C11 standard. It uses structured programming principles and avoids legacy constructs to ensure compatibility with modern compilers. Key functions in the library are prefixed with `s21_` for clarity and consistency. The matrix is defined as follows:

```c
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;
```

## Key Functions

- `s21_create_matrix`: Initializes a matrix with specified rows and columns.
- `s21_remove_matrix`: Frees the memory allocated for a matrix.
- `s21_eq_matrix`: Compares two matrices for equality.
- `s21_sum_matrix`: Adds two matrices.
- `s21_sub_matrix`: Subtracts one matrix from another.
- `s21_mult_number`: Multiplies a matrix by a scalar.
- `s21_mult_matrix`: Multiplies two matrices together.
- `s21_transpose`: Transposes a matrix.
- `s21_determinant`: Calculates the determinant of a matrix.
- `s21_inverse_matrix`: Computes the inverse of a matrix.
- `s21_calc_complements`: Calculates the minor and algebraic complements of a matrix.

---
# Chapter IV
### Unit Tests

Unit tests are written using the Check library to ensure the correct functionality of each matrix operation. The code is designed to have full coverage with unit tests that cover at least 80% of the functions, which are validated using the gcov tool.

### Building and Running the Library

To build and test the library, the following steps are necessary:

#### Clone the Repository:
```bash
git clone git@github.com:le0ruslan/matrix-library.git
cd matrix-library/src
```
#### Build the Static Library:
```bash
make s21_matrix.a
```
#### Run Unit Tests:
```bash
make test
```
#### Generate Code Coverage Report:
```bash
make gcov_report
```

#### Cleans build artifacts:
```bash
make clean
```
