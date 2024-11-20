#include "s21_matrix_test.h"

START_TEST(sub_matrix_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t sub_custom = {0};
  matrix_t sub = {0};

  s21_create_matrix(3, 6, &A);
  s21_create_matrix(3, 6, &B);
  s21_create_matrix(3, 6, &sub_custom);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = ((&B)->matrix[i][j] = (i + 1) * j) + 5;
      (&sub_custom)->matrix[i][j] = (&A)->matrix[i][j] - (&B)->matrix[i][j];
    }
  }

  int ret1 = s21_sub_matrix(&A, &B, &sub);
  int ret2 = s21_eq_matrix(&sub, &sub_custom);

  ck_assert_int_eq(ret1, OK);
  ck_assert_int_eq(ret2, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&sub);
  s21_remove_matrix(&sub_custom);
}
END_TEST
START_TEST(sub_matrix_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t sub_custom = {0};
  matrix_t sub = {0};

  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 1, &B);
  s21_create_matrix(3, 1, &sub_custom);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = ((&B)->matrix[i][j] = rand()) + 5;
      (&sub_custom)->matrix[i][j] = (&A)->matrix[i][j] - (&B)->matrix[i][j];
    }
  }

  int ret1 = s21_sub_matrix(&A, &B, &sub);
  int ret2 = s21_eq_matrix(&sub, &sub_custom);

  ck_assert_int_eq(ret1, OK);
  ck_assert_int_eq(ret2, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&sub);
  s21_remove_matrix(&sub_custom);
}
END_TEST

START_TEST(sub_matrix_test_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t sub = {0};

  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 2, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = ((&B)->matrix[i][j] = rand()) + 5;
    }
  }

  int ret1 = s21_sub_matrix(&A, &B, &sub);

  ck_assert_int_eq(ret1, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&sub);
}
END_TEST

START_TEST(sub_matrix_test_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t *sub = NULL;

  s21_create_matrix(3, 6, &A);
  s21_create_matrix(3, 6, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = ((&B)->matrix[i][j] = (i + 1) * j) + 5;
    }
  }

  int ret1 = s21_sub_matrix(&A, &B, sub);

  ck_assert_int_eq(ret1, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(sub);
}
END_TEST

Suite *suite_sub_matrix_test() {
  Suite *s = suite_create("s21_sub_matrix");
  TCase *tc = tcase_create("s21_sub_matrix_test");

  tcase_add_test(tc, sub_matrix_test_1);
  tcase_add_test(tc, sub_matrix_test_2);
  tcase_add_test(tc, sub_matrix_test_3);
  tcase_add_test(tc, sub_matrix_test_4);
  suite_add_tcase(s, tc);
  return s;
}