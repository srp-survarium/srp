int __cdecl vorbis_book_decodevs_add(codebook *book, float *a, oggpack_buffer *b, int n)
{
  int v5; // ebx
  void *v6; // esp
  void *v7; // esp
  _DWORD *v8; // edi
  int v9; // eax
  int v10; // ecx
  float *v11; // eax
  _BYTE v13[12]; // [esp+0h] [ebp-14h] BYREF
  _BYTE *v14; // [esp+Ch] [ebp-8h]
  float *v15; // [esp+10h] [ebp-4h]
  codebook *booka; // [esp+1Ch] [ebp+8h]
  int bookb; // [esp+1Ch] [ebp+8h]

  if ( book->used_entries <= 0 )
    return 0;
  v5 = n / book->dim;
  v6 = alloca(4 * v5);
  v15 = (float *)v13;
  v7 = alloca(4 * v5);
  booka = 0;
  v8 = v13;
  v14 = v13;
  if ( v5 <= 0 )
  {
LABEL_6:
    bookb = 0;
    if ( book->dim > 0 )
    {
      v15 = a;
      do
      {
        v10 = 0;
        if ( v5 > 0 )
        {
          v11 = v15;
          do
          {
            *v11 = *(float *)(*(_DWORD *)&v14[4 * v10++] + 4 * bookb) + *v11;
            ++v11;
          }
          while ( v10 < v5 );
        }
        ++bookb;
        v15 += v5;
      }
      while ( bookb < book->dim );
    }
    return 0;
  }
  v15 = (float *)((char *)v15 - v13);
  while ( 1 )
  {
    v9 = decode_packed_entry_number(book, b);
    *(_DWORD *)((char *)v8 + (_DWORD)v15) = v9;
    if ( v9 == -1 )
      return -1;
    booka = (codebook *)((char *)booka + 1);
    *v8++ = &book->valuelist[v9 * book->dim];
    if ( (int)booka >= v5 )
      goto LABEL_6;
  }
}
