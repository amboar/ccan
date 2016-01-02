/* MIT (BSD) license - see LICENSE file for details */
#ifndef CCAN_SUBSEQ_H
#define CCAN_SUBSEQ_H
#include <stddef.h>
#include <stdint.h>

int64_t subseq_count_subseqs(const char *const str);
int64_t subseq_count_nlong_subseqs(const char *const str, size_t nlong);
#endif /* CCAN_SUBSEQ_H */
