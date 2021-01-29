#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    FILE* fichier=NULL;
    int decompte(unsigned long x);
    void suivant(int d[4]);
    unsigned long x,nbiter;
    unsigned int r;
    int d[4]={1,1,1,1};
    char reste;
    int rebours,i,j;
    sscanf(argv[2],"%lu",&x);
    sscanf(argv[3],"%lu",&nbiter);
    fichier = fopen(argv[1], "w");
    fputs("#==================================================================\n",fichier);
    fputs("# generateur D. Rivollier\n",fichier);
    fputs("#==================================================================\n",fichier);
    fputs("type: d\n",fichier);
    fprintf(fichier,"count: %lu\n",nbiter);
    fputs("numbit: 32\n",fichier);
    rebours=decompte(x);
    time_t top=time(NULL);
    for (j=0;j<nbiter;j++)
    {
        r=0;
        for (i=0;i<16;i++)
        {
            if (rebours==0)
            {
                suivant(d);
                rebours=decompte(x);
            }
            rebours=rebours-1;
            reste=(x%4);
            r+=reste<<(2*i);
            if (reste==0)
            {
                x=(x>>2)+d[0];
            }
            else if (reste==1)
            {
                x=3*(x>>2)+d[1];
            }
            else if (reste==2)
            {
                x=5*(x>>2)+d[2];
            }
            else
            {
                x=17*(x>>2)+d[3];
            }
        }
    fprintf(fichier,"%u\n",r);
    }
    fclose(fichier);
    time_t sop=time(NULL);
    printf("%ld",sop-top);
    return 0;
}

void suivant(int d[4])
{
    if (d[0]==0 & d[1]==0)
    {
        if (d[2]==0)
        {
            d[0]=d[3]+1;d[1]=0;d[2]=0;d[3]=0;
        }
        else
        {
            d[0]=d[2]-1;d[1]=d[3]+1;d[2]=0;d[3]=0;
        }
    }
    else
    {
        if (d[2]==0)
        {
            d[2]=d[3]+1;d[3]=0;
        }
        else
        {
            d[2]=d[2]-1;d[3]=d[3]+1;
        }
        if (d[1]==0)
        {
            d[1]=d[0]-1;d[0]=0;
        }
        else
        {
            d[0]=d[0]+1;d[1]=d[1]-1;
        }
    }
}
int decompte(unsigned long x)
{
    int y=1;
    while (x>=(1UL<<(2*y)) & y<32)
    {
        y=y+1;
    }
    return y;
}
