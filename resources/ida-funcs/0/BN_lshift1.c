int __cdecl BN_lshift1(bignum_st *r, const bignum_st *a)
{
  bignum_st *v2; // eax
  bignum_st *v4; // eax
  unsigned int *d; // ecx
  unsigned int v6; // edx
  int v7; // ebx
  unsigned int *v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // eax

  if ( r == a )
  {
    if ( a->top + 1 > r->dmax )
      v4 = bn_expand2(r, a->top + 1);
    else
      v4 = r;
    if ( !v4 )
      return 0;
  }
  else
  {
    r->neg = a->neg;
    if ( a->top + 1 > r->dmax )
      v2 = bn_expand2(r, a->top + 1);
    else
      v2 = r;
    if ( !v2 )
      return 0;
    r->top = a->top;
  }
  d = r->d;
  v6 = 0;
  v7 = 0;
  v8 = a->d;
  if ( a->top > 0 )
  {
    do
    {
      v9 = *v8;
      *d = v6 | (2 * *v8);
      v10 = v9 >> 31;
      ++v7;
      ++v8;
      ++d;
      v6 = v10;
    }
    while ( v7 < a->top );
    if ( v10 )
    {
      *d = 1;
      ++r->top;
    }
  }
  return 1;
}
