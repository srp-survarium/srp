int __cdecl X509_PUBKEY_get0_param(
        asn1_object_st **ppkalg,
        unsigned __int8 **pk,
        int *ppklen,
        X509_algor_st **pa,
        X509_pubkey_st *pub)
{
  if ( ppkalg )
    *ppkalg = pub->algor->algorithm;
  if ( pk )
  {
    *pk = pub->public_key->data;
    *ppklen = pub->public_key->length;
  }
  if ( pa )
    *pa = pub->algor;
  return 1;
}
