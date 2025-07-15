void __cdecl EVP_PKEY_asn1_free(evp_pkey_asn1_method_st *ameth)
{
  if ( ameth && (ameth->pkey_flags & 2) != 0 )
  {
    if ( ameth->pem_str )
      CRYPTO_free(ameth->pem_str);
    if ( ameth->info )
      CRYPTO_free(ameth->info);
    CRYPTO_free((void *)ameth);
  }
}
