#include "s21_matrix.h"

int s21_is_valid_matrix(matrix_t *check) {
  int err = OK;
  if (check == NULL || check->matrix == NULL || check->rows <= 0 ||
      check->columns <= 0) {
    err = INVALID_MATRIX;
  }
  return err;
}

void s21_remove_matrix(matrix_t *A) {
  if (s21_is_valid_matrix(A)) {
    return;
  }
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}