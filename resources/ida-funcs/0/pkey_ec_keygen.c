int __usercall pkey_ec_keygen@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx, evp_pkey_st *pkey)
{
  int result; // eax
  char *v4; // eax

  if ( !ctx->pkey )
  {
    ERR_put_error(a1, 0x10u, 199, 139, ".\\crypto\\ec\\ec_pmeth.c", 293);
    return 0;
  }
  v4 = (char *)EC_KEY_new(a1);
  if ( !v4 )
    return 0;
  EVP_PKEY_assign(pkey, (void *)0x198, v4);
  result = EVP_PKEY_copy_parameters(a1, pkey, ctx->pkey);
  if ( result )
    return EC_KEY_generate_key((bignum_ctx *)pkey->pkey.ptr);
  return result;
}
