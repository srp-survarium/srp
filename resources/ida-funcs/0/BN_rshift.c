int __cdecl BN_rshift(bignum_st *r, const bignum_st *a, int n)
{
  int v3; // esi
  int v4; // ebx
  int top; // eax
  bignum_st *v6; // edx
  int result; // eax
  unsigned int *v8; // eax
  int v9; // ecx
  unsigned int *d; // edi
  unsigned int v11; // esi
  unsigned int *v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // ebp
  bool v15; // zf
  int v16; // eax
  unsigned int *v17; // ecx
  int v19; // [esp+1Ch] [ebp+Ch]

  v3 = n / 32;
  v4 = n % 32;
  top = a->top;
  if ( n / 32 >= top || !top )
  {
    BN_set_word(r, 0);
    return 1;
  }
  v6 = r;
  if ( r == a )
  {
    if ( !n )
      return 1;
    goto LABEL_10;
  }
  r->neg = a->neg;
  if ( a->top - v3 + 1 > r->dmax )
  {
    result = (int)bn_expand2(r, (unsigned int *)(a->top - v3 + 1));
    v6 = r;
  }
  else
  {
    result = (int)r;
  }
  if ( result )
  {
LABEL_10:
    v8 = &a->d[v3];
    v9 = a->top - v3;
    d = v6->d;
    v6->top = v9;
    if ( v4 )
    {
      v11 = *v8;
      v12 = v8 + 1;
      v19 = v9 - 1;
      if ( v9 != 1 )
      {
        do
        {
          v13 = v11;
          v11 = *v12;
          v14 = *v12++ << (32 - v4);
          ++d;
          v15 = v19-- == 1;
          *(d - 1) = (v13 >> v4) | v14;
        }
        while ( !v15 );
        v6 = r;
      }
      *d = v11 >> v4;
    }
    else
    {
      for ( ; v9; --v9 )
        *d++ = *v8++;
    }
    v16 = v6->top;
    if ( v16 > 0 )
    {
      v17 = &v6->d[v16 - 1];
      do
      {
        if ( *v17-- )
          break;
        --v16;
      }
      while ( v16 > 0 );
      v6->top = v16;
      return 1;
    }
    return 1;
  }
  return result;
}
