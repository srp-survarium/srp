unsigned int *__cdecl _make_words(int *l, int n, int sparsecount)
{
  int v3; // eax
  unsigned int *v4; // ebx
  int v5; // esi
  unsigned int v6; // edi
  int v7; // edx
  _DWORD *v8; // eax
  int j; // ecx
  unsigned int *v10; // eax
  int v11; // eax
  int v12; // edx
  int *v13; // esi
  int v14; // edx
  int v15; // eax
  int k; // ecx
  _DWORD dst[34]; // [esp+8h] [ebp-90h] BYREF
  void *memblock; // [esp+90h] [ebp-8h]
  int i; // [esp+94h] [ebp-4h]

  v3 = sparsecount;
  if ( !sparsecount )
    v3 = n;
  v4 = (unsigned int *)ogg_malloc_impl(4 * v3);
  memblock = v4;
  memset((int)dst, 0, 0x84u);
  for ( i = 0; i < n; ++i )
  {
    v5 = l[i];
    if ( v5 <= 0 )
    {
      if ( !sparsecount )
        ++v4;
    }
    else
    {
      v6 = dst[v5];
      if ( v5 < 32 && v6 >> v5 )
        goto LABEL_35;
      *v4++ = v6;
      v7 = v5;
      while ( 1 )
      {
        v8 = &dst[v7];
        if ( (*v8 & 1) != 0 )
          break;
        --v7;
        ++*v8;
        if ( v7 <= 0 )
          goto LABEL_14;
      }
      if ( v7 == 1 )
        ++dst[1];
      else
        dst[v7] = 2 * dst[v7 - 1];
LABEL_14:
      for ( j = v5 + 1; j < 33; ++j )
      {
        v10 = &dst[j];
        if ( *v10 >> 1 != v6 )
          break;
        v6 = *v10;
        *v10 = 2 * dst[j - 1];
      }
    }
  }
  v11 = 1;
  if ( sparsecount == 1 )
  {
LABEL_25:
    v12 = 0;
    i = 0;
    if ( n > 0 )
    {
      v13 = (int *)memblock;
      do
      {
        v14 = l[v12];
        v15 = 0;
        for ( k = 0; k < v14; ++k )
          v15 = ((unsigned int)*v13 >> k) & 1 | (2 * v15);
        if ( !sparsecount || v14 )
          *v13++ = v15;
        v12 = ++i;
      }
      while ( i < n );
    }
    return (unsigned int *)memblock;
  }
  else
  {
    while ( ((0xFFFFFFFF >> (32 - v11)) & dst[v11]) == 0 )
    {
      if ( ++v11 >= 33 )
        goto LABEL_25;
    }
LABEL_35:
    ogg_free_impl(memblock);
    return 0;
  }
}
