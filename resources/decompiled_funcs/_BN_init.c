void __cdecl BN_init(bignum_st *a)
{
  a->d = 0;
  a->top = 0;
  a->dmax = 0;
  a->neg = 0;
  a->flags = 0;
}
