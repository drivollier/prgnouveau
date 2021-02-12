#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>


int main(int argc, char *argv[])
{
    int N,j,nbiter;
    sscanf(argv[2],"%u",&nbiter);
    sscanf(argv[3],"%u",&N);
    uint64_t x[N];
    uint64_t d[N];

    for (int k=0;k<N;k++)
    {
	sscanf(argv[4+k],"%lu",&x[k]);        
	sscanf(argv[4+N+k],"%lu",&d[k]);
    }
    x[0]+=7;
    FILE* fichier=NULL;
    fichier = fopen(argv[1], "w");
    fputs("#==================================================================\n",fichier);
    fputs("# generateur D. Rivollier\n",fichier);
    fputs("#==================================================================\n",fichier);
    fputs("type: d\n",fichier);
    fprintf(fichier,"count: %u\n",nbiter);
    fputs("numbit: 32\n",fichier);
    uint32_t s;
    int i,k;
    char out,r,t;
    time_t top=time(NULL);
    for (j=0;j<nbiter;j++)
    {
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
                    x[k]=5*x[k]+r+d[k];
                    r=(x[k]>>61);
                    x[k]=((x[k]<<3)>>3);
                }
                x[N-1]=5*x[N-1]+r+d[N-1];
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

    fprintf(fichier,"%u\n",s);
    }
    fclose(fichier);
    time_t sop=time(NULL);
    printf("%ld\n",sop-top);
    return 0;
}
