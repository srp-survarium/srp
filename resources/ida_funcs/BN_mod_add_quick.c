int __cdecl BN_mod_add_quick(bignum_st *r, const bignum_st *a, const bignum_st *b, const bignum_st *m)
{
  int result; // eax

  result = (int)BN_uadd(r, a, b);
  if ( result )
  {
    if ( BN_ucmp(r, m) < 0 )
      return 1;
    else
      return BN_usub(r, r, m);
  }
  return result;
}
