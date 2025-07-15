int __cdecl tls1_final_finish_mac(ssl_st *s, char *str, unsigned int slen, unsigned __int8 *out)
{
  ssl3_state_st *s3; // edx
  unsigned int v5; // ebp
  unsigned __int8 *v6; // esi
  int result; // eax
  int v8; // eax
  int v9; // ebx
  int v10; // [esp+Ch] [ebp-C0h]
  const env_md_st *md; // [esp+10h] [ebp-BCh] BYREF
  int mask; // [esp+14h] [ebp-B8h] BYREF
  unsigned __int8 *out1; // [esp+18h] [ebp-B4h]
  void *seed1; // [esp+1Ch] [ebp-B0h]
  unsigned int size; // [esp+20h] [ebp-ACh] BYREF
  env_md_ctx_st ctx; // [esp+24h] [ebp-A8h] BYREF
  unsigned __int8 out2[12]; // [esp+3Ch] [ebp-90h] BYREF
  unsigned __int8 seed2[128]; // [esp+48h] [ebp-84h] BYREF
  int v19; // [esp+C8h] [ebp-4h] BYREF

  s3 = s->s3;
  v5 = 0;
  seed1 = str;
  out1 = out;
  v10 = 0;
  v6 = seed2;
  if ( !s3->handshake_buffer || (result = ssl3_digest_cached_records(s)) != 0 )
  {
    EVP_MD_CTX_init(&ctx);
    if ( ssl_get_handshake_digest(0, &mask, &md) )
    {
      do
      {
        if ( (mask & s->s3->tmp.new_cipher->algorithm2) != 0 )
        {
          v8 = EVP_MD_size(md);
          v9 = v8;
          if ( v8 < 0 || v8 > (char *)&v19 - (char *)v6 )
          {
            v10 = 1;
          }
          else
          {
            EVP_MD_CTX_copy_ex(&ctx, s->s3->handshake_dgst[v5]);
            EVP_DigestFinal_ex((unsigned int)s, &ctx, v6, &size);
            if ( size != v9 )
              v10 = 1;
            v6 += size;
          }
        }
        ++v5;
      }
      while ( ssl_get_handshake_digest(v5, &mask, &md) );
    }
    if ( !tls1_PRF(
            s->s3->tmp.new_cipher->algorithm2,
            (unsigned __int8 *)seed1,
            slen,
            seed2,
            v6 - seed2,
            0,
            0,
            0,
            0,
            0,
            0,
            s->session->master_key,
            s->session->master_key_length,
            out1,
            out2,
            12) )
      v10 = 1;
    EVP_MD_CTX_cleanup((unsigned int)s, &ctx);
    return v10 != 0 ? 0 : 12;
  }
  return result;
}
