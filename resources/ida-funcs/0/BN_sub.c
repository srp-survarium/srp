int __cdecl BN_sub(bignum_st *r, const bignum_st *a, const bignum_st *b)
{
  const bignum_st *v3; // ebx
  const bignum_st *v4; // esi
  unsigned int *top; // eax
  bignum_st *v6; // eax
  int v7; // edi

  v3 = a;
  v4 = b;
  if ( a->neg )
  {
    if ( b->neg )
    {
      v3 = b;
      v4 = a;
      goto LABEL_4;
    }
    v7 = 1;
LABEL_11:
    if ( BN_uadd(r, a, b) )
    {
      r->neg = v7;
      return 1;
    }
    return 0;
  }
  if ( b->neg )
  {
    v7 = 0;
    goto LABEL_11;
  }
LABEL_4:
  top = (unsigned int *)v3->top;
  if ( (int)top <= v4->top )
    top = (unsigned int *)v4->top;
  if ( (int)top > r->dmax )
    v6 = bn_expand2(r, top);
  else
    v6 = r;
  if ( !v6 )
    return 0;
  if ( BN_ucmp(v3, v4) < 0 )
  {
    if ( BN_usub(r, v4, v3) )
    {
      r->neg = 1;
      return 1;
    }
    return 0;
  }
  if ( !BN_usub(r, v3, v4) )
    return 0;
  r->neg = 0;
  return 1;
}
