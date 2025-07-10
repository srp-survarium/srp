BOOL __cdecl SSL_has_matching_session_id(const ssl_st *ssl, unsigned __int8 *id, unsigned int id_len)
{
  void **v4; // esi
  int data[17]; // [esp+8h] [ebp-F4h] BYREF
  unsigned int v6; // [esp+4Ch] [ebp-B0h]
  unsigned __int8 dst[168]; // [esp+50h] [ebp-ACh] BYREF

  if ( id_len > 0x20 )
    return 0;
  data[0] = ssl->version;
  v6 = id_len;
  memcpy(dst, id, id_len);
  if ( data[0] == 2 && id_len < 0x10 )
  {
    memset((int)&dst[id_len], 0, 16 - id_len);
    v6 = 16;
  }
  CRYPTO_lock((unsigned int)ssl, 5, 12, ".\\ssl\\ssl_lib.c", 463);
  v4 = lh_retrieve((lhash_st *)ssl->ctx->sessions, data);
  CRYPTO_lock((unsigned int)ssl, 6, 12, ".\\ssl\\ssl_lib.c", 465);
  return v4 != 0;
}
