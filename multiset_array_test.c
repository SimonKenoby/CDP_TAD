#include "point.h"
#include "seatest.h"
#include "multiset_array.h"
#include <string.h>

static void test_is_empty() {
	Array *array1 = create_empty();				//Test 1
	assert_true(is_empty(array1));

	Point *p1 = create_point(2, 8);				//Test 2
	Point *p2 = create_point(2, 8);

	array1 = add_to((void*)p1, array1);
	array1 = remove_from((void*)p2, array1, compare_points);
	assert_true(is_empty(array1));

	free(array1);
	free(p1);
	free(p2);
}

static void test_equals() {
	Point *p1 = create_point(2, 7);				//Test 1
	Point *p2 = create_point(4, 1);

	Array *array1 = create_empty();
	array1 = add_to((void*)p1, array1);
	array1 = add_to((void*)p2, array1);

	Array *array2 = create_empty();
	array2 = add_to((void*)p2, array2);
	array2 = add_to((void*)p1, array2);

	assert_true(equals(array1, array2, compare_points));

	free(array1);
	free(array2);
	free(p1);
	free(p2);
}

static void test_count() {
	Point *p1 = create_point(2, 7);				//Test 1

	Array *array1 = create_empty();
	for (int i = 0; i < 20; i++)
		array1 = add_to((void*)p1, array1);

	assert_int_equal(count(array1), 20);

	Array *array2 = create_empty();				//Test 2
	assert_int_equal(count(array2), 0);

	free(array1);
	free(array2);
	free(p1);
}

static void test_occurrences() {
	Point *p1 = create_point(3, 3);				//Test 1
	Point *p2 = create_point(5, 7);
	Point *p3 = create_point(3, 3);

	Array *array1 = create_empty();
	array1 = add_to((void*)p1, array1);
	array1 = add_to((void*)p2, array1);
	array1 = add_to((void*)p3, array1);
	array1 = add_to((void*)p3, array1);
	array1 = add_to((void*)p3, array1);

	assert_int_equal(occurrences(p1, array1, compare_points), 4);

	Array *array2 = create_empty();				//Test 2
	assert_int_equal(occurrences(p1, array2, compare_points), 0);

	free(array1);
	free(array2);
	free(p1);
	free(p2);
	free(p3);
}

static void test_part_of() {
	Point *p1 = create_point(3, 4);
	Point *p2 = create_point(9, -2);

	Array *array1 = create_empty();
	array1 = add_to((void*)p1, array1);

	assert_true(part_of(p1, array1, compare_points));
	assert_false(part_of(p2, array1, compare_points));

	free(array1);
	free(p1);
	free(p2);
}

static void test_join() {
	Point *p1 = create_point(2, 7);
	Point *p2 = create_point(4, 1);

	Array *array1 = create_empty();
	array1 = add_to((void*)p1, array1);

	Array *array2 = create_empty();
	array2 = add_to((void*)p2, array2);
	array2 = add_to((void*)p2, array2);

	Array *array3 = join(array1, array2);

	assert_int_equal(count(array1), 1);
	assert_int_equal(count(array2), 2);
	assert_int_equal(count(array3), 3);

	assert_int_equal(occurrences(p1, array3, compare_points), 1);
	assert_int_equal(occurrences(p2, array3, compare_points), 2);

	free(array1);
	free(array2);
	free(array3);
	free(p1);
	free(p2);
}

static void test_add_to() {
	Point *p1 = create_point(2, 7);

	Array *array1 = create_empty();
	assert_int_equal(occurrences(p1, array1, compare_points), 0);
	assert_int_equal(count(array1), 0);
	array1 = add_to((void*)p1, array1);
	assert_int_equal(occurrences(p1, array1, compare_points), 1);
	assert_int_equal(count(array1), 1);

	free(array1);
	free(p1);
}

static void test_remove_from() {
	Point *p1 = create_point(2, 7);				//Test 1
	Point *p2 = create_point(7, 1);

	Array *array1 = create_empty();
	array1 = add_to((void*)p1, array1);
	assert_int_equal(occurrences(p1, array1, compare_points), 1);
	assert_int_equal(count(array1), 1);
	array1 = remove_from((void*)p1, array1, compare_points);
	assert_int_equal(occurrences(p1, array1, compare_points), 0);
	assert_int_equal(count(array1), 0);

	array1 = add_to((void*)p2, array1);			//Test 2
	assert_int_equal(occurrences(p2, array1, compare_points), 1);
	assert_int_equal(count(array1), 1);
	array1 = remove_from((void*)p1, array1, compare_points);
	assert_int_equal(occurrences(p1, array1, compare_points), 0);
	assert_int_equal(occurrences(p2, array1, compare_points), 1);
	assert_int_equal(count(array1), 1);

	free(array1);
	free(p1);
	free(p2);
}

static void test_fixture() {
	test_fixture_start();

	run_test(test_is_empty);
	run_test(test_equals);
	run_test(test_count);
	run_test(test_occurrences);
	run_test(test_part_of);
	run_test(test_join);
	run_test(test_add_to);
	run_test(test_remove_from);

	test_fixture_end();
}

static void all_tests(void) {
	test_fixture();
}

int main() {
	return run_tests(all_tests);
}
