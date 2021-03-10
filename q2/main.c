#include <stdint.h>
#include <stdio.h>


uint16_t func(uint16_t N) {
    /* change all right side bits to 1 */
    N |= N >> 1;
    N |= N >> 2;
    N |= N >> 3;
    N |= N >> 4;

    return (N + 1) >> 1;
}

int main(void) {
    uint16_t a = 120;
    uint16_t b = func(a);
    printf("b=%d\n", b);
    return 0;
}