int __cdecl EVP_VerifyFinal(env_md_ctx_st *ctx, unsigned __int8 *sigbuf, unsigned int siglen, evp_pkey_st *pkey)
{
  const env_md_st *digest; // esi
  int v5; // ebx
  evp_pkey_ctx_st *v6; // eax
  evp_pkey_ctx_st *v7; // esi
  int v9; // edx
  int *required_pkey_type; // ecx
  int (__cdecl *verify)(int, const unsigned __int8 *, unsigned int, const unsigned __int8 *, unsigned int, void *); // eax
  unsigned int size; // [esp+10h] [ebp-64h] BYREF
  unsigned __int8 *sig; // [esp+14h] [ebp-60h]
  env_md_ctx_st ctxa; // [esp+18h] [ebp-5Ch] BYREF
  unsigned __int8 md[64]; // [esp+30h] [ebp-44h] BYREF

  sig = sigbuf;
  EVP_MD_CTX_init(&ctxa);
  EVP_MD_CTX_copy_ex(&ctxa, ctx);
  EVP_DigestFinal_ex((unsigned int)ctx, &ctxa, md, &size);
  EVP_MD_CTX_cleanup((unsigned int)ctx, &ctxa);
  digest = ctx->digest;
  if ( (ctx->digest->flags & 4) != 0 )
  {
    v5 = -1;
    v6 = EVP_PKEY_CTX_new(pkey, 0);
    v7 = v6;
    if ( v6 && EVP_PKEY_verify_init(v6) > 0 && EVP_PKEY_CTX_ctrl(v7, -1, 248, 1, 0, (void *)ctx->digest) > 0 )
      v5 = EVP_PKEY_verify(v7, sig, siglen, md, size);
    EVP_PKEY_CTX_free(v7);
    return v5;
  }
  else
  {
    v9 = 0;
    required_pkey_type = digest->required_pkey_type;
    while ( 1 )
    {
      if ( !*required_pkey_type )
      {
LABEL_11:
        ERR_put_error(6u, 108, 110, ".\\crypto\\evp\\p_verify.c", 107);
        return -1;
      }
      if ( pkey->type == *required_pkey_type )
        break;
      ++v9;
      ++required_pkey_type;
      if ( v9 >= 4 )
        goto LABEL_11;
    }
    verify = digest->verify;
    if ( verify )
    {
      return verify(digest->type, md, size, sigbuf, siglen, pkey->pkey.ptr);
    }
    else
    {
      ERR_put_error(6u, 108, 105, ".\\crypto\\evp\\p_verify.c", 112);
      return 0;
    }
  }
}
