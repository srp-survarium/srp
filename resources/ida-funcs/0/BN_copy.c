bignum_st *__cdecl BN_copy(bignum_st *a, const bignum_st *b)
{
  const bignum_st *v2; // esi
  bignum_st *v3; // edi
  bignum_st *result; // eax
  unsigned int *d; // eax
  unsigned int *v6; // ecx
  int v7; // edx
  unsigned int v8; // esi
  unsigned int v9; // edi
  unsigned int v10; // ebx

  v2 = b;
  v3 = a;
  if ( a == b )
    return v3;
  if ( b->top > a->dmax )
    result = bn_expand2(a, (unsigned int *)b->top);
  else
    result = a;
  if ( result )
  {
    d = a->d;
    v6 = b->d;
    v7 = b->top >> 2;
    if ( v7 > 0 )
    {
      do
      {
        v8 = v6[1];
        v9 = v6[2];
        v10 = v6[3];
        *d = *v6;
        d[1] = v8;
        d[2] = v9;
        d[3] = v10;
        --v7;
        d += 4;
        v6 += 4;
      }
      while ( v7 > 0 );
      v2 = b;
      v3 = a;
    }
    if ( (v2->top & 3) != 1 )
    {
      if ( (v2->top & 3) != 2 )
      {
        if ( (v2->top & 3) != 3 )
        {
LABEL_15:
          v3->top = v2->top;
          v3->neg = v2->neg;
          return v3;
        }
        d[2] = v6[2];
      }
      d[1] = v6[1];
    }
    *d = *v6;
    goto LABEL_15;
  }
  return result;
}
