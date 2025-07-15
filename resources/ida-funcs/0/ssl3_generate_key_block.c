int __cdecl ssl3_generate_key_block(unsigned __int8 *km, int num)
{
  int p_dh_meth; // edi
  engine_st *v3; // ebx
  unsigned int v5; // edi
  const env_md_st *v6; // eax
  const env_md_st *v7; // eax
  int v9; // [esp+10h] [ebp-60h]
  unsigned int v10; // [esp+14h] [ebp-5Ch]
  env_md_ctx_st v11; // [esp+18h] [ebp-58h] BYREF
  env_md_ctx_st ctx; // [esp+30h] [ebp-40h] BYREF
  __m128i src[2]; // [esp+48h] [ebp-28h] BYREF

  LOBYTE(v9) = 65;
  p_dh_meth = 0;
  EVP_MD_CTX_init(&ctx);
  EVP_MD_CTX_init(&v11);
  v3 = 0;
  if ( num > 0 )
  {
    while ( 1 )
    {
      v5 = p_dh_meth + 1;
      v10 = v5;
      if ( v5 > 0x10 )
        break;
      if ( v5 )
        memset((int)&src[1].m128i_i32[1], v9, v5);
      LOBYTE(v9) = v9 + 1;
      v6 = EVP_sha1();
      EVP_DigestInit_ex(v3, &v11, v6, 0);
      EVP_DigestUpdate(&v11);
      EVP_DigestUpdate(&v11);
      EVP_DigestUpdate(&v11);
      EVP_DigestUpdate(&v11);
      EVP_DigestFinal_ex(v5, (int)v3, &v11, (unsigned __int8 *)src, 0);
      v7 = EVP_md5();
      EVP_DigestInit_ex(v3, &ctx, v7, 0);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      p_dh_meth = (int)&v3->dh_meth;
      if ( (int)&v3->dh_meth <= num )
      {
        EVP_DigestFinal_ex(p_dh_meth, (int)v3, &ctx, km, 0);
      }
      else
      {
        EVP_DigestFinal_ex(p_dh_meth, (int)v3, &ctx, (unsigned __int8 *)src, 0);
        memcpy((int)km, src, num - (_DWORD)v3);
      }
      km += 16;
      v3 = (engine_st *)((char *)v3 + 16);
      if ( p_dh_meth >= num )
        goto LABEL_2;
      p_dh_meth = v10;
    }
    ERR_put_error((int)v3, 0x14u, 238, 68, ".\\ssl\\s3_enc.c", 180);
    return 0;
  }
  else
  {
LABEL_2:
    OPENSSL_cleanse(src, 20);
    EVP_MD_CTX_cleanup(p_dh_meth, (int)v3, &ctx);
    EVP_MD_CTX_cleanup(p_dh_meth, (int)v3, &v11);
    return 1;
  }
}
