int __cdecl PKCS5_PBKDF2_HMAC(
        char *pass,
        unsigned int passlen,
        unsigned __int8 *salt,
        unsigned int saltlen,
        int iter,
        const env_md_st *digest,
        int keylen,
        unsigned __int8 *out)
{
  unsigned __int8 *v9; // edi
  int v10; // ebx
  signed int v11; // esi
  int v13; // edx
  unsigned __int8 *v14; // eax
  signed int v15; // edi
  int v16; // [esp+10h] [ebp-130h]
  int v17; // [esp+18h] [ebp-128h]
  unsigned int n; // [esp+20h] [ebp-120h]
  hmac_ctx_st ctx; // [esp+2Ch] [ebp-114h] BYREF
  __m128i src[4]; // [esp+FCh] [ebp-44h] BYREF

  v9 = (unsigned __int8 *)pass;
  v10 = 1;
  v11 = EVP_MD_size(digest);
  n = v11;
  if ( v11 < 0 )
    return 0;
  HMAC_CTX_init(&ctx);
  v13 = keylen;
  v17 = keylen;
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
      HMAC_Init_ex((int)v9, &ctx, v9, passlen, digest, 0);
      HMAC_Update(&ctx);
      HMAC_Update(&ctx);
      HMAC_Final(&ctx, (unsigned __int8 *)src, 0);
      memcpy((int)out, src, v11);
      if ( iter > 1 )
      {
        v16 = iter - 1;
        do
        {
          HMAC(digest, v9, passlen, (const unsigned __int8 *)src, n, (unsigned __int8 *)src, 0);
          if ( v11 > 0 )
          {
            v14 = out;
            v15 = v11;
            do
            {
              *v14 ^= v14[(char *)src - (char *)out];
              ++v14;
              --v15;
            }
            while ( v15 );
            v9 = (unsigned __int8 *)pass;
          }
          --v16;
        }
        while ( v16 );
      }
      ++v10;
      out += v11;
      v17 -= v11;
      if ( !v17 )
        break;
      v13 = v17;
      v11 = n;
    }
  }
  HMAC_CTX_cleanup((int)v9, &ctx);
  return 1;
}
