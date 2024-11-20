#ifndef S21_MATRIX_TEST
#define S21_MATRIX_TEST

#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

Suite* suite_create_matrix_test();
Suite* suite_eq_matrix_test();
Suite* suite_sum_matrix_test();
Suite* suite_sub_matrix_test();
Suite* suite_mult_number_test();
Suite* suite_mult_matrix_test();
Suite* suite_transpose_test();
Suite* suite_complements_test();
Suite* suite_determinant_test();
Suite* suite_inverse_test();
Suite* suite_remove_matrix_test();

#endif