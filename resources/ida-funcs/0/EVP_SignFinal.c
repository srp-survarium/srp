int __cdecl EVP_SignFinal(env_md_ctx_st *ctx, unsigned __int8 *sigret, unsigned int *siglen, evp_pkey_st *pkey)
{
  const env_md_st *digest; // eax
  int v5; // ebx
  evp_pkey_ctx_st *v6; // eax
  evp_pkey_ctx_st *v7; // edi
  int v9; // esi
  int *required_pkey_type; // edx
  int (__cdecl *sign)(int, const unsigned __int8 *, unsigned int, unsigned __int8 *, unsigned int *, void *); // ecx
  unsigned int siglena; // [esp+10h] [ebp-68h] BYREF
  unsigned int tbslen; // [esp+14h] [ebp-64h] BYREF
  unsigned __int8 *sig; // [esp+18h] [ebp-60h]
  env_md_ctx_st ctxa; // [esp+1Ch] [ebp-5Ch] BYREF
  unsigned __int8 tbs[64]; // [esp+34h] [ebp-44h] BYREF

  sig = sigret;
  *siglen = 0;
  EVP_MD_CTX_init(&ctxa);
  EVP_MD_CTX_copy_ex((int)sigret, &ctxa, ctx);
  EVP_DigestFinal_ex((int)pkey, (int)sigret, &ctxa, tbs, &tbslen);
  EVP_MD_CTX_cleanup((int)pkey, (int)sigret, &ctxa);
  digest = ctx->digest;
  if ( (ctx->digest->flags & 4) != 0 )
  {
    v5 = 0;
    siglena = EVP_PKEY_size(pkey);
    v6 = EVP_PKEY_CTX_new((int)pkey, pkey, 0);
    v7 = v6;
    if ( v6
      && EVP_PKEY_sign_init(v6) > 0
      && EVP_PKEY_CTX_ctrl(0, v7, -1, 248, 1, 0, (void *)ctx->digest) > 0
      && EVP_PKEY_sign(v7, sig, &siglena, tbs, tbslen) > 0 )
    {
      *siglen = siglena;
      v5 = 1;
    }
    EVP_PKEY_CTX_free((int)v7, v7);
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
LABEL_12:
        ERR_put_error((int)sigret, 6u, 107, 110, ".\\crypto\\evp\\p_sign.c", 125);
        return 0;
      }
      if ( pkey->type == *required_pkey_type )
        break;
      ++v9;
      ++required_pkey_type;
      if ( v9 >= 4 )
        goto LABEL_12;
    }
    sign = digest->sign;
    if ( sign )
    {
      return sign(digest->type, tbs, tbslen, sigret, siglen, pkey->pkey.ptr);
    }
    else
    {
      ERR_put_error((int)sigret, 6u, 107, 104, ".\\crypto\\evp\\p_sign.c", 131);
      return 0;
    }
  }
}
