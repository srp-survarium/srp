int __cdecl encodepart(oggpack_buffer *opb, int *vec, int n, codebook *book)
{
  int v5; // eax
  int v7; // ebp
  int v8; // esi
  const static_codebook *c; // eax
  int v10; // esi
  int bits; // [esp+8h] [ebp-4h]
  codebook *booka; // [esp+1Ch] [ebp+10h]

  v5 = n / book->dim;
  bits = 0;
  if ( v5 <= 0 )
    return 0;
  booka = (codebook *)(4 * book->dim);
  v7 = v5;
  do
  {
    v8 = local_book_besterror(book, vec);
    if ( v8 < 0 || (c = book->c, v8 >= c->entries) )
    {
      v10 = 0;
    }
    else
    {
      oggpack_write(opb, book->codelist[v8], c->lengthlist[v8]);
      v10 = book->c->lengthlist[v8];
    }
    bits += v10;
    vec = (int *)((char *)vec + (_DWORD)booka);
    --v7;
  }
  while ( v7 );
  return bits;
}
