int __cdecl BN_dec2bn(bignum_st **bn, const char *a)
{
  const char *v2; // ebx
  int v3; // ebp
  int v4; // esi
  int v5; // ecx
  int result; // eax
  bignum_st *v7; // edi
  int v8; // kr00_4
  bignum_st *v9; // eax
  int v10; // eax
  char v11; // cl
  unsigned int i; // esi
  int top; // eax
  unsigned int *v14; // ecx
  int num; // [esp+10h] [ebp+8h]

  v2 = a;
  v3 = 0;
  if ( !a || !*a )
    return 0;
  if ( *a == 45 )
  {
    v3 = 1;
    v2 = a + 1;
  }
  v4 = 0;
  if ( isdigit(*(unsigned __int8 *)v2) )
  {
    do
      v5 = (unsigned __int8)v2[++v4];
    while ( isdigit(v5) );
  }
  result = v4 + v3;
  num = v4 + v3;
  if ( bn )
  {
    v7 = *bn;
    if ( *bn )
    {
      BN_set_word(v7, 0);
    }
    else
    {
      v7 = BN_new();
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
    v10 = 9 * (v4 / 9 + 1) - v4;
    if ( v10 == 9 )
      v10 = 0;
    v11 = *v2;
    for ( i = 0; *v2; v11 = *v2 )
    {
      ++v10;
      ++v2;
      i = v11 + 10 * i - 48;
      if ( v10 == 9 )
      {
        BN_mul_word(v7, 0x3B9ACA00u);
        BN_add_word(v7, i);
        i = 0;
        v10 = 0;
      }
    }
    top = v7->top;
    v7->neg = v3;
    if ( top > 0 )
    {
      v14 = &v7->d[top - 1];
      do
      {
        if ( *v14-- )
          break;
        --top;
      }
      while ( top > 0 );
      v7->top = top;
    }
    *bn = v7;
    return num;
  }
  return result;
}
