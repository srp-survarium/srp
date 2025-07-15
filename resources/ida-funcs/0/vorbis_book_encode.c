int __usercall vorbis_book_encode@<eax>(codebook *book@<edi>, int a@<ecx>, oggpack_buffer *b)
{
  const static_codebook *c; // eax
  int v4; // esi

  if ( a < 0 )
    return 0;
  c = book->c;
  if ( a >= c->entries )
    return 0;
  v4 = a;
  oggpack_write(b, book->codelist[a], c->lengthlist[a]);
  return book->c->lengthlist[v4];
}
