int __cdecl cms_DigestedData_do_final(CMS_ContentInfo_st *cms, bio_st *chain, int verify)
{
  int v3; // ebp
  asn1_string_st *data; // esi
  _DWORD *flags; // esi
  unsigned int v6; // eax
  int v7; // ecx
  unsigned __int8 *v8; // esi
  unsigned int size; // [esp+Ch] [ebp-60h] BYREF
  env_md_ctx_st ctx; // [esp+10h] [ebp-5Ch] BYREF
  unsigned __int8 md[64]; // [esp+28h] [ebp-44h] BYREF

  v3 = 0;
  EVP_MD_CTX_init(&ctx);
  data = cms->d.data;
  if ( cms_DigestAlgorithm_find_ctx(&ctx, chain, (X509_algor_st *)data->type)
    && EVP_DigestFinal_ex((unsigned int)chain, &ctx, md, &size) > 0 )
  {
    if ( verify )
    {
      flags = (_DWORD *)data->flags;
      v6 = size;
      if ( size != *flags )
      {
        ERR_put_error(0x2Eu, 117, 121, ".\\crypto\\cms\\cms_dd.c", 126);
        goto err_207;
      }
      v7 = flags[2];
      v8 = md;
      if ( size >= 4 )
      {
        while ( *(_DWORD *)v8 == *(_DWORD *)v7 )
        {
          v6 -= 4;
          v7 += 4;
          v8 += 4;
          if ( v6 < 4 )
            goto LABEL_9;
        }
        goto LABEL_15;
      }
LABEL_9:
      if ( v6
        && (*(_BYTE *)v7 != *v8 || v6 > 1 && (*(_BYTE *)(v7 + 1) != v8[1] || v6 > 2 && *(_BYTE *)(v7 + 2) != v8[2])) )
      {
LABEL_15:
        ERR_put_error(0x2Eu, 117, 158, ".\\crypto\\cms\\cms_dd.c", 132);
        goto err_207;
      }
    }
    else if ( !ASN1_STRING_set((asn1_string_st *)data->flags, (char *)md, size) )
    {
      goto err_207;
    }
    v3 = 1;
  }
err_207:
  EVP_MD_CTX_cleanup((unsigned int)chain, &ctx);
  return v3;
}
