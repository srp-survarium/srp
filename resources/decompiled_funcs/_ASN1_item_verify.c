unsigned int __cdecl ASN1_item_verify(
        const ASN1_ITEM_st *it,
        X509_algor_st *a,
        asn1_string_st *signature,
        struct ASN1_VALUE_st *asn,
        evp_pkey_st *pkey)
{
  unsigned int v5; // edi
  int v6; // eax
  const char *v8; // eax
  const env_md_st *digestbyname; // esi
  int v10; // esi
  unsigned __int8 *out; // [esp+4h] [ebp-24h] BYREF
  int pdig_nid; // [esp+8h] [ebp-20h] BYREF
  int ppkey_nid; // [esp+Ch] [ebp-1Ch] BYREF
  env_md_ctx_st ctx; // [esp+10h] [ebp-18h] BYREF

  out = 0;
  v5 = -1;
  EVP_MD_CTX_init(&ctx);
  v6 = OBJ_obj2nid(a->algorithm);
  if ( !OBJ_find_sigid_algs(v6, &pdig_nid, &ppkey_nid) )
  {
    ERR_put_error(0xDu, 197, 199, ".\\crypto\\asn1\\a_verify.c", 144);
    EVP_MD_CTX_cleanup(0xFFFFFFFF, &ctx);
    return -1;
  }
  v8 = OBJ_nid2sn(pdig_nid);
  digestbyname = EVP_get_digestbyname(v8);
  if ( !digestbyname )
  {
    ERR_put_error(0xDu, 197, 161, ".\\crypto\\asn1\\a_verify.c", 150);
    EVP_MD_CTX_cleanup(0xFFFFFFFF, &ctx);
    return -1;
  }
  if ( EVP_PKEY_type(ppkey_nid) == pkey->ameth->pkey_id )
  {
    if ( EVP_DigestInit_ex(&ctx, digestbyname, 0) )
    {
      v10 = ASN1_item_i2d(asn, &out, it);
      if ( !out )
      {
        ERR_put_error(0xDu, 197, 65, ".\\crypto\\asn1\\a_verify.c", 172);
        goto LABEL_15;
      }
      EVP_DigestUpdate(&ctx);
      OPENSSL_cleanse(out, v10);
      CRYPTO_free(out);
      if ( EVP_VerifyFinal(&ctx, signature->data, signature->length, pkey) > 0 )
      {
        v5 = 1;
        goto LABEL_15;
      }
      ERR_put_error(0xDu, 197, 6, ".\\crypto\\asn1\\a_verify.c", 184);
    }
    else
    {
      ERR_put_error(0xDu, 197, 6, ".\\crypto\\asn1\\a_verify.c", 163);
    }
    v5 = 0;
    goto LABEL_15;
  }
  ERR_put_error(0xDu, 197, 200, ".\\crypto\\asn1\\a_verify.c", 157);
LABEL_15:
  EVP_MD_CTX_cleanup(v5, &ctx);
  return v5;
}
