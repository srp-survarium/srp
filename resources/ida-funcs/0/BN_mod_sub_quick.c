int __cdecl BN_mod_sub_quick(bignum_st *r, const bignum_st *a, const bignum_st *b, const bignum_st *m)
{
  int result; // eax

  result = BN_sub(r, a, b);
  if ( result )
  {
    if ( r->neg )
      return BN_add(r, r, m);
    else
      return 1;
  }
  return result;
}
