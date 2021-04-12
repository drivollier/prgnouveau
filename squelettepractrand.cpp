#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include <random>



uint32_t gen32(void)
    {
    
    }
int main(void)
{

std::mt19937 rng(42);

    while (1) {
        uint32_t value = gen32();
        fwrite((void*) &value, sizeof(value), 1, stdout);

}
}


