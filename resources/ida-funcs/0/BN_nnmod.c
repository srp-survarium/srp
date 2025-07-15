int __usercall BN_nnmod@<eax>(int a1@<ebx>, bignum_st *r, const bignum_st *m, const bignum_st *d, bignum_ctx *ctx)
{
  int result; // eax
  int (__cdecl *v6)(bignum_st *, const bignum_st *, const bignum_st *); // eax

  result = BN_div(a1, 0, r, m, d, ctx);
  if ( result )
  {
    if ( r->neg )
    {
      v6 = BN_sub;
      if ( !d->neg )
        v6 = BN_add;
      return v6(r, r, d);
    }
    else
    {
      return 1;
    }
  }
  return result;
}
