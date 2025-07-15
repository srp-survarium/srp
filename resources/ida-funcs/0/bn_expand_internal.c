unsigned int *__usercall bn_expand_internal@<eax>(int a1@<ebx>, const bignum_st *b, int words)
{
  const bignum_st *v3; // esi
  _DWORD *v5; // eax
  unsigned int *d; // ecx
  int v7; // edx
  unsigned int v8; // esi
  unsigned int v9; // edi
  unsigned int v10; // ebx
  _DWORD *v11; // [esp+Ch] [ebp+8h]

  v3 = b;
  if ( words > 0xFFFFFF )
  {
    ERR_put_error(a1, 3u, 120, 114, ".\\crypto\\bn\\bn_lib.c", 328);
    return 0;
  }
  if ( (b->flags & 2) != 0 )
  {
    ERR_put_error(a1, 3u, 120, 105, ".\\crypto\\bn\\bn_lib.c", 333);
    return 0;
  }
  v5 = CRYPTO_malloc(4 * words, ".\\crypto\\bn\\bn_lib.c", 336);
  v11 = v5;
  if ( !v5 )
  {
    ERR_put_error(a1, 3u, 120, 65, ".\\crypto\\bn\\bn_lib.c", 339);
    return 0;
  }
  d = b->d;
  if ( b->d )
  {
    v7 = b->top >> 2;
    if ( v7 > 0 )
    {
      do
      {
        v8 = d[1];
        v9 = d[2];
        v10 = d[3];
        *v5 = *d;
        v5[1] = v8;
        v5[2] = v9;
        v5[3] = v10;
        --v7;
        v5 += 4;
        d += 4;
      }
      while ( v7 > 0 );
      v3 = b;
    }
    switch ( v3->top & 3 )
    {
      case 1:
        goto LABEL_16;
      case 2:
LABEL_15:
        v5[1] = d[1];
LABEL_16:
        *v5 = *d;
        return v11;
      case 3:
        v5[2] = d[2];
        goto LABEL_15;
    }
  }
  return v11;
}
