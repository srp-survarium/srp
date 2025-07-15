bignum_st *__cdecl BN_bin2bn(const unsigned __int8 *s, int len, bignum_st *ret)
{
  bignum_st *v3; // ebx
  int v4; // edi
  int v6; // ecx
  unsigned int *v7; // esi
  int v8; // ebp
  bignum_st *v9; // eax
  int v11; // esi
  int v12; // edx
  int top; // eax
  unsigned int *v14; // ecx
  bignum_st *a; // [esp+8h] [ebp-4h]

  v3 = ret;
  v4 = 0;
  a = 0;
  if ( !ret )
  {
    a = BN_new();
    v3 = a;
    if ( !a )
      return 0;
  }
  v6 = len;
  if ( len )
  {
    v7 = (unsigned int *)(((unsigned int)(len - 1) >> 2) + 1);
    v8 = (len - 1) & 3;
    if ( (int)v7 > v3->dmax )
    {
      v9 = bn_expand2(v3, v7);
      v6 = len;
    }
    else
    {
      v9 = v3;
    }
    if ( v9 )
    {
      v3->top = (int)v7;
      v3->neg = 0;
      v11 = (int)v7;
      do
      {
        v4 = *s | (v4 << 8);
        v12 = v8;
        --v6;
        ++s;
        --v8;
        if ( !v12 )
        {
          v3->d[--v11] = v4;
          v4 = 0;
          v8 = 3;
        }
      }
      while ( v6 );
      top = v3->top;
      if ( top > 0 )
      {
        v14 = &v3->d[top - 1];
        do
        {
          if ( *v14-- )
            break;
          --top;
        }
        while ( top > 0 );
        v3->top = top;
      }
      return v3;
    }
    else
    {
      if ( a )
        BN_free(a);
      return 0;
    }
  }
  else
  {
    v3->top = 0;
    return v3;
  }
}
