void __cdecl EVP_PKEY_meth_free(evp_pkey_method_st *pmeth)
{
  if ( pmeth )
  {
    if ( (pmeth->flags & 1) != 0 )
      CRYPTO_free(pmeth);
  }
}
