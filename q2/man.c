#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint16_t func(uint16_t N) {
    /* change all right side bits to 1 */
    N |= N >> 1; // 110000000000 | 011000000000 = 111000000000
    N |= N >> 2; // 111000000000 | 001110000000 = 111110000000
    N |= N >> 4; // 111110000000 | 000011111000 = 111111111000
    N |= N >> 8; // 111111111000 | 000011111111 = 111111111111

    return (N + 1) >> 1; // 111111111111 + 1 = 100000000000, 100000000000 >> 1 = 10000000000(2) = 2048(10)
}

int main(int argc, char *argv[]) {
    uint16_t a = strtoul(argv[1], NULL, 10); // 110000000000(2) = 3096(10)
    printf("a=%d\n", a);
    uint16_t b = func(a);
    printf("b=%d\n", b);
    return 0;
}