#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>
#include <random>

const int MAX_SEEDS = 1;
uint64_t seed_data[MAX_SEEDS];

uint32_t mt()
{
    static std::mt19937 rng(seed_data[0]);

    return rng();
}

static uint64_t       state      = 0x4d595df4d0f33173;		// Or something seed-dependent
static uint64_t const multiplier = 6364136223846793005u;
static uint64_t const increment  = 1442695040888963407u;	// Or an arbitrary odd constant

static uint32_t rotr32(uint32_t x, unsigned r)
{
	return x >> r | x << (-r & 31);
}

uint32_t pcg(void)
{
	uint64_t x = state;
	unsigned count = (unsigned)(x >> 59);		// 59 = 64 - 5

	state = x * multiplier + increment;
	x ^= x >> 18;								// 18 = (64 - 27)/2
	return rotr32((uint32_t)(x >> 27), count);	// 27 = 32 - 5
}




//place du générateur-pseudo-aléatoire
uint32_t gen32(void)
{
    
}




int main(int argc, char *argv[])
{


    uint64_t j,nbiter=100000000;

    double top=clock();
    for (j=0;j<nbiter;j++)
    {
    gen32();
}
    double sop=clock();
    printf("%f\n",(sop-top)/1000000);
    for (j=0;j<nbiter;j++)
    {
    pcg();
}
top=clock();
printf("%f\n",(top-sop)/1000000);
for (j=0;j<nbiter;j++)
    {
    mt();
}
sop=clock();
printf("%f\n",(sop-top)/1000000);

    return 0;
}
