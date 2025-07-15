const char *__cdecl ssl3_cert_verify_mac(ssl_st *s, int md_nid, unsigned __int8 *p)
{
  return ssl3_handshake_mac(s, md_nid, 0, 0, p);
}
