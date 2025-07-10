const char *__cdecl ssl3_final_finish_mac(ssl_st *s, const char *sender, unsigned int len, unsigned __int8 *p)
{
  const char *v4; // esi

  v4 = ssl3_handshake_mac(s, 4, sender, len, p);
  return &ssl3_handshake_mac(s, 64, sender, len, &p[(_DWORD)v4])[(_DWORD)v4];
}
