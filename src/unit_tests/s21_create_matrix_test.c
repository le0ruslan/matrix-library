#include "s21_matrix_test.h"

START_TEST(create_matrix_test_1) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_test_2) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_test_3) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_test_4) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(2, 4, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_test_5) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(10, 15, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_test_6) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(res, INVALID_MATRIX);
}
END_TEST

START_TEST(create_matrix_test_7) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(1, 0, &A);
  ck_assert_int_eq(res, INVALID_MATRIX);
}
END_TEST

START_TEST(create_matrix_test_8) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(0, 1, &A);
  ck_assert_int_eq(res, INVALID_MATRIX);
}
END_TEST

START_TEST(create_matrix_test_9) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(-1, 1, &A);
  ck_assert_int_eq(res, INVALID_MATRIX);
}
END_TEST

START_TEST(create_matrix_test_10) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = 0;
      ck_assert_ldouble_eq_tol(0, m.matrix[i][j], 1e-06);
    }
  }
  ck_assert_int_eq(m.rows, rows);
  ck_assert_int_eq(m.columns, cols);
  s21_remove_matrix(&m);
}
END_TEST

Suite *suite_create_matrix_test() {
  Suite *s = suite_create("s21_create_matrix");
  TCase *tc = tcase_create("s21_create_matrix_test");

  tcase_add_test(tc, create_matrix_test_1);
  tcase_add_test(tc, create_matrix_test_2);
  tcase_add_test(tc, create_matrix_test_3);
  tcase_add_test(tc, create_matrix_test_4);
  tcase_add_test(tc, create_matrix_test_5);
  tcase_add_test(tc, create_matrix_test_6);
  tcase_add_test(tc, create_matrix_test_7);
  tcase_add_test(tc, create_matrix_test_8);
  tcase_add_test(tc, create_matrix_test_9);
  tcase_add_test(tc, create_matrix_test_10);
  suite_add_tcase(s, tc);
  return s;
}
