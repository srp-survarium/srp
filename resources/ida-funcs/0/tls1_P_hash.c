int __fastcall tls1_P_hash(
        unsigned __int8 *seed2,
        unsigned __int8 *seed3,
        const env_md_st *md,
        unsigned __int8 *sec,
        unsigned int sec_len,
        unsigned __int8 *seed1,
        unsigned int seed1_len,
        unsigned int seed2_len,
        unsigned int seed3_len,
        unsigned __int8 *seed4,
        unsigned int seed4_len,
        unsigned __int8 *seed5,
        unsigned int seed5_len,
        unsigned __int8 *out,
        int olen)
{
  unsigned __int8 *v15; // edi
  int v16; // ebx
  unsigned __int8 *v17; // esi
  unsigned __int8 *v18; // ebp
  unsigned int v20; // [esp+10h] [ebp-208h] BYREF
  unsigned __int8 *dst; // [esp+14h] [ebp-204h]
  int v22; // [esp+18h] [ebp-200h]
  unsigned __int8 *v23; // [esp+1Ch] [ebp-1FCh]
  unsigned __int8 *v24; // [esp+20h] [ebp-1F8h]
  unsigned __int8 *data; // [esp+24h] [ebp-1F4h]
  unsigned __int8 *v26; // [esp+28h] [ebp-1F0h]
  unsigned int v27; // [esp+2Ch] [ebp-1ECh] BYREF
  unsigned __int8 *v28; // [esp+30h] [ebp-1E8h]
  hmac_ctx_st ctx; // [esp+34h] [ebp-1E4h] BYREF
  hmac_ctx_st v30; // [esp+104h] [ebp-114h] BYREF
  unsigned __int8 src[64]; // [esp+1D4h] [ebp-44h] BYREF

  v15 = sec;
  data = seed1;
  v24 = seed2;
  v23 = seed3;
  v28 = seed4;
  v26 = seed5;
  dst = out;
  v22 = 0;
  v16 = EVP_MD_size(md);
  if ( v16 < 0 )
    OpenSSLDie((unsigned int)sec, (unsigned int)md, ".\\ssl\\t1_enc.c", 169, "chunk >= 0");
  HMAC_CTX_init(&ctx);
  HMAC_CTX_init(&v30);
  if ( HMAC_Init_ex((unsigned int)sec, &ctx, sec, sec_len, md, 0) )
  {
    if ( HMAC_Init_ex((unsigned int)sec, &v30, sec, sec_len, md, 0) )
    {
      v17 = data;
      if ( (!data || HMAC_Update(&ctx)) && (!v24 || HMAC_Update(&ctx)) && (!v23 || HMAC_Update(&ctx)) )
      {
        v18 = v28;
        if ( !v28 || HMAC_Update(&ctx) )
        {
          v15 = v26;
          if ( (!v26 || HMAC_Update(&ctx))
            && HMAC_Final(&ctx, src, &v20)
            && HMAC_Init_ex((unsigned int)v15, &ctx, 0, 0, 0, 0) )
          {
            while ( HMAC_Init_ex((unsigned int)v15, &v30, 0, 0, 0, 0)
                 && HMAC_Update(&ctx)
                 && HMAC_Update(&v30)
                 && (!v17 || HMAC_Update(&ctx))
                 && (!v24 || HMAC_Update(&ctx))
                 && (!v23 || HMAC_Update(&ctx))
                 && (!v18 || HMAC_Update(&ctx))
                 && (!v15 || HMAC_Update(&ctx)) )
            {
              if ( olen <= v16 )
              {
                if ( HMAC_Final(&ctx, src, &v20) )
                {
                  memcpy(dst, src, olen);
                  v22 = 1;
                }
                break;
              }
              if ( !HMAC_Final(&ctx, dst, &v27) )
                break;
              dst += v27;
              olen -= v27;
              if ( !HMAC_Final(&v30, src, &v20) || !HMAC_Init_ex((unsigned int)v15, &ctx, 0, 0, 0, 0) )
                break;
              v17 = data;
            }
          }
        }
      }
    }
  }
  HMAC_CTX_cleanup((unsigned int)v15, &ctx);
  HMAC_CTX_cleanup((unsigned int)v15, &v30);
  OPENSSL_cleanse(src, 64);
  return v22;
}
