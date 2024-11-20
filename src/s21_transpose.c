#include <stdbool.h>

#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int err = OK;

  if (s21_is_valid_matrix(A) || result == NULL) {
    err = INVALID_MATRIX;
  }

  if (!err) err = s21_create_matrix(A->columns, A->rows, result);

  if (!err) {
    for (int rowi = 0; rowi < result->rows; ++rowi) {
      for (int coli = 0; coli < result->columns; ++coli) {
        result->matrix[rowi][coli] = A->matrix[coli][rowi];
      }
    }
  }
  return err;
}