int __cdecl PKCS5_PBE_keyivgen(
        evp_cipher_ctx_st *cctx,
        const char *pass,
        int passlen,
        asn1_type_st *param,
        const engine_st *cipher,
        const env_md_st *md,
        int en_de)
{
  char *ptr; // eax
  PBEPARAM_st *v8; // eax
  PBEPARAM_st *v9; // esi
  unsigned __int8 *length; // eax
  int v12; // edi
  int v13; // edi
  const rsa_meth_st *v14; // eax
  bio_st *v15; // eax
  bio_st *v16; // [esp-Ch] [ebp-B8h]
  int v17; // [esp+8h] [ebp-A4h]
  unsigned __int8 *in[3]; // [esp+14h] [ebp-98h] BYREF
  env_md_ctx_st ctx; // [esp+20h] [ebp-8Ch] BYREF
  unsigned __int8 iv[16]; // [esp+38h] [ebp-74h] BYREF
  unsigned __int8 dst[32]; // [esp+48h] [ebp-64h] BYREF
  __m128i mda; // [esp+68h] [ebp-44h] BYREF
  _BYTE v23[48]; // [esp+78h] [ebp-34h] BYREF

  if ( param && param->type == 16 && param->value.boolean )
  {
    ptr = param->value.ptr;
    in[0] = *((unsigned __int8 **)ptr + 2);
    v8 = d2i_PBEPARAM(0, in, *(const unsigned __int8 **)ptr);
    v9 = v8;
    if ( v8 )
    {
      if ( v8->iter )
        v17 = ASN1_INTEGER_get(v8->iter);
      else
        v17 = 1;
      length = (unsigned __int8 *)v9->salt->length;
      in[2] = v9->salt->data;
      in[1] = length;
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
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      PBEPARAM_free(v9);
      EVP_DigestFinal_ex(v12, &ctx, (unsigned __int8 *)&mda, 0);
      if ( EVP_MD_size(md) >= 0 )
      {
        v13 = v17;
        if ( v17 > 1 )
        {
          v13 = v17 - 1;
          do
          {
            EVP_DigestInit_ex(&ctx, md, 0);
            EVP_DigestUpdate(&ctx);
            EVP_DigestFinal_ex(v13--, &ctx, (unsigned __int8 *)&mda, 0);
          }
          while ( v13 );
        }
        EVP_MD_CTX_cleanup(v13, &ctx);
        if ( (int)EC_KEY_get0_public_key(cipher) > 64 )
          OpenSSLDie(
            v13,
            (int)cipher,
            (int)md,
            ".\\crypto\\evp\\p5_crpt.c",
            122,
            "EVP_CIPHER_key_length(cipher) <= (int)sizeof(md_tmp)");
        v14 = EC_KEY_get0_public_key(cipher);
        memcpy((int)dst, &mda, (unsigned int)v14);
        if ( (int)EC_KEY_get0_private_key((const ssl_st *)cipher) > 16 )
          OpenSSLDie(v13, (int)cipher, (int)md, ".\\crypto\\evp\\p5_crpt.c", 124, "EVP_CIPHER_iv_length(cipher) <= 16");
        v16 = EC_KEY_get0_private_key((const ssl_st *)cipher);
        v15 = EC_KEY_get0_private_key((const ssl_st *)cipher);
        memcpy((int)iv, (const __m128i *)(v23 - (_BYTE *)v15), (unsigned int)v16);
        EVP_CipherInit_ex(cctx, (const evp_cipher_st *)cipher, 0, dst, iv, en_de);
        OPENSSL_cleanse(&mda, 64);
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
      ERR_put_error((int)md, 6u, 117, 114, ".\\crypto\\evp\\p5_crpt.c", 95);
      return 0;
    }
  }
  else
  {
    ERR_put_error((int)md, 6u, 117, 114, ".\\crypto\\evp\\p5_crpt.c", 89);
    return 0;
  }
}
