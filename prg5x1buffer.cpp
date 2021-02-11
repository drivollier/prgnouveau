#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>


const int BUFFER_SIZE = 4096;
const int N=2;
static uint64_t x[N]={7};



void gen( uint32_t* buf, int nb) {


    uint32_t* end = buf+nb;

    for(; buf<end; ++buf)
        {
            uint32_t s;
    char out,r,t;
    int i,k;
        s=0;
        for (i=0;i<32;i++)
        {
            out=(x[0]& 0b1);
            s=2*s+out;
            if (out==1)
            {
                r=1;
                for (k=0;k<N-1;k++)
                {
                    x[k]=5*x[k]+r;
                    r=(x[k]>>61);
                    x[k]=((x[k]<<3)>>3);
                }
                x[N-1]=5*x[N-1]+r;
            }
            r=(x[N-1]& 0b1);
            x[N-1]=x[N-1]>>1;
            for (k=N-2;k>=0;k--)
            {
                t=(x[k]& 0b1);
                x[k]=(x[k]>>1)+((r*1UL)<<60);
                r=t;
            }
        }

        *buf = s;
    }
}
void dump(FILE* f, uint32_t* buf, int nb) {
    int reste = nb&0xF;
    uint32_t* end=buf+nb-reste;

    for(;buf<end;) {
        fprintf(f, "%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n" ,
            *(buf), *(buf+1), *(buf+2), *(buf+3), *(buf+4), *(buf+5), *(buf+6), *(buf+7), *(buf+8),
            *(buf+9), *(buf+10), *(buf+11), *(buf+12), *(buf+13), *(buf+14), *(buf+15));
        buf += 16;
    }
    for(;reste>0;--reste)
        fprintf(f, "%u\n", *(buf++));
}

int main(int argc, char *argv[])
{

    uint32_t nb;

    sscanf(argv[2],"%d",&nb);
    FILE* f = fopen(argv[1], "w");
    fprintf(f, "#==================================================================\n");
    fprintf(f, "# generateur D. Rivollier\n");
    fprintf(f, "#==================================================================\n");
    fprintf(f, "type: d\ncount: %d\nnumbit: 32\n", nb);
    uint32_t* buffer = (uint32_t*)malloc(BUFFER_SIZE*sizeof(*buffer));
    time_t top=time(NULL);

    for(uint32_t i=0; i<nb/BUFFER_SIZE; ++i) {
        gen(buffer, BUFFER_SIZE);
        dump(f, buffer, BUFFER_SIZE);
    }
    gen( buffer, nb%BUFFER_SIZE);
    dump(f, buffer, nb%BUFFER_SIZE);

    fclose(f);
    time_t sop=time(NULL);
    printf("%ld\n",sop-top);

    return 0;
}
