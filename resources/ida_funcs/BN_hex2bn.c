int __cdecl BN_hex2bn(bignum_st **bn, const char *a)
{
  const char *v2; // edi
  int v3; // ebp
  int v4; // esi
  int v5; // ecx
  int result; // eax
  bignum_st *v7; // edi
  int v8; // kr00_4
  bignum_st *v9; // eax
  int v10; // ebx
  int v11; // edi
  int v12; // edx
  const char *v13; // eax
  int v14; // ecx
  int v15; // ecx
  int v16; // eax
  unsigned int *v17; // ecx
  bignum_st *v19; // [esp+8h] [ebp-Ch]
  int v20; // [esp+Ch] [ebp-8h]

  v2 = a;
  v3 = 0;
  v20 = 0;
  if ( !a || !*a )
    return 0;
  if ( *a == 45 )
  {
    v2 = a + 1;
    v20 = 1;
    ++a;
  }
  v4 = 0;
  if ( isxdigit(*(unsigned __int8 *)v2) )
  {
    do
      v5 = (unsigned __int8)v2[++v4];
    while ( isxdigit(v5) );
  }
  result = v4 + v20;
  if ( bn )
  {
    if ( *bn )
    {
      v19 = *bn;
      BN_set_word(*bn, 0);
      v7 = v19;
    }
    else
    {
      v7 = BN_new();
      v19 = v7;
      if ( !v7 )
        return 0;
    }
    v8 = 4 * v4 + 31;
    if ( v8 / 32 > v7->dmax )
      v9 = bn_expand2(v7, (unsigned int *)(v8 / 32));
    else
      v9 = v7;
    if ( !v9 )
    {
      if ( !*bn )
      {
        BN_free(v7);
        return 0;
      }
      return 0;
    }
    v10 = v4;
    if ( v4 > 0 )
    {
      do
      {
        v11 = 8;
        if ( v10 < 8 )
          v11 = v10;
        v12 = 0;
        v13 = &a[v10 - v11];
        do
        {
          v14 = *v13;
          if ( (unsigned int)(v14 - 48) > 9 )
          {
            if ( (unsigned int)(v14 - 97) > 5 )
            {
              if ( (unsigned int)(v14 - 65) > 5 )
                v15 = 0;
              else
                v15 = v14 - 55;
            }
            else
            {
              v15 = v14 - 87;
            }
          }
          else
          {
            v15 = v14 - 48;
          }
          --v11;
          v12 = v15 | (16 * v12);
          ++v13;
        }
        while ( v11 > 0 );
        v19->d[v3] = v12;
        v10 -= 8;
        ++v3;
      }
      while ( v10 > 0 );
      v7 = v19;
    }
    v7->top = v3;
    v16 = v3;
    if ( v3 > 0 )
    {
      v17 = &v7->d[v3 - 1];
      do
      {
        if ( *v17-- )
          break;
        --v16;
      }
      while ( v16 > 0 );
      v7->top = v16;
    }
    v7->neg = v20;
    result = v4 + v20;
    *bn = v7;
  }
  return result;
}
