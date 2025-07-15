void __cdecl ASN1_STRING_free(asn1_string_st *a)
{
  if ( a )
  {
    if ( a->data )
    {
      if ( (a->flags & 0x10) == 0 )
        CRYPTO_free(a->data);
    }
    CRYPTO_free(a);
  }
}
