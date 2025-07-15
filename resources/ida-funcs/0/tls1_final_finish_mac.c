int __usercall tls1_final_finish_mac@<eax>(int a1@<ebx>, ssl_st *s, const char *str, int slen, unsigned __int8 *out)
{
  ssl3_state_st *s3; // edx
  unsigned int v6; // ebp
  unsigned __int8 *v7; // esi
  int result; // eax
  int v9; // eax
  int v10; // [esp-4h] [ebp-D0h]
  int v11; // [esp+Ch] [ebp-C0h]
  const env_md_st *md; // [esp+10h] [ebp-BCh] BYREF
  int v13; // [esp+14h] [ebp-B8h] BYREF
  unsigned __int8 *v14; // [esp+18h] [ebp-B4h]
  const void *v15; // [esp+1Ch] [ebp-B0h]
  unsigned int v16; // [esp+20h] [ebp-ACh] BYREF
  env_md_ctx_st ctx; // [esp+24h] [ebp-A8h] BYREF
  unsigned __int8 v18[12]; // [esp+3Ch] [ebp-90h] BYREF
  _BYTE v19[128]; // [esp+48h] [ebp-84h] BYREF
  int v20; // [esp+C8h] [ebp-4h] BYREF

  s3 = s->s3;
  v6 = 0;
  v15 = str;
  v14 = out;
  v11 = 0;
  v7 = v19;
  if ( !s3->handshake_buffer || (result = ssl3_digest_cached_records(a1, s)) != 0 )
  {
    EVP_MD_CTX_init(&ctx);
    if ( ssl_get_handshake_digest(0, &v13, &md) )
    {
      v10 = a1;
      do
      {
        if ( (v13 & s->s3->tmp.new_cipher->algorithm2) != 0 )
        {
          v9 = EVP_MD_size(a1, md);
          a1 = v9;
          if ( v9 < 0 || v9 > (char *)&v20 - (char *)v7 )
          {
            v11 = 1;
          }
          else
          {
            EVP_MD_CTX_copy_ex(v9, &ctx, s->s3->handshake_dgst[v6]);
            EVP_DigestFinal_ex((int)s, a1, &ctx, v7, &v16);
            if ( v16 != a1 )
              v11 = 1;
            v7 += v16;
          }
        }
        ++v6;
      }
      while ( ssl_get_handshake_digest(v6, &v13, &md) );
      a1 = v10;
    }
    if ( !tls1_PRF(
            s->s3->tmp.new_cipher->algorithm2,
            v15,
            slen,
            v19,
            v7 - v19,
            0,
            0,
            0,
            0,
            0,
            0,
            (const __m128i *)s->session->master_key,
            s->session->master_key_length,
            v14,
            v18,
            12) )
      v11 = 1;
    EVP_MD_CTX_cleanup((int)s, a1, &ctx);
    return v11 != 0 ? 0 : 12;
  }
  return result;
}
