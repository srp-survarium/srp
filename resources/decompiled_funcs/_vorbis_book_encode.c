int __usercall vorbis_book_encode@<eax>(codebook *book@<edi>, int a@<esi>, oggpack_buffer *b)
{
  const static_codebook *c; // eax

  if ( a < 0 )
    return 0;
  c = book->c;
  if ( a >= c->entries )
    return 0;
  oggpack_write(b, book->codelist[a], c->lengthlist[a]);
  return book->c->lengthlist[a];
}
