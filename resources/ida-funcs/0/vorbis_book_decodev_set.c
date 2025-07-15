int __usercall vorbis_book_decodev_set@<eax>(codebook *book@<esi>, int n@<eax>, float *a, oggpack_buffer *b)
{
  int v4; // ebx
  int v6; // eax
  float *v7; // eax
  int v8; // ecx

  v4 = 0;
  if ( book->used_entries <= 0 )
  {
    if ( n > 0 )
      memset(a, 0, 4 * n);
    return 0;
  }
  if ( n <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = decode_packed_entry_number(book, b);
    if ( v6 == -1 )
      break;
    v7 = &book->valuelist[v6 * book->dim];
    v8 = 0;
    if ( v4 < n )
    {
      do
      {
        if ( v8 >= book->dim )
          break;
        a[v4++] = v7[v8++];
      }
      while ( v4 < n );
      if ( v4 < n )
        continue;
    }
    return 0;
  }
  return -1;
}
