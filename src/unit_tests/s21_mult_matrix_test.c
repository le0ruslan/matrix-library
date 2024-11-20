#include "s21_matrix_test.h"

START_TEST(mult_matrix_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t mult_result = {0};
  matrix_t mult_custom = {0};
  double matrix[] = {30, 36, 42, 66, 81, 96, 102, 126, 150};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &mult_custom);

  int counter = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = ++counter;
    }
  }

  counter = 0;
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      (&B)->matrix[i][j] = ++counter;
    }
  }

  counter = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&mult_custom)->matrix[i][j] = matrix[counter++];
    }
  }

  int ret1 = s21_mult_matrix(&A, &B, &mult_result);
  int ret2 = s21_eq_matrix(&mult_result, &mult_custom);

  ck_assert_int_eq(ret1, OK);
  ck_assert_int_eq(ret2, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&mult_result);
  s21_remove_matrix(&mult_custom);
}
END_TEST

START_TEST(mult_matrix_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t mult_result = {0};
  matrix_t mult_custom = {0};
  double matrix[] = {22,  28,  49,  64,  76,  100, 103,
                     136, 130, 172, 157, 208, 184, 244};

  s21_create_matrix(7, 3, &A);
  s21_create_matrix(3, 2, &B);
  s21_create_matrix(7, 2, &mult_custom);

  int counter = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = ++counter;
    }
  }

  counter = 0;
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      (&B)->matrix[i][j] = ++counter;
    }
  }

  counter = 0;
  for (int i = 0; i < mult_custom.rows; i++) {
    for (int j = 0; j < mult_custom.columns; j++) {
      (&mult_custom)->matrix[i][j] = matrix[counter++];
    }
  }

  int ret1 = s21_mult_matrix(&A, &B, &mult_result);
  int ret2 = s21_eq_matrix(&mult_result, &mult_custom);

  ck_assert_int_eq(ret1, OK);
  ck_assert_int_eq(ret2, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&mult_result);
  s21_remove_matrix(&mult_custom);
}
END_TEST

START_TEST(mult_matrix_test_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t *mult_result = NULL;

  s21_create_matrix(7, 3, &A);
  s21_create_matrix(3, 2, &B);

  int counter = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = ++counter;
    }
  }

  counter = 0;
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      (&B)->matrix[i][j] = ++counter;
    }
  }

  int ret1 = s21_mult_matrix(&A, &B, mult_result);

  ck_assert_int_eq(ret1, INVALID_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(mult_result);
}
END_TEST

START_TEST(mult_matrix_test_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t mult_result = {0};

  s21_create_matrix(7, 2, &A);
  s21_create_matrix(3, 2, &B);

  int counter = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = ++counter;
    }
  }

  counter = 0;
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      (&B)->matrix[i][j] = ++counter;
    }
  }

  int ret1 = s21_mult_matrix(&A, &B, &mult_result);

  ck_assert_int_eq(ret1, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&mult_result);
}
END_TEST

START_TEST(mult_matrix_test_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t mult_result = {0};

  s21_create_matrix(5, 2, &A);
  s21_create_matrix(3, 2, &B);

  int counter = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = ++counter;
    }
  }

  counter = 0;
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      (&B)->matrix[i][j] = ++counter;
    }
  }

  int ret1 = s21_mult_matrix(&A, &B, &mult_result);

  ck_assert_int_eq(ret1, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&mult_result);
}
END_TEST

Suite *suite_mult_matrix_test() {
  Suite *s = suite_create("s21_mult_matrix");
  TCase *tc = tcase_create("s21_mult_matrix_test");

  tcase_add_test(tc, mult_matrix_test_1);
  tcase_add_test(tc, mult_matrix_test_2);
  tcase_add_test(tc, mult_matrix_test_3);
  tcase_add_test(tc, mult_matrix_test_4);
  tcase_add_test(tc, mult_matrix_test_5);
  suite_add_tcase(s, tc);

  return s;
}