int __cdecl i2a_ASN1_STRING(bio_st *bp, asn1_string_st *a)
{
  asn1_string_st *v2; // edi
  int v3; // ebx
  int v5; // esi
  unsigned __int8 *data; // eax

  v2 = a;
  v3 = 0;
  if ( !a )
    return 0;
  if ( a->length )
  {
    v5 = 0;
    if ( a->length <= 0 )
      return v3;
    while ( 1 )
    {
      if ( v5 && !(v5 % 35) )
      {
        if ( BIO_write(bp, "\\\n", 2) != 2 )
          return -1;
        v3 += 2;
      }
      data = v2->data;
      LOBYTE(a) = h_0[data[v5] >> 4];
      BYTE1(a) = h_0[data[v5] & 0xF];
      if ( BIO_write(bp, (const char *)&a, 2) != 2 )
        break;
      ++v5;
      v3 += 2;
      if ( v5 >= v2->length )
        return v3;
    }
  }
  else if ( BIO_write(bp, (const char *)&stru_95AF78.m_key_bindings[6].m_keyboard[1], 1) == 1 )
  {
    return 1;
  }
  return -1;
}
