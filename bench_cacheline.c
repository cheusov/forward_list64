#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define STEP 999331
#define COUNT 1000

int main(int argc, char **argv) {
    uint8_t *ptr = aligned_alloc(64, (COUNT + 63) / 64 * 64);
    if (!ptr) {
        perror("malloc(3) failed");
        return 1;
    }

    --argc;
    ++argv;

    if (argc != 1) {
        fprintf(stderr, "integer argument is expected\n");
        return 2;
    }

    ptr += atoi(argv[0]);

    size_t index = 0;
    size_t sum = 0;
    for (unsigned k = 0; k < 2000; ++k) {
        for (unsigned i = 0; i < COUNT; ++i) {
            uint8_t *bytes64 = ptr + index;
            sum += *bytes64;
            *bytes64 += 56;

            index = (index + STEP) % COUNT;
        }
    }

    printf("%zu\n", sum);
    return 0;
}
