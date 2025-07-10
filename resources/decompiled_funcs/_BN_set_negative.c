void __cdecl BN_set_negative(bignum_st *a, int b)
{
  a->neg = b && a->top;
}
