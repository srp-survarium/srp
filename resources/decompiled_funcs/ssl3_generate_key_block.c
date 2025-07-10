int __cdecl ssl3_generate_key_block(unsigned __int8 *km, int num)
{
  signed int v3; // edi
  int v4; // ebx
  unsigned int v6; // edi
  const env_md_st *v7; // eax
  const env_md_st *v8; // eax
  unsigned __int8 *value; // [esp+10h] [ebp-60h]
  unsigned int v11; // [esp+14h] [ebp-5Ch]
  env_md_ctx_st v12; // [esp+18h] [ebp-58h] BYREF
  env_md_ctx_st ctx; // [esp+30h] [ebp-40h] BYREF
  unsigned __int8 md[36]; // [esp+48h] [ebp-28h] BYREF

  LOBYTE(value) = 65;
  v3 = 0;
  EVP_MD_CTX_init(&ctx);
  EVP_MD_CTX_init(&v12);
  v4 = 0;
  if ( num > 0 )
  {
    while ( 1 )
    {
      v6 = v3 + 1;
      v11 = v6;
      if ( v6 > 0x10 )
        break;
      if ( v6 )
        memset((int)&md[20], value, v6);
      LOBYTE(value) = (_BYTE)value + 1;
      v7 = EVP_sha1();
      EVP_DigestInit_ex(&v12, v7, 0);
      EVP_DigestUpdate(&v12);
      EVP_DigestUpdate(&v12);
      EVP_DigestUpdate(&v12);
      EVP_DigestUpdate(&v12);
      EVP_DigestFinal_ex(v6, &v12, md, 0);
      v8 = EVP_md5();
      EVP_DigestInit_ex(&ctx, v8, 0);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      v3 = v4 + 16;
      if ( v4 + 16 <= num )
      {
        EVP_DigestFinal_ex(v3, &ctx, km, 0);
      }
      else
      {
        EVP_DigestFinal_ex(v3, &ctx, md, 0);
        memcpy(km, md, num - v4);
      }
      km += 16;
      v4 += 16;
      if ( v3 >= num )
        goto LABEL_2;
      v3 = v11;
    }
    ERR_put_error(0x14u, 238, 68, ".\\ssl\\s3_enc.c", 180);
    return 0;
  }
  else
  {
LABEL_2:
    OPENSSL_cleanse(md, 20);
    EVP_MD_CTX_cleanup(v3, &ctx);
    EVP_MD_CTX_cleanup(v3, &v12);
    return 1;
  }
}
