int __cdecl EVP_VerifyFinal(env_md_ctx_st *ctx, unsigned __int8 *sigbuf, unsigned int siglen, evp_pkey_st *pkey)
{
  const env_md_st *digest; // esi
  int v5; // ebx
  evp_pkey_ctx_st *v6; // eax
  evp_pkey_ctx_st *v7; // esi
  int v9; // edx
  int *required_pkey_type; // ecx
  int (__cdecl *verify)(int, const unsigned __int8 *, unsigned int, const unsigned __int8 *, unsigned int, void *); // eax
  unsigned int tbslen[2]; // [esp+10h] [ebp-64h] BYREF
  env_md_ctx_st ctxa; // [esp+18h] [ebp-5Ch] BYREF
  unsigned __int8 tbs[64]; // [esp+30h] [ebp-44h] BYREF

  tbslen[1] = (unsigned int)sigbuf;
  EVP_MD_CTX_init(&ctxa);
  EVP_MD_CTX_copy_ex((int)sigbuf, &ctxa, ctx);
  EVP_DigestFinal_ex((int)ctx, (int)sigbuf, &ctxa, tbs, tbslen);
  EVP_MD_CTX_cleanup((int)ctx, (int)sigbuf, &ctxa);
  digest = ctx->digest;
  if ( (ctx->digest->flags & 4) != 0 )
  {
    v5 = -1;
    v6 = EVP_PKEY_CTX_new((int)ctx, pkey, 0);
    v7 = v6;
    if ( v6 && EVP_PKEY_verify_init(v6) > 0 && EVP_PKEY_CTX_ctrl(-1, v7, -1, 248, 1, 0, (void *)ctx->digest) > 0 )
      v5 = EVP_PKEY_verify(v7);
    EVP_PKEY_CTX_free((int)ctx, v7);
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
        ERR_put_error((int)sigbuf, 6u, 108, 110, ".\\crypto\\evp\\p_verify.c", 107);
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
      return verify(digest->type, tbs, tbslen[0], sigbuf, siglen, pkey->pkey.ptr);
    }
    else
    {
      ERR_put_error((int)sigbuf, 6u, 108, 105, ".\\crypto\\evp\\p_verify.c", 112);
      return 0;
    }
  }
}
