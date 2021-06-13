const int N=8;
static uint16_t m[N]={7915,1551};
static uint16_t c[N]={5717,1958};
static uint16_t y[N]={};

uint16_t gen16(void)
    {
    int i,j;
    uint64_t it=m[0]*c[0];
    uint16_t output=it;

    for (i=1;i<N;i++)
    {
      it=it>>16;
      for (j=0;j<i+1;j++)
      {
          it+=c[j]*m[i-j];
      }
      y[i-1]=it;
    }
    it=it>>16;
    for (j=1;j<N;j++)
    {
        it+=c[j]*m[N-j];
    }
    y[N-1]=it;
    for (j=0;j<N;j++)
    {
        m[j]=y[j];
    }

    return output;
    }

uint32_t gen32()
{
    return ((gen16())<<16)+gen16();
}


