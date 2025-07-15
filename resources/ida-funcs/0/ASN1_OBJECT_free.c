void __cdecl ASN1_OBJECT_free(asn1_object_st *a)
{
  if ( a )
  {
    if ( (a->flags & 4) != 0 )
    {
      if ( a->sn )
        CRYPTO_free((void *)a->sn);
      if ( a->ln )
        CRYPTO_free((void *)a->ln);
      a->ln = 0;
      a->sn = 0;
    }
    if ( (a->flags & 8) != 0 )
    {
      if ( a->data )
        CRYPTO_free((void *)a->data);
      a->data = 0;
      a->length = 0;
    }
    if ( (a->flags & 1) != 0 )
      CRYPTO_free(a);
  }
}
