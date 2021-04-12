
const int N=2;
static uint64_t x[N]={9};
static uint32_t s=0;


uint32_t gen32(void)
{
    int i,k,out;
            for (i=0;i<32;i++)
        {
            out=x[0]%2;
            s=(s<<1)|out;
	    if (out==1)
            {
                x[0]=5*x[0];
                for(k=1;k<N;k++)
                {
                x[k]=5*x[k]+(x[k-1]>>61);
                x[k-1]=(x[k-1]<<3)>>3;
                }
            }
            for (k=0;k<N-1;k++)
            {
            x[k]=(x[k]>>1)|((x[k+1]%2)<<60);
            }
            x[N-1]=x[N-1]>>1;
        }
    return s;
}




