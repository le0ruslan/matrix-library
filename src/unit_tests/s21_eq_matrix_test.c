#include "s21_matrix_test.h"

START_TEST(eq_matrix_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 4, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = (&B)->matrix[i][j] = (i + 1) * j;
    }
  }

  int ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(4, 3, &A);
  s21_create_matrix(3, 4, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = (i + 1) * j;
    }
  }

  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      (&B)->matrix[i][j] = (i + 1) * j;
    }
  }

  int ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_3) {
  matrix_t A = {0};
  matrix_t *B = NULL;

  s21_create_matrix(4, 3, &A);
  s21_create_matrix(3, 4, B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = (i + 1) * j;
    }
  }

  int ret = s21_eq_matrix(&A, B);
  ck_assert_int_eq(ret, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(B);
}
END_TEST

START_TEST(eq_matrix_test_4) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 4, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = (&B)->matrix[i][j] = (i + 1) * j;
    }
  }

  (&A)->matrix[0][0] += 0.000001;

  int ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_5) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 4, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = (&B)->matrix[i][j] = (i + 1) * j;
    }
  }

  (&A)->matrix[0][0] += 0.0000001;

  int ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_6) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(6, 6, &A);
  s21_create_matrix(6, 6, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = (&B)->matrix[i][j] = (i + 1) * j;
    }
  }

  int ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_7) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = (&B)->matrix[i][j] = (i + 1) * j;
    }
  }

  int ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_8) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(0, 1, &A);
  s21_create_matrix(0, 1, &B);

  int ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_9) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(10, 1, &A);
  s21_create_matrix(10, 1, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = (&B)->matrix[i][j] = (i + 1) * j;
    }
  }

  int ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_10) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 4, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      (&A)->matrix[i][j] = (&B)->matrix[i][j] = (i + 1) * j;
    }
  }

  (&A)->matrix[0][0] += 0.000001;

  int ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_eq_matrix_test() {
  Suite *s = suite_create("s21_eq_matrix");
  TCase *tc = tcase_create("s21_eq_matrix_test");

  tcase_add_test(tc, eq_matrix_test_1);
  tcase_add_test(tc, eq_matrix_test_2);
  tcase_add_test(tc, eq_matrix_test_3);
  tcase_add_test(tc, eq_matrix_test_4);
  tcase_add_test(tc, eq_matrix_test_5);
  tcase_add_test(tc, eq_matrix_test_6);
  tcase_add_test(tc, eq_matrix_test_7);
  tcase_add_test(tc, eq_matrix_test_8);
  tcase_add_test(tc, eq_matrix_test_9);
  tcase_add_test(tc, eq_matrix_test_10);
  suite_add_tcase(s, tc);
  return s;
}