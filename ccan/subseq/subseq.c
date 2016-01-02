/* MIT (BSD) license - see LICENSE file for details */
#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "subseq.h"

#include <stdio.h>

#define UNSIGNED(x) ({ assert(x >= 0); abs(x); })

/**
 * Algorithm 1.
 */
int64_t subseq_count_subseqs(const char *const str) {
    size_t len;
    int16_t *l;
    int64_t *N;
    int ret, i;

    len = strlen(str);
    if (len > ((1L << (8 * sizeof(*l) - 1)) - 1)) {
        /* long string, indexes won't fit in typeof(*l) */
        ret = -1;
        goto done;
    }

    l = calloc(1 << CHAR_BIT, sizeof(*l));
    if (!l) {
        ret = -1;
        goto done;
    }

    N = calloc(len + 1, sizeof(*N));
    if (!N) {
        ret = -1;
        goto cleanup_l;
    }

    N[0] = 1;
    printf("foo\n");
    for(i = 1; i <= len; i++) {
        unsigned int ci;
        printf("bar: %d\n", i);
        ci = UNSIGNED(str[i - 1]);
        N[i] = 2 * N[i - 1];
        if (l[ci]) {
            N[i] -= N[l[ci] - 1];
        }
        l[ci] = (typeof(*l)) i;
        printf("l[0x%x] = %d\n", ci, i);
    }
    ret = N[len];

    free(N);
cleanup_l:
    free(l);
done:
    return ret;
}

int64_t subseq_count_nlong_subseqs(const char *const str, size_t nlong) {
    return 0;
}
