int __cdecl ASN1_STRING_print(bio_st *bp, const asn1_string_st *v)
{
  unsigned __int8 *data; // ebp
  int v4; // ecx
  int v5; // esi
  char v6; // al
  char in[80]; // [esp+8h] [ebp-54h] BYREF

  if ( !v )
    return 0;
  data = v->data;
  v4 = 0;
  v5 = 0;
  if ( v->length > 0 )
  {
    do
    {
      v6 = data[v5];
      if ( v6 != 127 && (v6 >= 32 || v6 == 10 || v6 == 13) )
        in[v4] = v6;
      else
        in[v4] = 46;
      if ( ++v4 >= 80 )
      {
        if ( BIO_write(bp, in, v4) <= 0 )
          return 0;
        v4 = 0;
      }
      ++v5;
    }
    while ( v5 < v->length );
    if ( v4 > 0 && BIO_write(bp, in, v4) <= 0 )
      return 0;
  }
  return 1;
}
