int __cdecl tls1_PRF(
        int digest_mask,
        unsigned __int8 *seed1,
        unsigned int seed1_len,
        unsigned __int8 *seed2,
        unsigned int seed2_len,
        unsigned __int8 *seed3,
        unsigned int seed3_len,
        unsigned __int8 *seed4,
        unsigned int seed4_len,
        unsigned __int8 *seed5,
        unsigned int seed5_len,
        unsigned __int8 *sec,
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
  int mask; // [esp+10h] [ebp-8h] BYREF
  const env_md_st *md; // [esp+14h] [ebp-4h] BYREF
  unsigned __int8 *seca; // [esp+48h] [ebp+30h]

  v16 = out2;
  v17 = 0;
  for ( i = 0; ssl_get_handshake_digest(v17, &mask, &md); ++v17 )
  {
    if ( ((mask << 8) & digest_mask) != 0 )
      ++i;
  }
  v19 = slen / i;
  v21 = v19;
  memset((int)out1, 0, olen);
  seca = 0;
  if ( !ssl_get_handshake_digest(0, &mask, &md) )
    return 1;
  while ( 1 )
  {
    if ( ((mask << 8) & digest_mask) == 0 )
      goto LABEL_13;
    if ( !md )
      break;
    if ( !tls1_P_hash(
            seed2,
            seed3,
            md,
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
    sec += v21;
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
    if ( !ssl_get_handshake_digest((unsigned int)++seca, &mask, &md) )
      return 1;
  }
  ERR_put_error(0x14u, 284, 326, ".\\ssl\\t1_enc.c", 265);
  return 0;
}
