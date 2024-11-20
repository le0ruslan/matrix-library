#include "s21_matrix_test.h"

START_TEST(remove_matrix_test_1) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(remove_matrix_test_2) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(remove_matrix_test_3) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(remove_matrix_test_4) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 4, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(remove_matrix_test_5) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, OK);
}
END_TEST

Suite *suite_remove_matrix_test() {
  Suite *s = suite_create("s21_remove_matrix");
  TCase *tc = tcase_create("s21_remove_matrix_test");

  tcase_add_test(tc, remove_matrix_test_1);
  tcase_add_test(tc, remove_matrix_test_2);
  tcase_add_test(tc, remove_matrix_test_3);
  tcase_add_test(tc, remove_matrix_test_4);
  tcase_add_test(tc, remove_matrix_test_5);
  suite_add_tcase(s, tc);
  return s;
}
