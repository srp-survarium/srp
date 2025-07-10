int __cdecl PKCS7_SIGNER_INFO_sign(pkcs7_signer_info_st *si)
{
  pkcs7_signer_info_st *v1; // esi
  X509_algor_st *digest_alg; // eax
  unsigned int v3; // eax
  const char *v4; // eax
  const env_md_st *digestbyname; // edi
  const ASN1_ITEM_st *v6; // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 *out; // [esp+8h] [ebp-20h] BYREF
  evp_pkey_ctx_st *pctx; // [esp+Ch] [ebp-1Ch] BYREF
  env_md_ctx_st ctx; // [esp+10h] [ebp-18h] BYREF

  v1 = si;
  digest_alg = si->digest_alg;
  out = 0;
  v3 = OBJ_obj2nid(digest_alg->algorithm);
  v4 = OBJ_nid2sn(v3);
  digestbyname = EVP_get_digestbyname(v4);
  if ( !digestbyname )
    return 0;
  EVP_MD_CTX_init(&ctx);
  if ( EVP_DigestSignInit(&ctx, &pctx, digestbyname, 0, v1->pkey) <= 0 )
    goto err_122;
  if ( EVP_PKEY_CTX_ctrl(pctx, -1, 8, 5, 0, v1) <= 0 )
  {
    ERR_put_error(0x21u, 139, 152, ".\\crypto\\pkcs7\\pk7_doit.c", 873);
    goto err_122;
  }
  v6 = PKCS7_ATTR_SIGN_it();
  ASN1_item_i2d((struct ASN1_VALUE_st *)v1->auth_attr, &out, v6);
  if ( !out )
    goto LABEL_14;
  if ( EVP_DigestUpdate(&ctx) <= 0 )
    goto err_122;
  CRYPTO_free(out);
  if ( EVP_DigestSignFinal(&ctx, 0, (unsigned int *)&si) <= 0 )
    goto err_122;
  v7 = (unsigned __int8 *)CRYPTO_malloc((int)si, ".\\crypto\\pkcs7\\pk7_doit.c", 886);
  out = v7;
  if ( !v7 )
  {
LABEL_14:
    EVP_MD_CTX_cleanup((unsigned int)digestbyname, &ctx);
    return 0;
  }
  if ( EVP_DigestSignFinal(&ctx, v7, (unsigned int *)&si) <= 0 )
  {
err_122:
    if ( out )
      CRYPTO_free(out);
    goto LABEL_14;
  }
  if ( EVP_PKEY_CTX_ctrl(pctx, -1, 8, 5, 1, v1) <= 0 )
  {
    ERR_put_error(0x21u, 139, 152, ".\\crypto\\pkcs7\\pk7_doit.c", 895);
    goto err_122;
  }
  EVP_MD_CTX_cleanup((unsigned int)digestbyname, &ctx);
  ASN1_STRING_set0(v1->enc_digest, out, (int)si);
  return 1;
}
