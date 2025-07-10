bignum_st *__cdecl BN_set_bit(bignum_st *a, int n)
{
  bignum_st *result; // eax
  int v3; // ebx
  int v4; // edi
  int i; // eax

  if ( n < 0 )
    return 0;
  v3 = n / 32;
  if ( a->top > n / 32 )
    goto LABEL_11;
  v4 = v3 + 1;
  if ( v3 + 1 > a->dmax )
    result = bn_expand2(a, (unsigned int *)(v3 + 1));
  else
    result = a;
  if ( result )
  {
    for ( i = a->top; i < v4; ++i )
      a->d[i] = 0;
    a->top = v4;
LABEL_11:
    a->d[v3] |= 1 << (n & 0x1F);
    return (bignum_st *)1;
  }
  return result;
}
