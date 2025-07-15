int __cdecl i2a_ASN1_INTEGER(bio_st *bp, asn1_string_st *a)
{
  asn1_string_st *v2; // edi
  int v3; // ebx
  int v5; // esi
  unsigned __int8 *v6; // eax

  v2 = a;
  v3 = 0;
  if ( !a )
    return 0;
  if ( (a->type & 0x100) != 0 )
  {
    if ( BIO_write(bp, "-", 1) != 1 )
      return -1;
    v3 = 1;
  }
  if ( v2->length )
  {
    v5 = 0;
    if ( v2->length <= 0 )
      return v3;
    while ( 1 )
    {
      if ( v5 && !(v5 % 35) )
      {
        if ( BIO_write(bp, "\\\n", 2) != 2 )
          return -1;
        v3 += 2;
      }
      v6 = &v2->data[v5];
      LOBYTE(a) = h[*v6 >> 4];
      BYTE1(a) = h[*v6 & 0xF];
      if ( BIO_write(bp, (const char *)&a, 2) != 2 )
        break;
      ++v5;
      v3 += 2;
      if ( v5 >= v2->length )
        return v3;
    }
  }
  else if ( BIO_write(bp, "00", 2) == 2 )
  {
    v3 += 2;
    return v3;
  }
  return -1;
}
