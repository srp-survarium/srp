int __cdecl pkey_dsa_keygen(evp_pkey_ctx_st *ctx, evp_pkey_st *pkey)
{
  int result; // eax
  char *v3; // eax

  if ( !ctx->pkey )
  {
    ERR_put_error(0xAu, 121, 107, ".\\crypto\\dsa\\dsa_pmeth.c", 269);
    return 0;
  }
  v3 = (char *)DSA_new();
  if ( !v3 )
    return 0;
  EVP_PKEY_assign(pkey, 116, v3);
  result = EVP_PKEY_copy_parameters(pkey, ctx->pkey);
  if ( result )
    return DSA_generate_key(pkey->pkey.dsa);
  return result;
}
