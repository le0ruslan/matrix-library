#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int err = OK;
  if (s21_is_valid_matrix(A) || result == NULL) {
    err = INVALID_MATRIX;
  }

  if (!err) {
    err = s21_create_matrix(A->rows, A->columns, result);
  }
  if (!err) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return err;
}