unsigned int __cdecl BN_is_bit_set(const bignum_st *a, int n)
{
  if ( n < 0 || a->top <= n / 32 )
    return 0;
  else
    return (a->d[n / 32] >> (n & 0x1F)) & 1;
}
