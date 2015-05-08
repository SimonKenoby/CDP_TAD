#include "point.h"
#include "seatest.h"
#include "multiset_list.h"
#include <string.h>

static void test_is_empty() {
	list *list1 = create_empty();			//Test 1
	assert_true(is_empty(list1));

	Point *p1 = create_point(2, 8);				//Test 2
	Point *p2 = create_point(2, 8);

	list1 = add_to(list1, (void*)p1);
	list1 = remove_from(list1, (void*)p2, compare_points);
	assert_true(is_empty(list1));
	free(list1);
	free(p1);
	free(p2);
}

static void test_equals() {
	Point *p1 = create_point(2, 7);				//Test 1
	Point *p2 = create_point(4, 1);

	list *list1 = create_empty();
	list1 = add_to(list1, (void*)p1);
	list1 = add_to(list1, (void*)p2);
	list *list2 = create_empty();
	list2 = add_to(list2, (void*)p2);
	list2 = add_to(list2, (void*)p1);

	assert_true(equals(list1, list2, compare_points));

	free(list1);
	free(list2);
	free(p1);
	free(p2);
}

static void test_count() {
	Point *p1 = create_point(2, 7);
	int i = 0;		//Test 1

	list *list1 = create_empty();
	for (i = 0; i < 20; i++)
		list1 = add_to(list1, (void*)p1);

	assert_int_equal(count(list1), 20);

	list *list2 = create_empty();				//Test 2
	assert_int_equal(count(list2), 0);

	free(list1);
	free(list2);
	free(p1);
}

static void test_occurrences() {
	Point *p1 = create_point(3, 3);				//Test 1
	Point *p2 = create_point(5, 7);
	Point *p3 = create_point(3, 3);

	list *list1 = create_empty();
	list1 = add_to(list1, (void*)p1);
	list1 = add_to(list1, (void*)p2);
	list1 = add_to(list1, (void*)p3);
	list1 = add_to(list1, (void*)p3);
	list1 = add_to(list1, (void*)p3);

	assert_int_equal(occurrences(list1, p1, compare_points), 4);


	list *list2 = create_empty();				//Test 2
	assert_int_equal(occurrences(list2, p2, compare_points), 0);


	free(list1);
	free(list2);
	free(p1);
	free(p2);
	free(p3);
}

static void test_part_of() {
	Point *p1 = create_point(3, 4);
	Point *p2 = create_point(9, -2);

	list *list1 = create_empty();
	list1 = add_to(list1, (void*)p1);

	assert_true(part_of(list1, p1, compare_points));
	assert_false(part_of(list1, p2, compare_points));

	free(list1);
	free(p1);
	free(p2);
}

static void test_join() {
	Point *p1 = create_point(2, 7);
	Point *p2 = create_point(4, 1);

	list *list1 = create_empty();
	list1 = add_to(list1, (void*)p1);

	list *list2 = create_empty();
	list2 = add_to(list2, (void*)p2);
	list2 = add_to(list2, (void*)p2);

	list *list3 = join(list1, list2);

	assert_int_equal(count(list1), 1);
	assert_int_equal(count(list2), 2);
	assert_int_equal(count(list3), 3);

	assert_int_equal(occurrences(list3, p1, compare_points), 1);
	assert_int_equal(occurrences(list3, p2, compare_points), 2);

	free(list1);
	free(list2);
	free(list3);
	free(p1);
	free(p2);
}

static void test_add_to() {
	Point *p1 = create_point(2, 7);

	list *list1 = create_empty();
	assert_int_equal(occurrences(list1, p1, compare_points), 0);
	assert_int_equal(count(list1), 0);
	list1 = add_to(list1, (void*)p1);
	assert_int_equal(occurrences(list1, p1, compare_points), 1);
	assert_int_equal(count(list1), 1);

	free(list1);
	free(p1);
}

static void test_remove_from() {
	Point *p1 = create_point(2, 7);				//Test 1
	Point *p2 = create_point(7, 1);

	list *list1 = create_empty();
	list1 = add_to(list1, (void*)p1);
	assert_int_equal(occurrences(list1, p1, compare_points), 1);
	assert_int_equal(count(list1), 1);
	list1 = remove_from(list1, (void*)p1, compare_points);
	assert_int_equal(occurrences(list1, p1, compare_points), 0);
	assert_int_equal(count(list1), 0);

	list1 = add_to(list1, (void*)p2);			//Test 2
	assert_int_equal(occurrences(list1, p2, compare_points), 1);
	assert_int_equal(count(list1), 1);
	list1 = remove_from(list1, (void*)p1, compare_points);
	assert_int_equal(occurrences(list1, p1, compare_points), 0);
	assert_int_equal(occurrences(list1, p2, compare_points), 1);
	assert_int_equal(count(list1), 1);

	free(list1);
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
