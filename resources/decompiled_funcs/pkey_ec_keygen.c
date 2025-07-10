int __cdecl pkey_ec_keygen(evp_pkey_ctx_st *ctx, evp_pkey_st *pkey)
{
  int result; // eax
  char *v3; // eax

  if ( !ctx->pkey )
  {
    ERR_put_error(0x10u, 199, 139, ".\\crypto\\ec\\ec_pmeth.c", 293);
    return 0;
  }
  v3 = (char *)EC_KEY_new();
  if ( !v3 )
    return 0;
  EVP_PKEY_assign(pkey, 408, v3);
  result = EVP_PKEY_copy_parameters(pkey, ctx->pkey);
  if ( result )
    return EC_KEY_generate_key((bignum_ctx *)pkey->pkey.ptr);
  return result;
}
