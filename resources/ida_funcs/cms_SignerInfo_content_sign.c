int __usercall cms_SignerInfo_content_sign@<eax>(
        CMS_ContentInfo_st *cms@<ebx>,
        CMS_SignerInfo_st *si@<esi>,
        bio_st *chain@<ecx>)
{
  int v4; // ebp
  int v6; // eax
  unsigned int size; // [esp+8h] [ebp-60h] BYREF
  env_md_ctx_st ctx; // [esp+Ch] [ebp-5Ch] BYREF
  unsigned __int8 md[64]; // [esp+24h] [ebp-44h] BYREF

  v4 = 0;
  EVP_MD_CTX_init(&ctx);
  if ( !si->pkey )
  {
    ERR_put_error(0x2Eu, 150, 133, ".\\crypto\\cms\\cms_sd.c", 629);
    return 0;
  }
  if ( cms_DigestAlgorithm_find_ctx(&ctx, chain, si->digestAlgorithm) )
  {
    if ( CMS_signed_get_attr_count(si) >= 0 )
    {
      chain = *(bio_st **)cms->d.data->data;
      EVP_DigestFinal_ex((unsigned int)chain, &ctx, md, &size);
      if ( !CMS_signed_add1_attr_by_NID(si, 51, 4, md, size)
        || CMS_signed_add1_attr_by_NID(si, 50, 6, chain, -1) <= 0
        || !CMS_SignerInfo_sign((unsigned int)chain, si) )
      {
        goto err_140;
      }
      goto LABEL_14;
    }
    v6 = EVP_PKEY_size(si->pkey);
    chain = (bio_st *)CRYPTO_malloc(v6, ".\\crypto\\cms\\cms_sd.c", 660);
    if ( chain )
    {
      if ( EVP_SignFinal(&ctx, (unsigned __int8 *)chain, &size, si->pkey) )
      {
        ASN1_STRING_set0(si->signature, (unsigned __int8 *)chain, size);
LABEL_14:
        v4 = 1;
        goto err_140;
      }
      ERR_put_error(0x2Eu, 150, 139, ".\\crypto\\cms\\cms_sd.c", 670);
      CRYPTO_free(chain);
    }
    else
    {
      ERR_put_error(0x2Eu, 150, 65, ".\\crypto\\cms\\cms_sd.c", 664);
    }
  }
err_140:
  EVP_MD_CTX_cleanup((unsigned int)chain, &ctx);
  return v4;
}
