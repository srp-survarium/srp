int __usercall cms_SignerInfo_content_sign@<eax>(
        CMS_ContentInfo_st *cms@<ebx>,
        CMS_SignerInfo_st *si@<esi>,
        bio_st *chain@<ecx>)
{
  int v4; // ebp
  int v6; // eax
  int len; // [esp+8h] [ebp-60h] BYREF
  env_md_ctx_st ctx; // [esp+Ch] [ebp-5Ch] BYREF
  unsigned __int8 bytes[64]; // [esp+24h] [ebp-44h] BYREF

  v4 = 0;
  EVP_MD_CTX_init(&ctx);
  if ( !si->pkey )
  {
    ERR_put_error((int)cms, 0x2Eu, 150, 133, ".\\crypto\\cms\\cms_sd.c", 629);
    return 0;
  }
  if ( cms_DigestAlgorithm_find_ctx(&ctx, chain, si->digestAlgorithm) )
  {
    if ( CMS_signed_get_attr_count(si) >= 0 )
    {
      chain = *(bio_st **)cms->d.data->data;
      EVP_DigestFinal_ex((int)chain, (int)cms, &ctx, bytes, (unsigned int *)&len);
      if ( !CMS_signed_add1_attr_by_NID(si, 0x33u, 4, bytes, len)
        || CMS_signed_add1_attr_by_NID(si, 0x32u, 6, (unsigned __int8 *)chain, -1) <= 0
        || !CMS_SignerInfo_sign((int)chain, si) )
      {
        goto err_142;
      }
      goto LABEL_14;
    }
    v6 = EVP_PKEY_size(si->pkey);
    chain = (bio_st *)CRYPTO_malloc(v6, ".\\crypto\\cms\\cms_sd.c", 660);
    if ( chain )
    {
      if ( EVP_SignFinal(&ctx, (unsigned __int8 *)chain, (unsigned int *)&len, si->pkey) )
      {
        ASN1_STRING_set0(si->signature, (unsigned __int8 *)chain, len);
LABEL_14:
        v4 = 1;
        goto err_142;
      }
      ERR_put_error((int)cms, 0x2Eu, 150, 139, ".\\crypto\\cms\\cms_sd.c", 670);
      CRYPTO_free(chain);
    }
    else
    {
      ERR_put_error((int)cms, 0x2Eu, 150, 65, ".\\crypto\\cms\\cms_sd.c", 664);
    }
  }
err_142:
  EVP_MD_CTX_cleanup((int)chain, (int)cms, &ctx);
  return v4;
}
