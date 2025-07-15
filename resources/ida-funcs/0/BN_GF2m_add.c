bignum_st *__cdecl BN_GF2m_add(bignum_st *r, const bignum_st *a, const bignum_st *b)
{
  const bignum_st *v3; // edi
  const bignum_st *v4; // esi
  bignum_st *result; // eax
  int i; // eax
  int top; // eax
  unsigned int *v8; // ecx

  v3 = b;
  if ( a->top >= b->top )
  {
    v4 = a;
  }
  else
  {
    v4 = b;
    v3 = a;
  }
  if ( v4->top > r->dmax )
    result = bn_expand2(r, v4->top);
  else
    result = r;
  if ( result )
  {
    for ( i = 0; i < v3->top; ++i )
      r->d[i] = v3->d[i] ^ v4->d[i];
    for ( ; i < v4->top; ++i )
      r->d[i] = v4->d[i];
    top = v4->top;
    r->top = top;
    if ( top > 0 )
    {
      v8 = &r->d[top - 1];
      do
      {
        if ( *v8-- )
          break;
        --top;
      }
      while ( top > 0 );
      r->top = top;
    }
    return (bignum_st *)1;
  }
  return result;
}
