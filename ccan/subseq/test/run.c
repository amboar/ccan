#include <ccan/subseq/subseq.h>
/* Include the C files directly. */
#include <ccan/subseq/subseq.c>
#include <ccan/tap/tap.h>

int main(void)
{
	/* This is how many tests you plan to run */
	plan_tests(2);

	/* Simple thing we expect to succeed */
	ok(subseq_count_subseqs("x") == 2, "One char two subsequence");
	ok(subseq_count_nlong_subseqs("x", 1) == 1, "One char subsequence length one");

	/* This exits depending on whether all tests passed */
	return exit_status();
}
