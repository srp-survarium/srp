int __cdecl tls1_PRF(
        int digest_mask,
        const void *seed1,
        int seed1_len,
        const void *seed2,
        int seed2_len,
        const void *seed3,
        int seed3_len,
        const void *seed4,
        int seed4_len,
        const unsigned __int8 *seed5,
        int seed5_len,
        const __m128i *sec,
        int slen,
        unsigned __int8 *out1,
        unsigned __int8 *out2,
        int olen)
{
  unsigned __int8 *v16; // ebx
  unsigned int v17; // ebp
  int i; // edi
  int v19; // eax
  int v21; // ebp
  unsigned __int8 *v22; // eax
  int v23; // edx
  int v25; // [esp+10h] [ebp-8h] BYREF
  const env_md_st *v26; // [esp+14h] [ebp-4h] BYREF
  int v27; // [esp+48h] [ebp+30h]

  v16 = out2;
  v17 = 0;
  for ( i = 0; ssl_get_handshake_digest(v17, &v25, &v26); ++v17 )
  {
    if ( ((v25 << 8) & digest_mask) != 0 )
      ++i;
  }
  v19 = slen / i;
  v21 = v19;
  memset((int)out1, 0, olen);
  v27 = 0;
  if ( !ssl_get_handshake_digest(0, &v25, &v26) )
    return 1;
  while ( 1 )
  {
    if ( ((v25 << 8) & digest_mask) == 0 )
      goto LABEL_13;
    if ( !v26 )
      break;
    if ( !tls1_P_hash(
            seed2,
            seed3,
            (int)v16,
            v26,
            sec,
            v21 + (slen & 1),
            seed1,
            seed1_len,
            seed2_len,
            seed3_len,
            seed4,
            seed4_len,
            seed5,
            seed5_len,
            v16,
            olen) )
      return 0;
    sec = (const __m128i *)((char *)sec + v21);
    if ( olen > 0 )
    {
      v22 = out1;
      v23 = olen;
      do
      {
        *v22 ^= v22[v16 - out1];
        ++v22;
        --v23;
      }
      while ( v23 );
      v16 = out2;
    }
LABEL_13:
    if ( !ssl_get_handshake_digest(++v27, &v25, &v26) )
      return 1;
  }
  ERR_put_error((int)v16, 0x14u, 284, 326, ".\\ssl\\t1_enc.c", 265);
  return 0;
}
