int __usercall PKCS7_SIGNER_INFO_sign@<eax>(int a1@<ebx>, pkcs7_signer_info_st *si)
{
  pkcs7_signer_info_st *v2; // esi
  X509_algor_st *digest_alg; // eax
  void *v4; // eax
  char *v5; // eax
  const env_md_st *digestbyname; // edi
  const ASN1_ITEM_st *v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 *out; // [esp+8h] [ebp-20h] BYREF
  evp_pkey_ctx_st *pctx; // [esp+Ch] [ebp-1Ch] BYREF
  env_md_ctx_st ctx; // [esp+10h] [ebp-18h] BYREF

  v2 = si;
  digest_alg = si->digest_alg;
  out = 0;
  v4 = OBJ_obj2nid(digest_alg->algorithm);
  v5 = (char *)OBJ_nid2sn(a1, (unsigned int)v4);
  digestbyname = EVP_get_digestbyname(v5);
  if ( !digestbyname )
    return 0;
  EVP_MD_CTX_init(&ctx);
  if ( EVP_DigestSignInit(&ctx, &pctx, digestbyname, 0, v2->pkey) <= 0 )
    goto err_124;
  if ( EVP_PKEY_CTX_ctrl(a1, pctx, -1, 8, 5, 0, v2) <= 0 )
  {
    ERR_put_error(a1, 0x21u, 139, 152, ".\\crypto\\pkcs7\\pk7_doit.c", 873);
    goto err_124;
  }
  v7 = PKCS7_ATTR_SIGN_it();
  ASN1_item_i2d((struct ASN1_VALUE_st *)v2->auth_attr, &out, v7);
  if ( !out )
    goto LABEL_14;
  if ( EVP_DigestUpdate(&ctx) <= 0 )
    goto err_124;
  CRYPTO_free(out);
  if ( EVP_DigestSignFinal(&ctx, 0, (unsigned int *)&si) <= 0 )
    goto err_124;
  v8 = (unsigned __int8 *)CRYPTO_malloc((int)si, ".\\crypto\\pkcs7\\pk7_doit.c", 886);
  out = v8;
  if ( !v8 )
  {
LABEL_14:
    EVP_MD_CTX_cleanup((int)digestbyname, a1, &ctx);
    return 0;
  }
  if ( EVP_DigestSignFinal(&ctx, v8, (unsigned int *)&si) <= 0 )
  {
err_124:
    if ( out )
      CRYPTO_free(out);
    goto LABEL_14;
  }
  if ( EVP_PKEY_CTX_ctrl(a1, pctx, -1, 8, 5, 1, v2) <= 0 )
  {
    ERR_put_error(a1, 0x21u, 139, 152, ".\\crypto\\pkcs7\\pk7_doit.c", 895);
    goto err_124;
  }
  EVP_MD_CTX_cleanup((int)digestbyname, a1, &ctx);
  ASN1_STRING_set0(v2->enc_digest, out, (int)si);
  return 1;
}
