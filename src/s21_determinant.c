#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int err = OK;
  if (result != NULL) {
    *result = 0.0;
  }

  if (s21_is_valid_matrix(A) || result == NULL) {
    err = INVALID_MATRIX;
  }

  if (A->rows != A->columns && !err) {
    err = CALCULATION_ERROR;
  }
  if (!err) {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else {
      *result = s21_find_det(A->matrix, A->rows);
    }
  }
  return err;
}