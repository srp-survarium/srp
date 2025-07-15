int __cdecl encodepart(oggpack_buffer *opb, char *vec, int n, codebook *book)
{
  int v6; // ebx
  int v7; // eax
  int v9; // [esp+4h] [ebp-4h]
  int booka; // [esp+1Ch] [ebp+14h]

  v9 = 0;
  if ( n / book->dim > 0 )
  {
    v6 = 4 * book->dim;
    booka = n / book->dim;
    do
    {
      v7 = local_book_besterror(vec);
      v9 += vorbis_book_encode(book, v7, opb);
      vec += v6;
      --booka;
    }
    while ( booka );
  }
  return v9;
}
