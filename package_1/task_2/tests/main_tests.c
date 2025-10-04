#include <assert.h>
#include "primes.h"

int main(void) {
    unsigned int result;

    find_nth_prime(1, &result);
    assert(result == 2);
    
    find_nth_prime(2, &result);
    assert(result == 3);

    find_nth_prime(3, &result);
    assert(result == 5);

    find_nth_prime(4, &result);
    assert(result == 7);

    find_nth_prime(5, &result);
    assert(result == 11);

    find_nth_prime(6, &result);
    assert(result == 13);

    return 0;
}
