#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err = OK;
  if (s21_is_valid_matrix(A) != OK) {
    err = INVALID_MATRIX;
  }

  if (A->rows != A->columns && !err) {
    err = CALCULATION_ERROR;
  }
  if (!err) {
    double d = 0;
    int code = s21_determinant(A, &d);

    if (d == 0 || code) {
      err = CALCULATION_ERROR;
    }

    if (!err) {
      matrix_t adj = {0};
      if (s21_calc_complements(A, &adj)) {
        err = CALCULATION_ERROR;
      }
      if (!err) {
        matrix_t transposed = {0};

        if (s21_transpose(&adj, &transposed) ||
            s21_create_matrix(A->rows, A->rows, result)) {
          err = CALCULATION_ERROR;
        }
        if (!err) {
          for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->rows; j++)
              result->matrix[i][j] = transposed.matrix[i][j] / d;
        }
        s21_remove_matrix(&transposed);
      }
      s21_remove_matrix(&adj);
    }
  }
  return err;
}