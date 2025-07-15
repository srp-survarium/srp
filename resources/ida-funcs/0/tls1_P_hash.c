int __usercall tls1_P_hash@<eax>(
        const void *seed2@<ecx>,
        const void *seed3@<edx>,
        int a3@<ebx>,
        const env_md_st *md,
        const __m128i *sec,
        signed int sec_len,
        const void *seed1,
        int seed1_len,
        int seed2_len,
        int seed3_len,
        const void *seed4,
        int seed4_len,
        const unsigned __int8 *seed5,
        int seed5_len,
        unsigned __int8 *out,
        int olen)
{
  unsigned __int8 *v16; // edi
  env_md_ctx_st *v17; // ebx
  const void *v18; // esi
  const void *v19; // ebp
  unsigned int v21; // [esp+10h] [ebp-208h] BYREF
  unsigned __int8 *dst; // [esp+14h] [ebp-204h]
  int v23; // [esp+18h] [ebp-200h]
  const void *v24; // [esp+1Ch] [ebp-1FCh]
  const void *v25; // [esp+20h] [ebp-1F8h]
  const void *v26; // [esp+24h] [ebp-1F4h]
  const unsigned __int8 *v27; // [esp+28h] [ebp-1F0h]
  unsigned int v28; // [esp+2Ch] [ebp-1ECh] BYREF
  const void *v29; // [esp+30h] [ebp-1E8h]
  hmac_ctx_st ctx; // [esp+34h] [ebp-1E4h] BYREF
  hmac_ctx_st v31; // [esp+104h] [ebp-114h] BYREF
  __m128i src[4]; // [esp+1D4h] [ebp-44h] BYREF

  v16 = (unsigned __int8 *)sec;
  v26 = seed1;
  v25 = seed2;
  v24 = seed3;
  v29 = seed4;
  v27 = seed5;
  dst = out;
  v23 = 0;
  v17 = (env_md_ctx_st *)EVP_MD_size(a3, md);
  if ( (int)v17 < 0 )
    OpenSSLDie((int)sec, (int)md, (int)v17, ".\\ssl\\t1_enc.c", 169, "chunk >= 0");
  HMAC_CTX_init(&ctx);
  HMAC_CTX_init(&v31);
  if ( HMAC_Init_ex((int)sec, v17, &ctx, sec, sec_len, md, 0) )
  {
    if ( HMAC_Init_ex((int)sec, v17, &v31, sec, sec_len, md, 0) )
    {
      v18 = v26;
      if ( (!v26 || HMAC_Update(&ctx)) && (!v25 || HMAC_Update(&ctx)) && (!v24 || HMAC_Update(&ctx)) )
      {
        v19 = v29;
        if ( !v29 || HMAC_Update(&ctx) )
        {
          v16 = (unsigned __int8 *)v27;
          if ( (!v27 || HMAC_Update(&ctx))
            && HMAC_Final(&ctx, (unsigned __int8 *)src, &v21)
            && HMAC_Init_ex((int)v16, v17, &ctx, 0, 0, 0, 0) )
          {
            while ( HMAC_Init_ex((int)v16, v17, &v31, 0, 0, 0, 0)
                 && HMAC_Update(&ctx)
                 && HMAC_Update(&v31)
                 && (!v18 || HMAC_Update(&ctx))
                 && (!v25 || HMAC_Update(&ctx))
                 && (!v24 || HMAC_Update(&ctx))
                 && (!v19 || HMAC_Update(&ctx))
                 && (!v16 || HMAC_Update(&ctx)) )
            {
              if ( olen <= (int)v17 )
              {
                if ( HMAC_Final(&ctx, (unsigned __int8 *)src, &v21) )
                {
                  memcpy((int)dst, src, olen);
                  v23 = 1;
                }
                break;
              }
              if ( !HMAC_Final(&ctx, dst, &v28) )
                break;
              dst += v28;
              olen -= v28;
              if ( !HMAC_Final(&v31, (unsigned __int8 *)src, &v21) || !HMAC_Init_ex((int)v16, v17, &ctx, 0, 0, 0, 0) )
                break;
              v18 = v26;
            }
          }
        }
      }
    }
  }
  HMAC_CTX_cleanup((int)v16, (int)v17, &ctx);
  HMAC_CTX_cleanup((int)v16, (int)v17, &v31);
  OPENSSL_cleanse(src, 64);
  return v23;
}
