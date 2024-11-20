#include "s21_matrix_test.h"

START_TEST(transpose_test_1) {
  int rows = 3;
  int cols = 3;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);

  matrix_t check = {0};
  s21_create_matrix(cols, rows, &check);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = i + j;
      check.matrix[j][i] = i + j;
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(s21_transpose(&m, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_test_2) {
  int res = 0;
  matrix_t A = {0};

  res = s21_transpose(&A, &A);
  ck_assert_int_eq(res, INVALID_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_test_3) {
  int rows = 4;
  int cols = 4;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);

  matrix_t check = {0};
  s21_create_matrix(cols, rows, &check);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = i + j;
      check.matrix[j][i] = i + j;
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(s21_transpose(&m, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_test_4) {
  int res;
  matrix_t m, check;

  m.rows = 20;
  m.columns = 199;
  m.matrix = NULL;
  res = s21_transpose(&m, &check);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *suite_transpose_test() {
  Suite *s = suite_create("s21_transpose_suite");
  TCase *tc = tcase_create("s21_transpose_suite");

  tcase_add_test(tc, transpose_test_1);
  tcase_add_test(tc, transpose_test_2);
  tcase_add_test(tc, transpose_test_3);
  tcase_add_test(tc, transpose_test_4);

  suite_add_tcase(s, tc);

  return s;
}
