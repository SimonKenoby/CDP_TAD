#include "seatest.h"
#include "multiset_array.h"

static void test_is_empty() {
	Array *array = create_empty();
	assert_true(is_empty(array));
	free(array);
}

static void test_fixture() {
	test_fixture_start();

	run_test(test_is_empty);

	test_fixture_end();
}

static void all_tests(void) {
	test_fixture();
}

int main() {
	return run_tests(all_tests);
}
