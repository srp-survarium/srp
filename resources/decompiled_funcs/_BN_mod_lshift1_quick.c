int __cdecl BN_mod_lshift1_quick(bignum_st *r, const bignum_st *a, const bignum_st *m)
{
  int result; // eax

  result = BN_lshift1(r, a);
  if ( result )
  {
    if ( BN_cmp(r, m) < 0 )
      return 1;
    else
      return BN_sub(r, r, m);
  }
  return result;
}
