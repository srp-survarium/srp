int __cdecl vorbis_book_decodevv_add(codebook *book, float **a, int ch, oggpack_buffer *b, int n)
{
  int offset; // ecx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  float *v10; // ebx
  int i; // ecx
  float *v12; // eax
  int booka; // [esp+14h] [ebp+4h]

  v7 = 0;
  if ( book->used_entries <= 0 )
    return 0;
  v8 = offset / ch;
  booka = (offset + n) / ch;
  if ( offset / ch >= booka )
    return 0;
  while ( 1 )
  {
    v9 = decode_packed_entry_number(book, b);
    if ( v9 == -1 )
      break;
    v10 = &book->valuelist[v9 * book->dim];
    for ( i = 0; i < book->dim; ++i )
    {
      v12 = a[v7++];
      v12[v8] = v10[i] + v12[v8];
      if ( v7 == ch )
      {
        v7 = 0;
        ++v8;
      }
    }
    if ( v8 >= booka )
      return 0;
  }
  return -1;
}
