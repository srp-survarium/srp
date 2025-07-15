void __cdecl BN_clear(bignum_st *a)
{
  if ( a->d )
    memset((int)a->d, 0, 4 * a->dmax);
  a->neg = 0;
  a->top = 0;
}
