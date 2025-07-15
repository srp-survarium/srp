void __cdecl cleanup3_LHASH_DOALL(asn1_object_st **str)
{
  if ( !--str[1]->nid )
    ASN1_OBJECT_free(str[1]);
  CRYPTO_free(str);
}
