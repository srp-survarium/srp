int __cdecl PKCS5_PBE_keyivgen(
        evp_cipher_ctx_st *cctx,
        const char *pass,
        unsigned int passlen,
        asn1_type_st *param,
        const engine_st *cipher,
        const env_md_st *md,
        int en_de)
{
  char *ptr; // eax
  PBEPARAM_st *v8; // eax
  PBEPARAM_st *v9; // esi
  unsigned int length; // eax
  unsigned int v12; // edi
  signed int v13; // esi
  unsigned int v14; // edi
  const rsa_meth_st *v15; // eax
  bio_st *v16; // eax
  bio_st *v17; // [esp-Ch] [ebp-B8h]
  int v18; // [esp+8h] [ebp-A4h]
  unsigned __int8 *in; // [esp+14h] [ebp-98h] BYREF
  unsigned int count; // [esp+18h] [ebp-94h]
  void *data; // [esp+1Ch] [ebp-90h]
  env_md_ctx_st ctx; // [esp+20h] [ebp-8Ch] BYREF
  unsigned __int8 iv[16]; // [esp+38h] [ebp-74h] BYREF
  unsigned __int8 dst[32]; // [esp+48h] [ebp-64h] BYREF
  unsigned __int8 mda[16]; // [esp+68h] [ebp-44h] BYREF
  _BYTE v26[48]; // [esp+78h] [ebp-34h] BYREF

  if ( param && param->type == 16 && param->value.boolean )
  {
    ptr = param->value.ptr;
    in = (unsigned __int8 *)*((_DWORD *)ptr + 2);
    v8 = d2i_PBEPARAM(0, (const unsigned __int8 **)&in, *(_DWORD *)ptr);
    v9 = v8;
    if ( v8 )
    {
      if ( v8->iter )
        v18 = ASN1_INTEGER_get(v8->iter);
      else
        v18 = 1;
      length = v9->salt->length;
      data = v9->salt->data;
      count = length;
      if ( pass )
      {
        v12 = passlen;
        if ( passlen == -1 )
          v12 = strlen(pass);
      }
      else
      {
        v12 = 0;
      }
      EVP_MD_CTX_init(&ctx);
      EVP_DigestInit_ex(&ctx, md, 0);
      EVP_DigestUpdate(&ctx, pass, v12);
      EVP_DigestUpdate(&ctx, data, count);
      PBEPARAM_free(v9);
      EVP_DigestFinal_ex(&ctx, mda, 0);
      v13 = EVP_MD_size(md);
      if ( v13 >= 0 )
      {
        v14 = v18;
        if ( v18 > 1 )
        {
          v14 = v18 - 1;
          do
          {
            EVP_DigestInit_ex(&ctx, md, 0);
            EVP_DigestUpdate(&ctx, mda, v13);
            EVP_DigestFinal_ex(&ctx, mda, 0);
            --v14;
          }
          while ( v14 );
        }
        EVP_MD_CTX_cleanup(&ctx);
        if ( (int)EC_KEY_get0_public_key(cipher) > 64 )
          OpenSSLDie(
            v14,
            (unsigned int)cipher,
            ".\\crypto\\evp\\p5_crpt.c",
            122,
            "EVP_CIPHER_key_length(cipher) <= (int)sizeof(md_tmp)");
        v15 = EC_KEY_get0_public_key(cipher);
        memcpy(dst, mda, (unsigned int)v15);
        if ( (int)EC_KEY_get0_private_key((const ssl_st *)cipher) > 16 )
          OpenSSLDie(v14, (unsigned int)cipher, ".\\crypto\\evp\\p5_crpt.c", 124, "EVP_CIPHER_iv_length(cipher) <= 16");
        v17 = EC_KEY_get0_private_key((const ssl_st *)cipher);
        v16 = EC_KEY_get0_private_key((const ssl_st *)cipher);
        memcpy(iv, (unsigned __int8 *)(v26 - (_BYTE *)v16), (unsigned int)v17);
        EVP_CipherInit_ex(cctx, (const evp_cipher_st *)cipher, 0, dst, iv, en_de);
        OPENSSL_cleanse(mda, 64);
        OPENSSL_cleanse(dst, 32);
        OPENSSL_cleanse(iv, 16);
        return 1;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      ERR_put_error(6u, 117, 114, ".\\crypto\\evp\\p5_crpt.c", 95);
      return 0;
    }
  }
  else
  {
    ERR_put_error(6u, 117, 114, ".\\crypto\\evp\\p5_crpt.c", 89);
    return 0;
  }
}
