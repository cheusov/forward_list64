#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// #define COUNT (32*1024*4)
#define COUNT 0x20000

int main(int argc, char **argv) {
    uint8_t *ptr = aligned_alloc(64, COUNT);
    if (!ptr) {
        perror("aligned_alloc(3) failed");
        return 1;
    }

    --argc;
    ++argv;

    if (argc != 1) {
        fprintf(stderr, "integer argument is expected\n");
        return 2;
    }

    size_t step = atoi(argv[0]);
    size_t index = 0;
    size_t sum = 0;
    for (unsigned k = 0; k < 5000; ++k) {
        for (unsigned i = 0; i < COUNT; ++i) {
            sum += ptr[index];
            index = (index + step) & (COUNT - 1);

            sum += ptr[index];
            index = (index + step) & (COUNT - 1);

            sum += ptr[index];
            index = (index + step) & (COUNT - 1);

            sum += ptr[index];
            index = (index + step) & (COUNT - 1);

            sum += ptr[index];
            index = (index + step) & (COUNT - 1);

            sum += ptr[index];
            index = (index + step) & (COUNT - 1);

            sum += ptr[index];
            index = (index + step) & (COUNT - 1);

            sum += ptr[index];
            index = (index + step) & (COUNT - 1);

        }
    }

    printf("%zu\n", sum);
    return 0;
}
