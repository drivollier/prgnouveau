
static uint64_t zz,z=0xb1a2bc2ec5;
static uint64_t yy1=0xa2bc2ec5;
static uint64_t yy2=0xb1;
static uint64_t yy3=0xb100000000;
static uint32_t s=0;


uint32_t gen32(void)
{
    uint64_t r=yy1*(z&0xffffffff);
    s=r;
    z=(r>>32)+(yy2*z)+(yy1*(z>>32))+(yy3*zz);
    zz=((((z>>32)*yy2)+((zz&0xffffffff)*yy1))>>32)+(yy2*zz)+(yy1*(zz>>32));

    return s;
}



