def suivant(L):
    a,b,c,d=L[0],L[1],L[2],L[3]
    if a==0 and b==0:
        if c==0:
            return [d+1,0,0,0]
        else:
            return [c-1,d+1,0,0]
    else:
        if c==0:
            x2,x3=d+1,0
        else:
            x2,x3=c-1,d+1
        if b==0:
            x0,x1=0,a-1
        else:
            x0,x1=a+1,b-1
        return [x0,x1,x2,x3]


def evol(x,c,d):
    j=x%4
    return j,c[j]*((x-j)//4)+d[j]


def genere1(nom,N,graine=5,c=[1,3,5,17],d=[1,1,1,1]):
    f = open (nom, "w", encoding="ascii")
    f.write('#==================================================================\n')
    f.write('# generateur D. Rivollier\n')
    f.write('#==================================================================\n')
    f.write('type: d\n')
    f.write('count: '+str(N)+'\n')
    f.write('numbit: 32\n')
    dejavu=set()
    x=graine
    L=[]
    for i in range(16*N):
        if x in dejavu:
            dejavu=set()
            d=suivant(d)
        dejavu.add(x)
        r,x=evol(x,c,d)
        L+=[r]
        if i%16==15:
            s=0
            for k in range(16):
                s+=L[k]*4**k
            f.write(str(s)+'\n')
            L=[]
    f.close()


def genere2(nom,N,graine=5,c=[1,3,5,17],d=[1,1,1,1]):
    f = open (nom, "w")
    f.write('#==================================================================\n')
    f.write('# generateur D. Rivollier\n')
    f.write('#==================================================================\n')
    f.write('type: d\n')
    f.write('count: '+str(N)+'\n')
    f.write('numbit: 32\n')
    x=graine
    L=[]
    rebours=(len(bin(x))-1)//2
    for i in range(16*N):
        if x>=2**64:
            x=x%(2**64)
        if rebours==0:
            d=suivant(d)
            rebours=(len(bin(x))-1)//2
        rebours=rebours-1
        r,x=evol(x,c,d)
        L+=[r]
        if i%16==15:
            s=0
            for k in range(16):
                s+=L[k]*4**k
            f.write(str(s)+'\n')
            L=[]
