int __usercall CMS_SignerInfo_sign@<eax>(int a1@<edi>, CMS_SignerInfo_st *si)
{
  CMS_SignerInfo_st *v2; // esi
  X509_algor_st *digestAlgorithm; // eax
  BOOL v4; // ebx
  void *v5; // eax
  char *v6; // eax
  const env_md_st *digestbyname; // ebp
  asn1_string_st *v8; // eax
  asn1_string_st *v9; // edi
  const ASN1_ITEM_st *v10; // eax
  unsigned __int8 *v11; // eax
  int v13; // [esp-4h] [ebp-30h]
  int v14; // [esp-4h] [ebp-30h]
  unsigned __int8 *out; // [esp+Ch] [ebp-20h] BYREF
  evp_pkey_ctx_st *pctx; // [esp+10h] [ebp-1Ch] BYREF
  env_md_ctx_st ctx; // [esp+14h] [ebp-18h] BYREF

  v2 = si;
  digestAlgorithm = si->digestAlgorithm;
  v4 = 0;
  out = 0;
  v5 = OBJ_obj2nid(digestAlgorithm->algorithm);
  v6 = (char *)OBJ_nid2sn(0, (unsigned int)v5);
  digestbyname = EVP_get_digestbyname(v6);
  if ( !digestbyname )
    return 0;
  EVP_MD_CTX_init(&ctx);
  if ( CMS_signed_get_attr_by_NID(v2, (asn1_object_st *)0x34, -1) < 0 )
  {
    v13 = a1;
    v8 = X509_gmtime_adj(0, 0);
    v9 = v8;
    if ( v8 )
      v4 = CMS_signed_add1_attr_by_NID(v2, 0x34u, v8->type, (unsigned __int8 *)v8, -1) > 0;
    ASN1_TIME_free(v9);
    a1 = v13;
    if ( !v4 )
    {
      ERR_put_error(0, 0x2Eu, 103, 65, ".\\crypto\\cms\\cms_sd.c", 486);
      goto err_140;
    }
  }
  if ( EVP_DigestSignInit(&ctx, &pctx, digestbyname, 0, v2->pkey) <= 0 )
    goto err_140;
  if ( EVP_PKEY_CTX_ctrl(v4, pctx, -1, 8, 11, 0, v2) <= 0 )
  {
    v14 = 728;
LABEL_17:
    ERR_put_error(v4, 0x2Eu, 151, 110, ".\\crypto\\cms\\cms_sd.c", v14);
    goto err_140;
  }
  v10 = CMS_Attributes_Sign_it();
  ASN1_item_i2d((struct ASN1_VALUE_st *)v2->signedAttrs, &out, v10);
  if ( !out )
    goto LABEL_20;
  if ( EVP_DigestUpdate(&ctx) <= 0 || EVP_DigestSignFinal(&ctx, 0, (unsigned int *)&si) <= 0 )
    goto err_140;
  CRYPTO_free(out);
  v11 = (unsigned __int8 *)CRYPTO_malloc((int)si, ".\\crypto\\cms\\cms_sd.c", 741);
  out = v11;
  if ( !v11 )
  {
LABEL_20:
    EVP_MD_CTX_cleanup(a1, v4, &ctx);
    return 0;
  }
  if ( EVP_DigestSignFinal(&ctx, v11, (unsigned int *)&si) <= 0 )
  {
err_140:
    if ( out )
      CRYPTO_free(out);
    goto LABEL_20;
  }
  if ( EVP_PKEY_CTX_ctrl(v4, pctx, -1, 8, 11, 1, v2) <= 0 )
  {
    v14 = 750;
    goto LABEL_17;
  }
  EVP_MD_CTX_cleanup(a1, v4, &ctx);
  ASN1_STRING_set0(v2->signature, out, (int)si);
  return 1;
}
