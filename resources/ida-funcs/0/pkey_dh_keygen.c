int __usercall pkey_dh_keygen@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx, evp_pkey_st *pkey)
{
  int result; // eax
  char *v4; // eax

  if ( !ctx->pkey )
  {
    ERR_put_error(a1, 5u, 113, 107, ".\\crypto\\dh\\dh_pmeth.c", 191);
    return 0;
  }
  v4 = (char *)DH_new(a1);
  if ( !v4 )
    return 0;
  EVP_PKEY_assign(pkey, (void *)0x1C, v4);
  result = EVP_PKEY_copy_parameters(a1, pkey, ctx->pkey);
  if ( result )
    return DH_generate_key(pkey->pkey.dh);
  return result;
}
