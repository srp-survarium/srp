int __cdecl decode_packed_entry_number(codebook *book, oggpack_buffer *b)
{
  signed int v3; // eax
  int v4; // edi
  int v5; // esi
  int used_entries; // eax
  void *v8; // eax
  unsigned int v9; // eax
  int i; // edx
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // [esp+10h] [ebp-4h]
  int bits; // [esp+1Ch] [ebp+8h]

  bits = book->dec_maxlength;
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
  v14 = used_entries;
  v8 = (void *)oggpack_look(b, bits);
  if ( (int)v8 >= 0 )
    goto LABEL_10;
  do
  {
    if ( bits <= 1 )
      break;
    v8 = (void *)oggpack_look(b, --bits);
  }
  while ( (int)v8 < 0 );
  if ( (int)v8 >= 0 )
  {
LABEL_10:
    v9 = bitreverse(v8);
    for ( i = v14 - v5; v14 - v5 > 1; i = v14 - v5 )
    {
      v11 = i >> 1;
      v12 = v9 < book->codelist[v11 + v5];
      v14 -= v11 & -v12;
      v5 += v11 & (v12 - 1);
    }
    v13 = book->dec_codelengths[v5];
    if ( v13 <= bits )
    {
      oggpack_adv(b, v13);
      return v5;
    }
    oggpack_adv(b, bits);
  }
  return -1;
}
