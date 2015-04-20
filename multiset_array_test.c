#include "seatest.h"
#include "multiset_array.h"

static void test_placeholder() {
	assert_int_equal(-2, -2);
}

static void test_fixture() {
	test_fixture_start();

	run_test(test_placeholder);

	test_fixture_end();
}

static void all_tests(void) {
	test_fixture();
}

int main() {
	return run_tests(all_tests);
}
