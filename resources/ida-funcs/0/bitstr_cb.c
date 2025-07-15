int __usercall bitstr_cb@<eax>(int a1@<ebx>, const char *elem, int len, asn1_string_st *bitstr)
{
  const char *v4; // esi
  signed int v5; // eax

  v4 = elem;
  if ( !elem )
    return 0;
  v5 = strtoul(a1, elem, &elem, 10);
  if ( elem )
  {
    if ( *elem && elem != &v4[len] )
      return 0;
  }
  if ( v5 < 0 )
  {
    ERR_put_error(a1, 0xDu, 180, 187, ".\\crypto\\asn1\\asn1_gen.c", 844);
    return 0;
  }
  if ( ASN1_BIT_STRING_set_bit(bitstr, v5, 1) )
    return 1;
  ERR_put_error(a1, 0xDu, 180, 65, ".\\crypto\\asn1\\asn1_gen.c", 849);
  return 0;
}
