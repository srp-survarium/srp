int __cdecl decode_packed_entry_number(codebook *book, oggpack_buffer *b)
{
  int dec_maxlength; // ebp
  signed int v3; // eax
  int v4; // ebx
  int v5; // esi
  int used_entries; // edi
  oggpack_buffer *v8; // ebx
  void *v9; // eax
  unsigned int v10; // eax
  int v11; // edx
  int v12; // edx
  int v13; // ecx
  int v14; // eax

  dec_maxlength = book->dec_maxlength;
  v3 = oggpack_look(b, book->dec_firsttablen);
  if ( v3 < 0 )
  {
    used_entries = book->used_entries;
    v5 = 0;
  }
  else
  {
    v4 = book->dec_firsttable[v3];
    if ( v4 >= 0 )
    {
      oggpack_adv(b, book->dec_codelengths[v4 - 1]);
      return v4 - 1;
    }
    v5 = (v4 >> 15) & 0x7FFF;
    used_entries = book->used_entries - (book->dec_firsttable[v3] & 0x7FFF);
  }
  v8 = b;
  v9 = (void *)oggpack_look(b, dec_maxlength);
  if ( (int)v9 >= 0 )
  {
LABEL_11:
    v10 = bitreverse(v9);
    v11 = used_entries - v5;
    if ( used_entries - v5 > 1 )
    {
      do
      {
        v12 = v11 >> 1;
        v13 = v10 < book->codelist[v12 + v5];
        used_entries -= v12 & -v13;
        v5 += v12 & (v13 - 1);
        v11 = used_entries - v5;
      }
      while ( used_entries - v5 > 1 );
      v8 = b;
    }
    v14 = book->dec_codelengths[v5];
    if ( v14 <= dec_maxlength )
    {
      oggpack_adv(v8, v14);
      return v5;
    }
    oggpack_adv(v8, dec_maxlength);
  }
  else
  {
    while ( dec_maxlength > 1 )
    {
      v9 = (void *)oggpack_look(b, --dec_maxlength);
      if ( (int)v9 >= 0 )
        goto LABEL_11;
    }
  }
  return -1;
}
