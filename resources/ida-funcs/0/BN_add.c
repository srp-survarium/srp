int __cdecl BN_add(bignum_st *r, const bignum_st *a, const bignum_st *b)
{
  const bignum_st *v3; // esi
  int neg; // ebx
  const bignum_st *v5; // edi
  int result; // eax

  v3 = a;
  neg = a->neg;
  v5 = b;
  if ( neg != b->neg )
  {
    if ( neg )
    {
      v3 = b;
      v5 = a;
    }
    if ( BN_ucmp(v3, v5) >= 0 )
    {
      if ( !BN_usub(r, v3, v5) )
        return 0;
      r->neg = 0;
      return 1;
    }
    else
    {
      if ( !BN_usub(r, v5, v3) )
        return 0;
      r->neg = 1;
      return 1;
    }
  }
  else
  {
    result = (int)BN_uadd(r, a, b);
    r->neg = neg;
  }
  return result;
}
