int __cdecl BN_nnmod(bignum_st *r, const bignum_st *m, const bignum_st *d, bignum_ctx *ctx)
{
  int result; // eax
  int (__cdecl *v5)(bignum_st *, const bignum_st *, const bignum_st *); // eax

  result = BN_div(0, r, m, d, ctx);
  if ( result )
  {
    if ( r->neg )
    {
      v5 = BN_sub;
      if ( !d->neg )
        v5 = BN_add;
      return v5(r, r, d);
    }
    else
    {
      return 1;
    }
  }
  return result;
}
