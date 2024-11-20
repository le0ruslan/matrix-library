#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = OK;
  if (s21_is_valid_matrix(A) || s21_is_valid_matrix(B) || result == NULL) {
    err = INVALID_MATRIX;
  }

  if (!err && A->columns != B->rows) {
    err = CALCULATION_ERROR;
  }

  if (!err) {
    err = s21_create_matrix(A->rows, B->columns, result);
  }

  if (!err) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return err;
}