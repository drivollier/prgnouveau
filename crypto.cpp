
const int N=2;
static uint64_t x[N]={7};
static uint64_t d[N]={1};
static uint32_t s=0;
static uint32_t puiss5[9]={1};
static uint16_t mult[256]={0};
static uint64_t inc[256]={0};
static uint32_t out[256]={0};
static char dejaconstruit=0;

void construit(void)

{
for (int j=0;j<256;j++)
{
    uint32_t alpha=0,outp=0;
    uint16_t m=0;
    uint64_t y=j;
    for (uint16_t i=0;i<8;i++)
    {
        if (y%2==0)
        {
            y>>=1;
        }
        else
        {
            outp=outp+(1<<i);
            m+=1;
            alpha=5*alpha+(1<<i);
            y=(5*y+d[0])>>1;
        }
    }
    out[j]=outp;
    mult[j]=m;
    inc[j]=alpha;

}
}

void decale(void)
{
    for (int k=0;k<N-1;k++)
    {
        x[k]=(x[k]>>8)|(x[k+1]<<56);
    }
    x[N-1]=(x[N-1]>>8);
}

void itere(uint32_t m,uint32_t alpha)
{
    uint64_t z=m*(x[0]>>32)+alpha*(d[0]>>32);
    x[0]=m*(x[0]& 0xffffffff)+alpha*(d[0]& 0xffffffff)+(z<<32);
    for (int k=1;k<N-1;k++)
    {
        uint64_t t=m*(x[k]>>32)+alpha*(d[k]>>32);
        x[k]=m*(x[k]& 0xffffffff)+alpha*(d[k]& 0xffffffff)+(t<<32)+(z>>32);
        z=t;
    }
    x[N-1]=m*x[N-1]+alpha*d[N-1]+(z>>32);

}

uint32_t gen32(void)
    {
if (dejaconstruit==0)
{
dejaconstruit=1;
for (int i=1;i<9;i++)
    {
        puiss5[i]=5*puiss5[i-1];
    }
    construit();
}
    uint32_t j=x[0]%256;
    s=out[j];
    itere(puiss5[mult[j]],inc[j]);
    decale();
    j=x[0]%256;
    s=s|(out[j]<<8);
    itere(puiss5[mult[j]],inc[j]);
    decale();
    j=x[0]%256;
    s=s|(out[j]<<16);
    itere(puiss5[mult[j]],inc[j]);
    decale();
    j=x[0]%256;
    s=s|(out[j]<<24);
    itere(puiss5[mult[j]],inc[j]);
    decale();


    return s;
    }


