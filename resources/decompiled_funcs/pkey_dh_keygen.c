int __cdecl pkey_dh_keygen(evp_pkey_ctx_st *ctx, evp_pkey_st *pkey)
{
  int result; // eax
  char *v3; // eax

  if ( !ctx->pkey )
  {
    ERR_put_error(5u, 113, 107, ".\\crypto\\dh\\dh_pmeth.c", 191);
    return 0;
  }
  v3 = (char *)DH_new();
  if ( !v3 )
    return 0;
  EVP_PKEY_assign(pkey, 28, v3);
  result = EVP_PKEY_copy_parameters(pkey, ctx->pkey);
  if ( result )
    return DH_generate_key(pkey->pkey.dh);
  return result;
}
