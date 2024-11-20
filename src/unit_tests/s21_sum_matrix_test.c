#include "s21_matrix_test.h"

START_TEST(sum_matrix_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t sum_custom = {0};
  matrix_t sum = {0};

  s21_create_matrix(3, 6, &A);
  s21_create_matrix(3, 6, &B);
  s21_create_matrix(3, 6, &sum_custom);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = ((&B)->matrix[i][j] = (i + 1) * j) + 5;
      (&sum_custom)->matrix[i][j] = (&A)->matrix[i][j] + (&B)->matrix[i][j];
    }
  }

  int ret1 = s21_sum_matrix(&A, &B, &sum);
  int ret2 = s21_eq_matrix(&sum, &sum_custom);

  ck_assert_int_eq(ret1, OK);
  ck_assert_int_eq(ret2, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&sum_custom);
}
END_TEST
START_TEST(sum_matrix_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t sum_custom = {0};
  matrix_t sum = {0};

  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 1, &B);
  s21_create_matrix(3, 1, &sum_custom);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = ((&B)->matrix[i][j] = rand()) + 5;
      (&sum_custom)->matrix[i][j] = (&A)->matrix[i][j] + (&B)->matrix[i][j];
    }
  }

  int ret1 = s21_sum_matrix(&A, &B, &sum);
  int ret2 = s21_eq_matrix(&sum, &sum_custom);

  ck_assert_int_eq(ret1, OK);
  ck_assert_int_eq(ret2, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&sum_custom);
}
END_TEST

START_TEST(sum_matrix_test_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t sum = {0};

  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 2, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = ((&B)->matrix[i][j] = rand()) + 5;
    }
  }

  int ret1 = s21_sum_matrix(&A, &B, &sum);

  ck_assert_int_eq(ret1, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&sum);
}
END_TEST

START_TEST(sum_matrix_test_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t *sum = NULL;

  s21_create_matrix(3, 6, &A);
  s21_create_matrix(3, 6, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = ((&B)->matrix[i][j] = (i + 1) * j) + 5;
    }
  }

  int ret1 = s21_sum_matrix(&A, &B, sum);

  ck_assert_int_eq(ret1, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(sum);
}
END_TEST

Suite *suite_sum_matrix_test() {
  Suite *s = suite_create("s21_sum_matrix");
  TCase *tc = tcase_create("s21_sum_matrix_test");

  tcase_add_test(tc, sum_matrix_test_1);
  tcase_add_test(tc, sum_matrix_test_2);
  tcase_add_test(tc, sum_matrix_test_3);
  tcase_add_test(tc, sum_matrix_test_4);
  suite_add_tcase(s, tc);
  return s;
}