void __usercall fdrffti(int n@<eax>, int *ifac@<ecx>, float *wsave)
{
  if ( n != 1 )
    drfti1(n, &wsave[n], ifac);
}
