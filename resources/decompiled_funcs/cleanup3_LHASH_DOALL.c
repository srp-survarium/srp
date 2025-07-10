void __cdecl cleanup3_LHASH_DOALL(asn1_object_st **arg)
{
  if ( !--arg[1]->nid )
    ASN1_OBJECT_free(arg[1]);
  CRYPTO_free(arg);
}
