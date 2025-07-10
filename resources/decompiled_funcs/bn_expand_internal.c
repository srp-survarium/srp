unsigned int *__cdecl bn_expand_internal(const bignum_st *b, unsigned int *words)
{
  const bignum_st *v2; // esi
  unsigned int *v4; // eax
  unsigned int *d; // ecx
  int v6; // edx
  unsigned int v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // ebx
  unsigned int *a; // [esp+Ch] [ebp+8h]

  v2 = b;
  if ( (int)words > (int)&vostok::memory::s_CRT_arena[5574199] )
  {
    ERR_put_error(3u, 120, 114, ".\\crypto\\bn\\bn_lib.c", 328);
    return 0;
  }
  if ( (b->flags & 2) != 0 )
  {
    ERR_put_error(3u, 120, 105, ".\\crypto\\bn\\bn_lib.c", 333);
    return 0;
  }
  v4 = (unsigned int *)CRYPTO_malloc(4 * (_DWORD)words, ".\\crypto\\bn\\bn_lib.c", 336);
  a = v4;
  if ( !v4 )
  {
    ERR_put_error(3u, 120, 65, ".\\crypto\\bn\\bn_lib.c", 339);
    return 0;
  }
  d = b->d;
  if ( b->d )
  {
    v6 = b->top >> 2;
    if ( v6 > 0 )
    {
      do
      {
        v7 = d[1];
        v8 = d[2];
        v9 = d[3];
        *v4 = *d;
        v4[1] = v7;
        v4[2] = v8;
        v4[3] = v9;
        --v6;
        v4 += 4;
        d += 4;
      }
      while ( v6 > 0 );
      v2 = b;
    }
    switch ( v2->top & 3 )
    {
      case 1:
        goto LABEL_16;
      case 2:
LABEL_15:
        v4[1] = d[1];
LABEL_16:
        *v4 = *d;
        return a;
      case 3:
        v4[2] = d[2];
        goto LABEL_15;
    }
  }
  return a;
}
