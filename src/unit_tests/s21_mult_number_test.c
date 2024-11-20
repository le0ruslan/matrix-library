#include "s21_matrix_test.h"

START_TEST(mult_number_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t mul = {0};

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 4, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&B)->matrix[i][j] = ((&A)->matrix[i][j] = (i + 1) * j) * 4;
    }
  }

  s21_mult_number(&A, 4, &mul);

  int ret = s21_eq_matrix(&mul, &B);
  ck_assert_int_eq(ret, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&mul);
}
END_TEST

START_TEST(mult_number_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t mul = {0};

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 4, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&B)->matrix[i][j] = ((&A)->matrix[i][j] = (i + 1) * j) * 0.25;
    }
  }

  s21_mult_number(&A, 0.25, &mul);

  int ret = s21_eq_matrix(&mul, &B);
  ck_assert_int_eq(ret, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&mul);
}
END_TEST

START_TEST(mult_number_test_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t mul = {0};

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 4, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&B)->matrix[i][j] = ((&A)->matrix[i][j] = (i + 1) * j) * 0.25;
    }
  }

  s21_mult_number(&A, 0.25, &mul);

  int ret = s21_eq_matrix(&mul, &B);
  ck_assert_int_eq(ret, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&mul);
}
END_TEST

START_TEST(mult_number_test_4) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &correct);
  double k = 2.5;
  double f = 3.25;
  double value = 1.3;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  for (int i = 0; i < correct.rows; i++) {
    for (int j = 0; j < correct.columns; j++) {
      correct.matrix[i][j] = f;
      f += 1.3;
    }
  }

  int ret_value = s21_mult_number(&A, value, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(mult_number_test_5) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &correct);
  double k = 2.5134512;
  double f = 3.2674866;
  double value = 1.3;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  for (int i = 0; i < correct.rows; i++) {
    for (int j = 0; j < correct.columns; j++) {
      correct.matrix[i][j] = f;
      f += 1.3;
    }
  }
  int ret_value = s21_mult_number(&A, value, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(mult_number_test_6) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &correct);
  double k = 2.5134512;
  double f = 3.2674866;
  double value = 1.3;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  for (int i = 0; i < correct.rows; i++) {
    for (int j = 0; j < correct.columns; j++) {
      correct.matrix[i][j] = f;
      f += 1.3;
    }
  }
  int ret_value = s21_mult_number(&A, value, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(mult_number_test_7) {
  matrix_t A = {0};
  A.columns = 6;
  A.rows = 5;
  A.matrix = NULL;

  matrix_t mul = {0};

  int ret = s21_mult_number(&A, 4, &mul);

  ck_assert_int_eq(ret, INVALID_MATRIX);

  s21_remove_matrix(&mul);
}
END_TEST

Suite *suite_mult_number_test() {
  Suite *s = suite_create("s21_mult_number");
  TCase *tc = tcase_create("s21_mult_number_test");

  tcase_add_test(tc, mult_number_test_1);
  tcase_add_test(tc, mult_number_test_2);
  tcase_add_test(tc, mult_number_test_3);
  tcase_add_test(tc, mult_number_test_4);
  tcase_add_test(tc, mult_number_test_5);
  tcase_add_test(tc, mult_number_test_6);
  tcase_add_test(tc, mult_number_test_7);
  suite_add_tcase(s, tc);

  return s;
}