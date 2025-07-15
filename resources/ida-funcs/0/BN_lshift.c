bignum_st *__cdecl BN_lshift(bignum_st *r, const bignum_st *a, int n)
{
  const bignum_st *v3; // esi
  int top; // edx
  int v5; // ebp
  bignum_st *result; // eax
  int v7; // edi
  unsigned int *d; // edx
  unsigned int *v9; // ecx
  int v10; // eax
  unsigned int *v11; // edi
  int v12; // esi
  unsigned int *v13; // edx
  unsigned int v14; // eax
  int v15; // ebp
  int v16; // eax
  unsigned int *v17; // edx
  int v19; // [esp+Ch] [ebp-8h]
  unsigned int *v20; // [esp+10h] [ebp-4h]
  unsigned int *v21; // [esp+20h] [ebp+Ch]

  v3 = a;
  r->neg = a->neg;
  top = a->top;
  v5 = n / 32;
  v19 = n / 32;
  if ( top + n / 32 + 1 > r->dmax )
    result = bn_expand2(r, top + n / 32 + 1);
  else
    result = r;
  if ( result )
  {
    v7 = n % 32;
    d = r->d;
    v9 = a->d;
    v21 = a->d;
    v20 = d;
    d[v5 + a->top] = 0;
    if ( v7 )
    {
      v12 = a->top - 1;
      if ( v12 >= 0 )
      {
        v13 = &d[v12 + 1 + v5];
        while ( 1 )
        {
          v14 = v9[v12--];
          *v13-- |= v14 >> (32 - v7);
          *v13 = v14 << v7;
          if ( v12 < 0 )
            break;
          v9 = v21;
        }
        v5 = v19;
        d = v20;
      }
      v3 = a;
    }
    else
    {
      v10 = a->top - 1;
      if ( v10 >= 0 )
      {
        v11 = &d[v10 + v5];
        do
          *v11-- = v9[v10--];
        while ( v10 >= 0 );
      }
    }
    memset((int)d, 0, 4 * v5);
    v15 = v3->top + v5 + 1;
    v16 = v15;
    r->top = v15;
    if ( v15 > 0 )
    {
      v17 = &r->d[v15 - 1];
      do
      {
        if ( *v17-- )
          break;
        --v16;
      }
      while ( v16 > 0 );
      r->top = v16;
    }
    return (bignum_st *)1;
  }
  return result;
}
