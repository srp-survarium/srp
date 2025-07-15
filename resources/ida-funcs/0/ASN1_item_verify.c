int __usercall ASN1_item_verify@<eax>(
        int a1@<ebx>,
        const ASN1_ITEM_st *it,
        X509_algor_st *a,
        asn1_string_st *signature,
        struct ASN1_VALUE_st *asn,
        evp_pkey_st *pkey)
{
  int v6; // edi
  void *v7; // eax
  char *v9; // eax
  const env_md_st *digestbyname; // esi
  int v11; // esi
  unsigned __int8 *out; // [esp+4h] [ebp-24h] BYREF
  int pdig_nid; // [esp+8h] [ebp-20h] BYREF
  int ppkey_nid; // [esp+Ch] [ebp-1Ch] BYREF
  env_md_ctx_st ctx; // [esp+10h] [ebp-18h] BYREF

  out = 0;
  v6 = -1;
  EVP_MD_CTX_init(&ctx);
  v7 = OBJ_obj2nid(a->algorithm);
  if ( !OBJ_find_sigid_algs(-1, (int)v7, &pdig_nid, &ppkey_nid) )
  {
    ERR_put_error(a1, 0xDu, 197, 199, ".\\crypto\\asn1\\a_verify.c", 144);
    EVP_MD_CTX_cleanup(-1, a1, &ctx);
    return -1;
  }
  v9 = (char *)OBJ_nid2sn(a1, pdig_nid);
  digestbyname = EVP_get_digestbyname(v9);
  if ( !digestbyname )
  {
    ERR_put_error(a1, 0xDu, 197, 161, ".\\crypto\\asn1\\a_verify.c", 150);
    EVP_MD_CTX_cleanup(-1, a1, &ctx);
    return -1;
  }
  if ( EVP_PKEY_type(-1, (void *)ppkey_nid) == (const char *)pkey->ameth->pkey_id )
  {
    if ( EVP_DigestInit_ex((engine_st *)pkey, &ctx, digestbyname, 0) )
    {
      v11 = ASN1_item_i2d(asn, &out, it);
      if ( !out )
      {
        ERR_put_error((int)pkey, 0xDu, 197, 65, ".\\crypto\\asn1\\a_verify.c", 172);
        goto LABEL_15;
      }
      EVP_DigestUpdate(&ctx);
      OPENSSL_cleanse(out, v11);
      CRYPTO_free(out);
      if ( EVP_VerifyFinal(&ctx, signature->data, signature->length, pkey) > 0 )
      {
        v6 = 1;
        goto LABEL_15;
      }
      ERR_put_error((int)pkey, 0xDu, 197, 6, ".\\crypto\\asn1\\a_verify.c", 184);
    }
    else
    {
      ERR_put_error((int)pkey, 0xDu, 197, 6, ".\\crypto\\asn1\\a_verify.c", 163);
    }
    v6 = 0;
    goto LABEL_15;
  }
  ERR_put_error((int)pkey, 0xDu, 197, 200, ".\\crypto\\asn1\\a_verify.c", 157);
LABEL_15:
  EVP_MD_CTX_cleanup(v6, a1, &ctx);
  return v6;
}
