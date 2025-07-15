int __cdecl X509_PUBKEY_set0_param(
        X509_pubkey_st *pub,
        asn1_object_st *aobj,
        int ptype,
        void *pval,
        unsigned __int8 *penc,
        int penclen)
{
  int result; // eax
  asn1_string_st *public_key; // ecx

  result = X509_ALGOR_set0(pub->algor, aobj, ptype, pval);
  if ( result )
  {
    if ( penc )
    {
      public_key = pub->public_key;
      if ( public_key->data )
        CRYPTO_free(public_key->data);
      pub->public_key->data = penc;
      pub->public_key->length = penclen;
      pub->public_key->flags &= 0xFFFFFFF0;
      pub->public_key->flags |= 8u;
    }
    return 1;
  }
  return result;
}
