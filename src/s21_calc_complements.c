#include "s21_matrix.h"

void s21_find_cofactor(double **m, double **tmp, int skip_row, int skip_col,
                       int size) {
  for (int i = 0, row = 0; row < size; row++) {
    for (int j = 0, col = 0; col < size; col++) {
      if (row != skip_row && col != skip_col) {
        tmp[i][j] = m[row][col];
        j++;
        if (j == size - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
}

double s21_find_det(double **m, int size) {
  double res = 0;
  int err = OK;
  if (size == 1) {
    res = m[0][0];
  }
  matrix_t tmp = {0};
  if (s21_create_matrix(size, size, &tmp)) {
    err = CALCULATION_ERROR;
  }
  if (!err) {
    int sign = 1;
    for (int i = 0; i < size; i++) {
      s21_find_cofactor(m, tmp.matrix, 0, i, size);
      res += sign * m[0][i] * s21_find_det(tmp.matrix, size - 1);
      sign = -sign;
    }
  }
  s21_remove_matrix(&tmp);
  return res;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err = OK;
  if (s21_is_valid_matrix(A)) {
    err = INVALID_MATRIX;
  }

  if (!err) {
    if (A->rows != A->columns ||
        s21_create_matrix(A->rows, A->columns, result) != OK) {
      err = CALCULATION_ERROR;
    }
  }
  if (!err) {
    if (A->rows == 1) {
      result->matrix[0][0] = 1;
    } else {
      matrix_t tmp = {0};

      if (s21_create_matrix(A->rows, A->columns, &tmp)) {
        err = CALCULATION_ERROR;
      }
      if (!err) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            s21_find_cofactor(A->matrix, tmp.matrix, i, j, A->rows);

            int sign = ((i + j) % 2 == 0) ? 1 : -1;

            result->matrix[i][j] = sign * s21_find_det(tmp.matrix, A->rows - 1);
          }
        }
      }

      s21_remove_matrix(&tmp);
    }
  }
  return err;
}