int __cdecl tls1_process_ticket(
        ssl_st *s,
        unsigned __int8 *session_id,
        unsigned int len,
        unsigned __int8 *limit,
        ssl_session_st **ret)
{
  unsigned __int8 *v5; // esi
  int version; // ecx
  unsigned __int8 *v8; // ecx
  unsigned int v9; // ecx
  unsigned __int16 *v10; // esi
  unsigned __int16 v11; // dx
  unsigned __int16 v12; // di
  const __m128i *v13; // esi
  unsigned int v14; // ecx

  v5 = &session_id[len];
  if ( (SSL_ctrl(s, 32, 0, 0) & 0x4000) != 0 )
    return 1;
  version = s->version;
  if ( s->version <= 768 || !limit )
    return 1;
  if ( v5 >= limit )
    return -1;
  if ( version == 65279 || version == 256 )
  {
    v5 += *v5 + 1;
    if ( v5 >= limit )
      return -1;
  }
  v8 = &v5[(v5[1] | (unsigned __int16)(*v5 << 8)) + 2];
  if ( v8 >= limit )
    return -1;
  v9 = (unsigned int)&v8[*v8 + 1];
  if ( v9 > (unsigned int)limit )
    return -1;
  v10 = (unsigned __int16 *)(v9 + 2);
  if ( v9 + 2 >= (unsigned int)limit )
    return 1;
  if ( v9 + 6 > (unsigned int)limit )
    return 1;
  while ( 1 )
  {
    v11 = _byteswap_ushort(*v10);
    v12 = _byteswap_ushort(v10[1]);
    v13 = (const __m128i *)(v10 + 2);
    v14 = (unsigned int)v13->m128i_u32 + v12;
    if ( v14 > (unsigned int)limit )
      return 1;
    if ( v11 == 35 )
      break;
    v10 = (unsigned __int16 *)((char *)v13->m128i_u16 + v12);
    if ( v14 + 4 > (unsigned int)limit )
      return 1;
  }
  if ( (SSL_ctrl(s, 32, 0, 0) & 0x4000) != 0 )
    return 1;
  if ( !v12 )
  {
    s->tlsext_ticket_expected = 1;
    return 0;
  }
  if ( s->tls_session_secret_cb )
    return 0;
  return tls_decrypt_ticket(ret, v13, s, v12, session_id, len);
}
