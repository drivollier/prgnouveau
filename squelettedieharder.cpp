#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>




uint32_t gen32(void)
{
   
}


int main(int argc, char *argv[])
{

    uint64_t j,nbiter;
    sscanf(argv[2],"%lu",&nbiter);

    FILE* fichier=NULL;
    fichier = fopen(argv[1], "w");
    fputs("#==================================================================\n",fichier);
    fputs("# generateur D. Rivollier\n",fichier);
    fputs("#==================================================================\n",fichier);
    fputs("type: d\n",fichier);
    fprintf(fichier,"count: %lu\n",nbiter);
    fputs("numbit: 32\n",fichier);
    time_t top=time(NULL);
    for (j=0;j<nbiter;j++)
    {
        fprintf(fichier,"%u\n",gen32());

}
    fclose(fichier);
    time_t sop=time(NULL);
    printf("%ld\n",sop-top);

    return 0;
}
