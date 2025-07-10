int __cdecl vorbis_book_decodev_set(codebook *book, float *a, oggpack_buffer *b, int n)
{
  int v4; // esi
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  float *v8; // edx
  float *v9; // ecx
  double v10; // st7
  int v11; // eax
  double v12; // st7
  int v13; // eax
  double v14; // st7
  int v15; // eax

  if ( book->used_entries <= 0 )
  {
    if ( n > 0 )
      memset(a, 0, 4 * n);
    return 0;
  }
  v4 = 0;
  if ( n <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = decode_packed_entry_number(book, b);
    if ( v5 == -1 )
      return -1;
    v6 = v5 * book->dim;
    v7 = 0;
    v8 = &book->valuelist[v6];
    if ( v4 >= n )
      return 0;
    if ( n - v4 < 4 )
    {
LABEL_12:
      if ( v4 >= n )
        return 0;
      while ( v7 < book->dim )
      {
        a[v4++] = v8[v7++];
        if ( v4 >= n )
          return 0;
      }
    }
    else
    {
      v9 = &a[v4 + 2];
      while ( v7 < book->dim )
      {
        v10 = v8[v7];
        v11 = v7 + 1;
        *(v9 - 2) = v10;
        if ( v11 >= book->dim )
        {
          ++v4;
          break;
        }
        v12 = v8[v11];
        v13 = v11 + 1;
        *(v9 - 1) = v12;
        if ( v13 >= book->dim )
        {
          v4 += 2;
          break;
        }
        v14 = v8[v13];
        v15 = v13 + 1;
        *v9 = v14;
        if ( v15 >= book->dim )
        {
          v4 += 3;
          break;
        }
        v4 += 4;
        v9[1] = v8[v15];
        v7 = v15 + 1;
        v9 += 4;
        if ( v4 >= n - 3 )
          goto LABEL_12;
      }
    }
    if ( v4 >= n )
      return 0;
  }
}
