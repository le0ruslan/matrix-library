#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = OK;
  if (s21_is_valid_matrix(A) || s21_is_valid_matrix(B) || result == NULL) {
    err = INVALID_MATRIX;
  }

  if (!err && (A->rows != B->rows || A->columns != B->columns)) {
    err = CALCULATION_ERROR;
  }

  if (!err) {
    err = s21_create_matrix(A->rows, A->columns, result);
  }

  if (!err) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return err;
}