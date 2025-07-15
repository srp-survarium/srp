int __usercall vorbis_book_decodevv_add@<eax>(
        codebook *book@<esi>,
        int offset@<ecx>,
        float **a,
        int ch,
        oggpack_buffer *b,
        int n)
{
  int v6; // ebx
  int v7; // eax
  int v8; // edx
  float *i; // ecx
  float *v10; // eax
  int v12; // [esp+8h] [ebp-8h]
  int v13; // [esp+Ch] [ebp-4h]

  v6 = 0;
  if ( book->used_entries <= 0 )
    return 0;
  v13 = offset / ch;
  v12 = (offset + n) / ch;
  if ( offset / ch >= v12 )
    return 0;
  while ( 1 )
  {
    v7 = decode_packed_entry_number(book, b);
    if ( v7 == -1 )
      break;
    v8 = 0;
    for ( i = &book->valuelist[v7 * book->dim]; v8 < book->dim; ++v8 )
    {
      v10 = &a[v6++][v13];
      *v10 = i[v8] + *v10;
      if ( v6 == ch )
      {
        v6 = 0;
        ++v13;
      }
    }
    if ( v13 >= v12 )
      return 0;
  }
  return -1;
}
