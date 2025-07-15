int __usercall cms_DigestedData_do_final@<eax>(int a1@<ebx>, CMS_ContentInfo_st *cms, bio_st *chain, int verify)
{
  int v4; // ebp
  asn1_string_st *data; // esi
  _DWORD *flags; // esi
  unsigned int v7; // eax
  int v8; // ecx
  __m128i *v9; // esi
  unsigned int v11; // [esp+Ch] [ebp-60h] BYREF
  env_md_ctx_st ctx; // [esp+10h] [ebp-5Ch] BYREF
  __m128i v13[4]; // [esp+28h] [ebp-44h] BYREF

  v4 = 0;
  EVP_MD_CTX_init(&ctx);
  data = cms->d.data;
  if ( cms_DigestAlgorithm_find_ctx(a1, &ctx, chain, (X509_algor_st *)data->type)
    && EVP_DigestFinal_ex((int)chain, a1, &ctx, (unsigned __int8 *)v13, &v11) > 0 )
  {
    if ( verify )
    {
      flags = (_DWORD *)data->flags;
      v7 = v11;
      if ( v11 != *flags )
      {
        ERR_put_error(a1, 0x2Eu, 117, 121, ".\\crypto\\cms\\cms_dd.c", 126);
        goto err_209;
      }
      v8 = flags[2];
      v9 = v13;
      if ( v11 >= 4 )
      {
        while ( v9->m128i_i32[0] == *(_DWORD *)v8 )
        {
          v7 -= 4;
          v8 += 4;
          v9 = (__m128i *)((char *)v9 + 4);
          if ( v7 < 4 )
            goto LABEL_9;
        }
        goto LABEL_15;
      }
LABEL_9:
      if ( v7
        && (*(_BYTE *)v8 != v9->m128i_i8[0]
         || v7 > 1 && (*(_BYTE *)(v8 + 1) != v9->m128i_i8[1] || v7 > 2 && *(_BYTE *)(v8 + 2) != v9->m128i_i8[2])) )
      {
LABEL_15:
        ERR_put_error(a1, 0x2Eu, 117, 158, ".\\crypto\\cms\\cms_dd.c", 132);
        goto err_209;
      }
    }
    else if ( !ASN1_STRING_set((asn1_string_st *)data->flags, v13, v11) )
    {
      goto err_209;
    }
    v4 = 1;
  }
err_209:
  EVP_MD_CTX_cleanup((int)chain, a1, &ctx);
  return v4;
}
