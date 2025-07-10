int __usercall vorbis_book_decode@<eax>(codebook *book@<esi>, oggpack_buffer *b@<eax>)
{
  int v2; // eax

  if ( book->used_entries <= 0 )
    return -1;
  v2 = decode_packed_entry_number(book, b);
  if ( v2 < 0 )
    return -1;
  else
    return book->dec_index[v2];
}
