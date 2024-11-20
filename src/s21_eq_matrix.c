#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (s21_is_valid_matrix(A) || s21_is_valid_matrix(B) || A->rows != B->rows ||
      A->columns != B->columns) {
    return FAILURE;
  }

  int err = SUCCESS;

  for (int i = 0; i < A->rows && err; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) {
        err = FAILURE;
      }
    }
  }

  return err;
}