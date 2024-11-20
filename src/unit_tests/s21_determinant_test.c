#include <stdio.h>

#include "s21_matrix_test.h"

START_TEST(determinant_test_1) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j;
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test_2) {
  const int size = 4;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j + i;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test_3) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][1] = 6;
  m.matrix[0][2] = -2;
  m.matrix[0][3] = -1;
  m.matrix[0][4] = 5;
  m.matrix[1][3] = -9;
  m.matrix[1][4] = -7;
  m.matrix[2][1] = 15;
  m.matrix[2][2] = 35;
  m.matrix[3][1] = -1;
  m.matrix[3][2] = -11;
  m.matrix[3][3] = -2;
  m.matrix[3][4] = 1;
  m.matrix[4][0] = -2;
  m.matrix[4][1] = -2;
  m.matrix[4][2] = 3;
  m.matrix[4][4] = -2;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 2480, 1e-3);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test_4) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 3;
  m.matrix[0][2] = 1;
  m.matrix[1][0] = 7;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 1;
  m.matrix[2][0] = 9;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = 1;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -32, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test_5) {
  const int size = 2;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = -5;
  m.matrix[0][1] = -4;
  m.matrix[1][0] = -2;
  m.matrix[1][1] = -3;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 7, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test_6) {
  const int size = 1;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = -5;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -5, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test_7) {
  matrix_t m = {0};
  int rows = rand() % 100 + 1;
  rows = -rows;
  s21_create_matrix(rows, rows, &m);
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_int_eq(code, INVALID_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test_8) {
  matrix_t m = {NULL, 0, 0};
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_int_eq(code, INVALID_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test_9) {
  matrix_t m = {0};
  s21_create_matrix(3, 2, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 3;
  m.matrix[1][0] = 7;
  m.matrix[1][1] = 4;
  m.matrix[2][0] = 9;
  m.matrix[2][1] = -2;
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_int_eq(code, CALCULATION_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

Suite *suite_determinant_test(void) {
  Suite *s = suite_create("s21_determinant");

  TCase *tc_core = tcase_create("s21_determinant_test");

  tcase_add_test(tc_core, determinant_test_1);
  tcase_add_test(tc_core, determinant_test_2);
  tcase_add_test(tc_core, determinant_test_3);
  tcase_add_test(tc_core, determinant_test_4);
  tcase_add_test(tc_core, determinant_test_5);
  tcase_add_test(tc_core, determinant_test_6);
  tcase_add_loop_test(tc_core, determinant_test_7, 0, 9);
  tcase_add_test(tc_core, determinant_test_8);
  tcase_add_test(tc_core, determinant_test_9);

  suite_add_tcase(s, tc_core);

  return s;
}
