int __cdecl PKCS5_PBKDF2_HMAC(
        const char *pass,
        unsigned int passlen,
        unsigned __int8 *salt,
        unsigned int saltlen,
        int iter,
        const env_md_st *digest,
        int keylen,
        unsigned __int8 *out)
{
  const char *v9; // edi
  int v10; // ebx
  int v11; // esi
  int v13; // edx
  unsigned __int8 *v14; // eax
  int v15; // edi
  int v16; // [esp+10h] [ebp-130h]
  unsigned __int8 v17[4]; // [esp+14h] [ebp-12Ch] BYREF
  int v18; // [esp+18h] [ebp-128h]
  const env_md_st *evp_md; // [esp+1Ch] [ebp-124h]
  unsigned int n; // [esp+20h] [ebp-120h]
  unsigned __int8 *data; // [esp+24h] [ebp-11Ch]
  const char *v22; // [esp+28h] [ebp-118h]
  hmac_ctx_st ctx; // [esp+2Ch] [ebp-114h] BYREF
  unsigned __int8 src[64]; // [esp+FCh] [ebp-44h] BYREF

  data = salt;
  v9 = pass;
  v22 = pass;
  evp_md = digest;
  v10 = 1;
  v11 = EVP_MD_size(digest);
  n = v11;
  if ( v11 < 0 )
    return 0;
  HMAC_CTX_init(&ctx);
  v13 = keylen;
  v18 = keylen;
  if ( pass )
  {
    if ( passlen == -1 )
      passlen = strlen(pass);
  }
  else
  {
    passlen = 0;
  }
  if ( keylen )
  {
    while ( 1 )
    {
      if ( v13 <= v11 )
        v11 = v13;
      v17[0] = HIBYTE(v10);
      v17[1] = BYTE2(v10);
      v17[2] = BYTE1(v10);
      v17[3] = v10;
      HMAC_Init_ex(&ctx, v9, passlen, evp_md, 0);
      HMAC_Update(&ctx, data, saltlen);
      HMAC_Update(&ctx, v17, 4u);
      HMAC_Final(&ctx, src, 0);
      memcpy(out, src, v11);
      if ( iter > 1 )
      {
        v16 = iter - 1;
        do
        {
          HMAC(evp_md, v9, passlen, src, n, src, 0);
          if ( v11 > 0 )
          {
            v14 = out;
            v15 = v11;
            do
            {
              *v14 ^= v14[src - out];
              ++v14;
              --v15;
            }
            while ( v15 );
            v9 = v22;
          }
          --v16;
        }
        while ( v16 );
      }
      ++v10;
      out += v11;
      v18 -= v11;
      if ( !v18 )
        break;
      v13 = v18;
      v11 = n;
    }
  }
  HMAC_CTX_cleanup(&ctx);
  return 1;
}
