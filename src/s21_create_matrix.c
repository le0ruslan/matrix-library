#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int err = OK;

  if (rows <= 0 || columns <= 0 || result == NULL) {
    err = INVALID_MATRIX;  // 1
    return err;
  }

  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix) {
    for (int i = 0; i < rows && !err; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (!result->matrix[i]) {
        for (int j = 0; j < i; j++) free(result->matrix[j]);

        free(result->matrix);
        err = INVALID_MATRIX;
      }
    }
  } else {
    err = CALCULATION_ERROR;
  }
  if (!err) {
    result->rows = rows;
    result->columns = columns;
  }
  return err;
}