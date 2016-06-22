#include <stdlib.h>
#include <check.h>
#include "../src/romanNumeralCalc.h"


START_TEST(test_nothing)
{
    ck_assert_str_eq("X","X");
    ck_assert_int_eq( 0 , 0 );

}
END_TEST

START_TEST(test_singleRomanToInt)
{
    ck_assert_int_eq(	singleRomanToInt('I'), 1);
    ck_assert_int_eq(	singleRomanToInt('V'), 5);
    ck_assert_int_eq(	singleRomanToInt('X'), 10);
    ck_assert_int_eq(	singleRomanToInt('L'), 50);
    ck_assert_int_eq(	singleRomanToInt('C'), 100);
    ck_assert_int_eq(	singleRomanToInt('D'), 500);
    ck_assert_int_eq(	singleRomanToInt('M'), 1000);
    ck_assert_int_eq(	singleRomanToInt('A'), INVALID_INPUT);

}
END_TEST


Suite * romanNumCalc_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("RomanNumeralCalc");

    /* Core test case */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_nothing);
    tcase_add_test(tc_core, test_singleRomanToInt);
    suite_add_tcase(s, tc_core);

    return s;
}


int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = romanNumCalc_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

}

