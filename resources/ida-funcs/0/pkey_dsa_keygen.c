int __usercall pkey_dsa_keygen@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx, evp_pkey_st *pkey)
{
  int result; // eax
  char *v4; // eax

  if ( !ctx->pkey )
  {
    ERR_put_error(a1, 0xAu, 121, 107, ".\\crypto\\dsa\\dsa_pmeth.c", 269);
    return 0;
  }
  v4 = (char *)DSA_new(a1);
  if ( !v4 )
    return 0;
  EVP_PKEY_assign(pkey, (void *)0x74, v4);
  result = EVP_PKEY_copy_parameters(a1, pkey, ctx->pkey);
  if ( result )
    return DSA_generate_key(pkey->pkey.dsa);
  return result;
}
