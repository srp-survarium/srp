BOOL __usercall SSL_has_matching_session_id@<eax>(
        int a1@<ebx>,
        const ssl_st *ssl,
        const __m128i *id,
        unsigned int id_len)
{
  void ***v5; // esi
  int v6[17]; // [esp+8h] [ebp-F4h] BYREF
  unsigned int v7; // [esp+4Ch] [ebp-B0h]
  unsigned __int8 dst[168]; // [esp+50h] [ebp-ACh] BYREF

  if ( id_len > 0x20 )
    return 0;
  v6[0] = ssl->version;
  v7 = id_len;
  memcpy((int)dst, id, id_len);
  if ( v6[0] == 2 && id_len < 0x10 )
  {
    memset((int)&dst[id_len], 0, 16 - id_len);
    v7 = 16;
  }
  CRYPTO_lock((int)ssl, a1, 5, 12, ".\\ssl\\ssl_lib.c", 463);
  v5 = lh_retrieve((lhash_st *)ssl->ctx->sessions, v6);
  CRYPTO_lock((int)ssl, a1, 6, 12, ".\\ssl\\ssl_lib.c", 465);
  return v5 != 0;
}
